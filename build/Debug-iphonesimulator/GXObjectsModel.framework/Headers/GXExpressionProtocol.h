//
//  GXExpressionProtocol.h
//  GXFlexibleClient
//
//  Created by willy on 2/4/14.
//  Copyright (c) 2014 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXActionParametersDescriptorProtocol.h>
#import <GXObjectsModel/GXEntityDataFieldInfoProtocol.h>
#import <GXObjectsModel/GXEntityDataProtocol.h>
#import <GXObjectsModel/GXModelObjectProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXActionHandlerContext;
@protocol GXActionParametersDescriptor;

typedef NS_ENUM(uint_least8_t, GXExpressionType) {
	GXExpressionTypeFunction,
	GXExpressionTypeMethod,
	GXExpressionTypeProperty,
	GXExpressionTypeLogic,
	GXExpressionTypeNumber,
	GXExpressionTypeDate,
	GXExpressionTypeBoolean,
	GXExpressionTypeString,
	GXExpressionTypeAttribute,
	GXExpressionTypeVariable,
	GXExpressionTypeArithmetic,
	GXExpressionTypeControl,
	GXExpressionTypeDataType,
	GXExpressionTypeConstructor,
	GXExpressionTypeGXObject,
	GXExpressionTypeImage,
	GXExpressionTypeDomain,
	GXExpressionTypeCollection,
	GXExpressionTypeGXObjectLink,
	GXExpressionTypeStyleClass
};

#define GXExpressionType_UNDEFINED ((GXExpressionType)UINT_LEAST8_MAX)

GXExpressionType GXExpressionTypeFromString(NSString * __nullable exprTypeStr) NS_REFINED_FOR_SWIFT;

@protocol GXExpression <GXModelObject, NSObject>

@property(assign, readonly) GXExpressionType expressionType;

- (nullable id<GXEntityDataFieldInfo>)expressionDataFieldInfo;

@end

@protocol GXExpressionWithRootTargetResolver <GXExpression>

- (BOOL)expressionTryResolveRootTargetExpression:(out id<GXExpression> __nullable * __nonnull)rootTargetExpression;

@end

@protocol GXExpressionWithFieldSpecifierResolver <GXExpressionWithRootTargetResolver>

- (BOOL)expressionTryResolveInvariantFieldSpecifier:(out NSString * __nullable * __nonnull)fieldSpecifier;

@end


@protocol GXExpressionConstant <GXExpression> // expressionType == GXExpressionType(Number|Date|Boolean)

@property(strong, readonly) id expressionConstantValue;

@end

@protocol GXExpressionString <GXExpressionConstant> // expressionType == GXExpressionTypeString

@property(strong, readonly) NSString *expressionConstantValueString; // without translation applied
@property(assign, readonly) BOOL expressionTranslatable;

@end

@protocol GXExpressionWithParameters <GXExpression>

@property(nullable, nonatomic, strong, readonly) id <GXActionParametersDescriptor> expressionParameters;

@end

@protocol GXExpressionNamedElement <GXExpression>

@property(nonatomic, strong, readonly) NSString *expressionElementName;

@end

@protocol GXExpressionFunction <GXExpressionNamedElement, GXExpressionWithParameters> // expressionType == GXExpressionTypeFunction

@property(nonatomic, strong, readonly) NSString *expressionFunctionName; // Lowercase

@end

@protocol GXExpressionWithTargetExpression <GXExpression>

@property(nonatomic, strong, readonly) id <GXExpression> expressionTargetExpression;

@end

@protocol GXExpressionConstructor <GXExpression>

@property(nonatomic, strong, readonly) NSString *expressionConstructorDataTypeName;
@property(nonatomic, readonly) BOOL expressionConstructorIsCollection;

@end

@protocol GXExpressionMethod <GXExpressionNamedElement, GXExpressionWithParameters, GXExpressionWithTargetExpression> // expressionType == GXExpressionTypeMethod

@property(nonatomic, strong, readonly) NSString *expressionMethodName;

@end

@protocol GXExpressionProperty <GXExpressionNamedElement, GXExpressionWithTargetExpression>  // expressionType == GXExpressionTypeProperty

@property(nonatomic, strong, readonly) NSString *expressionPropertyName;

@end

@protocol GXExpressionControl <GXExpressionNamedElement>  // expressionType == GXExpressionTypeControl

@property(nonatomic, strong, readonly) NSString *expressionControlName;

@end

@protocol  GXExpressionDataType <GXExpression> // expressionType == GXExpressionTypeDataType

@property(strong, readonly) NSString *expressionDataTypeName; // Lowercase

@end

@protocol GXExpressionOperation <GXExpression>  // expressionType == GXExpressionType(Logic|Arithmetic)

@property(nonatomic, strong, readonly) NSString *expressionOperator;
@property(nonatomic, assign, readonly, getter=isExpressionOperationUnary) BOOL expressionOperationUnary;
@property(nullable, nonatomic, strong, readonly) id <GXExpression> expressionLeftTargetExpression; // nullable only if self.expressionOperationUnary = YES
@property(nonatomic, strong, readonly) id <GXExpression> expressionRightTargetExpression;

@end

@protocol GXExpressionWithFieldDescriptor <GXExpressionNamedElement, GXExpression> // expressionType == GXExpressionType(Attribute|Variable)

@property(nonatomic, strong, readonly) NSString *expressionFieldName;
@property(nullable, nonatomic, strong, readonly) id<GXEntityDataFieldDescriptor> expressionFieldDescriptor;

@end

@protocol  GXExpressionGXObject <GXExpressionNamedElement, GXExpressionWithParameters> // expressionType == GXExpressionTypeGXObject

@property(nonatomic, strong, readonly) NSString *expressionObjectName;
@property(nonatomic, assign, readonly) GXObjectType expressionObjectType;

@end

@protocol GXExpressionGXObjectLink <GXExpressionGXObject> // expressionType == GXExpressionTypeGXObjectLink

@end

@protocol GXExpressionImage <GXExpressionNamedElement> // expressionType == GXExpressionTypeImage

@property(nonatomic, strong, readonly) NSString *expressionImageName;

@end

@protocol GXExpressionDomain <GXExpressionNamedElement> // expressionType = GXExpressionTypeDomain

@property(nonatomic, strong, readonly) NSString *expressionDomainName;

@end

@protocol GXExpressionStyleClass <GXExpressionNamedElement> // expressionType = GXExpressionTypeStyleClass

@property(nonatomic, strong, readonly) NSString *expressionStyleClassName;

@end

@protocol GXExpressionCollection <GXExpressionWithParameters> // expressionType = GXExpressionTypeCollection
@end

NS_ASSUME_NONNULL_END
