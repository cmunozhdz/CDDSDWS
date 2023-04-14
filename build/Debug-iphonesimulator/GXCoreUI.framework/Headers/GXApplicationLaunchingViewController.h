//
//  GXApplicationLaunchingViewController.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 16/07/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

@import UIKit;
#import <GXCoreUI/GXRootControllerProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXApplicationLaunchingRootController <GXRootControllerProtocol>
@end

@interface GXApplicationLaunchingViewController : UIViewController<GXApplicationLaunchingRootController>

+ (UIViewController<GXApplicationLaunchingRootController> *)createApplicationLaunchingViewController;

- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

#if TARGET_OS_IOS
+ (nullable NSString *)lauchImageNameForOrientation:(UIInterfaceOrientation)orientation;
+ (nullable UIImage *)lauchImageForOrientation:(UIInterfaceOrientation)orientation;
#else
+ (nullable NSString *)lauchImageName;
+ (nullable UIImage *)lauchImage;
#endif // TARGET_OS_IOS

@end

NS_ASSUME_NONNULL_END
