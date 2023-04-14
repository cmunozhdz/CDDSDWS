//
//  GXWorkWithRules.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 2/25/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXEntityDataFieldDescriptorProtocol.h>
#import <GXObjectsModel/GXWorkWithRule.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXWorkWithRules : GXModelObjectChild

@property(nonatomic, strong, readonly) NSArray<__kindof GXWorkWithRule *> *rules;

- (instancetype)initWithRules:(nullable NSArray<__kindof GXWorkWithRule *> *)rules
			   forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

+ (nullable instancetype)workWithRulesFromMetadata:(nullable NSDictionary<NSString *, id> *)metadata
									  dataElements:(nullable NSDictionary<NSString *, id<GXEntityDataFieldDescriptor>> *)dataElementsByName
									forModelObject:(nullable id<GXModelObject>)modelObject
											 error:(out NSError * __autoreleasing __nullable * __nullable)error;

@end

NS_ASSUME_NONNULL_END
