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
class ColorQrCode {
public:
   static ColorElementStyle QQstyle = new ColorElementStyle(new int[]{0xFF0094FF,0xFFFED545,0xFF5ACF00,0xFF000000,0xffffffff},
                                                                          "color_bak.bmp",
                                                                          "color_logo1.png",
                                                                        "color_water.png");
    ColorQrCode(ColorElementStyle style);
    ColorQrCode();
    static int ComputCellNumberByVersion(int version);
    CGImageRef ColorQRSweatake(string txt, int margin, int version);
    CGImageRef ColorQRMinSheng(string txt, int margin, int version);
private:
    int version=0;
    int margin=0;
    ColorElementStyle style;
};
#endif /* ColorQrCode_hpp */
