//
//  GXActionParametersDescriptorProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 20/11/15.
//  Copyright © 2015 Artech. All rights reserved.
//

@import Foundation;
@import GXFoundation;
#import <GXObjectsModel/GXEntityDataFieldInfoProtocol.h>
#import <GXObjectsModel/GXExpressionProtocol.h>
#import <GXObjectsModel/GXParametersDescriptorProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXExpression;

typedef NS_ENUM(uint_least8_t, GXActionParameterType) {
	GXActionParameterTypeAttribute,
	GXActionParameterTypeVariable,
	GXActionParameterTypeConstant,
	GXActionParameterTypeExpression,
};

#pragma mark -

@protocol GXActionParameterDescriptor <NSObject>

@property(nonatomic, assign, readonly) GXActionParameterType actionParameterType;
@property(nullable, nonatomic, strong, readonly) id<GXEntityDataFieldInfo> actionParameterFieldInfo;

/*!
 Called Target Parameter Name

 @discussion This value refers to the called target parameter name, it's used for calls when matching between the caller action parameter and called target parameter is made by name, instead of by position, i.e. BC calls, this value can be nil when in otherwise.
 */
@property(nullable, nonatomic, strong, readonly) NSString *actionParameterCalledTargetParameterName;

@end

#pragma mark -

@protocol GXActionParameterDescriptorConstant <GXActionParameterDescriptor>

@property(nullable, nonatomic, strong, readonly) id actionParameterConstantValue;

@end

#pragma mark -

@protocol GXActionParameterDescriptorExpression <GXActionParameterDescriptor>

@property(nonatomic, strong, readonly) id<GXExpression> actionParameterExpression;

@end

#pragma mark -

@protocol GXActionParameterDescriptorField <GXActionParameterDescriptor>

@property(nonatomic, strong, readonly) NSString *actionParameterFieldName;
@property(nonatomic, strong, readonly) id<GXEntityDataFieldDescriptor> actionParameterFieldDescriptor;

@end

#pragma mark -

@protocol GXActionParameterDescriptorVariable <GXActionParameterDescriptorField>

@property(nullable, nonatomic, strong, readonly) NSString *actionParameterVariableFieldSpecifier;
- (nullable id<GXEntityDataFieldInfo>)actionParameterResolvedFieldInfo;

@end

#pragma mark -

@protocol GXActionParametersDescriptor <NSObject>

@property(nonatomic, strong, readonly) NSArray<id<GXActionParameterDescriptor>> *actionParametersDescriptors;

@end

NS_ASSUME_NONNULL_END
