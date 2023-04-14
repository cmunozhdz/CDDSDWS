//
//  GXApplicationBarsAppearance.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 24/06/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@protocol GXApplicationBarsAppearance <NSObject>

- (BOOL)showGxApplicationBars;
- (nullable NSString *)gxApplicationBarsClassName;

@optional
- (void)setGxApplicationBarsClassName:(nullable NSString *)className;
- (nullable NSString *)gxNavigationBarClassName;
#if TARGET_OS_IOS
- (BOOL)gxAllowsLargeTitleDisplayModeFromThemeClass API_AVAILABLE(ios(11.0)); // YES if not implemented
#endif // TARGET_OS_IOS

@end

NS_ASSUME_NONNULL_END
