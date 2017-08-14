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
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
class ColorQrCode {
public:
    static ColorElementStyle *QQstyle;
    static UInt32 QQstyle_color[5];

    
    ColorQrCode(ColorElementStyle style);
    ColorQrCode();
    static int ComputCellNumberByVersion(int version);
    CGImageRef ColorQRSweatake(string txt, int margin, int version);
    CGImageRef ColorQRMinSheng(string txt, int margin, int version);
    CGImageRef getDiskBitmap(string imagename);
    CGImageRef getResizedBitmap(CGImageRef imageref, CGSize newSize);

    
private:
    int version=0;
    int margin=0;
    ColorElementStyle style;
};
#endif /* ColorQrCode_hpp */
