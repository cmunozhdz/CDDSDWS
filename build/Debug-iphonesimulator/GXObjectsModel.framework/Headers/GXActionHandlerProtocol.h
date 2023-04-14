//
//  GXActionHandlerProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 04/02/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import Foundation;
@import GXFoundation;
#import <GXObjectsModel/GXActionDescriptorProtocol.h>
#import <GXObjectsModel/GXEntityDataProtocol.h>
#import <GXObjectsModel/GXInheritedConnectivitySupportResolver.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXActionHandler;
@protocol GXActionHandlerDelegate;

typedef NS_ENUM(NSInteger, GXActionHandlerConcurrencyMode) {
	GXActionHandlerConcurrencyModeDefault,
	GXActionHandlerConcurrencyModeDiscardDuplicate,
	GXActionHandlerConcurrencyModeConcurrentDuplicates,
};

@protocol GXActionHandlerDelegate <NSObject>

- (void)actionHandler:(id <GXActionHandler>)actionHandler didFinishedExecutingWithError:(nullable NSError *)error;

@optional
- (nullable id <GXInheritedConnectivitySupportResolver>)actionHandlerInheritedConnectivitySupportResolver:(id <GXActionHandler>)actionHandler;

@end

@protocol GXActionSender <NSObject>
@end

typedef NS_ENUM(uint_least8_t, GXActionHandlerContextRedirectFirstCallOptions) {
	GXActionHandlerContextRedirectFirstCallDisabled,
	GXActionHandlerContextRedirectFirstCallEnabled,
	GXActionHandlerContextRedirectFirstCallEnabledAnimated
};

NS_SWIFT_NAME(GXActionHandlerContextProtocol)
@protocol GXActionHandlerContext <NSObject>

@property(nonatomic, strong, readonly) id <GXEntityDataWithOverrideValues> actionHandlerContextEntityData;
@property(nullable, nonatomic, strong, readonly) id <GXActionSender> actionHandlerContextSender;
@property(nonatomic, assign, readonly) GXActionErrorHandlingMode actionHandlerContextErrorHandlingMode;
@property(nonatomic, assign) NSInteger actionHandlerContextSkip;
@property(nonatomic, assign) GXActionHandlerContextRedirectFirstCallOptions actionHandlerRedirectFirstCallOptions;
@property(nullable, nonatomic, strong) NSError *actionHandlerContextLastError;

@property(nullable, nonatomic, weak) id<GXActionHandler> actionHandlerContextExecutionHandler;

@end

@protocol GXActionHandler <NSObject>

@property(nullable, nonatomic, weak, readonly) id <GXActionHandlerDelegate> delegate;
@property(nullable, nonatomic, weak, readonly) id <GXActionHandler> parentActionHandler;
@property(nullable, nonatomic, strong, readonly) id <GXActionHandlerContext> actionHandlerContext;
@property(nonatomic, assign) GXActionHandlerConcurrencyMode actionHandlerConcurrencyMode;

@property(nonatomic, strong, readonly) id <GXActionDescriptor> actionDescriptor;

- (void)actionExecuteWithContext:(nullable id <GXActionHandlerContext>)context
						delegate:(nullable id <GXActionHandlerDelegate>)delegate;

- (BOOL)isActionExecuting;
- (void)continueWithoutDelegate;
- (void)cancelActionExecution;
- (nullable id<GXEntityDataWithOverrideValues>)contextEntityData;

@end

extern NSString *const GXActionHandlerDidFinishNotification;
extern NSString *const GXActionHandlerErrorKey;

extern NSString *const GXSynchronizationReceiveDidFinishNotification;
extern NSString *const GXSynchronizationReceiveErrorKey;

extern NSString *const GXDatabaseRestoreDidFinishNotification;
extern NSString *const GXDatabaseRestoreErrorKey;

NS_ASSUME_NONNULL_END
