//
//  UIImage+Color.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 26/07/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import UIKit;

@interface UIImage (Color)

+ (UIImage *)imageFromColor:(UIColor *)color;

- (UIImage *)imageWithTint:(UIColor *)tintColor;
- (UIImage *)imageWithTint:(UIColor *)tintColor maskApha:(BOOL)alpha;

@end
