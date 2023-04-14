//
//  GXProcedureParameter.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 08/03/11.
//  Copyright 2011 Artech. All rights reserved.
//


@import Foundation;
@import GXFoundation;
#import <GXObjectsModel/GXNamedModelObjectChild.h>
#import <GXObjectsModel/GXParametersDescriptorProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@class GXTypedObjectInfo;

@interface GXProcedureParameter : GXNamedModelObjectChild <GXParameterDescriptor> // Abstract

@property(nonnull, nonatomic, strong, readonly) NSString *name;

- (instancetype)initWithName:(nullable NSString *)name forModelObject:(nullable id<GXModelObject>)modelObject NS_UNAVAILABLE;

@end


@interface GXProcedureParameterAttribute : GXProcedureParameter <GXEntityDataFieldAttributeDescriptor>
@end


@interface GXProcedureParameterVariable : GXProcedureParameter <GXEntityDataFieldVariableDescriptor>

@property(nonatomic, strong, readonly) GXTypedObjectInfo *typedObject;

@end


@interface GXProcedureParameterVariableOldMetadataFormat : GXProcedureParameter <GXEntityDataFieldVariableDescriptor, GXEntityDataFieldInfo>
@end

NS_ASSUME_NONNULL_END
