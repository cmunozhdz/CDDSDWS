//
//  GXUtilities+CoreGraphics.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 13/11/15.
//  Copyright © 2015 Artech. All rights reserved.
//

#import <GXFoundation/GXUtilities.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Returns a size with floor for each size value (width, height)
 * Notice: GXIntegerFrame(frame).size != GXIntegerSize(frame.size)
 */
CGSize GXIntegerSize(CGSize size) __attribute__((const));

/**
 Aligns the point with a screen scale equals 1.0
 
 @param point Point to align
 @result The aligned point, with all members as integers
 @discussion Same as calling GXPixelAlignedPoint for each value (x and y)
 */
CGPoint GXIntegerPoint(CGPoint point);

/*!
 Aligns the frame with a screen scale equals 1.0
 
 @param frame Frame to align
 @result The aligned frame, with all members as integers
 @discussion Same as calling GXPixelAlignedFrame(frame, 1.0). Notice GXIntegerSize(frame).size != GXIntegerSize(frame.size).
 */
CGRect GXIntegerFrame(CGRect frame) __attribute__((const));

#pragma mark - Equality

/// Compares values taking epsilon into account
BOOL GXNearlyEqualFloats(float a, float b) __attribute__((const));

/// Compares values taking epsilon into account
BOOL GXNearlyEqualDoubles(double a, double b) __attribute__((const));

/// Compares values taking epsilon into account
BOOL GXNearlyEqualCGFloats(CGFloat a, CGFloat b) __attribute__((const));

/// Compares values taking epsilon into account
BOOL GXNearlyEqualCGSizes(CGSize a, CGSize b) __attribute__((const));

/// Compares values taking epsilon into account
BOOL GXNearlyEqualCGPoints(CGPoint a, CGPoint b) __attribute__((const));

/// Compares values taking epsilon into account
BOOL GXNearlyEqualCGRects(CGRect a, CGRect b) __attribute__((const));

/// Compares values taking epsilon into account
BOOL GXNearlyEqualUIEdgeInsets(UIEdgeInsets a, UIEdgeInsets b) __attribute__((const));

#pragma mark - Screen

/// Device main screen scale
CGFloat GXMainScreenScale(void);

/// Device main screen screen size in fixed coordinate space
CGSize GXMainScreenSize(void);

#pragma mark - Alignment

CGRect GXHorizontalAlignedFrame(CGRect frame, CGFloat width, GXHorizontalAlignType align) __attribute__((const)); // defaultAlign == GXHorizontalAlignTypeCenter
CGRect GXVerticalAlignedFrame(CGRect frame, CGFloat height, GXVerticalAlignType align) __attribute__((const)); // defaultAlign == GXVerticalAlignTypeCenter
CGRect GXAlignedFrame(CGRect frame, CGSize size, GXHorizontalAlignType hAlign, GXVerticalAlignType vAlign) __attribute__((const)); // hDefualtAlign == GXHorizontalAlignTypeCenter && vDefualtAlign == GXVerticalAlignTypeCenter

CGRect GXHorizontalAlignedFrameWithDefaultResolver(CGRect frame, CGFloat width, GXHorizontalAlignType align, GXHorizontalAlignType defaultAlign) __attribute__((const)); // defaultAlign must be Left | Center | Right
CGRect GXVerticalAlignedFrameWithDefaultResolver(CGRect frame, CGFloat height, GXVerticalAlignType align, GXVerticalAlignType defaultAlign) __attribute__((const)); // defaultAlign must be Top | Center | Bottom
CGRect GXAlignedFrameWithDefaultResolver(CGRect frame, CGSize size,
										 GXHorizontalAlignType hAlign, GXVerticalAlignType vAlign,
										 GXHorizontalAlignType hDefualtAlign, GXVerticalAlignType vDefualtAlign) __attribute__((const)); // hDefualtAlign must be Left | Center | Right & vDefualtAlign must be Top | Center | Bottom

/*!
 Aligns the frame with the main screen
 
 @param frame Frame in points to align
 @result The frame aligned to the main screen scale
 @discussion Same as calling GXPixelAlignedFrame(frame, GXMainScreenScale())
 */
CGRect GXPixelAlignedFrameWithMainScreenScale(CGRect frame);

/*!
 Aligns the frame (in points) to the given screen scale
 
 @param frame Frame in points to align
 @param scale Screen pixel scale (pixels per point, ie: 2.0 for retina displays)
 @result The freame aligned to the given screen scale
 @discussion Views might see blurry if frame is not aligned to screen pixels. Transforms the given frame in points to pixels, then makes floorf for each bound origin and size (x and width, y and height) and if the sum difference by applying floorf origing and size is equal or greater than 1, 1 pixel is added to the bound size, finally converts back the frame in pixels to points.
 */
CGRect GXPixelAlignedFrame(CGRect frame, CGFloat scale) __attribute__((const));

/*!
 Rounds the given point to the main screen pixel scale
 
 @param point The point to round based on main screen pixel scale
 @result The point rounded to main screen pixel scale
 @discussion Same as calling GXPixelAlignedPointValueWithMainScreenScale for each value (x and y)
 */
CGPoint GXPixelAlignedPointWithMainScreenScale(CGPoint point);

/*!
 Rounds the given point to the given scale
 
 @param point The point to round based on the given scale
 @param scale Screen pixel scale (pixels per point, ie: 2.0 for retina displays)
 @result The point rounded to given scale
 @discussion Same as calling GXPixelAlignedPointValue for each value (x and y)
 */
CGPoint GXPixelAlignedPoint(CGPoint point, CGFloat scale) __attribute__((const));

/*!
 Rounds the given value in points to the main screen pixel scale
 
 @param value The value in points to round based on main screen pixel scale
 @result The value rounded to main screen pixel scale
 @discussion Sample: 1.3 in a retina display (scale 2.0) retuns 1.5 (3 screen pixels), and on a non retina display returns 1.0 (1 screen pixel)
 */
CGFloat GXPixelAlignedPointValueWithMainScreenScale(CGFloat value);

/*!
 Rounds the given value in points to the given scale
 
 @param value The value in points to round based on main screen pixel scale
 @param scale Screen pixel scale (pixels per point, ie: 2.0 for retina displays)
 @result The value rounded to given scale
 @discussion Sample: 1.3 in a retina display (scale 2.0) retuns 1.5 (3 screen pixels), and on a non retina display returns 1.0 (1 screen pixel)
 */
CGFloat GXPixelAlignedPointValue(CGFloat value, CGFloat scale) __attribute__((const));

/*!
 Compares the given values rounding to the given screen scale
 
 @param value1 The first value in points to compare
 @param value2 The second value in points to compare
 @param scale Screen pixel scale (pixels per point, ie: 2.0 for retina displays)
 @result YES if the values rounded to given scale are equal, NO otherwise
 @discussion Sample: 1.3 and 1.6 returns YES in a retina display (scale 2.0), but on a non retina display returns NO (scale 1.0)
 */
BOOL GXPixelAlignedEquals(CGFloat value1, CGFloat value2, CGFloat scale) __attribute__((const));

/*!
 Compares the given values rounding to the main screen pixel scale
 
 @param value1 The first value in points to compare
 @param value2 The second value in points to compare
 @result YES if the values rounded to the main screen pixel scale are equal, NO otherwise
 @discussion Sample: 1.3 and 1.6 returns YES in a retina display (scale 2.0), but on a non retina display returns NO (scale 1.0)
 */
BOOL GXPixelAlignedEqualsWithMainScreenScale(CGFloat value1, CGFloat value2);

#pragma mark - Inset

CGRect GXHorizontalFrameInset(CGRect frame, CGFloat left, CGFloat right) __attribute__((const));
CGRect GXVerticalFrameInset(CGRect frame, CGFloat top, CGFloat bottom) __attribute__((const));
CGRect GXFrameInset(CGRect frame, CGFloat left, CGFloat right, CGFloat top, CGFloat bottom) __attribute__((const));
CGRect GXFrameOutset(CGRect frame, CGFloat left, CGFloat right, CGFloat top, CGFloat bottom) __attribute__((const));

CGRect GXFrameInsetMargin(CGRect frame, GXLayoutQuadDimension margin) __attribute__((const));
CGRect GXFrameInsetEdgeInsets(CGRect frame, UIEdgeInsets insets) __attribute__((const));
CGRect GXFrameOutsetMargin(CGRect frame, GXLayoutQuadDimension margin) __attribute__((const));
CGRect GXFrameOutsetEdgeInsets(CGRect frame, UIEdgeInsets insets) __attribute__((const));

NS_ASSUME_NONNULL_END
