//
//  CMBCImageRef.hpp
//  C++
//
//  Created by liming on 2017/8/2.
//  Copyright © 2017年 杨金保. All rights reserved.
//

#ifndef CMBCImageRef_hpp
#define CMBCImageRef_hpp

#include <CoreGraphics/CoreGraphics.h>
#include "ViewController.h"
#include <stdio.h>
#include <iostream>
#include <string>

class CMBCImageRefClass {
    
public:
    
#pragma mark - 修改版
    CGImageRef SetBitMapImage(NSString *imageName);
    
    void CreateImage(NSString *imageName, uint32_t *bitmapData);
    
    CGImageRef CreateImageRef(float imageWidth, float imageHeight, uint32_t *bitmapData);
};


#endif /* CMBCImageRef_hpp */
