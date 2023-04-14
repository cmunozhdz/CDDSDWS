//
//  UIViewController+GXCallOptions.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 17/11/15.
//  Copyright © 2015 Artech. All rights reserved.
//

@import Foundation;
#if !TARGET_OS_WATCH
@import UIKit;
#else
@import WatchKit;
#endif
@import GXObjectsModel;

#define kCALL_OPTIONS_STORE_PROPERTY_NAME @"gxCallOptions"

NS_ASSUME_NONNULL_BEGIN

#if !TARGET_OS_WATCH
@interface UIViewController (GXCallOptions)
#else
@interface WKInterfaceController (GXCallOptions)
#endif // !TARGET_OS_WATCH

/*!
 Returns the call options used when receiver was presented
 
 @discussion See callOptionsForViewController: class method in GXCallOptions.
 */
@property (nullable, nonatomic, assign, readonly) GXCallOptions *gxCalledOptions;
- (void)setGxCalledOptions:(nullable GXCallOptions *)options; // Stores a copy of the given options. Must be called once.
/// Returns self.gxCalledOptions if gxCalledOptions.empty == NO, nil otherwise
@property (nullable, nonatomic, assign, readonly) GXCallOptions *gxNonEmptyCalledOptions;

#if !TARGET_OS_WATCH
- (void)applyPreferredContentSizeFromGXCalledOptionsTargetCustomSize:(BOOL)animated;

+ (void)applyGxPreferredContentSize:(UIViewController *)controller
	fromCallOptionsTargetCustomSize:(GXCallOptions *)callOptions
						   animated:(BOOL)animated;

+ (UIModalPresentationStyle)modalPresentationStyleFromGxCallOptionTargetSize:(GXCallOptionTargetSize)targetSize;
+ (UIModalPresentationStyle)modalPresentationStyleFromGxCallOptionTargetSize:(GXCallOptionTargetSize)targetSize
															unspecifiedValue:(UIModalPresentationStyle)unspecifiedValue;
#endif // !TARGET_OS_WATCH

@end

NS_ASSUME_NONNULL_END
