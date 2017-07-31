//
//  AppDelegate.h
//  C++
//
//  Created by 杨金保 on 2017/7/21.
//  Copyright © 2017年 杨金保. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (readonly, strong) NSPersistentContainer *persistentContainer;

- (void)saveContext;


@end

