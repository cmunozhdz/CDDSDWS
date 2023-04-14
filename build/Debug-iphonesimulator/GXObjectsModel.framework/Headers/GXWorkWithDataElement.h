//
//  GXWorkWithDataElement.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 10/12/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXDescriptionModelObjectChild.h>
#import <GXObjectsModel/GXEntityDataFieldDescriptorProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@class GXTypedObjectInfo;

typedef NS_ENUM(uint_least8_t, GXWorkWithDataElementType) {
	GXWorkWithDataElementTypeAttribute,
	GXWorkWithDataElementTypeVariable
};

@interface GXWorkWithDataElement : GXDescriptionModelObjectChild <GXEntityDataFieldDescriptor>

@property(assign, readonly) GXWorkWithDataElementType type;

@end

#pragma mark -

@interface GXWorkWithDataElementAttribute : GXWorkWithDataElement <GXEntityDataFieldAttributeDescriptor>

@property(assign, readonly) BOOL isKey;

- (instancetype)initWithName:(NSString *)name
				 description:(nullable NSString *)desc
					   isKey:(BOOL)isKey
			  forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithName:(nullable NSString *)name
				 description:(nullable NSString *)desc
			  forModelObject:(nullable id<GXModelObject>)modelObject NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

#pragma mark -

@interface GXWorkWithDataElementVariable : GXWorkWithDataElement <GXEntityDataFieldVariableDescriptor>

@property(nonatomic, strong, readonly) GXTypedObjectInfo *typedObjectInfo;

- (instancetype)initWithTypedObjectInfo:(GXTypedObjectInfo *)typedObjectInfo
						 forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithName:(nullable NSString *)name
				 description:(nullable NSString *)desc
			  forModelObject:(nullable id<GXModelObject>)modelObject NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
