//
//  GXWorkWithRulePrompt.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 2/25/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXWorkWithRule.h>
#import <GXObjectsModel/GXEntityDataFieldDescriptorProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXWorkWithRulePrompt : GXWorkWithRule

- (instancetype)initWithModelObject:(nullable id<GXModelObject>)modelObject NS_UNAVAILABLE;

+ (nullable instancetype)workWithRulePromptFromMetadata:(nullable NSDictionary<NSString *, id> *)metadata
										   dataElements:(nullable NSDictionary<NSString *, id<GXEntityDataFieldDescriptor>> *)dataElementsByName
										 forModelObject:(nullable id<GXModelObject>)modelObject
												  error:(out NSError * __autoreleasing __nullable * __nullable)error;

/// #deprecated: 2022-01-11: trunk; #to-remove: ??
+ (nullable instancetype)workWithRulePromptFromMetadata:(nullable NSDictionary<NSString *, id> *)metadata
										   dataElements:(nullable NSDictionary<NSString *, id<GXEntityDataFieldDescriptor>> *)dataElementsByName
												  error:(out NSError * __autoreleasing __nullable * __nullable)error __attribute__((deprecated("Use workWithRulePromptFromMetadata:dataElements:forModelObject:error: instead")));

@end

NS_ASSUME_NONNULL_END
