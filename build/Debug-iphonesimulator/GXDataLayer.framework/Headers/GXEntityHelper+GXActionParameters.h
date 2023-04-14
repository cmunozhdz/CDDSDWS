//
//  GXEntityHelper+GXActionParameters.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 29/1/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@interface GXEntityHelper (GXActionParameters)

+ (BOOL)parametersDescriptorHasOutParameters:(id<GXParametersDescriptor>)paramsDesc;

/**
 * If mapParametersByName is set to YES, the matchng between the parameter descriptors is made by name (actionParameterCalledTargetParameterName). Otherwise, it is made by position.
 * paramKind can be used to filter paramsDesc: in -> in & inout, out -> out & inout, inout -> all
 */
+ (nullable id<GXCancelableOperation>)entityDataForActionParametersDesc:(id<GXActionParametersDescriptor>)actionParamsDesc
														  paramtersDesc:(id<GXParametersDescriptor>)paramsDesc
											   filteringByParameterKind:(GXParameterKind)paramKind
															   fromData:(nullable id<GXEntityData>)data
												   actionHandlerContext:(nullable id<GXActionHandlerContext>)context
													mapParametersByName:(BOOL)mapByName
															 completion:(void(^)(id<GXEntityData> _Nullable parametersEntityData, NSError * _Nullable error))completion;

+ (nullable id<GXCancelableOperation>)entityDataForActionParametersDescArray:(NSArray *)actionParamsDesc // Collection of id<GXActionParameterDescriptor> or NSNull
														  paramtersDescArray:(NSArray *)paramsDesc // Collection of id<GXParameterDescriptor> or NSNull
																	fromData:(nullable id<GXEntityData>)data
														actionHandlerContext:(nullable id<GXActionHandlerContext>)context
																  completion:(void(^)(id<GXEntityData> _Nullable parametersEntityData, NSError * _Nullable error))completion;

+ (nullable id<GXCancelableOperation>)entityDataValueForParameter:(id<GXActionParameterDescriptor>)actionParamDesc
										 calledParameterFieldInfo:(nullable id<GXEntityDataFieldInfo>)paramFieldInfo
														 fromData:(nullable id<GXEntityData>)data
											 actionHandlerContext:(nullable id<GXActionHandlerContext>)context
													   completion:(void(^)(id _Nullable fieldValue, NSError * _Nullable error))completion;

+ (nullable id)entityDataValueForConstantParameter:(id<GXActionParameterDescriptorConstant>)actionConstantParamDesc
						  calledParameterFieldInfo:(nullable id<GXEntityDataFieldInfo>)paramFieldInfo;

+ (nullable id<GXCancelableOperation>)parametersStringFromEntityData:(nullable id<GXEntityData>)entityData
												actionHandlerContext:(nullable id<GXActionHandlerContext>)context
										   inputParameterDescriptors:(NSArray<id<GXActionParameterDescriptor>> *)parametersDescriptors
														  completion:(void(^)(NSString *_Nullable parametersString, NSError * _Nullable error))completion;

+ (void)setOverrideValueForParameter:(id<GXActionParameterDescriptor>)actionParamDesc
						toEntityData:(id<GXEntityDataWithOverrideValues>)data
							   value:(nullable id)value;

+ (void)setActionParametersDescArray:(id<GXActionParametersDescriptor>)actionParamsDesc
					   paramtersDesc:(id<GXParametersDescriptor>)paramsDesc
					  fromEntityData:(id<GXEntityData>)fromEntityData
						toEntityData:(id<GXEntityDataWithOverrideValues>)toEntityData
				 mapParametersByName:(BOOL)mapByName;

+ (void)setActionParametersDescArray:(NSArray *)actionParamsDesc // Collection of id<GXActionParameterDescriptor> or NSNull
					   outParameters:(NSArray *)paramsDesc // Collection of id<GXParameterDescriptor> or NSNull
					  fromEntityData:(id<GXEntityData>)fromEntityData
						toEntityData:(id<GXEntityDataWithOverrideValues>)toEntityData;

+ (void)entityData:(id<GXEntityDataWithOverrideValues>)entityData
		  setValue:(id)value
forParameterDescriptor:(id<GXActionParameterDescriptor>)actionParamDesc;

+ (void)entityData:(id<GXEntityDataWithOverrideValues>)entityData
		  setValue:(nullable id)value
	  toExpression:(id<GXExpression>)expression;

@end

NS_ASSUME_NONNULL_END
