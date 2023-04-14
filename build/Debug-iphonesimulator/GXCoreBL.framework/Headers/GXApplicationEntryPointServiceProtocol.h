//
//  GXApplicationEntryPointServiceProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 22/4/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import Foundation;
@import GXObjectsModel;
#import <GXCoreBL/GXActionExObjEventsHelper.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(GXApplicationEntryPointServiceProtocol)
@protocol GXApplicationEntryPointService <NSObject>

- (nullable id<GXActionHandler>)executeApplicationEntryPointNotificationWithName:(NSString *)notificationEventName
																	  parameters:(nullable NSDictionary<NSString *, id> *)parameters
																 concurrencyMode:(GXActionHandlerConcurrencyMode)concurrencyMode
															   completionHandler:(void (^ _Nullable)(id<GXActionHandler> _Nullable))completionHandler;

- (nullable id<GXActionHandler>)executeApplicationEntryPointEventWithName:(NSString *)eventName
															   parameters:(nullable NSDictionary<NSString *, id> *)parameters
														  concurrencyMode:(GXActionHandlerConcurrencyMode)concurrencyMode
														completionHandler:(void (^ _Nullable)(id<GXActionHandler> _Nullable))completionHandler;

#if TARGET_OS_IOS
- (nullable id<GXActionHandler>)executeApplicationEntryPointShortcutWithName:(NSString *)shortcutName
																  parameters:(nullable NSDictionary<NSString *, id> *)parameters
															 concurrencyMode:(GXActionHandlerConcurrencyMode)concurrencyMode
														   completionHandler:(void (^ _Nullable)(id<GXActionHandler> _Nullable))completionHandler;
#endif // TARGET_OS_IOS

/// completionHandler isn't called if return value is nil
- (nullable id<GXActionHandler>)executeApplicationEntryPointExternalObjectEvent:(NSString *)eventName
																 withParameters:(nullable NSArray *)parameters
														   outParametersIndexes:(nullable NSIndexSet *)outParametersIndexes
																concurrencyMode:(GXActionHandlerConcurrencyMode)concurrencyMode
																	 completion:(nullable GXActionExternalObjectEventNotificationContextCompletionHandler)completion;


- (nullable id<GXActionHandler>)executeApplicationEntryPointDynamicObjectCall:(NSString *)dynamicCallString
															completionHandler:(void (^ _Nullable)(id<GXActionHandler> _Nullable))completionHandler;

- (BOOL)hasApplicationEntryPointNotificationWithEventName:(NSString *)notificationEventName;
- (BOOL)hasApplicationEntryPointEventWithName:(NSString *)eventName;
#if TARGET_OS_IOS
- (BOOL)hasApplicationEntryPointShortcutWithName:(NSString *)shortcutName;
#endif // TARGET_OS_IOS

- (void)restartApplication;

@end

NS_ASSUME_NONNULL_END
