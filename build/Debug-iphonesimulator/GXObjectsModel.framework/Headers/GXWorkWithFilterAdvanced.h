//
//  GXWorkWithFilterAdvanced.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 10/12/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXWorkWithFilterAttribute.h>
#import <GXObjectsModel/GXEntityListFilterAdvancedProtocol.h>
#import <GXObjectsModel/GXModelObjectChild.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXWorkWithFilterAdvanced : GXModelObjectChild <GXEntityListFilterAdvanced>

- (instancetype)initWithFields:(NSArray<id<GXEntityListFilterAdvancedField>> *)fields
				forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithModelObject:(nullable id<GXModelObject>)modelObject NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
