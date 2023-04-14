//
//  GXWorkWithDataBase.h
//  GXObjectsModel
//
//  Created by Fabian Inthamoussu on 11/5/18.
//  Copyright © 2018 GeneXus. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXEntityDataDescriptorProtocol.h>
#import <GXObjectsModel/GXEntityDataKeyDescriptorProtocol.h>
#import <GXObjectsModel/GXModelObjectChild.h>
#import <GXObjectsModel/GXWorkWithDataElement.h>

NS_ASSUME_NONNULL_BEGIN

@class GXWorkWithDataSublevel;

@interface GXWorkWithDataBase : GXModelObjectChild <GXEntityDataDescriptor, GXEntityDataKeyDescriptor>

@property(nonatomic, strong, readonly) NSArray<__kindof GXWorkWithDataElement *> *elements;
@property(nonatomic, strong, readonly) NSArray<__kindof GXWorkWithDataElement *> *keyElements;
@property(nonatomic, strong, readonly) NSArray<__kindof GXWorkWithDataElement *> *storageKeyElements;
@property(nonatomic, strong, readonly) NSDictionary<NSString *, __kindof GXWorkWithDataElement *> *elementsByName;
@property(nonatomic, assign, readonly) BOOL isCollection; // Abstract
@property(nullable, nonatomic, strong, readonly) NSString *level;
@property(nonatomic, strong, readonly) NSArray<GXWorkWithDataSublevel *> *sublevels;

- (instancetype)initWithElements:(nullable NSArray<__kindof GXWorkWithDataElement *> *)elements
						   level:(nullable NSString *)level
					   sublevels:(nullable NSArray<GXWorkWithDataSublevel *> *)sublevels
				  forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithModelObject:(nullable id<GXModelObject>)modelObject NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
