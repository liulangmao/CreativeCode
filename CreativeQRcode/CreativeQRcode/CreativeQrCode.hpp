//
//  CreativeQrCode.hpp
//  CreativeQRcode
//
//  Created by liming on 2017/7/25.
//  Copyright © 2017年 liming. All rights reserved.
//

#ifndef CreativeQrCode_hpp
#define CreativeQrCode_hpp

#include <stdio.h>
#include <CreativeEnv.hpp>
#include <CreativeElement.hpp>
#include <BasicQRTool.hpp>
#include <CreativeQRTool.hpp>
#include <CreativeElementStyle.hpp>
#include <string>
#include "CoreGraphics/CGImage.h"
using namespace std;

class CreativeQrCode{
public:
    CreativeQrCode(CreativeElementStyle style);
   // Bitmap getDiskBitmap(Context mContext, string name);
   // Bitmap getResizedBitmap(Bitmap bm, int newWidth, int newHeight);
    void AnalysisStyle(int cellSize);
    static int ComputCellNumberByVersion(int version);
    //Bitmap CreativeQRZXing(string txt,int size,int margin,Context mContext);
    CreativeElementStyle getStyle();
    void setStyle(CreativeElementStyle style);
    string getLogoPath();
    void setLogoPath(string logoBmp);
    
private:
    int version=0;
    int margin=0;
    string logoBmpPath="";
    CreativeElementStyle style;
    static int ComputCellSize(CreativeElementStyle style);
    static int binarySearch(int* srcArray, int des);
    bool AnalysisVersion(int size, string txt,int margin);
    
};

#endif /* CreativeQrCode_hpp */
