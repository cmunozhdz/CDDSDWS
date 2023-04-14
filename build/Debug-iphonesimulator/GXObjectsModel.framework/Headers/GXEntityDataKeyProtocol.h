//
//  GXEntityDataKeyProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 18/01/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXEntityDataKeyDescriptorProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXEntityDataKey <NSObject>

@property(nonatomic, strong, readonly) id <GXEntityDataKeyDescriptor> entityDataKeyDescriptor;

- (nullable id)valueForEntityDataKeyFieldName:(NSString *)name;
- (nullable id <GXEntityDataKey>)parentEntityDataKey;

- (NSArray *)allKeyValuesWithEmptyForNulls;

@end

NS_ASSUME_NONNULL_END
