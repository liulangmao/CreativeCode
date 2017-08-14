//
//  ColorQrCode.cpp
//  C++
//
//  Created by liming on 2017/8/14.

//

#include "ColorQrCode.hpp"

UInt32 ColorQrCode::QQstyle_color [5] =  {  0xFF0094FF,0xFFFED545,0xFF5ACF00,0xFF000000,0xffffffff} ;
ColorElementStyle *ColorQrCode::QQstyle = new ColorElementStyle(ColorQrCode::QQstyle_color,"color_bak.bmp","color_logo1.png","color_water.png");


ColorQrCode::ColorQrCode(ColorElementStyle style)
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
    
    
CGImageRef ColorQrCode::ColorQRSweatake(string txt, int margin, int version) {
        
        int cellNumber = ComputCellNumberByVersion(version);
        int cellSize = 12;
        /*
         1.CreativeQRTool must be created before GenMatrix
         */
        ColorQRTool *h = new ColorQRTool(cellNumber, cellSize,style);
        //h.collectPixelCountBitmap(h.m_mat, WBImage, cellSize, cellSize);
        BasicQRTool *basic= new BasicQRTool(&txt);
        /*
         2. be careful about below line because in the method of GenMatrix will fill in h.m_mat
         */
        basic->GenMatrix(h->getMat());
        h->GenColorQrCode(margin);
        if(style.getLogoPathName()!=""){
            h->AddLogo();
        }
        if(style.getBackgroundPathName()!=""){
            h->AddBackground();
        }
        if(style.getWaterPathName()!=""){
            h->AddWatermark();
        }
        
        CGImageRef finalImage=h->getFinalImage();
        h->clean();
        return finalImage;
        
}
CGImageRef ColorQrCode::ColorQRMinSheng(string txt, int margin, int version ) {
        
        int cellNumber = ComputCellNumberByVersion(version);
        int cellSize = 10;
        /*
         1.CreativeQRTool must be created before GenMatrix
         */
        ColorQRTool *h = new ColorQRTool(cellNumber, cellSize,style);
        //h.collectPixelCountBitmap(h.m_mat, WBImage, cellSize, cellSize);
        BasicQRTool *basic= new BasicQRTool(&txt);
        /*
         2. be careful about below line because in the method of GenMatrix will fill in h.m_mat
         */
        basic->GenMatrix(h->getMat());
        h->GenMinShengColorQrCode(margin);
        
        CGImageRef finalImage=h->getFinalImage();
        h->clean();
    
        return finalImage;
        
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
