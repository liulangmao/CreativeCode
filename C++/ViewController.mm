//
//  ViewController.m
//  C++
//
//  Created by 杨金保 on 2017/7/21.
//  Copyright © 2017年 杨金保. All rights reserved.
//

#define SCREENWIDTH [UIScreen mainScreen].bounds.size.width
#define SCREENHEIGHT [UIScreen mainScreen].bounds.size.height

#import "ViewController.h"
#import "CMBCImageRef.hpp"
#import "CMBCBitmapUtil.h"
#include "CreativeQrCode.hpp"
#include "CreativeElementStyle.hpp"
#include "ColorElementStyle.hpp"
#include "ColorQrCode.hpp"
@interface ViewController ()
{
    UIImageView *imageView;
    CMBCBitmapUtil *bitmapUtil;
    CMBCImageRefClass *imageRefClass;
}
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    /*    //调用C++
     size_t width = 200;
     size_t height = 200;
     size_t bytesPerRow = width * 4;
     uint32_t* bitmapData = (uint32_t*)malloc(bytesPerRow * height);
     
     imageRefClass = new CMBCImageRefClass;
     imageRefClass->SetBitMapImage(@"imageRef.png");
     imageRefClass->CreateImage(@"imageRef.png", bitmapData);
     imageRefClass->CreateImageRef(200, 200, bitmapData);
     */
    
    
    //OC调用
    imageView = [[UIImageView alloc] init];
    imageView.frame = CGRectMake(SCREENWIDTH/2-100, 50, 200, 200);
    imageView.center = CGPointMake(self.view.center.x, self.view.center.y);
    [self.view addSubview:imageView];
    
    
    //method1:
    
  /*
    CreativeQrCode *qrcode= new CreativeQrCode(*(CreativeQrCode::YELLOWBOY));
    CGImageRef resultRef=qrcode->CreativeQRZXing("i am limingsdfsdfsdfsdfdfdffddjsdhjfhsdhjahuehagbguguhriagrigejgiergrngnerbgbergb", 1000, 5);
    UIImage * resultUIImage =[UIImage imageWithCGImage: resultRef];
    imageView.image = resultUIImage;
  */
    
    //method2:
  /*
    string MELON_namelist[2]={"melon_7_7.bmp","melon_1_1.bmp"};
    CreativeElementStyle *MELON= new CreativeElementStyle(26, MELON_namelist,2);
    CreativeQrCode* qrcode2= new CreativeQrCode(*MELON);
        CGImageRef resultRef2=qrcode2->CreativeQRZXing("i am limingsdfsdfsdfsdfdfdffddjsdhjfhsdhjahuehagbguguhriagrigejgiergrngnerbgbergb", 1000, 5);
    UIImage * resultUIImage2 =[UIImage imageWithCGImage: resultRef2];
    imageView.image = resultUIImage2;
  */
    
    //method3:
    UInt32 color[5]={0xFF0094FF, 0xFFFED545, 0xFF5ACF00, 0xFF000000,0xffffffff };
    ColorElementStyle custom2 = new ColorElementStyle(color, "color_bak.bmp", "color_logo1.png","color_water.png");
    custom2.setLogoPathName("color_logo1.png");
    custom2.setBackgroundPathName("color_bak.bmp");
    custom2.setWaterPathName("color_water.png");
    ColorQrCode *temp3 = new ColorQrCode(custom2);
    CGImageRef FinalImageMat = temp3->ColorQRSweatake("i am liming welcome to cmbc", 0, 1);
    UIImage * resultUIImage2 =[UIImage imageWithCGImage: FinalImageMat];
    imageView.image = resultUIImage2;
    
    //method4:
    UInt32 color[5]={0xFF0094FF, 0xFFFED545, 0xFF5ACF00, 0xFF000000,0xffffffff };
    ColorElementStyle custom3 = new ColorElementStyle(color);
    custom3.setLogoPathName("color_logo1.png");
    custom3.setBackgroundPathName("color_bak.bmp");
    custom3.setWaterPathName("color_water.png");
    ColorQrCode *temp3 = new ColorQrCode(custom2);
    CGImageRef FinalImageMat = temp3->ColorQRSweatake("i am liming welcome to cmbc", 0, 1);
    UIImage * resultUIImage2 =[UIImage imageWithCGImage: FinalImageMat];
    imageView.image = resultUIImage2;
    
    //method5:
//    ColorElementStyle *custom4 = new ColorElementStyle();
//    UInt32 color[2]={0xff3A7583,0xff213F90};
//    custom4->setColor(color);
//    ColorQrCode *temp6 = new ColorQrCode(*custom4);
//    FinalImageMat = temp6->ColorQRMinSheng("i am liming", 0, 7);
//    UIImage * resultUIImage2 =[UIImage imageWithCGImage: FinalImageMat];
//    imageView.image = resultUIImage2;
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
