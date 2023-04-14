//
//  GXControlBase.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 12/12/11.
//  Copyright (c) 2011 Artech. All rights reserved.
//

@import Foundation;
#if !TARGET_OS_WATCH
#import <GXCoreUI/GXDragDropManager.h>
#import <GXCoreUI/GXControlBaseReuseContext.h>
#endif // !TARGET_OS_WATCH
#import <GXCoreUI/GXControlContainer.h>
#import <GXCoreUI/GXUserInterfaceContextHelper+GXControl.h>
#if !TARGET_OS_WATCH
#import <GXCoreUI/GXViewLayoutDelegationProtocol.h>
#endif // !TARGET_OS_WATCH

NS_ASSUME_NONNULL_BEGIN

@interface GXControlBase : NSObject <GXControl>

- (instancetype)init NS_UNAVAILABLE;
#if TARGET_OS_WATCH
- (instancetype)initWithInterfaceObject:(WKInterfaceObject *)interfaceObject
						  layoutElement:(id <GXLayoutElement>)layoutElement
							  controlId:(NSUInteger)controlId
								 gxMode:(GXModeType)modeType
						   indexerStack:(nullable NSArray<NSNumber *> *)indexer
						  parentControl:(nullable id<GXControlContainer>)parentControl NS_DESIGNATED_INITIALIZER;
#else
- (instancetype)initWithLayoutElement:(id <GXLayoutElement>)layoutElement
							controlId:(NSUInteger)controlId
							   gxMode:(GXModeType)modeType
						 indexerStack:(nullable NSArray<NSNumber *> *)indexer
						parentControl:(nullable id<GXControlContainer>)parentControl NS_DESIGNATED_INITIALIZER;

@property(nullable, nonatomic, strong, readonly) UIView<GXControlView> *loadedView;
@property(nullable, nonatomic, strong, readonly) UIView *loadedBorderView;
@property(nullable, nonatomic, strong, readonly) UIView *loadedBackgroundColorView;
@property(nullable, nonatomic, strong, readonly) UIImageView *loadedBackgourndImageView;
@property(nullable, nonatomic, strong, readonly) UIView *loadedContainerView;

@property(nonatomic, assign, readonly) UIUserInterfaceLayoutDirection userInterfaceLayoutDirection;
@property(nonatomic, readonly, getter=isLayoutDirectionLeftToRight) BOOL layoutDirectionLeftToRight;
@property(nonatomic, readonly, getter=isLayoutDirectionRightToLeft) BOOL layoutDirectionRightToLeft;

/*!
 Applies modifiers to the given control frame
 
 @param frame Control's frame
 @result Retruns frame with transformations applied
 @discussion Default implementation applies transformation from style class (if conforms to GXThemeClassWithTransformation).
 Called from setFrame:, self.frame is the result of calling this methods with self.originalFrame.
 */
- (CGRect)frameWithTransform:(CGRect)frame;
/**
 * Retuns frame for self.view
 * Default implementation returns controlFrame with viewRequiredEdgeInsetsToControlFrame applied 
 */
- (CGRect)viewFrameForControlFrame:(CGRect)controlFrame;
/**
 * Retuns frame for self.contentView
 * Default implementation returns frame with contentRequiredEdgeInsetsToViewFrame applied 
 */
- (CGRect)contentFrameForViewFrame:(CGRect)viewFrame;
/**
 * Retuns content frame for given control frame
 * Default implementation calls [self contentFrameForViewFrame:[self viewFrameForControlFrame:controlFrame]]
 */
- (CGRect)contentFrameForControlFrame:(CGRect)controlFrame;
/**
 * Retuns content frame for current control frame (self.frame)
 * Default implementation calls [self contentFrameForControlFrame:self.frame]
 */
- (CGRect)contentFrame;

/**
 * Returns the edge insets required to be applied to the control frame
 * Default implementation returns insets required for the margin
 */
- (GXLayoutQuadDimension)viewRequiredEdgeInsetsToControlFrame;

/**
 * Returns the edge insets required to be applied to the view frame
 * Default implementation returns insets required for the border & padding
 */
- (GXLayoutQuadDimension)contentRequiredEdgeInsetsToViewFrame;

/**
 * Returns the total edge insets required to be applied to the control frame
 * Default implementation returns the sum of insets viewRequiredEdgeInsetsToControlFrame & contentRequiredEdgeInsetsToViewFrame
 */
- (GXLayoutQuadDimension)contentRequiredEdgeInsetsToControlFrame;

/**
 * Called at the end of loadView
 * Default implementation calls applyStyleClass
 */
- (void)viewDidLoad;

/**
 * Called on setFrame: with control frame if [self isViewLoaded]
 * Default implementation sets [self viewFrameForControlFrame:controlFrame] to self.view
 */
- (void)setViewFrame:(CGRect)controlFrame;

#endif // TARGET_OS_WATCH

/**
 * Applies style class to view
 * Called on loadView & onStyleClassChanged
 */
- (void)applyStyleClass;

/**
 * Returns if [self applyHighlighAnimated:NO] should be called on applyStyleClass
 * Default implementation returns borderOrBgImageViewsChanged && self.highlightStyle != GXHighlightStyleNone;
 */
- (BOOL)applyHighlighOnApplyStyleClass:(BOOL)borderOrBgImageViewsChanged;

/**
 *	Applies Highlight
 * This method is called when higlight state changes
 */
- (void)applyHighlighAnimated:(BOOL)animated;

/**
 * Applies the given propValue to the given propName
 * Returns YES if the property was found, NO otherwise
 * Called in setProperty:value:
 * Default implementation applies class, enabled & visible properties
 */
- (BOOL)applyPropertyValue:(nullable id)propValue toPropertyName:(NSString *)propName;

#pragma mark - Override points

/// Called on setModeType: if mode is different
- (void)onModeChanged:(GXModeType)oldMode;
/// Called on setVisible: if visible is different
- (void)onVisibleChanged;
/// Called on setEnabled: if enabled is different
- (void)onEnabledChanged;

#if !TARGET_OS_WATCH

/*!
 Keeps loadedView.userInteractionEnabled = !self.enabled
 
 @discussion Default implementation returns ![self.loadedView isKindOfClass:[UIScrollView class]]
 */
- (BOOL)updateLoadedViewUserInteractionEnabledWithControlEnabled;

/**
 * Called on setFrame: if frame is different
 * Default implementation does nothing
 */
- (void)onControlFrameChanged:(CGRect)oldControlFrame;

#endif // !TARGET_OS_WATCH

/**
 * Called on applyStykeClass: if styleClass is new
 * Default implementation calls applyStyleClass
 */
- (void)onStyleClassChanged:(nullable GXStyleClass *)oldStyleClass;

#if !TARGET_OS_WATCH

/*!
 Returns YES if onPreferredContentSizeChanged should be called when the user has changed the preferred content size category for the system, see UIContentSizeCategoryDidChangeNotification
 
 @result YES if onPreferredContentSizeChanged should be called when the user has changed the preferred content size category for the system, NO otherwise
 @discussion Default implementation returns NO, should return YES if control uses style class font property
 */
+ (BOOL)controlShouldObservePreferredContentSizeChanges;

/*!
 Adjust control after the user has changed the preferred content size category for the system
 
 @discussion Default implementation calls applyStyleClass
 */
- (void)onPreferredContentSizeChanged;

#endif // !TARGET_OS_WATCH

#pragma mark - Abstract

#if !TARGET_OS_WATCH

/**
 * Creates the content views for the control
 * These views are placed inside a container view, that draws the margin, border and padding when necesary
 * For internal use, called in loadView
 */
- (void)loadContentViewsWithContentFrame:(CGRect)contentFrame intoContainerView:(UIView *)containerView;

/*
 * Creates a new main view with the given frame
 * Called in loadView
 */
- (UIView<GXControlView> *)newMainViewWithFrame:(CGRect)frame;

#endif // !TARGET_OS_WATCH

@end

#pragma mark - Control User Actions

@protocol GXControlBaseUserActions <NSObject>
@property(nullable, nonatomic, strong, readonly) NSString *controlUserActionTapIdentifier; // Handled on Tap
@end

@interface GXControlBaseMutableUserActions : NSObject <GXControlBaseUserActions>
- (void)setControlUserActionTapIdentifier:(nullable NSString *)userActionId;
@end

extern NSString *const GXControlBaseUserActionIdentifierControlTapEvent; // Control.Tap Event

@interface GXControlBase (GXUserActions) <GXControlBaseUserActions>

/// Invalidates current GXControlBaseUserActions values (loadControlUserActions: will be called when needed).
/// If view is loaded, GXControlBaseUserActions values are updated immediately.
- (void)invalidateControlUserActions;

/// Updates current GXControlBaseUserActions values immediately if are invalid.
- (void)updateUserActionsIfNeeded;

#pragma mark - Control User Actions Override Points

/// Class used to call loadControlUserActions:
- (Class)controlMutableUserActionForLoading;
/// Loads current values for GXControlBaseUserActions into given controlUserActions
- (void)loadControlUserActions:(GXControlBaseMutableUserActions *)controlUserActions;
/// Updates self GXControlBaseUserActions from given controlUserActions (after loadControlUserActions:)
- (void)updateUserActionsFrom:(id <GXControlBaseUserActions>)controlUserActions;

/*!
 Handles user action
 
 @param actionIdentifier The user action identifier to handle.
 @param sender The sender context which triggered the user action.
 @result YES if user action has been handled, NO otherwise.
 */
- (BOOL)handleControlActionWithIdentifier:(NSString *)actionIdentifier sender:(nullable id)sender;

@end

#pragma mark - GXActionHandler Helpers

@interface GXControlBase (GXActionHandler)

/// If entityData for firing actions is nil, this entity data is used instead. Default implementation returns [self.parentControlContainer containerLoadedEntityData]
- (nullable id <GXEntityDataWithOverrideValues>)defaultEntityDataForFiringActions;

/// Checks if there is an action descriptor for the given control event name
- (BOOL)hasActionForControlEvent:(NSString *)eventName;

/*!
 Fire action asociated with the given control event name
 
 @param eventName Name of the control event to fire
 @param uiContext User interface context to execute the action. If nil, a new one is created.
 @result Action handler for the action. Nil value is returned if action could not be executed.
 @discussion Notice that self (GXControl) is automatically added to uiContext. Same as calling fireControlEvent:userInterfaceContext:withEntityData: with nil entityData.
 */
- (nullable id <GXActionHandler>)fireControlEvent:(NSString *)eventName
							 userInterfaceContext:(nullable GXUserInterfaceContext *)uiContext;

/*!
 Fire action asociated with the given control event name
 
 @param eventName Name of the control event to fire
 @param uiContext User interface context to execute the action. If nil, a new one is created.
 @param entityData Context entity data to execute the action. If nil, the containerLoadedEntityData will be used.
 @param params Parameters to be passed to the event.
 @result Action handler for the action. Nil value is returned if action could not be executed.
 @discussion Notice that self (GXControl) is automatically added to uiContext. Same as calling fireActionWithName:userInterfaceContext:withEntityData: with the action name for the control event ("ControlName.eventName").
 */
- (nullable id <GXActionHandler>)fireControlEvent:(NSString *)eventName
							 userInterfaceContext:(nullable GXUserInterfaceContext *)uiContext
								   withEntityData:(nullable id<GXEntityDataWithOverrideValues>)entityData
									   parameters:(nullable NSArray *)params;

/*!
 Fire action asociated with the given name
 
 @param actionName Name of the action to fire
 @param uiContext User interface context to execute the action. If nil, a new one is created.
 @param entityData Context entity data to execute the action. If nil, the containerLoadedEntityData will be used.
 @result Action handler for the action. Nil value is returned if action could not be executed.
 @discussion Notice that self (GXControl) is automatically added to uiContext.
 */
- (nullable id <GXActionHandler>)fireActionWithName:(NSString *)actionName
							   userInterfaceContext:(nullable GXUserInterfaceContext *)uiContext
									 withEntityData:(nullable id<GXEntityDataWithOverrideValues>)entityData;

/*!
 Fire action asociated with the given control event name
 
 @param eventName Name of the control event to fire
 @param uiContext User interface context to execute the action. If nil, a new one is created.
 @param entityData Context entity data to execute the action. If nil, the containerLoadedEntityData will be used.
 @param params Parameters to be passed to the event.
 @param concurrencyMode Concurrency mode
 @result Action handler for the action. Nil value is returned if action could not be executed.
 @discussion Notice that self (GXControl) is automatically added to uiContext. Same as calling fireActionWithName:userInterfaceContext:withEntityData: with the action name for the control event ("ControlName.eventName").
 */
- (nullable id <GXActionHandler>)fireControlEvent:(NSString *)eventName
							 userInterfaceContext:(nullable GXUserInterfaceContext *)uiContext
								   withEntityData:(nullable id<GXEntityDataWithOverrideValues>)entityData
									   parameters:(nullable NSArray *)params
								  concurrencyMode:(GXActionHandlerConcurrencyMode)concurrencyMode;

#if TARGET_OS_IOS
- (nullable id <GXActionHandler>)fireControlEvent:(NSString *)eventName
							 userInterfaceContext:(nullable GXUserInterfaceContext *)uiContext
								   withEntityData:(nullable id<GXEntityDataWithOverrideValues>)entityData
									   parameters:(nullable NSArray *)params
						   allowMultipleInstances:(BOOL)allowMultipleInstances;
#endif // TARGET_OS_IOS

@end

#pragma mark - GXViewTouchResponderDelegate

#if !TARGET_OS_WATCH

@interface GXControlBase (GXViewTouchResponderDelegate) <GXViewTouchResponderDelegate>

/*!
 Flag to check if control should be highlighted on touch
	
 @result YES If control should be highlighted on touch, NO otherwise.
 @discussion Loaded after view is lodaded and after invalidateControlHighlightOnTouch. Do not override, override loadControlHighlightOnTouch instead.
 */
@property(nonatomic, assign, readonly) BOOL controlHighlightOnTouch;

/// Invalidates controlHighlightOnTouch, loadControlHighlightOnTouch will be called to re-load the property value.
- (void)invalidateControlHighlightOnTouch;

#pragma mark - Override Points

/// Returns the value for controlHighlightOnTouch.
/// Default implementation returns self.controlUserActionTapIdentifier != nil || [self hasControlEventLongTap]
- (BOOL)loadControlHighlightOnTouch;

@end

#endif // !TARGET_OS_WATCH

#pragma mark - UIGestureRecognizerDelegate

#if !TARGET_OS_WATCH

@interface GXControlBase (UIGestureRecognizerDelegate) <UIGestureRecognizerDelegate>
@end

#endif // !TARGET_OS_WATCH

#pragma mark - GXDropTargetControl

#if !TARGET_OS_WATCH

@interface GXControlBase (GXDropTargetControl) <GXDropTargetControl>
@end

#endif // !TARGET_OS_WATCH

#pragma mark - GXDropTargetControl

#if !TARGET_OS_WATCH

@interface GXControlBase (GXDragableControl) <GXDragableControl>
@end

#endif // !TARGET_OS_WATCH


#pragma mark - Reuse

#if !TARGET_OS_WATCH

@interface GXControlBase (Reuse)

@property(nullable, nonatomic, strong, readonly) GXControlBaseReuseContext *reuseContext;
@property(nonatomic, assign, readonly, getter=isPreparingForReuse) BOOL preparingForReuse;

- (Class)reuseContextClass;

@end

#endif // !TARGET_OS_WATCH

NS_ASSUME_NONNULL_END
