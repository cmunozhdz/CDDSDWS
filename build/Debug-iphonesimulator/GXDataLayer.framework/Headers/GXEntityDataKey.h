//
//  GXEntityDataKey.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 18/01/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@interface GXEntityDataKey : NSObject <GXEntityDataKey> {
	id<GXEntityDataKeyDescriptor> _descriptor;
	NSDictionary<NSString *, id> *_values;
}

- (instancetype)initWithEntityDataKeyDescriptor:(id<GXEntityDataKeyDescriptor>)descriptor
							 entityDataFieldKey:(NSDictionary<NSString *, id> *)values NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

+ (__kindof GXEntityDataKey *)entityDataKeyWithEntityDataKeyDescriptor:(id<GXEntityDataKeyDescriptor>)descriptor
													entityDataFieldKey:(NSDictionary<NSString *, id> *)values;

+ (__kindof GXEntityDataKey *)entityDataKeyWithEntityDataKeyDescriptor:(id<GXEntityDataKeyDescriptor>)descriptor
															entityData:(id<GXEntityData>)entityData;

@end

@interface GXEntityDataKeyWithParent : GXEntityDataKey {
	id <GXEntityDataKey> _parentKey;
}

- (instancetype)initWithEntityDataKeyDescriptor:(id <GXEntityDataKeyDescriptor>)descriptor
				   entityDataFieldKey:(NSDictionary<NSString *, id> *)values
					  parentEntityKey:(id <GXEntityDataKey>)parentKey NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithEntityDataKeyDescriptor:(id<GXEntityDataKeyDescriptor>)descriptor
							 entityDataFieldKey:(NSDictionary<NSString *, id> *)values NS_UNAVAILABLE;


@end

NS_ASSUME_NONNULL_END
