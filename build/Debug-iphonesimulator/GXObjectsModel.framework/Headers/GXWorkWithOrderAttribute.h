//
//  GXWorkWithOrderField.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 10/12/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXDescriptionModelObjectChild.h>
#import <GXObjectsModel/GXEntityListOrderProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@class GXTypedObjectInfo;

@interface GXWorkWithOrderField : GXDescriptionModelObjectChild <GXEntityListOrderField>

@property(assign, readonly) BOOL ascending;
@property(nonatomic, strong, readonly) NSString *name;

- (instancetype)initWithName:(NSString *)name
				 description:(nullable NSString *)desc
				   ascending:(BOOL)ascending
			  forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithName:(nullable NSString *)name
				 description:(nullable NSString *)desc
			  forModelObject:(nullable id<GXModelObject>)modelObject NS_UNAVAILABLE;

@end


@interface GXWorkWithOrderFieldAttribute : GXWorkWithOrderField <GXEntityDataFieldAttributeDescriptor>

@end


@interface GXWorkWithOrderFieldVariable : GXWorkWithOrderField <GXEntityDataFieldVariableDescriptor>

@property(nonatomic, strong, readonly) GXTypedObjectInfo *typedObjectInfo;

- (instancetype)initWithTypedObjectInfo:(GXTypedObjectInfo *)typedObjectInfo
							description:(nullable NSString *)desc
							  ascending:(BOOL)ascending
						 forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithName:(NSString *)name
				 description:(nullable NSString *)desc
				   ascending:(BOOL)ascending
			  forModelObject:(nullable id<GXModelObject>)modelObject NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
