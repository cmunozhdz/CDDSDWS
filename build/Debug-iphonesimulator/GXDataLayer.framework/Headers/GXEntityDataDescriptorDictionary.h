//
//  GXEntityDataDescriptorDictionary.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 24/02/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@interface GXEntityDataDescriptorDictionary : NSObject <GXEntityDataDescriptor>

- (instancetype)initWithDictionary:(nullable NSDictionary<NSString *, id<GXEntityDataFieldDescriptor>> *)fieldsDescriptorsByName NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithArray:(nullable NSArray<id<GXEntityDataFieldDescriptor>> *)fieldsDescriptors;

@end

NS_ASSUME_NONNULL_END
