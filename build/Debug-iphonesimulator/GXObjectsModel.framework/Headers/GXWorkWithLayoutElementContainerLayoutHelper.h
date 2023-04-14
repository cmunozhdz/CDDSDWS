//
//  GXWorkWithLayoutElementContainerLayoutHelper.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 23/04/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import Foundation;
@import CoreGraphics;
@import GXFoundation;

NS_ASSUME_NONNULL_BEGIN

@interface GXWorkWithLayoutElementContainerLayoutHelper : NSObject <NSCoding>

@property(assign, readonly) GXLayoutDimension width;
@property(assign, readonly) GXLayoutDimension height;
@property(assign, readonly) CGFloat fixedWidthSum;
@property(assign, readonly) CGFloat fixedHeightSum;

- (instancetype)initWithWidth:(GXLayoutDimension)width
					   height:(GXLayoutDimension)height
				fixedWidthSum:(CGFloat)fixedWidthSum
			   fixedHeightSum:(CGFloat)fixedHeightSum NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

+ (GXLayoutDimension)width:(nullable GXWorkWithLayoutElementContainerLayoutHelper *)layoutHelperObject;
+ (GXLayoutDimension)height:(nullable GXWorkWithLayoutElementContainerLayoutHelper *)layoutHelperObject;
+ (CGFloat)fixedWidthSum:(nullable GXWorkWithLayoutElementContainerLayoutHelper *)layoutHelperObject;
+ (CGFloat)fixedHeightSum:(nullable GXWorkWithLayoutElementContainerLayoutHelper *)layoutHelperObject;

@end

NS_ASSUME_NONNULL_END
