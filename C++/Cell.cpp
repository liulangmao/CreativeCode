//
//  Cell.cpp
//  C++
//
//  Created by liming on 2017/8/3.
//  Copyright © 2017年 杨金保. All rights reserved.
//

#include "Cell.hpp"
Cell::Cell(){
    
}
Cell::~Cell(){
    }
Cell::Cell(UInt32* preImage, int x, int y){
    this->width=x;
    this->heigh=y;
    this->preImage= preImage;
}
Cell::Cell(Cell *src){
    this->width=src->width;
    this->heigh=src->heigh;
    this->preImage= src->preImage;
}

void Cell::setWidthHeigh(int x, int y){
    this->width=x;
    this->heigh=y;
}
bool Cell::operator == (const Cell &i){
    return (this->width == i.width && this->heigh ==i.heigh);
}
bool Cell::operator != (const Cell &i){
    return (this->width != i.width || this->heigh !=i.heigh);
}
int Cell::getWidth(){
    return  this->width;
}
int Cell::getHeigh(){
    return  this->heigh;
}

void Cell::setPreImage(UInt32* preImage){
    this->preImage=preImage;

}
UInt32*  Cell::getPreImage(){
    return this->preImage;
}

