//
//  GXEntityDataWithOverrideValues.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 10/03/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import GXObjectsModel;

@interface GXEntityDataWithOverrideValues : NSObject <GXEntityDataWithOverrideValues>

@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, id> *instanceOverrideValuesByFieldName;
@property(nullable, nonatomic, strong, readonly) id<GXEntityData> innerEntityData;

+ (nullable id<GXEntityData>)entityDataForOverrideValuesByFieldName:(nullable NSDictionary<NSString *, id> *)overrideValuesByFieldName
														 entityData:(nullable id<GXEntityData>)entityData
														 allowMerge:(BOOL)allowMerge
														   allowNil:(BOOL)allowNil
												  requiredProtocols:(GXEntityDataProtocolsFlags)requiredProtocols;

+ (nullable id<GXEntityData>)entityDataForOverrideValuesByFieldName:(nullable NSDictionary<NSString *, id> *)overrideValuesByFieldName
														 entityData:(nullable id<GXEntityData>)entityData
														 allowMerge:(BOOL)allowMerge
														   allowNil:(BOOL)allowNil;

// Same as allowNil:YES
+ (nullable id<GXEntityData>)entityDataForOverrideValuesByFieldName:(nullable NSDictionary<NSString *, id> *)overrideValuesByFieldName
														 entityData:(nullable id<GXEntityData>)entityData
														 allowMerge:(BOOL)allowMerge;

// Same as allowMerge:YES
+ (nullable id<GXEntityData>)entityDataForOverrideValuesByFieldName:(nullable NSDictionary<NSString *, id> *)overrideValuesByFieldName
														 entityData:(nullable id<GXEntityData>)entityData;

+ (nullable id<GXEntityDataWithOverrideValues>)entityDataWithOverrideValuesForOverrideValuesByFieldName:(nullable NSDictionary<NSString *, id> *)overrideValuesByFieldName
																							 entityData:(nullable id<GXEntityData>)entityData
																							 allowMerge:(BOOL)allowMerge
																							   allowNil:(BOOL)allowNil;

+ (nullable id<GXMutableEntityData>)mutableEntityDataForOverrideValuesByFieldName:(nullable NSDictionary<NSString *, id> *)overrideValuesByFieldName
																	   entityData:(nullable id<GXEntityData>)entityData
																	   allowMerge:(BOOL)allowMerge
																		 allowNil:(BOOL)allowNil;

+ (nullable id<GXMutableEntityData, GXEntityDataWithOverrideValues>)mutableEntityDataWithOverrideValuesForOverrideValuesByFieldName:(nullable NSDictionary<NSString *, id> *)overrideValuesByFieldName
																														 entityData:(nullable id<GXEntityData>)entityData
																														 allowMerge:(BOOL)allowMerge
																														   allowNil:(BOOL)allowNil;

+ (nullable id<GXBusinessComponentLevelEntityData>)businessComponentLevelEntityDataForOverrideValuesByFieldName:(nullable NSDictionary<NSString *, id> *)overrideValuesByFieldName
																									 entityData:(nullable id<GXEntityData>)entityData
																									 allowMerge:(BOOL)allowMerge
																									   allowNil:(BOOL)allowNil;

+ (nullable id<GXBusinessComponentLevelEntityData, GXEntityDataWithOverrideValues>)businessComponentLevelEntityDataWithOverrideValuesForOverrideValuesByFieldName:(nullable NSDictionary<NSString *, id> *)overrideValuesByFieldName
																																					   entityData:(nullable id<GXEntityData>)entityData
																																					   allowMerge:(BOOL)allowMerge
																																						 allowNil:(BOOL)allowNil;
@end

/**
 * In this subclass, when a mutable entity wrapper is created in class constructor methods,
 * it returns YES to entityDataNew.
 */
@interface GXNewEntityDataWithOverrideValues : GXEntityDataWithOverrideValues
@end


@interface GXMutableEntityDataWithOverrideValues : GXEntityDataWithOverrideValues <GXMutableEntityData>
@end


@interface GXBusinessComponentLevelEntityDataWithOverrideValues : GXMutableEntityDataWithOverrideValues <GXBusinessComponentLevelEntityData>
@end
