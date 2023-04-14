//
//  GXLayoutRectangle.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 07/04/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import Foundation;
@import CoreGraphics;

NS_ASSUME_NONNULL_BEGIN

@interface GXLayoutRectangle : NSObject <NSCoding>

@property(assign, readonly) CGFloat x;
@property(assign, readonly) CGFloat y;
@property(assign, readonly) CGFloat xRelative;
@property(assign, readonly) CGFloat yRelative;
@property(assign, readonly) CGFloat width;
@property(assign, readonly) CGFloat height;
@property(assign, readonly) CGFloat widthRelative;
@property(assign, readonly) CGFloat heightRelative;

- (CGFloat)computedX:(CGFloat)totalWidth;
- (CGFloat)computedY:(CGFloat)totalHeight;
- (CGFloat)computedWidth:(CGFloat)totalWidth;
- (CGFloat)computedHeight:(CGFloat)totalHeight;
- (CGRect)computedFrame:(CGSize)totalSize;

- (instancetype)initWithMetadata:(nullable NSDictionary<NSString *, id> *)metadata NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

@interface GXMutableLayoutRectangle : GXLayoutRectangle

@property(assign, readwrite) CGFloat x;
@property(assign, readwrite) CGFloat y;
@property(assign, readwrite) CGFloat xRelative;
@property(assign, readwrite) CGFloat yRelative;
@property(assign, readwrite) CGFloat width;
@property(assign, readwrite) CGFloat height;
@property(assign, readwrite) CGFloat widthRelative;
@property(assign, readwrite) CGFloat heightRelative;

@end

NS_ASSUME_NONNULL_END