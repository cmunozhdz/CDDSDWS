//
//  GXUserNotificationsManager+GXUserNotificationsDelegateHelper.h
//  GXCoreBL
//
//  Created by Fabian Inthamoussu on 21/11/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

#import <GXCoreBL/GXUserNotificationsManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXUserNotificationsManager (GXUserNotificationsDelegateHelper)

#pragma mark - User Notifications

+ (void)onDidRegisterUserNotificationSettings;

#pragma mark - Remote Notifications

+ (void)onDidRegisterForRemoteNotificationsWithDeviceToken:(NSData *)devToken;
+ (void)onDidFailToRegisterForRemoteNotificationsWithError:(NSError *)error;


#if TARGET_OS_IOS
+ (void)onDidReceiveRemoteNotification:(NSDictionary *)userInfo NS_DEPRECATED_IOS(3_0, 10_0);
#endif // TARGET_OS_IOS

#if !TARGET_OS_TV
+ (void)onDidReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(void))completionHandler;
#endif // !TARGET_OS_TV


#if TARGET_OS_IOS
+ (void)onHandleActionWithIdentifier:(nullable NSString*)identifier forRemoteNotification:(NSDictionary *)userInfo withResponseInfo:(NSDictionary *)responseInfo completionHandler:(void(^)(void))completionHandler NS_DEPRECATED_IOS(9_0, 10_0);

+ (void)onHandleActionWithIdentifier:(nullable NSString*)identifier forRemoteNotification:(NSDictionary *)userInfo completionHandler:(void(^)(void))completionHandler NS_DEPRECATED_IOS(8_0, 10_0);
#endif // TARGET_OS_IOS

#pragma mark - Local Notifications

#if TARGET_OS_IOS
+ (void)onDidReceiveLocalNotification:(id)localNotification NS_DEPRECATED_IOS(4_0, 10_0); // UILocalNotification


+ (void)onHandleActionWithIdentifier:(nullable NSString*)identifier for:(id)localNotification withResponseInfo:(NSDictionary *)responseInfo completionHandler:(void(^)(void))completionHandler NS_DEPRECATED_IOS(9_0, 10_0);

+ (void)onHandleActionWithIdentifier:(nullable NSString*)identifier for:(id)localNotification completionHandler:(void(^)(void))completionHandler NS_DEPRECATED_IOS(8_0, 10_0);
#endif // TARGET_OS_IOS

@end

NS_ASSUME_NONNULL_END
