//
//  CreativeElementStyle.cpp
//  CreativeQRcode
//
//  Created by liming on 2017/7/25.
//  Copyright © 2017年 liming. All rights reserved.
//

#include "CreativeElementStyle.hpp"

CreativeElementStyle::CreativeElementStyle(int value,string namelist[],int size){
    this->setCellsize(value);
    this->setNamelist(namelist,size);
    this->namelistSize=size;
}
CreativeElementStyle::CreativeElementStyle(){
    this->setCellsize(0.0);
    string x="";
    this->setNamelist(&x,0);
    this->namelistSize=0;
}

int CreativeElementStyle::getCellsize() {
    return this->cellsize;
}
int CreativeElementStyle::getNamelistSize() {
    return this->namelistSize;
}

string* CreativeElementStyle::getNamelist() {
    return this->namelist;
}

void CreativeElementStyle::setCellsize(int cellsize) {
    this->cellsize = cellsize;
}

void CreativeElementStyle::setNamelist(string namelist[],int size) {
    //this->namelist = namelist;
    this->namelist=new string [size];
    namelistSize=size;
    for(int i=0;i<size;i++)
    {
        this->namelist[i]=namelist[i];
    }
}
