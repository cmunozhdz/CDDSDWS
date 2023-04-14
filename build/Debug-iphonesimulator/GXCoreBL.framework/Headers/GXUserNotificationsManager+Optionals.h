//
//  GXUserNotificationsManager+Optionals.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 19/9/14.
//  Copyright (c) 2014 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@protocol GXUserNotificationsManagerOptionals <NSObject>

@optional
@property(readonly) BOOL supportsRemoteNotifications;
@property(readonly) BOOL supportsLocalNotifications;

@property(copy, readonly) NSDictionary *notificationsProviderProperties;

@end


@protocol GXUserNotificationsManagerRemoteOptionals <GXUserNotificationsManagerOptionals>

@optional
/// Returns UIApplicationLaunchOptionsRemoteNotificationKey.
@property(readonly) NSString *const applicationLaunchOptionsRemoteNotificationKey;

/// Calls [[UIApplication sharedApplication] registerForRemoteNotifications].
- (void)applicationRegisterForRemoteNotifications;

@end


@protocol GXUserNotificationsManagerLocalOptionals <GXUserNotificationsManagerOptionals>

@optional
/// Returns UIApplicationLaunchOptionsLocalNotificationKey.
@property(readonly) NSString *const applicationLaunchOptionsLocalNotificationKey;

@end

NS_ASSUME_NONNULL_END
