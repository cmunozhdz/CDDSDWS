//
//  UIImage+GIF.h
//  LBGIFImage
//
//  Created by Laurin Brandner on 06.01.12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (GIF)

+ (UIImage *)gxAnimatedGIFNamed:(NSString *)name;

+ (UIImage *)gxAnimatedGIFWithData:(NSData *)data;

- (UIImage *)gxAnimatedImageByScalingAndCroppingToSize:(CGSize)size;

@end
