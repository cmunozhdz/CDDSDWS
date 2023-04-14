//
//  GXControl.h
//  GXFlexibleClient
//
//  Created by willy on 5/5/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import Foundation;
@import UIKit;
#if TARGET_OS_WATCH
@import WatchKit;
#endif // TARGET_OS_WATCH
@import GXFoundation;
@import GXObjectsModel;
@import GXObjectsModel.Swift;
#if TARGET_OS_WATCH
#import <GXCoreUI/GXControlInterfaceObjectsProvider.h>
#endif // TARGET_OS_WATCH
#import <GXCoreUI/GXUserInterfaceContext+GXControl.h>
#if !TARGET_OS_WATCH
#import <GXCoreUI/GXControlScrollIntoViewTypes.h>
#endif // !TARGET_OS_WATCH

@protocol GXControl;
@protocol GXControlDelegate;
@protocol GXControlContainer;
@protocol GXControlActionsDispatcher;
@protocol GXActionHandler;
@class GXUserInterfaceContext;


NS_ASSUME_NONNULL_BEGIN

#if !TARGET_OS_WATCH
extern NSString *const GXControlEventNameTap;
extern NSString *const GXControlEventNameDoubleTap;
extern NSString *const GXControlEventNameLongTap;
extern NSString *const GXControlEventNameSwipe;
extern NSString *const GXControlEventNameSwipeLeft;
extern NSString *const GXControlEventNameSwipeRight;
extern NSString *const GXControlEventNameSwipeUp;
extern NSString *const GXControlEventNameSwipeDown;
extern NSString *const GXControlEventNamePinch;

@protocol GXControlView <NSObject>

/*
 * Classes implementing GXControlView protocol must implement UIAccessibilityContainer methods and properties from NSObject
 *
 * - (NSString *)accessibilityIdentifier;
 *
 * See another existing subclass for implementation
 */

@property(nullable, nonatomic, weak) id<GXControl> gxControl;

@end
#endif // !TARGET_OS_WATCH

@protocol GXControlBaseProperties <NSObject>

@property(nonatomic, assign) BOOL visible;
@property(nonatomic, assign) BOOL enabled;
@property(nullable, nonatomic, strong) GXStyleClass *styleClass;
@property(nullable, nonatomic, weak, readonly) id <GXControlContainer> parentControlContainer;

@optional
- (void)reloadStyleClassFromCurrentStyleObject;

@end

@protocol GXControlBaseRuntimeProperties <NSObject>

/// Returns property value for the given property name (which must be lowercase)
/// @Param propertyName The lowercased property name to get its value.
/// @Result The value for the given property name.
- (nullable id)valueForPropertyName:(NSString *)propertyName;
/// Sets the given property value to the given property name (which must be lowercase)
/// @Param propertyName The lowercased property name to be applied.
/// @Param propertyValue The property value to be applied. Value should have the expected type or be a string representation when called for a dynamic property.
- (void)setProperty:(NSString *)propertyName value:(nullable id)propertyValue;

@optional
/// Executes the method with the given name (which must be lowercase) and paramenters
/// @Param methodName The lowercased method name to be called.
/// @Param parameters The parameters for the given method.  Values should have the expected types or be string representations when called for a dynamic method.
/// @Result The result value of calling the given method if it has a return value, nil otherwise.
/// @Note Same as executeMethod:withParameters:entityData:userInterfaceContext: with nil entity data and nil UI context.
- (nullable id)executeMethod:(NSString *)methodName withParameters:(NSArray *)parameters;
/// Executes the method with the given name (which must be lowercase), paramenters and entity data
/// @Param methodName The lowercased method name to be called.
/// @Param parameters The parameters for the given method.  Values should have the expected types or be string representations when called for a dynamic method.
/// @Param entityData The caller's context entity data.
/// @Result The result value of calling the given method if it has a return value, nil otherwise.
/// @Note Same as executeMethod:withParameters:entityData:userInterfaceContext: with nil UI context.
- (nullable id)executeMethod:(NSString *)methodName
			  withParameters:(NSArray *)parameters
				  entityData:(nullable id <GXEntityDataWithOverrideValues>)entityData;
/// Executes the method with the given name (which must be lowercase), paramenters, entity data and user interface context
/// @Param methodName The lowercased method name to be called.
/// @Param parameters The parameters for the given method.  Values should have the expected types or be string representations when called for a dynamic method.
/// @Param entityData The caller's context entity data.
/// @Param uiContext The caller's user interface context.
/// @Result The result value of calling the given method if it has a return value, nil otherwise.
- (nullable id)executeMethod:(NSString *)methodName
			  withParameters:(NSArray *)parameters
				  entityData:(nullable id<GXEntityDataWithOverrideValues>)entityData
		userInterfaceContext:(nullable GXUserInterfaceContext *)uiContext;

@end

@protocol GXControlRuntimePropertiesProxy <NSObject>

/// Returns property value for the given property name (which must be lowercase) of the control with the given name (case insensitive)
- (nullable id)valueForProperty:(NSString *)propertyName
					controlName:(NSString *)controlName
		   userInterfaceContext:(nullable GXUserInterfaceContext *)uiContext;
/// Sets the given property value to the given property name (which must be lowercase) of the control with the given name (case insensitive)
- (void)applyProperty:(NSString *)propName
				value:(nullable id)propValue
	toControlWithName:(NSString *)controlName
 userInterfaceContext:(nullable GXUserInterfaceContext *)uiContext
	contextEntityData:(nullable id<GXEntityDataWithOverrideValues>)contextEntityData;
/// Executes the method with the given name (which must be lowercase) and paramenters of the control with the given name (case insensitive)
- (nullable id)executeMethod:(NSString *)methodName
			  withParameters:(NSArray *)parameters
		   toControlWithName:(NSString *)controlName
		userInterfaceContext:(nullable GXUserInterfaceContext *)uiContext
		   contextEntityData:(nullable id<GXEntityDataWithOverrideValues>)contextEntityData;

@end

@protocol GXControl <GXNamedControlElement, GXControlBaseProperties, GXControlBaseRuntimeProperties, GXLayoutLocator>

@property (nonatomic, assign) GXHorizontalAlignType horizontalAlign;
@property (nonatomic, assign) GXVerticalAlignType verticalAlign;
@property (nonatomic, assign) GXHighlightStyleType highlightStyle;
@property (nonatomic, readonly) NSUInteger controlId;
#if TARGET_OS_WATCH
@property (nonatomic, strong, readonly) WKInterfaceObject *interfaceObject;
#else
@property (nonatomic, assign) CGRect frame;
@property (nonatomic, assign) CGRect originalFrame; // frame before transformations
@property (nonatomic, strong, readonly) UIView<GXControlView> *view;
@property (nonatomic, readonly, getter = isViewLoaded) BOOL viewLoaded;
#endif // TARGET_OS_WATCH
@property (nonatomic, assign, readonly) GXViewVisibleStateType viewVisibleState;
@property (nonatomic, strong) NSArray<NSNumber *> *indexer;
@property (nonatomic, strong, readonly) id<GXLayoutElement> layoutElement;
@property (nonatomic, assign) GXModeType modeType;
@property (nullable, nonatomic, weak, readonly) id <GXControlDelegate> controlDelegate;
@property (nullable, nonatomic, weak, readonly) id <GXControlActionsDispatcher> actionDispatcher;

#if TARGET_OS_WATCH
- (id)initWithInterfaceObject:(WKInterfaceObject *)interfaceObject
				layoutElement:(id <GXLayoutElement>)layoutElement
					controlId:(NSUInteger)controlId
					   gxMode:(GXModeType)modeType
				 indexerStack:(nullable NSArray<NSNumber *> *)indexer
				parentControl:(nullable id<GXControlContainer>)parentControl;
#else
- (id)initWithLayoutElement:(id <GXLayoutElement>)layoutElement
				  controlId:(NSUInteger)controlId
					 gxMode:(GXModeType)modeType
			   indexerStack:(nullable NSArray<NSNumber *> *)indexer
			  parentControl:(nullable id<GXControlContainer>)parentControl;
#endif // TARGET_OS_WATCH

#if !TARGET_OS_WATCH
- (void)loadView;
- (void)unloadView;

/// Begins Control preparation for being reused (Grid item controls may be reused)
- (void)prepareForReuseViews;
/// Ends Control preparation for being reused (Called after prepareForReuseViews and after reloaded with (optionally) new data).
- (void)endPrepareForReuseViews;
#endif // !TARGET_OS_WATCH

- (void)setHighlightStyle:(GXHighlightStyleType)style animated:(BOOL)animated;

@optional

@property (nullable, nonatomic, strong, readonly) NSString *gxControlAccessibleValue;

#if TARGET_OS_IOS
/**
 * This event is triggered before the screen rotation begins
 * See UIViewController reference for more information
 */
- (void)willRotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration;

/**
 * This event is triggered after the willRotate... method but before the rotate animation begins
 * It is executed in the same animation block as the rest of the rotate animation
 * See UIViewController reference for more information
 */
- (void)willAnimateRotationToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation duration:(NSTimeInterval)duration;

/**
 * This event is triggered after the screen rotation ends
 * See UIViewController reference for more information
 */
- (void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation;
#endif // TARGET_OS_IOS

- (void)viewWillAppear:(BOOL)animated;    // Called when the view is about to made visible. Default does nothing
- (void)viewDidAppear:(BOOL)animated;     // Called when the view has been fully transitioned onto the screen. Default does nothing
- (void)viewWillDisappear:(BOOL)animated; // Called when the view is dismissed, covered or otherwise hidden. Default does nothing
- (void)viewDidDisappear:(BOOL)animated;  // Called after the view was dismissed, covered or otherwise hidden. Default does nothing

#if !TARGET_OS_WATCH
/**
 * Called when the view controller needs to dismiss the keyboard
 */
- (void)resignFirstResponder;
#endif // !TARGET_OS_WATCH

@end


@protocol GXControlActionsDispatcher <NSObject>

- (BOOL)hasActionWithName:(NSString *)actionName;
- (nullable id <GXActionHandler>)fireActionWithName:(NSString *)actionName
											 sender:(nullable id)sender
							   userInterfaceContext:(nullable GXUserInterfaceContext *)uiContext;
- (nullable id <GXActionHandler>)fireActionWithName:(NSString *)actionName
											 sender:(nullable id)sender
							   userInterfaceContext:(nullable GXUserInterfaceContext *)uiContext
										 entityData:(nullable id<GXEntityDataWithOverrideValues>)entityData
									concurrencyMode:(GXActionHandlerConcurrencyMode)concurrencyMode;

- (nullable id <GXActionHandler>)fireEventWithName:(NSString *)eventName
											sender:(nullable id)sender
							  userInterfaceContext:(nullable GXUserInterfaceContext *)uiContext
										parameters:(nullable NSArray *)parametersValues
								   concurrencyMode:(GXActionHandlerConcurrencyMode)concurrencyMode;

- (nullable id<GXEventDescriptor>)eventDescriptorForEventName:(NSString *)eventName;
- (nullable id<GXActionParametersDescriptor>)actionEventParametersForName:(NSString *)eventName;
- (nullable id)valueForActionParameter:(id<GXActionParameterDescriptor>)parameter;
- (void)setValue:(nullable id)value forActionParameter:(id<GXActionParameterDescriptor>)parameter;

@end


@protocol GXControlDelegate <NSObject>

- (GXViewVisibleStateType)viewVisibleStateForControl:(id <GXControl>)control;

#if !TARGET_OS_WATCH
/// Notifies control's visible property value has changed. Control's layout element invisible mode must be GXLayoutInvisibleModeCollapseSpace
- (void)controlWithCollapseSpaceInvisibleModeVisibleChanged:(id <GXControl>)control;

/// Notifies control's frame must be reset.
- (void)controlFrameModifierChanged:(id <GXControl>)control;

/// Notifies control requires re-layout and should be animated.
- (void)controlAnimatedLayoutRequired:(id <GXControl>)control;
#endif // !TARGET_OS_WATCH

/// Returns the layoutElement (or it's default) style class for the given control.
- (nullable GXStyleClass *)controlLayoutElementStyleClass:(id <GXControl>)control;

@property(nullable, nonatomic, strong, readonly) id <GXControllerPresentationHandlerProtocol> controlControllerPresentationHandler;

#if TARGET_OS_WATCH
@property(nullable, nonatomic, strong, readonly) id<GXControlInterfaceObjectsProvider> controlInterfaceObjectsProvider;
#endif // TARGET_OS_WATCH

#if !TARGET_OS_WATCH
/*
 Scrolls the view controller content so that the given control is visible on screen
 */
- (void)scrollToMakeControlVisible:(id<GXControl>)control position:(GXScrollIntoViewPosition)pos animated:(BOOL)animated;
#endif	// !TARGET_OS_WATCH

@end

NS_ASSUME_NONNULL_END
