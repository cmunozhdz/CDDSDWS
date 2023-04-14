//
//  GXWorkWithParameter.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 14/12/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXNamedModelObjectChild.h>
#import <GXObjectsModel/GXParametersDescriptorProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@class GXTypedObjectInfo;

typedef NS_ENUM(uint_least8_t, GXWorkWithParameterType) {
	GXWorkWithParameterTypeAttribute,
	GXWorkWithParameterTypeVariable
};

@interface GXWorkWithParameter : GXNamedModelObjectChild <GXParameterDescriptor>

@property(nonnull, nonatomic, strong, readonly) NSString *name;
@property(assign, readonly) GXWorkWithParameterType type;
@property(assign, readonly) BOOL nullValue;

- (instancetype)initWithName:(NSString *)name
				   paramName:(nullable NSString *)paramName
				   paramKind:(GXParameterKind)kind
				   nullValue:(BOOL)nullValue
			  forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithName:(nullable NSString *)name forModelObject:(nullable id<GXModelObject>)modelObject NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

@interface GXWorkWithParameterAttribute : GXWorkWithParameter <GXEntityDataFieldAttributeDescriptor>
@end

@interface GXWorkWithParameterVariable : GXWorkWithParameter <GXEntityDataFieldVariableDescriptor>

@property(nonatomic, strong, readonly) GXTypedObjectInfo *typedObjectInfo;

- (instancetype)initWithTypedObjectInfo:(GXTypedObjectInfo *)typedObjectInfo
							  paramName:(nullable NSString *)paramName
							  paramKind:(GXParameterKind)kind
							  nullValue:(BOOL)nullValue
						 forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithName:(NSString *)name
				   paramName:(nullable NSString *)paramName
				   paramKind:(GXParameterKind)kind
				   nullValue:(BOOL)nullValue
			  forModelObject:(nullable id<GXModelObject>)modelObject NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
