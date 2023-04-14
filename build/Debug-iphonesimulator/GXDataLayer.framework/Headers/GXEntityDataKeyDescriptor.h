//
//  GXEntityDataKeyDescriptor.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 18/01/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@interface GXEntityDataKeyDescriptor : NSObject <GXEntityDataKeyDescriptor>

- (instancetype)initWithEntityDataKeyFieldsDescriptors:(NSArray<id <GXEntityDataFieldDescriptor>> *)keyFieldsDescriptors NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

@end

@interface GXEntityDataKeyDescriptorWithParent : GXEntityDataKeyDescriptor

- (instancetype)initWithEntityDataKeyFieldsDescriptors:(NSArray<id <GXEntityDataFieldDescriptor>> *)keyFieldsDescriptors
						  parenEntityDataKeyDescriptor:(id <GXEntityDataKeyDescriptor>)parentKeyDescriptor NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithEntityDataKeyFieldsDescriptors:(NSArray<id <GXEntityDataFieldDescriptor>> *)keyFieldsDescriptors NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
