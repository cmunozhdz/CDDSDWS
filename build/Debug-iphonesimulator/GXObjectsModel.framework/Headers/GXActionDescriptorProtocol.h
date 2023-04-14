//
//  GXActionDescriptorProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 28/02/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import Foundation;
@import GXFoundation;
#import <GXObjectsModel/GXActionParametersDescriptorProtocol.h>
#import <GXObjectsModel/GXEntityDataFieldDescriptorProtocol.h>
#import <GXObjectsModel/GXEventDescriptorProtocol.h>
#import <GXObjectsModel/GXExpressionProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXEventDescriptor;

typedef NS_ENUM(uint_least8_t, GXActionCallObjectType) {
	GXActionCallObjectTypeBusinessComponent,
	GXActionCallObjectTypeProcedure,
	GXActionCallObjectTypeWWSDPattern,
	GXActionCallObjectTypeExternalObject,
	GXActionCallObjectTypeWebPanel,
	GXActionCallObjectTypeMenu,
	GXActionCallObjectTypeDynamicObject,
	GXActionCallObjectTypeDataProvider,
	GXActionCallObjectTypeUnsupported = UINT_LEAST8_MAX - 1
};

typedef NS_ENUM(uint_least8_t, GXActionType) {
	GXActionTypeCallObject = 0,
	GXActionTypeLink,
	GXActionTypeForIn,
	GXActionTypeForEachLine,
	GXActionTypeComposite,
	GXActionTypeUnsupported = UINT_LEAST8_MAX - 1
};

typedef NS_ENUM(uint_least8_t, GXActionBCApplyToType) {
	GXActionBCApplyToTypeAllAttributes,
	GXActionBCApplyToTypeAttribute
};

typedef NS_ENUM(uint_least8_t, GXMultilineActionIterationType) {
	GXMultilineActionIterationAll,
	GXMultilineActionIterationSelection,
};

#pragma mark -

@protocol GXActionDescriptor <GXModelObject, NSObject>

@property(nonatomic, assign, readonly) GXActionType actionType;
@property(nullable, nonatomic, weak, readonly) id <GXActionDescriptor> parentActionDescriptor;

@optional
@property(nullable, nonatomic, strong, readonly) NSArray<id<GXActionDescriptor>> *actionComponentActions;
@property(nullable, nonatomic, strong, readonly) id <GXActionParametersDescriptor> actionParametersDescriptor;

@end

@protocol GXEventActionDescriptor <GXActionDescriptor>

@property(nullable, nonatomic, weak, readonly) id <GXEventDescriptor> actionEventDescriptor;

@end

@protocol GXActionCallObjectDescriptor <GXActionDescriptor>

@property(nonatomic, strong, readonly) NSString *actionCallObjectName;
@property(nonatomic, assign, readonly) GXActionCallObjectType actionCallObjectType;

@end

#pragma mark - Multiline Actions

@protocol GXMultilineActionDescriptor <GXActionDescriptor>

@property(nonatomic, assign, readonly, getter=isActionMultiline) BOOL actionMultiline;
@property(nonatomic, assign, readonly) GXMultilineActionIterationType actionMultilineIterationType;
@property(nullable, nonatomic, strong, readonly) NSString *actionMultilineGridControlName;

@end

#pragma mark -

@protocol GXActionBusinessComponentDescriptor <GXActionCallObjectDescriptor>

@property(nonatomic, assign, readonly) GXModeType actionCallMode;
@property(nonatomic, assign, readonly) BOOL actionBCCallBatch;
@property(nonatomic, assign, readonly) GXActionBCApplyToType actionBCApplyToType;
@property(nullable, nonatomic, strong, readonly) id <GXEntityDataFieldDescriptor> actionBCVariable;

@end

#pragma mark -

typedef NS_OPTIONS(uint_least8_t, GXWorkWithModeType) {
	GXWorkWithModeView = GXModeView,
	GXWorkWithModeInsert = GXModeInsert,
	GXWorkWithModeUpdate = GXModeUpdate,
	GXWorkWithModeDelete = GXModeDelete,
	GXWorkWithModeEdit = 1 << 4
};

GXWorkWithModeType GXWorkWithModeFromString(NSString * __nullable value);
GXModeType GXModeFromWorkWithMode(GXWorkWithModeType wwMode);

@protocol GXActionWorkWithDescriptor <GXActionCallObjectDescriptor>

@property(nonatomic, assign, readonly) GXWorkWithModeType actionCallMode;
@property(nullable, nonatomic, strong, readonly) NSString *actionWWComponent;
@property(nonatomic, assign, readonly) BOOL actionSelfEdit;
@property(nullable, nonatomic, strong, readonly) id <GXEntityDataFieldDescriptor> actionBcVariable;

@end

#pragma mark -

@protocol GXActionExternalObjectDescriptor <GXActionCallObjectDescriptor>

@property(nonatomic, strong, readonly) NSString *actionExternalObjectMethod;
@property(nullable, nonatomic, strong, readonly) NSString *actionExternalObjectReturnValue;
@property(nullable, nonatomic, strong, readonly) id<GXExpression> actionExternalObjectReturnValueExpression;
@property(nonatomic, assign, readonly) BOOL actionExternalObjectIsEvent;

@end

#pragma mark -

@protocol GXActionLinkDescriptor <GXActionDescriptor>

@property(nonatomic, strong, readonly) NSURL *actionLinkURL;

@end

#pragma mark -

@protocol GXActionForInDescriptor <GXActionDescriptor>

@property(nonatomic, strong, readonly) id<GXEntityDataFieldDescriptor> actionForInVariableDescriptor;
@property(nonatomic, strong, readonly) id<GXExpression> actionForInCollectionExpression;
@property(nonatomic, strong, readonly) id<GXActionDescriptor> actionForInBlockActionDescriptor;

@end

@protocol GXActionForEachLineDescriptor <GXMultilineActionDescriptor>

@property(nonatomic, strong, readonly) id<GXActionDescriptor> actionForEachLineBlockActionDescriptor;

@end

#pragma mark -

#define kGXBackEventName @"Back"
#define kGXClientStartEventName @"ClientStart"
#define kGXClientStartEventNameEv2 @"gxstart"

extern NSString *const GXBackEventName;
extern NSString *const GXClientStartEventName;

typedef NS_ENUM(uint_least8_t, GXClientStartExecutionState) {
	GXClientStartExecutionStatePending = 0,
	GXClientStartExecutionStateRunning,
	GXClientStartExecutionStateExecuted,
	GXClientStartExecutionStateCancelled,
	GXClientStartExecutionStateWaitingForNavigationStart
};

typedef void(^GXClientStartExecutionContextCompletionBlock)(NSDictionary<NSString *, id> * __nullable clientStartOverrideValuesByFieldName);

@protocol GXClientStartExecutionContext <NSObject>

@property(nullable, atomic, copy) GXClientStartExecutionContextCompletionBlock clientStartCompletionBlock;

@end

NS_ASSUME_NONNULL_END
