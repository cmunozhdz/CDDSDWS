//
//  GXWorkWithOrder.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 10/12/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXNamedModelObjectChild.h>
#import <GXObjectsModel/GXEntityListOrderProtocol.h>
#import <GXObjectsModel/GXWorkWithOrderAttribute.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXWorkWithOrder : GXNamedModelObjectChild <GXEntityListOrder>

@property(nonatomic, strong, readonly) NSString *name;
@property(nonatomic, strong, readonly) NSArray<__kindof GXWorkWithOrderField *> *fields;
@property(nonatomic, assign, readonly) BOOL alphaIndexerEnabled;

- (instancetype)initWithName:(NSString *)name
					  fields:(NSArray<__kindof GXWorkWithOrderField *> *)fields
				alphaIndexer:(BOOL)alphaIndexerEnabled
			  forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithName:(nullable NSString *)name forModelObject:(nullable id<GXModelObject>)modelObject NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

@interface GXWorkWithGroupedOrder : GXWorkWithOrder

@property(nonatomic, assign, readonly) NSUInteger groupByUpToIndex;
@property(nullable, nonatomic, strong, readonly) id <GXEntityDataFieldDescriptor> groupByDescriptionField;

- (instancetype)initWithName:(NSString *)name
					  fields:(NSArray<__kindof GXWorkWithOrderField *> *)fields
				alphaIndexer:(BOOL)alphaIndexerEnabled
			groupByDescField:(nullable id <GXEntityDataFieldDescriptor>)descField
			  forModelObject:(nullable id<GXModelObject>)modelObject;

- (instancetype)initWithName:(NSString *)name
					  fields:(NSArray<__kindof GXWorkWithOrderField *> *)fields
				alphaIndexer:(BOOL)alphaIndexerEnabled
			groupByDescField:(nullable id <GXEntityDataFieldDescriptor>)descField
			groupByUpToIndex:(NSUInteger)upToIndex
			  forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
