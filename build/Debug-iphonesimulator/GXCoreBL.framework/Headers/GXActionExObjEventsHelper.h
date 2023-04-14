//
//  GXActionExObjEventsHelper.h
//  GXFlexibleClient
//
//  Created by willy on 12/5/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import Foundation;
@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

extern NSString *const GXActionExternalObjectEventNotificationNameSuffix;
extern NSString *const GXActionExternalObjectEventNotificationContextKey;

@class GXActionExternalObjectEventNotificationContext;

typedef void(^GXActionExternalObjectEventNotificationContextHandlerCompletion)(NSArray * _Nullable outParameters);
typedef void(^GXActionExternalObjectEventNotificationContextHandler)(GXActionExternalObjectEventNotificationContext *context, GXActionExternalObjectEventNotificationContextHandlerCompletion completion);
typedef void(^GXActionExternalObjectEventNotificationContextCompletionHandler)(GXActionExternalObjectEventNotificationContext *context);


@interface GXActionExObjEventsHelper : NSObject

+ (NSString *)notificationNameFromEventName:(NSString *)eventName;
+ (NSString *)notificationNameForEventSubscription:(NSString *)eventName;

+ (void)subscribeListener:(id)listener selector:(SEL)aSelector forExternalObjectEventName:(NSString *)eventName;
+ (void)unsubscribeListener:(id)listener;

+ (BOOL)subscribeExternalObjectActions:(nullable NSArray<id <GXEventDescriptor>> *)events observer:(id)observer selector:(SEL)aSelector;
+ (void)unsubscribeExternalObjectActionsObserver:(id)observer;

+ (BOOL)handleExternalObjectNotification:(NSNotification *)notification
			   withEventDescriptorLoader:(id<GXEventDescriptor> _Nullable (^)(NSString *eventName))eventDescriptorLoader
								 handler:(id<GXActionHandler> _Nullable (^)(id<GXEventDescriptor> eventDesc, GXActionExternalObjectEventNotificationContext *context))handler;

+ (BOOL)handleExternalObjectNotification:(NSNotification *)notification
			   withEventDescriptorLoader:(id<GXEventDescriptor> _Nullable (^)(NSString *eventName))eventDescriptorLoader
			 handlerWithParametersByName:(id<GXActionHandler> _Nullable (^)(id<GXEventDescriptor> eventDesc, GXActionExternalObjectEventNotificationContext *context, NSDictionary<NSString *, id> * _Nullable parameters))handler;

+ (BOOL)handleExternalObjectNotification:(NSNotification *)notification
					withEventDescriptors:(nullable NSArray<id <GXEventDescriptor>> *)eventDescriptors
								 handler:(id<GXActionHandler> _Nullable (^)(id<GXEventDescriptor> eventDesc, GXActionExternalObjectEventNotificationContext *context))handler;

+ (BOOL)handleExternalObjectNotification:(NSNotification *)notification
					withEventDescriptors:(nullable NSArray<id <GXEventDescriptor>> *)eventDescriptors
			 handlerWithParametersByName:(id<GXActionHandler> _Nullable (^)(id<GXEventDescriptor> eventDesc, GXActionExternalObjectEventNotificationContext *context, NSDictionary<NSString *, id> * _Nullable parameters))handler;

+ (void)dispatchExternalObjectEvent:(NSString *)eventName;

+ (void)dispatchExternalObjectEvent:(NSString *)eventName
					 withParameters:(nullable NSArray *)inParameters;

+ (void)dispatchExternalObjectEvent:(NSString *)eventName
					 withParameters:(nullable NSArray *)parameters
			   outParametersIndexes:(nullable NSIndexSet *)outParametersIndexes
					 serialHandling:(BOOL)serialHandling
					concurrencyMode:(GXActionHandlerConcurrencyMode)concurrencyMode
						 completion:(nullable GXActionExternalObjectEventNotificationContextCompletionHandler)completion;

@end





@interface GXActionExternalObjectEventNotificationContext : NSObject

- (instancetype)initWithExternalObjectEvent:(NSString *)eventName
							 withParameters:(nullable NSArray *)parameter
					   outParametersIndexes:(nullable NSIndexSet *)outParametersIndexes
							 serialHandling:(BOOL)serialHandling
							concurrencyMode:(GXActionHandlerConcurrencyMode)concurrencyMode
								 completion:(nullable GXActionExternalObjectEventNotificationContextCompletionHandler)completion;

- (instancetype)initWithExternalObjectEvent:(NSString *)eventName
							 withParameters:(nullable NSArray *)parameter
					   outParametersIndexes:(nullable NSIndexSet *)outParametersIndexes
							 serialHandling:(BOOL)serialHandling
							concurrencyMode:(GXActionHandlerConcurrencyMode)concurrencyMode
		   synchronicCompletionAfterHandled:(BOOL)syncCompletionAfterHandled
								 completion:(nullable GXActionExternalObjectEventNotificationContextCompletionHandler)completion NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

@property(nonatomic, strong, readonly) NSString *eventName;
@property(nonatomic, copy, readonly) NSArray *parameters;
@property(nonatomic, strong, readonly) NSIndexSet *outParametersIndexes;
@property(nonatomic, assign, readonly) BOOL handled; // YES if a handler was added
@property(nonatomic, assign, readonly) BOOL serialHandling; // If YES, handlers are called once a time (FIFO), concurrent otherwise.
@property(nonatomic, assign, readonly) GXActionHandlerConcurrencyMode concurrencyMode;
@property(nonatomic, assign, readonly) BOOL allowSynchronicCompletionAfterHandled; // If YES, completion will be called synchronic after being handled.

- (void)appendHandler:(GXActionExternalObjectEventNotificationContextHandler)handler;

- (void)callCompletionIfNotHandled;

@end

NS_ASSUME_NONNULL_END
