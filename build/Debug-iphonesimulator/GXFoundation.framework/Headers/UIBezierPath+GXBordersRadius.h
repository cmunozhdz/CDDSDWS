//
//  UIBezierPath+GXBordersRadius.h
//  GXFoundation
//
//  Created by Fabian Inthamoussu on 23/8/18.
//  Copyright © 2018 GeneXus. All rights reserved.
//

@import UIKit;
#import <GXFoundation/GXCommon.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIBezierPath (GXBordersRadius)

/*!
Creates and returns a new UIBezierPath object initialized with a rounded rectangular path using bordersRadius for each corner radius

@param rect The rectangle that defines the basic shape of the path.
@param bordersRadius The radius of each corner. A value of 0 results in a rectangle without rounded corners. Values larger than half the rectangle’s width or height are clamped appropriately to half the width or height.
@param includeZeroCorners Whether arcs with zero radius included or not.
@result A new path object with the rounded rectangular path.
*/
+ (instancetype)bezierPathWithRoundedRect:(CGRect)rect
							bordersRadius:(GXBordersRadius)bordersRadius
					   includeZeroCorners:(BOOL)includeZeroCorners;

/// Same as [self bezierPathWithRoundedRect:rect bordersRadius:bordersRadius includeZeroCorners:NO]
+ (instancetype)bezierPathWithRoundedRect:(CGRect)rect
							bordersRadius:(GXBordersRadius)bordersRadius;

// Same result as [self bezierPathWithRoundedRect:rect bordersRadius:bordersRadius includeZeroCorners:!GXBordersRadiusIsEmpty(bordersRadius)]
+ (instancetype)bezierPathIncludingZeroCornersIfNonEmptyBordersRadiusWithRoundedRect:(CGRect)rect
																	   bordersRadius:(GXBordersRadius)bordersRadius;

@end

NS_ASSUME_NONNULL_END
