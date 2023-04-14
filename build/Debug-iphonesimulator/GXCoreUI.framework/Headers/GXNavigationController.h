//
//  GXNavigationController.h
//  GXFlexibleClient
//
//  Created by willy on 10/16/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import UIKit;
@import GXObjectsModel;
#import <GXCoreUI/GXNavigationBar.h>
#import <GXCoreUI/GXWindow.h>
#import <GXCoreUI/UINavigationController+Helpers.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXNavigationController : UINavigationController <UINavigationControllerDelegate, GXAllowLowContrastTintColor>

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

@end

@interface UINavigationController (GXStyleClass)

#if TARGET_OS_IOS
@property(nonatomic, assign) BOOL gxPrefersLargeTitles API_AVAILABLE(ios(11.0));
#endif // TARGET_OS_IOS
@property(nullable, nonatomic, strong) GXStyleClass *gxAppBarsStyleClass;
@property(nullable, nonatomic, strong) GXStyleClass *gxNavigationAppBarStyleClass;

@end

NS_ASSUME_NONNULL_END
