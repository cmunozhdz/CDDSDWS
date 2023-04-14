//
//  GXActionExternalObjectHandler.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 14/03/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import GXObjectsModel;
#import <GXCoreBL/GXActionHandler.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, GXActionExternalObjectHandlerThreadRequirement) {
	GXActionExternalObjectHandlerThreadRequirementAny,
	GXActionExternalObjectHandlerThreadRequirementMain,
	GXActionExternalObjectHandlerThreadRequirementBackground,
};

#define kGXActionExternalObjectHandler_MethodHandlerSelectorNamePrefix @"gxActionExObjMethodHandler_"

@interface GXActionExternalObjectHandler : GXActionHandler

+ (nullable Class)actionHandlerClassForAction:(nullable id <GXActionExternalObjectDescriptor>)actionExObjDesc;
+ (BOOL)canHandleAction:(nullable id <GXActionExternalObjectDescriptor>)actionExObjDesc;

+ (BOOL)handleActionExecutionUsingMethodHandlerSelectorNamePrefix;

/// If NO is returned, the EO is not available for Mini Apps. If handleActionExecutionUsingMethodHandlerSelectorNamePrefix returns YES, action execution will fail if called form a Mini App, otherwise error should be manually handled (see executingNotMiniAppGXModel). Default returns YES;
+ (BOOL)availableForMiniApps;

@property(nonatomic, strong, readonly) id <GXActionExternalObjectDescriptor> actionExObjDesc;

/**
 * Thread constrains for action execution.
 * Handled automatically only if handleActionExecutionUsingMethodHandlerSelectorNamePrefix returns YES
 *
 * Default implementation returns GXActionExternalObjectHandlerThreadRequirementMain
 */
@property(nonatomic, assign, readonly) GXActionExternalObjectHandlerThreadRequirement actionExObjThreadRequirement;

- (instancetype)initWithActionExObjDescriptor:(id <GXActionExternalObjectDescriptor>)actionExObjDesc
					 componentActionsHandlers:(nullable NSArray<id<GXActionHandler>> *)componentActionsHandlers
									 userInfo:(nullable NSDictionary<GXActionHandlerUserInfoKey, id> *)userInfo NS_DESIGNATED_INITIALIZER;

/**
 * Sets the context entity data for the action handler with the result of the operation in the return parameter.
 *
 * @return YES if the action has a return value, NO otherwise
 */
- (BOOL)setReturnValue:(nullable id)val;

- (nullable NSError *)validateNumberOfParametersReceived:(NSUInteger)received expected:(NSUInteger)expected;
- (nullable NSError *)validateNumberOfParametersReceived:(NSUInteger)received minimum:(NSUInteger)min;

- (NSError *)invalidParameterErrorValidForMethod:(nullable NSString *)method atIndex:(NSUInteger)index developerDescription:(NSString *)developerDescription;

- (nullable NSError *)validateNumberOfParametersValidForMethod:(nullable NSString *)method received:(NSUInteger)received expected:(NSUInteger)expected;
- (nullable NSError *)validateNumberOfParametersValidForMethod:(nullable NSString *)method received:(NSUInteger)received minimum:(NSUInteger)min;

@end


@interface GXActionExternalObjectHandler (GXRegisterEO)

/*!
 Registers the given external object handler class for the given external object name
 
 @param externalObjectHandlerClass External object handler class, must be subclass of GXActionExternalObjectHandler
 @param externalObjectName Case sensitive external object name
 */
+ (void)registerExternalObjectHandler:(Class)externalObjectHandlerClass
				forExternalObjectName:(NSString *)externalObjectName;

@end

NS_ASSUME_NONNULL_END
