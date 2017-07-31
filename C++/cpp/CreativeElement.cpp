//
//  CreativeElement.cpp
//  CreativeQRcode
//
//  Created by liming on 17/07/2017.
//  Copyright © 2017 liming. All rights reserved.
//

#include "CreativeElement.hpp"

CreativeElement::CreativeElement(int value, int rowspan,int  colspan) {
    this->setValue(value);
    this->setColspan(colspan);
    this->setRowspan(rowspan);
    
    for(int h=0;h<rowspan;h++)
    {
        for(int w=0;w<colspan;w++)
        {
            setStr(getStr() +"1");
        }
        setStr(getStr() +"0");
    }
    this->nameSwitch=rowspan+"_"+colspan;
    setPreImage(new vector<CGImageRef>());
    setM_start(new vector<PointS>());
}
CreativeElement::~CreativeElement(){
    
}
vector<PointS>*  CreativeElement::getM_start(){
    return m_start;
}

bool CreativeElement::equals(CreativeElement other) {
    if ((other.getRowspan() == this->getRowspan())&&(other.getColspan() == this->getColspan()))
    {
        return true;
    }
    else
    {
        return false;
    }
}



vector<CGImageRef>* CreativeElement::getPreImage() {
    return preImage;
}

void CreativeElement::setPreImage(vector<CGImageRef>* preImage) {
    this->preImage = preImage;
}

void CreativeElement::setM_start(vector<PointS> *m_start) {
    this->m_start = m_start;
}

int CreativeElement::getColspan() {
    return colspan;
}

void CreativeElement::setColspan(int colspan) {
    this->colspan = colspan;
}

int CreativeElement::getRowspan() {
    return rowspan;
}

void CreativeElement::setRowspan(int rowspan) {
    this->rowspan = rowspan;
}

int CreativeElement::getValue() {
    return value;
}

void CreativeElement::setValue(int value) {
    this->value = value;
}

string CreativeElement::getStr() {
    return str;
}

void CreativeElement::setStr(string str) {
    this->str = str;
}
