//
//  GXActionHandler.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 04/02/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import GXFoundation;
@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSInteger, GXActionHandlerContextLastErrorUpdateType) {
	GXActionHandlerContextLastErrorUpdateNever = 0,
	GXActionHandlerContextLastErrorUpdateOnSuccess = 1 << 0,
	GXActionHandlerContextLastErrorUpdateOnFailure = 1 << 1,
	GXActionHandlerContextLastErrorUpdateAlways = GXActionHandlerContextLastErrorUpdateOnSuccess | GXActionHandlerContextLastErrorUpdateOnFailure
};

typedef NSString *const GXActionHandlerUserInfoKey NS_TYPED_EXTENSIBLE_ENUM NS_SWIFT_NAME(ActionHandler.UserInfoKey);

NS_SWIFT_NAME(ActionHandler)
@interface GXActionHandler : NSObject <GXActionHandler, GXActionHandlerDelegate>

@property(nonatomic, strong, readonly) id <GXActionDescriptor> actionDesc;
@property(nullable, nonatomic, weak) id <GXActionHandlerDelegate> delegate;
@property(nonatomic, assign, readonly, getter=isSelfExecuting) BOOL executing;
@property(nullable, nonatomic, strong, readonly) NSDictionary<GXActionHandlerUserInfoKey, id> *userInfo;

/// Safe helpers over actionDesc
@property(nullable, nonatomic, strong, readonly) id<GXActionParametersDescriptor> actionDescParametersDescriptor;
@property(nullable, nonatomic, strong, readonly) NSArray<id<GXActionParameterDescriptor>> *actionDescParametersArray;
@property(nullable, nonatomic, strong, readonly) id<GXEventDescriptor> actionDescEventDescriptor;

/// Returns GXModel from actionDesc.gxModel if isSelfExecuting, nil otherwise. If isSelfExecuting and GXModel is not available, calls onFinishedExecutingWithError: returns nil
@property(nullable, nonatomic, strong, readonly) GXModel *executingGXModel;
/// Returns same as executingGXModel but also checks GXModel is not a mini app. If isSelfExecuting and GXModel is a mini app, calls onFinishedExecutingWithError: returns nil
@property(nullable, nonatomic, strong, readonly) GXModel *executingNotMiniAppGXModel;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithActionDescriptor:(id <GXActionDescriptor>)actionDesc
				componentActionsHandlers:(nullable NSArray<id<GXActionHandler>> *)componentActionsHandlers
								userInfo:(nullable NSDictionary<GXActionHandlerUserInfoKey, id> *)userInfo NS_DESIGNATED_INITIALIZER;

- (BOOL)isSelfExecuting;
- (BOOL)isComponentActionExecuting;

- (BOOL)hasComponentActions;
 
/// Called from onFinishedExecutingWithError: to update (or not) self.actionHandlerContext.actionHandlerContextLastError
/// Default implementation returns GXActionHandlerContextLastErrorUpdateAlways
@property(nonatomic, readonly) GXActionHandlerContextLastErrorUpdateType onFinishedExecutingContextLastErrorUpdateType;

/**
 * Called when all component actions finished executing, must not be called directly
 * Default implementation notifies delegate & post notification
 */
- (void)onFinishedExecutingAllComponentsWithError:(nullable NSError *)error;

- (void)onFinishedExecutingWithDefaultError;
- (void)onFinishedExecutingWithError:(nullable NSError *)error;

- (void)onFinishedExecutingWithDefaultErrorAfterDelay:(NSTimeInterval)ti;
- (void)onFinishedExecutingWithError:(nullable NSError *)error afterDelay:(NSTimeInterval)ti;

// These methods calls the withError equivalent with nil as parameter.
- (void)onFinishedExecutingWithSuccess;
- (void)onFinishedExecutingWithSuccessAfterDelay:(NSTimeInterval)ti;

/**
 * Calls [self parametersEntityData:paramentersDesc filteringByParameterKind:GXParameterKindIn mapParametersByName:NO completion:completion]
 */
- (nullable id<GXCancelableOperation>)parametersEntityData:(nullable id <GXParametersDescriptor>)paramentersDesc
												completion:(void(^)(id<GXEntityData> _Nullable parametersEntityData, NSError * _Nullable error))completion;

/**
 * If mapParametersByName is set to YES, the matchng between the parameter descriptors is made by name. Otherwise, it is made by position.
 * paramKind can be used to filter parametersDesc: in -> in & inout, out -> out & inout, inout -> all
 */
- (nullable id<GXCancelableOperation>)parametersEntityData:(nullable id <GXParametersDescriptor>)parametersDesc
								  filteringByParameterKind:(GXParameterKind)paramKind
									   mapParametersByName:(BOOL)mapByName
												completion:(void(^)(id<GXEntityData> _Nullable parametersEntityData, NSError * _Nullable error))completion;


/*!
 Checks if there is any out or inout parameter
 
 @param parameters The parameters descriptor to look for out or inout parameter
 @result YES if there is any out or inout parameter in the givern parameters descriptor
 */
- (BOOL)hasAnyOutParameter:(nullable id <GXParametersDescriptor>)parameters;

/**
 * Sets out parameters to contextEntityData taking its values from the given entityData
 * Calls setOutParametersFromEntityData:parameters:mapParametersByName: with mapByName = NO
 */
- (void)setOutParametersFromEntityData:(nullable id <GXEntityData>)entityData
							parameters:(nullable id <GXParametersDescriptor>)parameters;

/**
 * Sets out parameters to contextEntityData taking its values from the given entityData
 * If mapParametersByName is set to YES, the matchng between the parameter descriptors is made by name. Otherwise, it is made by position.
 */
- (void)setOutParametersFromEntityData:(nullable id <GXEntityData>)entityData
							parameters:(nullable id <GXParametersDescriptor>)parameters
				   mapParametersByName:(BOOL)mapByName;

#pragma mark - Reading information

#pragma mark At Index

- (nullable id<GXCancelableOperation>)readSDTParameterAtIndex:(NSUInteger)index
											   fromEntityData:(nullable id<GXEntityData>)contextEntityData
												   completion:(void(^)(id<GXSDTData> _Nullable sdtParam, NSError * _Nullable error))completion;
- (nullable id<GXCancelableOperation>)readSDTCollectionParameterAtIndex:(NSUInteger)index
														 fromEntityData:(nullable id<GXEntityData>)contextEntityData
															 completion:(void(^)(id<GXSDTDataCollection> _Nullable sdtCollectionParam, NSError * _Nullable error))completion;

#pragma mark Typed Reading

- (nullable id<GXCancelableOperation>)readStringParameter:(id<GXActionParameterDescriptor>)actionParameter
										   fromEntityData:(nullable id<GXEntityData>)contextEntityData
											   completion:(void(^)(NSString * _Nullable stringParam, NSError * _Nullable error))completion;

- (nullable id<GXCancelableOperation>)readStringParametersFromEntityData:(nullable id<GXEntityData>)contextEntityData
															  completion:(void(^)(NSArray<NSString *> *paramStringValues, NSError * _Nullable error))completion;

- (nullable id<GXCancelableOperation>)readDateParameter:(id<GXActionParameterDescriptor>)actionParameter
										 fromEntityData:(nullable id<GXEntityData>)contextEntityData
											 completion:(void(^)(NSDate * _Nullable dateParam, NSError * _Nullable error))completion;

/// Returns DateTime in UTC. Sames as [self readDateTimeParameter:actionParameter fromEntityData:contextEntityData localTimeZone:NO completion:completion]
- (nullable id<GXCancelableOperation>)readDateTimeParameter:(id<GXActionParameterDescriptor>)actionParameter
											 fromEntityData:(nullable id<GXEntityData>)contextEntityData
												 completion:(void(^)(NSDate * _Nullable dateTimeUTCParam, NSError * _Nullable error))completion;
/// Returns DateTime in the local time zone if localTimeZone == YES, UTC otherwise
- (nullable id<GXCancelableOperation>)readDateTimeParameter:(id<GXActionParameterDescriptor>)actionParameter
											 fromEntityData:(nullable id<GXEntityData>)contextEntityData
											  localTimeZone:(BOOL)localTimeZone
												 completion:(void(^)(NSDate * _Nullable dateTimeParam, NSError * _Nullable error))completion;

- (nullable id<GXCancelableOperation>)readIntParameter:(id<GXActionParameterDescriptor>)actionParameter
										fromEntityData:(nullable id<GXEntityData>)contextEntityData
											completion:(void(^)(NSInteger intParam, NSError * _Nullable error))completion;

- (nullable id<GXCancelableOperation>)readBoolParameter:(id<GXActionParameterDescriptor>)actionParameter
										 fromEntityData:(nullable id<GXEntityData>)contextEntityData
											 completion:(void(^)(BOOL boolParam, NSError * _Nullable error))completion;

- (nullable id<GXCancelableOperation>)readSDTParameter:(id<GXActionParameterDescriptor>)actionParameter
										fromEntityData:(nullable id<GXEntityData>)contextEntityData
											completion:(void(^)(id<GXSDTData> _Nullable sdtParam, NSError * _Nullable error))completion;

- (nullable id<GXCancelableOperation>)readSDTCollectionParameter:(id<GXActionParameterDescriptor>)actionParameter
												  fromEntityData:(nullable id<GXEntityData>)contextEntityData
													  completion:(void(^)(id<GXSDTDataCollection> _Nullable sdtCollectionParam, NSError * _Nullable error))completion;

#pragma mark Casting Types

- (nullable NSString *)stringParameter:(id<GXActionParameterDescriptor>)actionParameter fromValue:(nullable id)paramValue;
- (NSString *)nonNullStringParameter:(id<GXActionParameterDescriptor>)actionParameter fromValue:(nullable id)paramValue;

- (nullable NSURL *)urlParameter:(id<GXActionParameterDescriptor>)actionParameter fromValue:(nullable id)paramValue;

- (nullable NSDate *)dateParameter:(id<GXActionParameterDescriptor>)actionParameter fromValue:(nullable id)paramValue;
/// Returns DateTime in UTC. Sames as [self dateTimeParameter:actionParameter fromValue:paramValue localTimeZone:NO]
- (nullable NSDate *)dateTimeParameter:(id<GXActionParameterDescriptor>)actionParameter fromValue:(nullable id)paramValue;
/// Returns DateTime in the local time zone if localTimeZone == YES, UTC otherwise
- (nullable NSDate *)dateTimeParameter:(id<GXActionParameterDescriptor>)actionParameter fromValue:(nullable id)paramValue localTimeZone:(BOOL)localTimeZone;

- (NSInteger)integerParameter:(id<GXActionParameterDescriptor>)actionParameter fromValue:(nullable id)paramValue defaultValue:(NSInteger)defaultValue;
/// Sames as [self integerParameter:actionParameter fromValue:paramValue defaultValue:0]
- (NSInteger)integerParameter:(id<GXActionParameterDescriptor>)actionParameter fromValue:(nullable id)paramValue;

- (NSUInteger)unsignedIntegerParameter:(id<GXActionParameterDescriptor>)actionParameter fromValue:(nullable id)paramValue defaultValue:(NSUInteger)defaultValue;
/// Sames as [self unsignedIntegerParameter:actionParameter fromValue:paramValue defaultValue:0]
- (NSUInteger)unsignedIntegerParameter:(id<GXActionParameterDescriptor>)actionParameter fromValue:(nullable id)paramValue;

- (BOOL)boolParameter:(id<GXActionParameterDescriptor>)actionParameter fromValue:(nullable id)paramValue defaultValue:(BOOL)defaultValue;
/// Sames as [self boolParameter:actionParameter fromValue:paramValue defaultValue:NO]
- (BOOL)boolParameter:(id<GXActionParameterDescriptor>)actionParameter fromValue:(nullable id)paramValue;

- (float)floatParameter:(id<GXActionParameterDescriptor>)actionParameter fromValue:(nullable id)paramValue defaultValue:(float)defaultValue;
/// Sames as [self floatParameter:actionParameter fromValue:paramValue defaultValue:0]
- (float)floatParameter:(id<GXActionParameterDescriptor>)actionParameter fromValue:(nullable id)paramValue;

- (double)doubleParameter:(id<GXActionParameterDescriptor>)actionParameter fromValue:(nullable id)paramValue defaultValue:(double)defaultValue;
/// Sames as [self doubleParameter:actionParameter fromValue:paramValue defaultValue:0]
- (double)doubleParameter:(id<GXActionParameterDescriptor>)actionParameter fromValue:(nullable id)paramValue;

- (nullable id<GXSDTData>)sdtParameter:(id<GXActionParameterDescriptor>)actionParameter fromValue:(nullable id)paramValue;
- (nullable id<GXSDTDataCollection>)sdtCollectionParameter:(id<GXActionParameterDescriptor>)actionParameter fromValue:(nullable id)paramValue;

#pragma mark Generic

- (nullable id<GXCancelableOperation>)readParameter:(id<GXActionParameterDescriptor>)actionParameter
									 fromEntityData:(nullable id<GXEntityData>)contextEntityData
										 completion:(void(^)(id _Nullable paramValue, NSError * _Nullable error))completion;

- (nullable id<GXCancelableOperation>)readParameters:(NSArray<id<GXActionParameterDescriptor>> *)actionParameters
									  fromEntityData:(nullable id<GXEntityData>)contextEntityData
										  completion:(void(^)(NSArray * _Nullable paramValues, NSError * _Nullable error))completion;
/// Sames as [self readParameters:self.actionDescParametersArray ? : @[] fromEntityData:contextEntityData completion:completion]
- (nullable id<GXCancelableOperation>)readParametersFromEntityData:(nullable id<GXEntityData>)contextEntityData
														completion:(void(^)(NSArray * _Nullable paramValues, NSError * _Nullable error))completion;
/// Sames as [self readParametersFromEntityData:self.contextEntityData completion:completion]
- (nullable id<GXCancelableOperation>)readParametersWithCompletion:(void(^)(NSArray * _Nullable paramValues, NSError * _Nullable error))completion;

/// Enumerates actionParameters and paramValues using block. Given actionParameters and paramValues must match.
- (void)enumerateReadParameters:(NSArray<id<GXActionParameterDescriptor>> *)actionParameters
						 values:(NSArray *)paramValues
					 usingBlock:(void (NS_NOESCAPE ^)(id<GXActionParameterDescriptor> actionParameter, id _Nullable paramValue, NSUInteger idx, BOOL *stop))block;
/// Sames as [self enumerateReadParameters:self.actionDescParametersArray ? : @[] values:paramValues usingBlock:block]
- (void)enumerateReadParametersValues:(NSArray *)paramValues
						   usingBlock:(void (NS_NOESCAPE ^)(id<GXActionParameterDescriptor> actionParameter, id _Nullable paramValue, NSUInteger idx, BOOL *stop))block;

@end

NS_ASSUME_NONNULL_END
