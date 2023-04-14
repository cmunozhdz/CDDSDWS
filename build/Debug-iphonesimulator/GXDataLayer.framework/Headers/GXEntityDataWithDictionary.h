//
//  GXEntityDataWithDictionary.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 07/02/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@interface GXEntityDataWithDictionary : NSObject <GXEntityData>

+ (nullable id <GXEntityData>)entityDataWithFieldValuesByName:(nullable NSDictionary *)fieldValuesByName
												   descriptor:(nullable id<GXEntityDataDescriptor>)descriptor
													 allowNil:(BOOL)allowNil;

+ (nullable id <GXEntityData>)entityDataWithFieldValuesByName:(nullable NSDictionary *)fieldValuesByName
												   descriptor:(nullable id<GXEntityDataDescriptor>)descriptor;

+ (nullable id <GXEntityData>)entityDataWithFieldValuesByName:(nullable NSDictionary *)fieldValuesByName;

@property(nullable, nonatomic, strong, readonly) id <GXEntityDataDescriptor> entityDataDescriptor;

@end

NS_ASSUME_NONNULL_END
