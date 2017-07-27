//
//  main.cpp
//  CreativeQRcode
//
//  Created by liming on 7/14/17.
//  Copyright © 2017 liming. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;

#include "BasicQRTool.hpp"
#include "CreativeQRTool.hpp"

int main(int argc, const char * argv[]) {
    /**
     CreativeQrCode temp1 = new CreativeQrCode(CreativeQrCode.BAMBOO);
     FinalImageMat = temp1.CreativeQRZXing("i am liming", 1000, 5,MainActivity.this);
     **/
    
    
    /**
     CreativeQRTool h = new CreativeQRTool(cellNumber, cellSize);
     BasicQRTool basic= new BasicQRTool(version,txt);
     basic.GenMatrix(h.getMat());
     h.fillEye();
     h.FindCellEqualsOne();
     h.FillbyType();
     **/
    int cellNumber=21;
    int cellSize=5;
    char *txt="Hello, World";
    BasicQRTool *basic=new BasicQRTool(txt);

    int **arrary;
    arrary=  new int* [21];
    for (int i=0; i<21; i++) {
        arrary[i]=new int [21];
    }
    
    CreativeQRTool *h = new CreativeQRTool(cellNumber, cellSize);
    basic->GenMatrix(h->getMat());
    h->fillEye();
    basic->Print(h->getMat(),21 , 21);
    h->FindCellEqualsOne();
    h->FillbyType();
    return 0;
}
