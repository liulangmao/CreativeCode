//
//  CreativeElement.hpp
//  CreativeQRcode
//
//  Created by liming on 17/07/2017.
//  Copyright © 2017 liming. All rights reserved.
//

#ifndef CreativeElement_hpp
#define CreativeElement_hpp

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
#include "CoreGraphics/CGImage.h"

#include "Point.hpp"

class CreativeElement{
public:
    
    CreativeElement(int value, int rowspan,int  colspan);
    ~CreativeElement();
    
public:

    bool equals(CreativeElement other);
    vector<CGImageRef>* getPreImage();
    void setPreImage(vector<CGImageRef>* preImage);
    vector<PointS>* getM_start();
    void setM_start(vector<PointS>* m_start);
    int getColspan();
    void setColspan(int colspan);
    int getRowspan();
    void setRowspan(int rowspan);
    int getValue();
    void setValue(int value);
    string getStr();
    void setStr(string str);
    
    
private:
    int colspan=0;
    int rowspan=0;
    int value=0;
    string str="";
    vector<CGImageRef> *preImage;
    string nameSwitch="";
    vector<PointS> *m_start;
    
    
};





#endif /* CreativeElement_hpp */
