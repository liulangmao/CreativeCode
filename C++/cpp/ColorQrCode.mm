//
//  ColorQrCode.cpp
//  C++
//
//  Created by liming on 2017/8/14.

//

#include "ColorQrCode.hpp"


UInt32 ColorQrCode::QQstyle_color [5] =  {  0xFF0094FF,0xFFFED545,0xFF5ACF00,0xFF000000,0xffffffff} ;
ColorElementStyle *ColorQrCode::QQstyle = new ColorElementStyle(ColorQrCode::QQstyle_color,"color_bak.bmp","color_logo1.png","color_water.png");


ColorQrCode::ColorQrCode(ColorElementStyle* style)
{
        this->style=style;
}
ColorQrCode::ColorQrCode()
{
        
}
int ColorQrCode::ComputCellNumberByVersion(int version)
{
        int cellNumber = 21 + (version-1) * 4;
        return cellNumber;
}

int ColorQrCode::binarySearch(int* srcArray, int width,int des){
    
    int low = 0;
    int high = width-1;
    while(low <= high) {
        int middle = (low + high)/2;
        if(low==high)
        {
            return low;
        }
        if(des < srcArray[middle]&&des >= srcArray[middle-1]) {
            return middle;
        }else if(des >=srcArray[middle]) {
            low = middle+1;
        }else {
            high = middle - 1;
        }
    }
    return 0;
}
typedef char byte;
int ColorQrCode::AnalysisVersion(int size, string txt,int margin) {
    // std::string srt = "hello world mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm";
    byte* cstr = new byte [txt.size() + 1];
    std::strcpy(cstr, txt.c_str());
    
    
    int versiontemp = 0;
    int numbersize [40]= {17, 32, 53, 78, 106, 134, 154, 192, 230, 271, 321, 367, 425, 458, 520, 586, 644, 718, 792, 858, 929, 1003,
        1091,1171,1273,1367,1465,1528,1628,1732,1840,1952,2068,2188,2303,2431,2563,2699,2809,2053};
    versiontemp = (binarySearch(numbersize,(int)txt.size() + 1,(int)txt.size() + 1))+1;

    
    version=versiontemp;
    int versionwidth=21+(versiontemp-1)*4;
    double wtdouble = (double)versionwidth;
    int sizetemp=size-2*margin;
    double cellsizedoule=floor(sizetemp/wtdouble);
    style->setCellSize((int)cellsizedoule);
    int finalsize=versionwidth*(int)cellsizedoule+margin*2;
    
    
    cout<< "binarySearch  "<<"version="<<versiontemp<<" margin="<<margin<<" totalsize="<<finalsize<<endl;
    delete [] cstr;
    if(finalsize!=size)
    {
        return finalsize;
    }
    else{
        return finalsize;
    }

}
CGImageRef ColorQrCode::getResizedBitmap(CGImageRef imageref, CGSize newSize){
    
    CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
    
    UInt32 * resizePixels = (UInt32 *)calloc(newSize.width * newSize.height, sizeof(UInt32));
    
    CGContextRef mainViewContentContext = CGBitmapContextCreate (resizePixels, newSize.width, newSize.height,
                                                                 8, newSize.width*4, colorSpace, kCGImageAlphaPremultipliedLast |kCGBitmapByteOrder32Big);
    
    
    
    CGContextSetInterpolationQuality(mainViewContentContext, kCGInterpolationHigh);
    CGContextDrawImage(mainViewContentContext, CGRectMake(0,0, newSize.width, newSize.height), imageref);
    
    CGDataProviderRef dataProvider = CGDataProviderCreateWithData(NULL, resizePixels, 4 * newSize.width, NULL);
    size_t bytesPerRow = newSize.width * 4;
    CGImageRef imageRefresize = CGImageCreate(newSize.width, newSize.height, 8, 32, bytesPerRow, colorSpace,kCGImageAlphaPremultipliedLast |kCGBitmapByteOrder32Big, dataProvider,NULL, YES, kCGRenderingIntentDefault);

    CGDataProviderRelease(dataProvider);
    CGContextRelease(mainViewContentContext);
    CGColorSpaceRelease(colorSpace);
    
    return imageRefresize;
}
CGImageRef  ColorQrCode::getDiskBitmap(string imagename){
    NSString *imageName = [NSString stringWithCString:imagename.c_str()
                                             encoding:[NSString defaultCStringEncoding]];
    UIImage *image = [UIImage imageNamed:imageName];
    CGImageRef imageRefs = [image CGImage];
    return imageRefs;
    
}
UInt32 * ColorQrCode::ChangFromImage2Int(CGImageRef imageRefs){
    
    size_t imageWidth = CGImageGetWidth(imageRefs);
    size_t imageHeight = CGImageGetHeight(imageRefs);
    size_t bytesPerRow = imageWidth * 4;
    
    //为所有的像素点分配内存
    UInt32 * bitmapData = (UInt32 *)calloc(bytesPerRow * imageHeight, sizeof(UInt32));
    //颜色空间
    CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
    
    //创建context
    CGContextRef context = CGBitmapContextCreate(bitmapData, imageWidth, imageHeight, 8, bytesPerRow, colorSpace,kCGBitmapByteOrderDefault | kCGImageAlphaPremultipliedFirst);
    
    CGContextDrawImage(context, CGRectMake(0, 0, imageWidth, imageHeight),imageRefs);
    
    CGContextRelease(context);
    CGColorSpaceRelease(colorSpace);
    
    return bitmapData;
}
CGImageRef ColorQrCode::ChangFromInt2Image(UInt32 * bitmapData,int imageWidth, int imageHeight){
    
    size_t bytesPerRow = imageWidth * 4;
    CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
    CGContextRef context = CGBitmapContextCreate(bitmapData, imageWidth, imageHeight, 8, bytesPerRow, colorSpace,kCGBitmapByteOrderDefault | kCGImageAlphaPremultipliedFirst);
    CGContextDrawImage(context, CGRectMake(0, 0, imageWidth, imageHeight),NULL);
    
    CGDataProviderRef dataProvider = CGDataProviderCreateWithData(NULL, bitmapData, bytesPerRow * imageHeight, NULL);
    CGImageRef imageRef = CGImageCreate(imageWidth, imageHeight, 8, 32, bytesPerRow, colorSpace,kCGBitmapByteOrderDefault | kCGImageAlphaPremultipliedFirst, dataProvider,NULL, YES, kCGRenderingIntentDefault);
    
    
    CGDataProviderRelease(dataProvider);
    CGContextRelease(context);
    CGColorSpaceRelease(colorSpace);
    
    return imageRef;
}
CGImageRef ColorQrCode::ColorQRZXing(string txt, int size,int margin) {
    
    /*
        1.CreativeQRTool must be created before GenMatrix
    */
    int finalsize=  AnalysisVersion(size,txt,margin);
    int cellNumber = ComputCellNumberByVersion(version);
    CGImageRef finalImage=NULL;
    ColorQRTool *h = new ColorQRTool(cellNumber, style->getCellSize(),style);
    //h.collectPixelCountBitmap(h.m_mat, WBImage, cellSize, cellSize);
    BasicQRTool *basic= new BasicQRTool(&txt);
    /*
    2. be careful about below line because in the method of GenMatrix will fill in h.m_mat
    */
    basic->GenMatrix(h->getMat());
    h->GenColorQrCode(margin);
    
    finalImage=ChangFromInt2Image(h->getFinalImage(), finalsize, finalsize);
    
    finalImage=getResizedBitmap(finalImage,CGSizeMake(300, 300));
    //add background:
    UIImage* image;
    if(style->getBackgroundPathName()!=""){
    image = [UIImage imageWithCGImage: finalImage];
    CGImageRef backbmp=getDiskBitmap("color_bak.bmp");
    UIImage* backgroundImg = [UIImage imageWithCGImage: backbmp];
    image=addImage(backgroundImg,image,100,300);//image cover background
    finalImage=image.CGImage;
    }
    
    if(style->getBackgroundPathName()!=""){
    CGImageRef waterbmp=getDiskBitmap("color_water.png");
     UIImage* waterImage = [UIImage imageWithCGImage: waterbmp];
    image=addImage(image,waterImage,300,80);
        finalImage=image.CGImage;
    }
    
    if(style->getBackgroundPathName()!=""){
    CGImageRef logobmp=getDiskBitmap("color_logo1.png");
    logobmp=getResizedBitmap(logobmp,CGSizeMake(60, 60));
    UIImage* logoImage = [UIImage imageWithCGImage: logobmp];
    image=addImage(image,logoImage,230,420);
        finalImage=image.CGImage;
    }
    h->clean();
    
    return finalImage;
        
}
UIImage *ColorQrCode::addImage(UIImage *image1,UIImage *image2,int width, int height){
    
    
    UIGraphicsBeginImageContext(image1.size);
    
    [image1 drawInRect:CGRectMake(0, 0, image1.size.width, image1.size.height)];
    
    //    [image2 drawInRect:CGRectMake((image1.size.width - image2.size.width)/2,(image1.size.height - image2.size.height)/2, image2.size.width, image2.size.height)];
    [image2 drawInRect:CGRectMake(width,height, image2.size.width, image2.size.height)];
    
    UIImage *resultingImage = UIGraphicsGetImageFromCurrentImageContext();
    
    UIGraphicsEndImageContext();
    
    return resultingImage;

}


CGImageRef ColorQrCode::ColorQRMinSheng(string txt, int size, int margin) {
        
    int finalsize=  AnalysisVersion(size,txt,margin);
    int cellNumber = ComputCellNumberByVersion(version);
    CGImageRef finalImage=NULL;
    ColorQRTool *h = new ColorQRTool(cellNumber, style->getCellSize(),style);
    //h.collectPixelCountBitmap(h.m_mat, WBImage, cellSize, cellSize);
    BasicQRTool *basic= new BasicQRTool(&txt);
    /*
     2. be careful about below line because in the method of GenMatrix will fill in h.m_mat
     */
    basic->GenMatrix(h->getMat());
   
    CGImageRef resizeimage=getDiskBitmap("ms_logo.bmp");
    if(!(CGImageGetWidth(resizeimage)==cellNumber&&CGImageGetHeight(resizeimage)==cellNumber))
    {
        resizeimage=getResizedBitmap(resizeimage,CGSizeMake(finalsize,  finalsize));
    }
    UInt32* temp=ChangFromImage2Int(resizeimage);
    h->SetMask(temp,cellNumber);
    h->GenMinShengColorQrCode(margin);
    finalImage=ChangFromInt2Image(h->getFinalImage(), finalsize, finalsize);
    
    
    h->clean();
    return finalImage;
}
