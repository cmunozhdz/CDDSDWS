//
//  GXWorkWithBreakBy.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 27/01/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXEntityListBreakByProtocol.h>
#import <GXObjectsModel/GXWorkWithBreakByAttribute.h>
#import <GXObjectsModel/GXModelObjectChild.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXWorkWithBreakBy : GXModelObjectChild <GXEntityListBreakBy>

+ (nullable instancetype)workWithBreakByFromMetadata:(NSDictionary<NSString *, id> *)metadata
								  dataElementsByName:(nullable NSDictionary<NSString *, id<GXEntityDataFieldDescriptor>> *)dataElementsByName
									  forModelObject:(nullable id<GXModelObject>)modelObject
											   error:(out NSError *__autoreleasing __nullable * __nullable)error;

- (instancetype)initWithBreakByFields:(NSArray<__kindof GXWorkWithBreakByField *> *)fields
					 descriptionField:(nullable __kindof GXWorkWithBreakByField *)descField
					   forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithModelObject:(nullable id<GXModelObject>)modelObject NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
