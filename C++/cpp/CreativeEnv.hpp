//
//  CreativeEnv.hpp
//  CreativeQRcode
//
//  Created by liming on 18/07/2017.
//  Copyright © 2017 liming. All rights reserved.
//

#ifndef CreativeEnv_hpp
#define CreativeEnv_hpp

#include <stdio.h>
#include <list>
#include "CreativeElement.hpp"
using namespace std;
class CreativeEnv{
public:
   
    static void addEye();
    static CreativeElement getEye();
    static void  addElement(CreativeElement *element);
    static int getlistSize();
    
    static list<CreativeElement*> elementList;
    static list<CreativeElement*>::iterator elementListIt;
//    static {
//        CreativeElement *EYE = new CreativeElement(-1,7,7);
//        elementList.push_back(EYE);
//    }
    //static CreativeEnv* instance;
};

#endif
