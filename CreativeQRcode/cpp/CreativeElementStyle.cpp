//
//  CreativeElementStyle.cpp
//  CreativeQRcode
//
//  Created by liming on 2017/7/25.
//  Copyright © 2017年 liming. All rights reserved.
//

#include "CreativeElementStyle.hpp"

CreativeElementStyle::CreativeElementStyle(int value,string* namelist){
    this->setCellsize(value);
    this->setNamelist(namelist);
}

int CreativeElementStyle::getCellsize() {
    return this->cellsize;
}

string* CreativeElementStyle::getNamelist() {
    return this->namelist;
}

void CreativeElementStyle::setCellsize(int cellsize) {
    this->cellsize = cellsize;
}

void CreativeElementStyle::setNamelist(string* namelist) {
    this->namelist = namelist;
}
