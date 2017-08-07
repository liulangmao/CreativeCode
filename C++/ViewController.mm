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
    
    
    //方法一
    
    //UIImage *resultUIImage = [UIImage imageWithCGImage:[CMBCBitmapUtil setBitMapImage:@"imageRef.png"]];
    //imageView.image = resultUIImage;
    
    
    //方法四
//     string name="imageRef.png";
//     CreativeElementStyle *style= new CreativeElementStyle(50,&name);
//    CreativeQrCode *qrcode= new CreativeQrCode(*style);
//    
//    UIImage *resultUIImage=qrcode->testRead();
//    imageView.image = resultUIImage;
    //方法五
    string name1="bamboo_1_1_1.bmp";
    string name2="bamboo_7_7.bmp";
    string namelist[2]={name2,name1};
   // string namelist[1]={name1};
    CreativeElementStyle *style= new CreativeElementStyle(50,namelist,2);
    CreativeQrCode *qrcode= new CreativeQrCode(*style);
    CGImageRef resultRef=qrcode->CreativeQRZXing("i am liming", 1000, 5);
    UIImage * resultUIImage =[UIImage imageWithCGImage: resultRef]; ;
    imageView.image = resultUIImage;
    
    //方法二 无返回值
//    size_t width = 200;
//    size_t height = 200;
//    size_t bytesPerRow = width * 4;
//    uint32_t* bitmapData = (uint32_t*)malloc(bytesPerRow * height);
//    
//    [CMBCBitmapUtil createImage:nil bitmapData:bitmapData];
    
    
    //方法三
//    size_t width = 200;
//    size_t height = 200;
//    size_t bytesPerRow = width * 4;
//    uint32_t* bitmapData = (uint32_t*)malloc(bytesPerRow * height);
//    
//    UIImage *images = [UIImage imageWithCGImage:[CMBCBitmapUtil createImageRefWidth:200 height:200 bitmapData:bitmapData]];
//    imageView.image = images;


    // Do any additional setup after loading the view, typically from a nib.
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
