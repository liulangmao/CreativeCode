//
//  ColorQRTool.hpp
//  C++
//
//  Created by liming on 2017/8/14.
//

#ifndef ColorQRTool_hpp
#define ColorQRTool_hpp

#include <stdio.h>
#include "ColorElementStyle.hpp"
#include "CoreGraphics/CGImage.h"
#include <string>
#include <iostream>
using namespace std;
class ColorQRTool {
public:
    ColorQRTool(int size,int cellsize,ColorElementStyle style);
    int** getMat();
    void Print(int** array,int width,int height);
    
   // CGImageRef getResizedBitmap(CGImageRef bm, int newWidth, int newHeight) ;
//    CGImageRef getDiskBitmap(string name);
//    CGImageRef oldgetDiskBitmap(string pathString);
    
    void GenColorQrCode(int margin);
    void GenMinShengColorQrCode(int margin);
    
    void AddLogo();
    void AddBackground();
    void AddWatermark() ;
    void clean();
    
    UInt32* getFinalImage();
    
    void setFinalImage(UInt32* finalImage);

    int **m_mat;
    int size=0;
    int cellsize=0;
    
private:
    UInt32* finalImage;
    ColorElementStyle style;
    bool opendebug=true;
    
};








#endif /* ColorQRTool_hpp */
