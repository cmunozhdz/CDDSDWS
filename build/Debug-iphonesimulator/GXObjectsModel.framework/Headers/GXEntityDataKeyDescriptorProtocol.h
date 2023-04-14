//
//  GXEntityDataKeyDescriptorProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 18/01/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXEntityDataFieldDescriptorProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXEntityDataKeyDescriptor <NSObject>

@property(nonatomic, strong, readonly) NSArray<id <GXEntityDataFieldDescriptor>> *entityDataKeyFieldsDescriptors;
@property(nullable, nonatomic, strong, readonly) id <GXEntityDataKeyDescriptor> parentEntityDataKeyDescriptor;

@end

NS_ASSUME_NONNULL_END
