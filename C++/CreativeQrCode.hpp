//
//  CreativeQrCode.hpp
//  C++
//
//  Created by liming on 2017/8/2.
//  Copyright © 2017年 杨金保. All rights reserved.
//

#ifndef CreativeQrCode_hpp
#define CreativeQrCode_hpp

#include <stdio.h>
#include "CreativeEnv.hpp"
#include "CreativeElement.hpp"
#include "BasicQRTool.hpp"
#include "CreativeQRTool.hpp"
#include "CreativeElementStyle.hpp"
#include <string>
#include "CoreGraphics/CGImage.h"
#include <stdbool.h>
using namespace std;



#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

class CreativeQrCode{
public:
    
    static CreativeElementStyle *YELLOWBOY;
    static string YELLOWBOY_namelist[9];
    static CreativeElementStyle *BAMBOO;
    static string BAMBOO_namelist[5];

    CreativeQrCode(CreativeElementStyle style);
    CGImageRef CreativeQRZXing(string txt,int size,int margin);
    CGImageRef getDiskBitmap(string imagename);
    CGImageRef getResizedBitmap(CGImageRef imageref, CGSize newSize);
    
    void AnalysisStyle(int cellSize);
    static int ComputCellNumberByVersion(int version);
    //Bitmap CreativeQRZXing(string txt,int size,int margin,Context mContext);
    CreativeElementStyle getStyle();
    void setStyle(CreativeElementStyle style);
    string getLogoPath();
    void setLogoPath(string logoBmp);
    
    
    CGImageRef* CreateFinal(int size,int margin);
    UIImage* testRead();
    
    
    UIImage* creatEmptyImg(UIColor * color,CGSize size);
    UIImage * processUsingPixels(UIImage* inputImage);
    
    
private:
    int version=0;
    int margin=0;
    string logoBmpPath="";
    CreativeElementStyle style;
    static int ComputCellSize(CreativeElementStyle style);
    static int binarySearch(int* srcArray, int width,int des);
    UInt32 * ChangFromImage2Int(CGImageRef imageRefs);
    // bool AnalysisVersion(int size, string txt,int margin);
    bool opendebug=true;
};


#endif /* CreativeQrCode_hpp */
