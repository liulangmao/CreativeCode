//
//  CMBCImageRef.cpp
//  C++
//
//  Created by 杨金保 on 2017/7/21.
//  Copyright © 2017年 杨金保. All rights reserved.
//

#include "CMBCImageRef.hpp"
//#import "ViewController.h"

#include <list>
#include <string>
using namespace std;

#pragma mark - 
/*
 @param imageName 图片名字
 @return CGImageRef 返回CGImageRef
 */
 CGImageRef SetBitMapImage(string imagename) {
     
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

/*
 *@param imageName 图片名字
 *@param bitmapData
 */
void CreateImage(std::string imageName , uint32_t *bitmapData) {
//    CGImageRef imageRef = [self createImageRefWidth:200 height:200 bitmapData:bitmapData];
//    
//    std::cout<<imageRef<<std::endl;
}

/*
 *@param imageWidth 图片宽度
 *@param imageHeight 图片高度
 *@param bitmapData
 *@return CGImageRef
 */
CGImageRef CreateImageRef(float imageWidth, float imageHeight, uint32_t *bitmapData)
{
    size_t bytesPerRow = imageWidth * 4;
    
    //颜色空间
    CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
    
    uint32_t* rgbBufferData;
    if (!bitmapData) {
        CGColorSpaceRelease(colorSpace);
        return NULL;
    }else {
        rgbBufferData = bitmapData;
    }
    
    //遍历像素
    size_t pixelNum = imageWidth * imageHeight;
    uint32_t* pCurPtr = rgbBufferData;
    for (int i = 0; i < pixelNum; i++, pCurPtr++) {
        uint8_t* ptr = (uint8_t*)pCurPtr;
        ptr[0] = 255;//alpha
        ptr[1] = 0;//red
        ptr[2] = 255;//green
        ptr[3] = 0;//blue
        NSLog(@"比特:%d  A:%hhu  R:%hhu  G:%hhu  B:%hhu",i,ptr[0],ptr[1],ptr[2],ptr[3]);
    }
    //创建context
    CGContextRef context = CGBitmapContextCreate(bitmapData, imageWidth, imageHeight, 8, bytesPerRow, colorSpace,kCGBitmapByteOrderDefault | kCGImageAlphaPremultipliedFirst);
    
    CGContextDrawImage(context, CGRectMake(0, 0, imageWidth, imageHeight),NULL);
    
    CGDataProviderRef dataProvider = CGDataProviderCreateWithData(NULL, bitmapData, bytesPerRow * imageHeight, NULL);
    
    CGImageRef imageRef = CGImageCreate(imageWidth, imageHeight, 8, 32, bytesPerRow, colorSpace,kCGBitmapByteOrderDefault | kCGImageAlphaPremultipliedFirst, dataProvider,NULL, YES, kCGRenderingIntentDefault);
    CGDataProviderRelease(dataProvider);
    
    CGContextRelease(context);
    CGColorSpaceRelease(colorSpace);
    
    return imageRef;
}


