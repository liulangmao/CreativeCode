//
//  CMBCBitmapUtil.h
//  ABC
//
//  Created by 杨金保 on 2017/7/25.
//  Copyright © 2017年 杨金保. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreImage/CoreImage.h>
#import <UIKit/UIKit.h>

@interface CMBCBitmapUtil : NSObject

+ (CGImageRef)setBitMapImage:(NSString*)imageName;

+ (void)createImage:(NSString *)imageName bitmapData:(uint32_t *)bitmapData;

+ (CGImageRef)createImageRefWidth:(CGFloat)imageWidth height:(CGFloat)imageHeight bitmapData:(uint32_t *)bitmapData;

@end
