//
//  GXBusinessComponentAttribute.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 16/12/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXEntityDataFieldDescriptorProtocol.h>
#import <GXObjectsModel/GXParametersDescriptorProtocol.h>
#import <GXObjectsModel/GXModelObjectProtocol.h>

NS_ASSUME_NONNULL_BEGIN

#define kBusinessComponentAttributeKeyKey @"k"
#define kBusinessComponentAttributeReadOnlyKey @"ro"
#define kBusinessComponentAttributeAllowNullsKey @"null"

@interface GXBusinessComponentAttribute : NSObject <GXEntityDataFieldAttributeDescriptor, GXParameterDescriptor, GXModelObject, NSCoding>

@property(nonatomic, strong, readonly) NSString *name;
@property(nonatomic, assign, readonly, getter=isKey) BOOL key;
@property(nonatomic, assign, readonly, getter=isReadOnly) BOOL readOnly;
@property(nonatomic, assign, readonly) BOOL allowsNulls;

- (instancetype)initWithAttributeInfo:(GXAttributeInfo *)attributeInfo
						   properties:(nullable NSDictionary<NSString *, id> *)properties NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
