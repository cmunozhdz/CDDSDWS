//
//  GXEntityDataWithFieldResolver.h
//  GXFlexibleClient
//
//  Created by willy on 8/19/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@interface GXEntityDataWithFieldResolver : NSObject <GXEntityData>

- (instancetype)init NS_UNAVAILABLE;

@property(nonatomic, strong, readonly) id <GXEntityData> innerEntityData;
@property(nonatomic, strong, readonly) id <GXEntityDataDescriptor> entityDataDescriptor;
@property(nullable, nonatomic, strong, readonly) NSArray<NSNumber *> *indexer;

+ (nullable id<GXEntityData>)entityDataWithEntityData:(nullable id<GXEntityData>)entityData
								 entityDataDescriptor:(nullable id<GXEntityDataDescriptor>)entityDataDescriptor
										 indexerStack:(nullable NSArray<NSNumber *> *)indexer;

@end



@interface GXEntityDataWithFieldResolverOverrideValues : GXEntityDataWithFieldResolver <GXEntityDataWithOverrideValues>
@end


@interface GXMutableEntityDataWithFieldResolver : GXEntityDataWithFieldResolver <GXMutableEntityData>
@end


@interface GXMutableEntityDataWithFieldResolverOverrideValues : GXEntityDataWithFieldResolverOverrideValues <GXMutableEntityData>
@end


@interface GXBusinessComponentLevelEntityDataWithFieldResolver : GXMutableEntityDataWithFieldResolver <GXBusinessComponentLevelEntityData>
@end


@interface GXBusinessComponentLevelEntityDataWithFieldResolverOverrideValues : GXMutableEntityDataWithFieldResolverOverrideValues <GXBusinessComponentLevelEntityData>
@end

NS_ASSUME_NONNULL_END
