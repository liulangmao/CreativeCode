//
//  main.cpp
//  CreativeQRcode
//
//  Created by liming on 7/14/17.
//  Copyright © 2017 liming. All rights reserved.
//




#include <iostream>
#include <string.h>

#include "CreativeElementStyle.hpp"
//#include "CreativeQrCode.hpp"
#include "BasicQRTool.hpp"
#include "CreativeQRTool.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    
    
    /**
     CreativeQrCode temp1 = new CreativeQrCode(CreativeQrCode.BAMBOO);
     FinalImageMat = temp1.CreativeQRZXing("i am liming", 1000, 5,MainActivity.this);
     **/
    
    
    /**
     
    int cellNumber=21;
    int cellSize=5;
    string *txt=new string("Hello, World");
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
    **/
//    string name="imageRef.png";
//    CreativeElementStyle *style= new CreativeElementStyle(50,&name);
    //CreativeQrCode *qrcode= new CreativeQrCode(*style);
    //CGImageRef image= qrcode->getDiskBitmap("imageRef.png");
    
    
    //for test
//    CreativeQrCode *qrcode= new CreativeQrCode(*style);
//
//    qrcode->testRead();
    
    
   
//    return 0;
}


//
//  main.m
//  C++
//
//  Created by 杨金保 on 2017/7/21.
//  Copyright © 2017年 杨金保. All rights reserved.
//

//#import <UIKit/UIKit.h>
//#import "AppDelegate.h"
//
//int main(int argc, char * argv[]) {
//    @autoreleasepool {
//        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
//    }
//}
