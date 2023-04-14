//
//  UIBarButtonItem+Helpers.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 04/04/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import UIKit;
@import GXCoreBL;

@interface UIBarButtonItem (Helpers)

+ (instancetype)cancelButtonItemWithTarget:(id)target selector:(SEL)selector;
+ (instancetype)doneButtonItemWithTarget:(id)target selector:(SEL)selector;

@end

@interface UIBarButtonItem (GXTargetActionBlock)

- (void)setTargetActionWithBlock:(void (^)(void))block;

+ (instancetype)cancelButtonItemWithTargetActionBlock:(void (^)(void))block;
+ (instancetype)doneButtonItemWithTargetActionBlock:(void (^)(void))block;

@end
