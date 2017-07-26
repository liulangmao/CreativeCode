//
//  Point.cpp
//  CreativeQRcode
//
//  Created by liming on 17/07/2017.
//  Copyright © 2017 liming. All rights reserved.
//

#include "Point.hpp"
PointS::PointS(){
    
}
PointS::~PointS(){
    this->x=0;
    this->y=0;
}
PointS::PointS(int x, int y){
    this->x=x;
    this->y=y;
}
PointS::PointS(PointS *src){
    this->x=src->x;
    this->y=src->y;
}

void PointS::set(int x, int y){
    this->x=x;
    this->y=y;
}
bool PointS::operator == (const PointS &i){
    return (this->x == i.x && this->y ==i.y);
}
bool PointS::operator != (const PointS &i){
     return (this->x != i.x || this->y !=i.y);
}
bool PointS::equals(int x, int y){
    
    return (this->x == x && this->y ==y);
}
int PointS::getX(){
    return  this->x;
}
int PointS::getY(){
    return  this->y;
}
