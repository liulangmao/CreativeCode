//
//  ColorElementStyle.hpp
//  C++
//
//  Created by liming on 2017/8/14.
//

#ifndef ColorElementStyle_hpp
#define ColorElementStyle_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "CoreGraphics/CGImage.h"
using namespace std;
class ColorElementStyle {
public:
    ColorElementStyle();
    ColorElementStyle(UInt32* Color,string backgroundPathName,string logoPathName,string waterPathName);
    ColorElementStyle(UInt32* Color);
    void setColor(UInt32*  Color);
    UInt32* getColor();
    
    void setLogoPathName(string logoPathName) ;
    string getLogoPathName();
    void setBackgroundPathName(string backgroundPathName) ;
    string getBackgroundPathName();
    
    void setWaterPathName(string waterPathName) ;
    string getWaterPathName();
    
    void setCellSize(int cellSize);
    int getCellSize();
    private:
    UInt32*  color;//[0] 左上，左下，右上，右下。
    string logoPathName="";
    string backgroundPathName="";
    string WaterPathName="";
    int  cellsize;
    
};
#endif /* ColorElementStyle_hpp */
