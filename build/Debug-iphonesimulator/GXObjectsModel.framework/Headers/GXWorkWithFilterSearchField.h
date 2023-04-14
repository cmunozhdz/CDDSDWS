//
//  GXWorkWithFilterSearchField.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 22/11/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXDescriptionModelObjectChild.h>
#import <GXObjectsModel/GXEntityListFilterSearchProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@class GXTypedObjectInfo;

@interface GXWorkWithFilterSearchField : GXDescriptionModelObjectChild <GXEntityListFilterSearchField>

@property(nonatomic, strong, readonly) NSString *name;
@property(nonatomic, strong, readonly) NSString *desc;
@property(nonatomic, strong, readonly) NSString *descNoTranslation;

@end


@interface GXWorkWithFilterSearchFieldAttribute : GXWorkWithFilterSearchField <GXEntityDataFieldAttributeDescriptor>
@end


@interface GXWorkWithFilterSearchFieldVariable : GXWorkWithFilterSearchField <GXEntityDataFieldVariableDescriptor>

@property(nonatomic, strong, readonly) GXTypedObjectInfo *typedObjectInfo;

- (instancetype)initWithTypedObjectInfo:(GXTypedObjectInfo *)typedObjectInfo
							description:(NSString *)desc
						 forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithName:(nullable NSString *)name
				 description:(nullable NSString *)desc
			  forModelObject:(nullable id<GXModelObject>)modelObject NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
