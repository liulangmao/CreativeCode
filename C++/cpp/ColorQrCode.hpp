//
//  ColorQrCode.hpp
//  C++
//
//  Created by liming on 2017/8/14.

//

#ifndef ColorQrCode_hpp
#define ColorQrCode_hpp

#include <stdio.h>
#include "ColorElementStyle.hpp"
#include "CoreGraphics/CGImage.h"
#include "ColorQRTool.hpp"
#include "BasicQRTool.hpp"
#include <stdbool.h>
#include <math.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
class ColorQrCode {
public:

    static ColorElementStyle *QQstyle;
    static UInt32 QQstyle_color[5];

    
    ColorQrCode();
    ColorQrCode(ColorElementStyle* style);
   
    static int ComputCellNumberByVersion(int version);
    CGImageRef ColorQRZXing(string txt, int size, int margin);
    CGImageRef ColorQRMinSheng(string txt, int size, int margin);
    int AnalysisVersion(int size, string txt,int margin);
    
    CGImageRef ChangFromInt2Image(UInt32 * bitmapData,int imageWidth, int imageHeight);
    CGImageRef getDiskBitmap(string imagename);
    CGImageRef getResizedBitmap(CGImageRef imageref, CGSize newSize);
    UInt32 * ChangFromImage2Int(CGImageRef imageRefs);
    UIImage *addImage(UIImage *image1,UIImage *image2,int width, int height);
    //UIImage *addWaterColorImage(UIImage *image1,UIImage *image2);
    //UIImage *addLogoImage(UIImage *image1,UIImage *image2);
    int binarySearch(int* srcArray, int width,int des);

private:
    int version=0;
    int margin=0;
    ColorElementStyle *style;
};
#endif /* ColorQrCode_hpp */
