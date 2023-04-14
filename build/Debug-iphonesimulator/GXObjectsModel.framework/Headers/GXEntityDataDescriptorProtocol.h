//
//  GXEntityDataDescriptor.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 16/12/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXEntityDataFieldDescriptorProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXEntityDataDescriptor <NSObject>

@property(nonatomic, strong, readonly) NSArray<id<GXEntityDataFieldDescriptor>> *entityDataFieldDescriptors;

- (nullable id <GXEntityDataFieldDescriptor>)entityDataFieldDescriptorForName:(NSString *)fieldName;

@end

NS_ASSUME_NONNULL_END
