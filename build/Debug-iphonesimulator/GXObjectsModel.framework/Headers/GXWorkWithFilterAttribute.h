//
//  GXWorkWithFilterAttribute.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 10/12/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXDescriptionModelObjectChild.h>
#import <GXObjectsModel/GXEntityListFilterAdvancedProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@class GXTypedObjectInfo;

typedef NS_ENUM(uint_least8_t, GXWorkWithFilterAdvancedAttributeType) {
	GXWorkWithFilterAdvancedAttributeTypeStandard,
	GXWorkWithFilterAdvancedAttributeTypeRange
};

@interface GXWorkWithFilterAdvancedField : GXDescriptionModelObjectChild <GXEntityListFilterAdvancedField>

@property(nonatomic, strong, readonly) NSString *name;
@property(nonatomic, strong, readonly) NSString *desc;
@property(nonatomic, strong, readonly) NSString *descNoTranslation;

@property(assign, readonly) GXWorkWithFilterAdvancedAttributeType type;

@end



@interface GXWorkWithFilterAdvancedFieldStandard : GXWorkWithFilterAdvancedField <GXEntityListFilterAdvancedFieldStandard>

- (instancetype)initWithName:(NSString *)name
				 description:(NSString *)desc
				defaultValue:(nullable id)defaultValue
				   allOption:(BOOL)allOption
			  forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithName:(nullable NSString *)name
				 description:(nullable NSString *)desc
			  forModelObject:(nullable id<GXModelObject>)modelObject NS_UNAVAILABLE;

@end



@interface GXWorkWithFilterAdvancedFieldRange : GXWorkWithFilterAdvancedField <GXEntityListFilterAdvancedFieldRange>

- (instancetype)initWithName:(NSString *)name
				 description:(NSString *)desc
			defaultFromValue:(nullable id)defaultFromValue
			  defaultToValue:(nullable id)defaultToValue
			  forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithName:(nullable NSString *)name
				 description:(nullable NSString *)desc
			  forModelObject:(nullable id<GXModelObject>)modelObject NS_UNAVAILABLE;

@end



@interface GXWorkWithFilterAdvancedFieldAttributeStandard : GXWorkWithFilterAdvancedFieldStandard <GXEntityDataFieldAttributeDescriptor>

@end

@interface GXWorkWithFilterAdvancedFieldVariableStandard : GXWorkWithFilterAdvancedFieldStandard <GXEntityDataFieldVariableDescriptor>

@property(nonatomic, strong, readonly) GXTypedObjectInfo *typedObjectInfo;

- (instancetype)initWithTypedObjectInfo:(GXTypedObjectInfo *)typedObjectInfo
							description:(NSString *)desc
						   defaultValue:(nullable id)defaultValue
							  allOption:(BOOL)allOption
						 forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithName:(NSString *)name
				 description:(NSString *)desc
				defaultValue:(nullable id)defaultValue
				   allOption:(BOOL)allOption
			  forModelObject:(nullable id<GXModelObject>)modelObject NS_UNAVAILABLE;

@end



@interface GXWorkWithFilterAdvancedFieldAttributeRange : GXWorkWithFilterAdvancedFieldRange <GXEntityDataFieldAttributeDescriptor>

@end

@interface GXWorkWithFilterAdvancedFieldVariableRange : GXWorkWithFilterAdvancedFieldRange <GXEntityDataFieldVariableDescriptor>

@property(nonatomic, strong, readonly) GXTypedObjectInfo *typedObjectInfo;

- (instancetype)initWithTypedObjectInfo:(GXTypedObjectInfo *)typedObjectInfo
							description:(NSString *)desc
					   defaultFromValue:(nullable id)defaultFromValue
						 defaultToValue:(nullable id)defaultToValue
						 forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithName:(NSString *)name
				 description:(NSString *)desc
			defaultFromValue:(nullable id)defaultFromValue
			  defaultToValue:(nullable id)defaultToValue
			  forModelObject:(nullable id<GXModelObject>)modelObject NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
