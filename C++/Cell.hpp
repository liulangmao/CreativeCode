//
//  Cell.hpp
//  C++
//
//  Created by liming on 2017/8/3.
//  Copyright © 2017年 杨金保. All rights reserved.
//

#ifndef Cell_hpp
#define Cell_hpp
#include "CoreGraphics/CGImage.h"
#include <stdio.h>
class Cell{
public:
    Cell();
    Cell(UInt32* preImage, int width, int heigh);
    Cell(Cell * src);
    ~Cell();
    
public:
    void setWidthHeigh(int x, int y);
    //bool equals(int x, int y);
    bool operator == (const Cell &i);
    bool operator != (const Cell &i);
    int  getWidth();
    int  getHeigh();
    void setPreImage(UInt32*);
private:
    int width;
    int heigh;
    UInt32* preImage;
    
};
#endif /* Cell_hpp */
