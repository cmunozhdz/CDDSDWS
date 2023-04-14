//
//  GXEntityDataWrapper.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 15/02/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@interface GXEntityDataWrapper : NSObject <GXEntityData>

@property(nonatomic, strong, readonly) id <GXEntityData> innerEntityData;

+ (id<GXEntityData>)entityDataFromEntityData:(nullable id<GXEntityData>)entityData
						   requiredProtocols:(GXEntityDataProtocolsFlags)requiredProtocols;

+ (id<GXEntityDataWithOverrideValues>)entityDataWithOverrideValuesFromEntityData:(nullable id<GXEntityData>)entityData;
+ (id<GXMutableEntityData>)mutableEntityDataFromEntityData:(nullable id<GXEntityData>)entityData;
+ (id<GXMutableEntityData, GXEntityDataWithOverrideValues>)mutableEntityDataWithOverrideValuesFromEntityData:(nullable id<GXEntityData>)entityData;
+ (id<GXBusinessComponentLevelEntityData>)businessComponentLevelEntityDataFromEntityData:(nullable id<GXEntityData>)entityData;
+ (id<GXBusinessComponentLevelEntityData, GXEntityDataWithOverrideValues>)businessComponentLevelEntityDataWithOverrideValuesFromEntityData:(nullable id<GXEntityData>)entityData;

@end

/**
 * In this subclass, when a mutable entity wrapper is created in class constructor methods,
 * it returns YES to entityDataNew.
 */
@interface GXNewEntityDataWrapper : GXEntityDataWrapper
@end


@interface GXEntityDataWithOverrideValuesWrapper : GXEntityDataWrapper <GXEntityDataWithOverrideValues>
@end

@interface GXMutableEntityDataWrapper : GXEntityDataWrapper <GXMutableEntityData>
@end

@interface GXMutableEntityDataWithOverrideValuesWrapper : GXEntityDataWithOverrideValuesWrapper <GXMutableEntityData>
@end

@interface GXBusinessComponentLevelEntityDataWrapper : GXMutableEntityDataWrapper <GXBusinessComponentLevelEntityData>
@end

@interface GXBusinessComponentLevelEntityDataWithOverrideValuesWrapper : GXMutableEntityDataWithOverrideValuesWrapper <GXBusinessComponentLevelEntityData>
@end


// New variants returns YES to entityDataNew
@interface GXNewMutableEntityDataWrapper : GXMutableEntityDataWrapper
@end

@interface GXNewMutableEntityDataWithOverrideValuesWrapper : GXMutableEntityDataWithOverrideValuesWrapper
@end

@interface GXNewBusinessComponentLevelEntityDataWrapper : GXBusinessComponentLevelEntityDataWrapper
@end

@interface GXNewBusinessComponentLevelEntityDataWithOverrideValuesWrapper : GXBusinessComponentLevelEntityDataWithOverrideValuesWrapper
@end

NS_ASSUME_NONNULL_END
