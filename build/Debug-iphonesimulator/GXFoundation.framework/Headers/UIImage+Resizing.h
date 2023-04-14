//
//  UIImage+Resizing.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 28/11/11.
//  Copyright (c) 2011 Artech. All rights reserved.
//

@import UIKit;
@import CoreGraphics;

NS_ASSUME_NONNULL_BEGIN

#if TARGET_OS_WATCH
typedef NS_ENUM(NSInteger, UIImageResizeContentMode) {
    UIImageResizeContentModeScaleToFill,
    UIImageResizeContentModeScaleAspectFit,
    UIImageResizeContentModeScaleAspectFill,
    UIImageResizeContentModeCenter,
    UIImageResizeContentModeTop,
    UIImageResizeContentModeBottom,
    UIImageResizeContentModeLeft,
    UIImageResizeContentModeRight,
    UIImageResizeContentModeTopLeft,
    UIImageResizeContentModeTopRight,
    UIImageResizeContentModeBottomLeft,
    UIImageResizeContentModeBottomRight,
};
#endif // TARGET_OS_WATCH

@interface UIImage (Resizing)

/*!
 Reduces the receiver size keeping the same aspect ratio and scale if needed.
 
 @param targetSizeInPixels The maximum allowed size in pixels
 @return Returns a new image scaled down if the receiver is larger than the given target size, self otherwise.
 */
- (UIImage *)reduceImageToMaxSize:(CGSize)targetSizeInPixels;

/*!
 Reduces the receiver size keeping the same aspect ratio and scale if needed.
 
 @return Returns a new image scaled down if the receiver is larger than the main screen max bound square size, self otherwise.
 @discussion Calls reduceImageToMaxSize: with the main screen max bound square size (in pixels)
 */
- (UIImage *)reduceImageToMaxDeviceSize;

/// Same as [self resizeImageWithContentMode: toSize:targetSize targetScale:0]
#if !TARGET_OS_WATCH
- (UIImage *)resizeImageWithContentMode:(UIViewContentMode)contentMode
#else
- (UIImage *)resizeImageWithContentMode:(UIImageResizeContentMode)contentMode
#endif // !TARGET_OS_WATCH
								 toSize:(CGSize)targetSize;

/**
 Resizes the receiver to the target size by using the specified content mode.
 
 @param contentMode The content mode to be used to resize the image
 @param targetSize The target size in points (see targetScale).
 @param targetScale The returned image scale. If the given value is 0 or lower, main screen scale is used.
 @return A new image, that is the result of resizing the receiver to the target size by using the specified content mode.
 */
#if !TARGET_OS_WATCH
- (UIImage *)resizeImageWithContentMode:(UIViewContentMode)contentMode
#else
- (UIImage *)resizeImageWithContentMode:(UIImageResizeContentMode)contentMode
#endif // !TARGET_OS_WATCH
								 toSize:(CGSize)targetSize
								  scale:(CGFloat)targetScale;

@end

NS_ASSUME_NONNULL_END
