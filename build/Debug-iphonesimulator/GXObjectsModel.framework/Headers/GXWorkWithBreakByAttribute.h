//
//  GXWorkWithBreakByAttribute.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 27/01/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXNamedModelObjectChild.h>
#import <GXObjectsModel/GXEntityListBreakByProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@class GXTypedObjectInfo;

@interface GXWorkWithBreakByField : GXNamedModelObjectChild <GXEntityListBreakByField>

@property(nonatomic, strong, readonly) NSString *name;

@end

@interface GXWorkWithBreakByFieldAttribute : GXWorkWithBreakByField <GXEntityDataFieldAttributeDescriptor>
@end

@interface GXWorkWithBreakByFieldVariable : GXWorkWithBreakByField <GXEntityDataFieldVariableDescriptor>

@property(nonatomic, strong, readonly) GXTypedObjectInfo *typedObjectInfo;

- (instancetype)initWithTypedObjectInfo:(GXTypedObjectInfo *)typedObjectInfo
						 forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithName:(nullable NSString *)name forModelObject:(nullable id<GXModelObject>)modelObject NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
