//
//  GXWorkWithParameters.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 10/12/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXWorkWithParameter.h>
#import <GXObjectsModel/GXParametersDescriptorProtocol.h>
#import <GXObjectsModel/GXEntityDataKeyDescriptorProtocol.h>
#import <GXObjectsModel/GXModelObjectChild.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXWorkWithParameters : GXModelObjectChild <GXParametersDescriptor, GXEntityDataKeyDescriptor>

@property(nonatomic, strong, readonly) NSArray<__kindof GXWorkWithParameter *> *parameters;
@property(nonatomic, strong, readonly) NSDictionary<NSString *, __kindof GXWorkWithParameter *> *parametersByFieldName;

- (instancetype)initWithParameters:(NSArray<__kindof GXWorkWithParameter *> *)parameters
					forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithModelObject:(nullable id<GXModelObject>)modelObject NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;


@end

NS_ASSUME_NONNULL_END
