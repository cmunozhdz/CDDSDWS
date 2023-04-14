//
//  GXControlEdit.h
//  GXFlexibleClient
//
//  Created by willy on 5/5/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import GXObjectsModel;
#import <GXCoreUI/GXControl.h>
#import <GXCoreUI/GXControlWithPromptRule.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const GXControlEventNameControlValueChanged;
extern NSString *const GXControlEventNameControlValueChanging;

@protocol GXControlWithData;

@protocol GXControlWithDataEventsDelegate <NSObject>

- (void)handleRelationLink:(id <GXControlWithData>)sender
				entityData:(id <GXEntityDataWithOverrideValues>)entityData
				  relation:(GXBusinessComponentRelation *)relation;

- (void)gxControlWithDataWillBecomeFirstResponder:(id<GXControlWithData>)control;
- (void)gxControlWithDataDidBecomeFirstResponder:(id<GXControlWithData>)control;
- (void)gxControlWithDataWillResignFirstResponder:(id<GXControlWithData>)control;
- (void)gxControlWithDataDidResignFirstResponder:(id<GXControlWithData>)control;

@end

#pragma mark -

@protocol GXControlWithData <GXControl, GXControlWithPromptRule>

#if TARGET_OS_WATCH
- (instancetype)initWithInterfaceObject:(WKInterfaceObject *)interfaceObject
						  layoutElement:(id<GXLayoutElementData>)layoutElement
							  controlId:(NSUInteger)controlId
								 gxMode:(GXModeType)modeType
						fieldDescriptor:(id <GXEntityDataFieldDescriptor>)fieldDescriptor
						   indexerStack:(nullable NSArray<NSNumber *> *)indexer
						  parentControl:(id<GXControlContainer>)parentControl;
#else
- (instancetype)initWithLayoutElement:(id<GXLayoutElementData>)layoutElement
							controlId:(NSUInteger)controlId
							   gxMode:(GXModeType)modeType
					  fieldDescriptor:(id<GXEntityDataFieldDescriptor>)fieldDescriptor
						 indexerStack:(nullable NSArray<NSNumber *> *)indexer
						parentControl:(id<GXControlContainer>)parentControl;
#endif // TARGET_OS_WATCH

@property(nullable, nonatomic, strong) NSString *caption;

/**
 Loads the control's corresponding value from the entity data
 @return YES if the value was updated, NO otherwise (the current value in the control is equal to the value in the entity data for the control)
 */
- (BOOL)loadEntityData:(nullable id <GXEntityDataWithOverrideValues>)entityData;

@property(nullable, nonatomic, weak) id <GXControlWithDataEventsDelegate> controlWithDataEventsDelegate;
@property(nullable, nonatomic, strong) GXBusinessComponentRelation *controlWithDataBusinessComponentRelation;

@property(nullable, nonatomic, strong, readonly) id<GXEntityDataFieldDescriptor> fieldDescriptor;
@property(nullable, nonatomic, strong, readonly) id<GXEntityDataWithOverrideValues> entityData;

+ (BOOL)isValidForDataType:(GXDataType)dataType;

@optional
#if TARGET_OS_IOS
/**
 Returns the controls preferred rect (in view.superview coordinate) to make visible when control becomes first responder (see gxControlWithDataDidBecomeFirstResponder:).
 If not implemented, view.frame is used. If returned rect is CGRectNull, no adjustment is made.
*/
@property(nonatomic, readonly) CGRect controlPreferredVisibleFrame;
#endif // TARGET_OS_IOS
@end

extern NSString *const GXControlValueChangedNotification;
extern NSString *const GXControlValueChangedNotificationOldValueKey;
extern NSString *const GXControlValueChangedNotificationNewValueKey;

NS_ASSUME_NONNULL_END
