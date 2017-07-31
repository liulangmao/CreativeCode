//
//  CreativeQrCode.cpp
//  CreativeQRcode
//
//  Created by liming on 2017/7/25.
//  Copyright © 2017年 liming. All rights reserved.
//

#include "CreativeQrCode.hpp"
#include "CoreGraphics/CGImage.h"
#import <UIKit/UIKit.h>
#include <string>
using namespace std;

CreativeQrCode::CreativeQrCode(CreativeElementStyle style){
    this->setStyle(style);
}

CGImageRef  CreativeQrCode::getDiskBitmap(string imagename){
    NSString *imageName = [NSString stringWithCString:imagename.c_str()
                                             encoding:[NSString defaultCStringEncoding]];
    
    
    UIImage *image = [UIImage imageNamed:imageName];
    CGImageRef imageRefs = [image CGImage];
    
    size_t imageWidth = CGImageGetWidth(imageRefs);
    size_t imageHeight = CGImageGetHeight(imageRefs);
    size_t bytesPerRow = imageWidth * 4;
    
    //为所有的像素点分配内存
    uint32_t* bitmapData = (uint32_t*)malloc(bytesPerRow * imageHeight);
    
    //颜色空间
    CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
    
    //创建context
    CGContextRef context = CGBitmapContextCreate(bitmapData, imageWidth, imageHeight, 8, bytesPerRow, colorSpace,kCGBitmapByteOrderDefault | kCGImageAlphaPremultipliedFirst);
    
    CGContextDrawImage(context, CGRectMake(0, 0, imageWidth, imageHeight),imageRefs);
    
    //遍历像素
    size_t pixelNum = imageWidth * imageHeight;
    uint32_t* pCurPtr = bitmapData;
    for (int i = 0; i < pixelNum; i++, pCurPtr++) {
        uint8_t* ptr = (uint8_t*)pCurPtr;
        //        ptr[0] = 255;//alpha
        //        ptr[1] = 0;//red
        //        ptr[2] = 255;//green
        //        ptr[3] = 0;//blue
       // NSLog(@"比特:%d  A:%hhu  R:%hhu  G:%hhu  B:%hhu",i,ptr[0],ptr[1],ptr[2],ptr[3]);
    }
    CGDataProviderRef dataProvider = CGDataProviderCreateWithData(NULL, bitmapData, bytesPerRow * imageHeight, NULL);
    
    CGImageRef imageRef = CGImageCreate(imageWidth, imageHeight, 8, 32, bytesPerRow, colorSpace,kCGBitmapByteOrderMask | kCGImageAlphaPremultipliedFirst, dataProvider,NULL, YES, kCGRenderingIntentDefault);
    
    CGDataProviderRelease(dataProvider);
    CGContextRelease(context);
    CGColorSpaceRelease(colorSpace);
    
    return imageRef;

}
CGImageRef CreativeQrCode::getResizedBitmap(CGImageRef imageref, CGSize newSize){
    
        UIImage* image = [UIImage imageWithCGImage: imageref];
    
        UIGraphicsBeginImageContext(newSize);
        UIGraphicsBeginImageContextWithOptions(newSize, NO, 0.0);
        [image drawInRect:CGRectMake(0, 0, newSize.width, newSize.height)];
        UIImage *newImage = UIGraphicsGetImageFromCurrentImageContext();
        UIGraphicsEndImageContext();
    
        return newImage.CGImage;
}
void CreativeQrCode::AnalysisStyle(int cellSize){
    string name="";
    string* namelist=style.getNamelist();
    cout<<"AnalysisStyle====namelist"<<namelist->size();
    bool resize=true;
    for ( int n=0;n<namelist->size();n++) {
        name=namelist[n];
        std::size_t found_=name.find("_");
        std::size_t foundbmp=name.find("bmp");
        if((found_!= std::string::npos)&&(foundbmp!= std::string::npos))
        {
            int index=(int)found_;
            int index_bmp=(int)name.find(".");
            string nameread=name.substr(0,index_bmp);
            string nameswitch=name.substr(index+1, index+1+3);
            CGImageRef image = getDiskBitmap(nameread);
            CGImageRef resizeimage;
            if(strcmp(nameswitch.c_str(),"4_2")==0)
            {
                    CreativeElement *FourByTwo = new CreativeElement(-4,4,2);
                    if(resize) {
                        CGSize size=CGSizeMake(2 * cellSize, 4 * cellSize);
                        resizeimage = getResizedBitmap(image, size);
                        FourByTwo->getPreImage()->push_back(resizeimage);
                    }
                    else{
                        FourByTwo->getPreImage()->push_back(image);
                    }
                CreativeEnv::addElement(FourByTwo);
                //cout<<"AnalysisStyle====case 4_2";

                    
            }else if(strcmp(nameswitch.c_str(),"7_7")==0){
                if(resize) {
                    CGSize size=CGSizeMake(7 * cellSize, 7 * cellSize);
                    resizeimage = getResizedBitmap(image, size);
                    CreativeEnv::getEye().getPreImage()->push_back(resizeimage);
                }
                else{
                    CreativeEnv::getEye().getPreImage()->push_back(image);
                }
                 //cout<<"AnalysisStyle====case 7_7";
            }else if(strcmp(nameswitch.c_str(),"3_1")==0){
                    CreativeElement *ThreeByOne = new CreativeElement(-5, 3, 1);
                    if(resize) {
                        CGSize size=CGSizeMake(cellSize, 3 * cellSize);
                        resizeimage = getResizedBitmap(image, size);
                        ThreeByOne->getPreImage()->push_back(resizeimage);
                    }
                    else{
                        ThreeByOne->getPreImage()->push_back(image);
                    }
                    CreativeEnv::addElement(ThreeByOne);
                    //cout<<"AnalysisStyle====case 3_1";
            }else if(strcmp(nameswitch.c_str(),"2_2")==0){
                    CreativeElement *TwoByTwo = new CreativeElement(-2, 2, 2);
                    if(resize) {
                        CGSize size=CGSizeMake(2 * cellSize, 2 * cellSize);
                        resizeimage = getResizedBitmap(image, size);
                        TwoByTwo->getPreImage()->push_back(resizeimage);
                    }
                    else{
                        TwoByTwo->getPreImage()->push_back(image);
                    }
                    CreativeEnv::addElement(TwoByTwo);
                    //cout<<"AnalysisStyle====case 2_2";
            }else if(strcmp(nameswitch.c_str(),"2_1")==0){
                
                    CreativeElement *TwoByOne = new CreativeElement(-3, 2, 1);
                    if(resize) {
                        CGSize size=CGSizeMake(cellSize, 2 * cellSize);
                        resizeimage = getResizedBitmap(image, size);
                        TwoByOne->getPreImage()->push_back(resizeimage);
                    }
                    else{
                        TwoByOne->getPreImage()->push_back(image);
                    }
                    CreativeEnv::addElement(TwoByOne);
                    //cout<<"AnalysisStyle====case 2_1";
            }else if(strcmp(nameswitch.c_str(),"1_1")==0){
                    
                    CreativeElement *OneByOne = new CreativeElement(-6, 1, 1);
                    if(resize) {
                        CGSize size=CGSizeMake(cellSize, cellSize);
                        resizeimage = getResizedBitmap(image, size);
                        OneByOne->getPreImage()->push_back(resizeimage);
                    }
                    else{
                        OneByOne->getPreImage()->push_back(image);
                    }
                    CreativeEnv::addElement(OneByOne);
                    //cout<<"AnalysisStyle====case 1_1";
                }
           
        }
    }
}
int CreativeQrCode::ComputCellNumberByVersion(int version){
    int cellNumber = 21 + (version-1) * 4;
    return cellNumber;
}
CGImageRef CreativeQrCode::CreativeQRZXing(string txt,int size,int margin){
    bool Ischange=AnalysisVersion(size, txt,margin);
    
    //string error="version="+version+"margin"+margin;
    //Log.i("CreativeQRZXing", error);
    int cellNumber = ComputCellNumberByVersion(version);
    int cellSize = this->getStyle().getCellsize();
    //System.out.println("version="+version+"cellNumber:"+cellNumber+"cellsize"+cellSize);
    /*
     1.CreativeQRTool must be created before GenMatrix
     */
    AnalysisStyle(cellSize);
    CreativeQRTool *h = new CreativeQRTool(cellNumber, cellSize);
    //h.collectPixelCountBitmap(h.m_mat, WBImage, cellSize, cellSize);
    BasicQRTool *basic= new BasicQRTool(&txt);
    /*
     2. be careful about below line because in the method of GenMatrix will fill in h.m_mat
     */
    
    basic->GenMatrix(h->getMat());
    h->fillEye();
    //basic->Print(h->getMat(),21 , 21);
    h->FindCellEqualsOne();
    h->FillbyType();

    
    int inputImageSize=cellNumber*cellSize+2*margin;
    //h.LoadPreImage(style.getNamelist(),mContext);// in current directory just ok.
   
    //to do:
    //Bitmap finalImage=h.CreateFinal(inputImageSize, margin);
    
    //System.out.println("finalImage.width()"+finalImage.getWidth()+"finalImage.height()"+finalImage.getHeight());
    if(Ischange){
        //to do
        //finalImage=h->getResizedBitmap(finalImage,size,size);
        
        //System.out.println("size="+size+"finalImage.width()"+finalImage.getWidth()+"finalImage.height()"+finalImage.getHeight());
    }
    
    h->clean();
    
    //to do
    CGImageRef a;
    
    return a;
}
  int CreativeQrCode::binarySearch(int* srcArray, int width,int des){
    
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
    return -1;
}
// to do
//bool CreativeQrCode::AnalysisVersion(int size, string txt,int margin) {
//    byte* d = new byte[0];
//    d = txt.getBytes();
//    int versiontemp = 0;
//    int* numbersize = {17, 32, 53, 78, 106, 134, 154, 192, 230, 271, 321, 367, 425, 458, 520, 586, 644, 718, 792, 858, 929, 1003,
//        1091,1171,1273,1367,1465,1528,1628,1732,1840,1952,2068,2188,2303,2431,2563,2699,2809,2053};
//    versiontemp = binarySearch(numbersize, d.length)+1;
//    margin=margin;
//    
//    version=versiontemp;
//    int versionwidth=21+(versiontemp-1)*4;
//    double wtdouble = (double)versionwidth;
//    int sizetemp=size-2*margin;
//    double cellsizedoule=Math.floor(sizetemp/wtdouble);
//    style.setCellsize((int)cellsizedoule);
//    int finalsize=versionwidth*(int)cellsizedoule+margin*2;
//    
//    
//    String error="version="+versiontemp+"margin"+margin+"totalsize:"+finalsize;
//    Log.i("binarySearch=", error);
//    System.out.println("version="+versiontemp+"totalsize:"+finalsize);
//    
//    if(finalsize!=size)
//    {
//        return true;
//    }
//    else{
//        return false;
//    }
//}
CreativeElementStyle CreativeQrCode::getStyle(){
        return style;
}
void CreativeQrCode::setStyle(CreativeElementStyle style){
      this->style = style;
}
string CreativeQrCode::getLogoPath(){
   return logoBmpPath;
}
void CreativeQrCode::setLogoPath(string logoBmp){
    logoBmpPath = logoBmp;
}
