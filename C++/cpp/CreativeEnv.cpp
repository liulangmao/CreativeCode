//
//  CreativeEnv.cpp
//  CreativeQRcode
//
//  Created by liming on 18/07/2017.
//  Copyright © 2017 liming. All rights reserved.
//

#include <stdio.h>


#include "CreativeEnv.hpp"
list<CreativeElement*> CreativeEnv::elementList;
list<CreativeElement*>::iterator CreativeEnv::elementListIt;

void CreativeEnv::addEye(){
    CreativeElement *EYE = new CreativeElement(-1,7,7);
    elementList.push_back(EYE);}

CreativeElement CreativeEnv::getEye()
{
    elementListIt=elementList.begin();
    return *(*elementListIt);
}
void  CreativeEnv::addElement(CreativeElement *element){
    elementList.push_back(element);
}
int CreativeEnv::getlistSize()
{
    return (int)elementList.size();
}
