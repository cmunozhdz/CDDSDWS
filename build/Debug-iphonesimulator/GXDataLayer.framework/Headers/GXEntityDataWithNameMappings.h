//
//  GXEntityDataWithNameMappings.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 09/05/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@interface GXEntityDataWithNameMappings : NSObject <GXEntityData>

- (instancetype)init NS_UNAVAILABLE;

@property(nonatomic, strong, readonly) NSDictionary<NSString *, NSString *> *fieldNamesMapping;
@property(nonatomic, strong, readonly) id <GXEntityData> innerEntityData;

+ (nullable id<GXEntityData>)entityDataWithFieldNamesMappings:(nullable NSDictionary<NSString *, NSString *> *)fieldNamesMapping
												   entityData:(nullable id<GXEntityData>)entityData
													 allowNil:(BOOL)allowNil;

// Same as allowNil:YES
+ (nullable id<GXEntityData>)entityDataWithFieldNamesMappings:(nullable NSDictionary<NSString *, NSString *> *)fieldNamesMapping
												   entityData:(nullable id<GXEntityData>)entityData;

@end


@interface GXEntityDataWithNameMappingsOverrideValues : GXEntityDataWithNameMappings <GXEntityDataWithOverrideValues>
@end


@interface GXMutableEntityDataWithNameMappings : GXEntityDataWithNameMappings <GXMutableEntityData>
@end


@interface GXMutableEntityDataWithNameMappingsOverrideValues : GXEntityDataWithNameMappingsOverrideValues <GXMutableEntityData>
@end


@interface GXBusinessComponentLevelEntityDataWithNameMappings : GXMutableEntityDataWithNameMappings <GXBusinessComponentLevelEntityData>
@end


@interface GXBusinessComponentLevelEntityDataWithNameMappingsOverrideValues : GXMutableEntityDataWithNameMappingsOverrideValues <GXBusinessComponentLevelEntityData>
@end

NS_ASSUME_NONNULL_END
