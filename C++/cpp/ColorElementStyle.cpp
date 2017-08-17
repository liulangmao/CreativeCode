//
//  ColorElementStyle.cpp
//  C++
//
//  Created by liming on 2017/8/14.
//

#include "ColorElementStyle.hpp"
ColorElementStyle::ColorElementStyle() {
    
}
ColorElementStyle::ColorElementStyle(UInt32* Color,string backgroundPathName,string logoPathName,string waterPathName) {
    
    this->color=Color;
    this->setBackgroundPathName(backgroundPathName);
    this->setLogoPathName(logoPathName);
    this->setWaterPathName(waterPathName);
}
ColorElementStyle::ColorElementStyle(UInt32* Color) {
    this->color=Color;
}
void ColorElementStyle::setCellSize(int cellsize)
{
    this->cellsize=cellsize;
}
int ColorElementStyle::getCellSize()
{
    return this->cellsize;
}

 void ColorElementStyle::setColor(UInt32*  Color)
{
    this->color=Color;
}
 UInt32* ColorElementStyle::getColor()
{
    return this->color;
}

void ColorElementStyle::setLogoPathName(string logoPathName) {
    this->logoPathName = logoPathName;
}
string ColorElementStyle::getLogoPathName() {
    return logoPathName;
}
string ColorElementStyle::getBackgroundPathName() {
    return backgroundPathName;
}

void ColorElementStyle::setBackgroundPathName(string backgroundPathName) {
    this->backgroundPathName = backgroundPathName;
}

string ColorElementStyle::getWaterPathName() {
    return WaterPathName;
}

void ColorElementStyle::setWaterPathName(string waterPathName) {
    WaterPathName = waterPathName;
}
