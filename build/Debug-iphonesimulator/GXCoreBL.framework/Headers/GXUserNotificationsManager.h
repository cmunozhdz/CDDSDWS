//
//  GXUserNotificationsManager.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 19/9/14.
//  Copyright (c) 2014 Artech. All rights reserved.
//

@import GXObjectsModel;
#import <GXCoreBL/GXUserNotificationsManager+Optionals.h>

@protocol GXUserNotificationsProviderProtocol;
@protocol GXUNNotificationActionHandler;
@protocol GXUNNotificationResponse;

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, GXUNNotificationPresentationOptions) {
	GXUNNotificationPresentationOptionsBadge = 1 << 0,
	GXUNNotificationPresentationOptionsSound = 1 << 1,
	GXUNNotificationPresentationOptionsAlert = 1 << 2,
	GXUNNotificationPresentationOptionsAll = GXUNNotificationPresentationOptionsBadge | GXUNNotificationPresentationOptionsSound | GXUNNotificationPresentationOptionsAlert
};

@interface GXUserNotificationsManager : NSObject <GXUserNotificationsManagerRemoteOptionals, GXUserNotificationsManagerLocalOptionals>

@property(class, readonly) BOOL registeredForUserNotificationsSinceApplicationLaunch;
+ (void)markRegisteredForUserNotificationsSinceApplicationLaunch;

+ (void)registerForNotifications; // force == NO
+ (void)registerForNotifications:(BOOL)force;

+ (BOOL)registeredNotificationsAreUpToDate; // same as calling registeredNotificationsAreUpToDateForRemoteNotifications:YES forLocalNotifications:YES
+ (BOOL)registeredNotificationsAreUpToDateForRemoteNotifications:(BOOL)remote forLocalNotifications:(BOOL)local;

#pragma mark - GXModel Helpers

+ (BOOL)modelRemoteNotificationsEnabled:(GXModel *)model;
+ (BOOL)modelSilentRemoteNotificationsEnabled:(GXModel *)model;
+ (GXApplicationEntryPointNotificationReg)modelNotificationsRegistrationMode:(GXModel *)model;

#pragma mark - Remote

@property(class, readonly) BOOL supportsRemoteNotifications;

@property(class, readonly) BOOL shouldRenewRemoteNotificationsToken;
+ (void)markRemoteNotificationsTokenRenewNotNeeded;

#pragma mark - Local

@property(class, readonly) BOOL supportsLocalNotifications;

#pragma mark - Handling

@property(class, readonly) GXUNNotificationPresentationOptions defaultGXUNNotificationPresentationOptions;

#if !TARGET_OS_TV
+ (void)handleReceivedNotificationResponse:(id<GXUNNotificationResponse>)response withCompletionHandler:(void(^ _Nullable)(void))completionHandler;

+ (void)handleReceivedSilentNotification:(id<GXUNNotificationActionHandler>)notificationActionHandler withCompletionHandler:(void(^ _Nullable)(void))completionHandler;
#endif // !TARGET_OS_TV

#pragma mark - Initialization

+ (void)onFinishLaunchingWithOptions:(nullable NSDictionary *)launchOptions;

@end



@interface GXUserNotificationsManager (GXUserNotificationsProvider)

+ (void)registerNotificationsProviderClass:(Class)remoteListProviderClass forTypeIdentifier:(NSString *)typeIdentifier;

@property(class, copy, readonly) NSDictionary *notificationsProviderProperties;

@property(class, readonly, nullable) id <GXUserNotificationsProviderProtocol> notificationsProvider;

@end

NS_ASSUME_NONNULL_END
