//
//  GXEntityDataFieldDescriptorProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 16/12/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXEntityDataFieldInfoProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@class GXDomainInfo, GXAttributeInfo;
@protocol GXEntityDataDescriptor;

typedef NS_ENUM(uint_least8_t, GXEntityDataFieldType) {
	GXEntityDataFieldTypeAttribute,
	GXEntityDataFieldTypeVariable,
	GXEntityDataFieldTypeSublevel
};

typedef NS_ENUM(uint_least8_t, GXEntityDataFieldControlType) {
	GXEntityDataFieldControlTypeEdit,
	GXEntityDataFieldControlTypeUserControl
};

@protocol GXEntityDataFieldDescriptor <NSObject>

@property(nonatomic, strong, readonly) NSString *entityDataFieldName;
@property(nonatomic, assign, readonly) GXEntityDataFieldType entityDataFieldType;
@property(nonatomic, strong, readonly) id <GXEntityDataFieldInfo> entityDataFieldInfo;
@property(nullable, nonatomic, assign, readonly) GXDomainInfo *entityDataFieldDomainInfo;

@end

@protocol GXEntityDataFieldAttributeDescriptor <GXEntityDataFieldDescriptor>

@property(nonatomic, strong, readonly) GXAttributeInfo *entityDataFieldAttributeInfo;

@end

@protocol GXEntityDataFieldVariableDescriptor <GXEntityDataFieldDescriptor>

@end

@protocol GXEntityDataFieldSublevelDescriptor <GXEntityDataFieldDescriptor>

@property(nonatomic, strong, readonly) id<GXEntityDataDescriptor> entityDataFieldSublevelDescriptor;

@end

NS_ASSUME_NONNULL_END
