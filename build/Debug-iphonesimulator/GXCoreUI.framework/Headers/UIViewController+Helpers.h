//
//  UIViewController+Helpers.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 04/09/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (Helpers)

- (UIViewController *)lastModalViewController;

/// Returns self if is kind of class UINavigationController, otherwise returns self.navigationController
@property(nullable, nonatomic, strong, readonly) UINavigationController *gxNavigationController;

@property(nonatomic) CGSize gxPreferredContentSize;
- (void)setGxPreferredContentSize:(CGSize)size animated:(BOOL)animated;

#if TARGET_OS_IOS
- (BOOL)gxIsForceReloadSupportedInterfaceOrientationsNeeded;
- (void)gxForceReloadSupportedInterfaceOrientationsIfNeeded;
- (void)gxForceReloadSupportedInterfaceOrientations;

@property(nonatomic, assign, readonly) UIInterfaceOrientation gxInterfaceOrientation;
- (UIInterfaceOrientation)gxInterfaceOrientationFromTargetTransfrom:(CGAffineTransform)transform;

#endif // TARGET_OS_IOS

@property(nonatomic, assign, readonly) BOOL gxIsInPopover;
@property(nonatomic, assign, readonly) BOOL gxIsInSplitViewControllerMaster;
@property(nonatomic, assign, readonly) BOOL gxIsInSplitViewControllerDetail;

/// Returns the same as modalPresentationStyle but without resolving UIModalPresentationAutomatic value
@property(nonatomic, assign, readonly) UIModalPresentationStyle gxUnresolvedModalPresentationStyle;

+ (BOOL)gxModalPresentationStyleIsFullScreen:(UIModalPresentationStyle)style;

// UIModalPresentationAutomatic on iOS 13, UIModalPresentationFullScreen otherwise
+ (BOOL)gxUnresolvedModalPresentationStyleIsDefault:(UIModalPresentationStyle)style;

- (UIEdgeInsets)gxSafeAreaInsets;

@end

NS_ASSUME_NONNULL_END
