//
//  GXParametersDescriptorProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 28/02/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import Foundation;
@import GXFoundation;
#import <GXObjectsModel/GXEntityDataDescriptorProtocol.h>
#import <GXObjectsModel/GXEntityDataFieldDescriptorProtocol.h>

@protocol GXEntityDataFieldDescriptor;
@protocol GXEntityDataDescriptor;

@protocol GXParameterDescriptor <GXEntityDataFieldDescriptor>

@property(nonatomic, strong, readonly) NSString *parameterName;
@property(nonatomic, assign, readonly) GXParameterKind parameterKind;

@end

@protocol GXParametersDescriptor <GXEntityDataDescriptor>
// implementation of GXParametersDescriptor->entityDataFieldDescriptors must return NSArray of id<GXParameterDescriptor>
- (id <GXParameterDescriptor>)parameterDescriptorForFieldName:(NSString *)fieldName;

@end
