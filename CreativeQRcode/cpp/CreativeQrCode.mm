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
        NSLog(@"比特:%d  A:%hhu  R:%hhu  G:%hhu  B:%hhu",i,ptr[0],ptr[1],ptr[2],ptr[3]);
    }
    CGDataProviderRef dataProvider = CGDataProviderCreateWithData(NULL, bitmapData, bytesPerRow * imageHeight, NULL);
    
    CGImageRef imageRef = CGImageCreate(imageWidth, imageHeight, 8, 32, bytesPerRow, colorSpace,kCGBitmapByteOrderMask | kCGImageAlphaPremultipliedFirst, dataProvider,NULL, YES, kCGRenderingIntentDefault);
    
    CGDataProviderRelease(dataProvider);
    CGContextRelease(context);
    CGColorSpaceRelease(colorSpace);
    
    return imageRef;

}
// Bitmap getResizedBitmap(Bitmap bm, int newWidth, int newHeight);
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
            //Bitmap image = getDiskBitmap(mContext,nameread);
            //CGImage resizeimage;
            if(strcmp(nameswitch.c_str(),"4_2")==0)
            {
                    CreativeElement *FourByTwo = new CreativeElement(-4,4,2);
                    if(resize) {
                        //resizeimage = getResizedBitmap(image, 2 * cellSize, 4 * cellSize);
                        //FourByTwo.getPreImage().add(resizeimage);
                    }
                    else{
                       // FourByTwo.getPreImage().add(image);
                    }
                CreativeEnv::addElement(FourByTwo);
                    
            }else if(strcmp(nameswitch.c_str(),"7_7")==0){
                    if(resize) {
                       // resizeimage = getResizedBitmap(image, 7 * cellSize, 7 * cellSize);
                       // CreativeEnv.getEye().getPreImage().add(resizeimage);
                    }
                    else{
                       // CreativeEnv.getEye().getPreImage().add(image);
                    }
                    //System.out.println("AnalysisStyle====case 7_7");
            }else if(strcmp(nameswitch.c_str(),"3_1")==0){
                    CreativeElement *ThreeByOne = new CreativeElement(-5, 3, 1);
                    if(resize) {
                        //resizeimage = getResizedBitmap(image,  cellSize, 3 * cellSize);
                       // ThreeByOne.getPreImage().add(resizeimage);
                    }
                    else{
                        //ThreeByOne.getPreImage().add(image);
                    }
                    CreativeEnv::addElement(ThreeByOne);
                    //System.out.println("AnalysisStyle====case 3_1");
            }else if(strcmp(nameswitch.c_str(),"2_2")==0){
                    CreativeElement *TwoByTwo = new CreativeElement(-2, 2, 2);
                    if(resize) {
                        //resizeimage = getResizedBitmap(image, 2 * cellSize, 2 * cellSize);
                        //TwoByTwo.getPreImage().add(resizeimage);
                    }
                    else{
                        //TwoByTwo.getPreImage().add(image);
                    }
                    CreativeEnv::addElement(TwoByTwo);
                    //System.out.println("AnalysisStyle====case 2_2");
            }else if(strcmp(nameswitch.c_str(),"2_1")==0){
                
                    CreativeElement *TwoByOne = new CreativeElement(-3, 2, 1);
                    if(resize) {
                       // resizeimage = getResizedBitmap(image,  cellSize, 2 * cellSize);
                       // TwoByOne.getPreImage().add(resizeimage);
                    }
                    else{
                        //TwoByOne.getPreImage().add(image);
                    }
                    CreativeEnv::addElement(TwoByOne);
                    //System.out.println("AnalysisStyle====case 2_1");
            }else if(strcmp(nameswitch.c_str(),"1_1")==0){
                    
                    CreativeElement *OneByOne = new CreativeElement(-6, 1, 1);
                    if(resize) {
                       // resizeimage = getResizedBitmap(image, cellSize,  cellSize);
                      //  OneByOne.getPreImage().add(resizeimage);
                    }
                    else{
                       // OneByOne.getPreImage().add(image);
                    }
                CreativeEnv::addElement(OneByOne);
                    //System.out.println("AnalysisStyle====case 1_1");
                }
           
        }
    }
}
int CreativeQrCode::ComputCellNumberByVersion(int version){
    int cellNumber = 21 + (version-1) * 4;
    return cellNumber;
}
//Bitmap CreativeQRZXing(string txt,int size,int margin,Context mContext);
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
