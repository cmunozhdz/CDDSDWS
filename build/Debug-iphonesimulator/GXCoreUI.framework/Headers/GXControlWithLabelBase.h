//
//  GXControlWithLabelBase.h
//  GXFlexibleClient
//
//  Created by willy on 5/13/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import Foundation;
#if !TARGET_OS_WATCH
#import <GXCoreUI/GXControlAutoHeight.h>
#import <GXCoreUI/GXControlBaseWithLayout.h>
#else
#import <GXCoreUI/GXControlBase.h>
#endif // !TARGET_OS_WATCH
#import <GXCoreUI/GXControlWithData.h>
#if !TARGET_OS_WATCH
#import <GXCoreUI/GXControlWithLabelAutoWidth.h>
#endif // !TARGET_OS_WATCH

NS_ASSUME_NONNULL_BEGIN

#if !TARGET_OS_WATCH
typedef struct {
	CGFloat additionalToEditor;
	CGFloat minimum;
} GXControlWithLabelBaseRequiredHeight;
#endif // !TARGET_OS_WATCH

#if !TARGET_OS_WATCH
@interface GXControlWithLabelBase : GXControlBaseWithLayout <GXControlWithData, GXControlAutoHeight, GXControlWithLabelAutoWidth, GXEntityDataOverrideValueChangedDelegate, GXEntityDataFieldEditorViewControllerDelegate>
#else
@interface GXControlWithLabelBase : GXControlBase <GXControlWithData, GXEntityDataOverrideValueChangedDelegate>
#endif // !TARGET_OS_WATCH
{
@protected
    NSString *                          _caption;
@private
#if !TARGET_OS_WATCH
	UIView *_labelBorderView;
#endif // !TARGET_OS_WATCH
	id <GXEntityDataFieldInfo>			_resolvedFieldInfo;
#if !TARGET_OS_WATCH
	CGFloat								_labelAutoWidth;
#endif // !TARGET_OS_WATCH
}

#if TARGET_OS_WATCH
- (instancetype)initWithInterfaceObject:(WKInterfaceObject *)interfaceObject
						  layoutElement:(id <GXLayoutElement>)layoutElement
							  controlId:(NSUInteger)controlId
								 gxMode:(GXModeType)modeType
						   indexerStack:(nullable NSArray<NSNumber *> *)indexer
						  parentControl:(nullable id<GXControlContainer>)parentControl NS_UNAVAILABLE;

- (instancetype)initWithInterfaceObject:(WKInterfaceObject *)interfaceObject
						  layoutElement:(id<GXLayoutElementData>)layoutElement
							  controlId:(NSUInteger)controlId
								 gxMode:(GXModeType)modeType
						fieldDescriptor:(id <GXEntityDataFieldDescriptor>)fieldDescriptor
						   indexerStack:(nullable NSArray<NSNumber *> *)indexer
						  parentControl:(id<GXControlContainer>)parentControl NS_DESIGNATED_INITIALIZER;
#else
- (instancetype)initWithLayoutElement:(id<GXLayoutElement>)layoutElement
							controlId:(NSUInteger)controlId
							   gxMode:(GXModeType)modeType
						 indexerStack:(nullable NSArray<NSNumber *> *)indexer
						parentControl:(nullable id<GXControlContainer>)parentControl NS_UNAVAILABLE;

- (instancetype)initWithLayoutElement:(id<GXLayoutElementData>)layoutElement
							controlId:(NSUInteger)controlId
							   gxMode:(GXModeType)modeType
					  fieldDescriptor:(id<GXEntityDataFieldDescriptor>)fieldDescriptor
						 indexerStack:(nullable NSArray<NSNumber *> *)indexer
						parentControl:(id<GXControlContainer>)parentControl NS_DESIGNATED_INITIALIZER;
#endif // TARGET_OS_WATCH

#if !TARGET_OS_WATCH
@property(nullable, nonatomic, strong, readonly) UILabel *label;
#else
@property(nullable, nonatomic, strong, readonly) WKInterfaceLabel *label;
#endif // !TARGET_OS_WATCH
@property(nonatomic, strong, readonly) id <GXLayoutElementData> layoutElementData;
@property(nonatomic, strong, readonly) id <GXCodingPropertiesObject> properties;
@property(nonatomic, strong, readonly) id <GXEntityDataFieldDescriptor> fieldDescriptor;
@property(nonatomic, strong, readonly) id <GXEntityDataFieldInfo> resolvedFieldInfo;
#if !TARGET_OS_WATCH
@property(nonatomic, readonly) BOOL autoGrow;
#endif // !TARGET_OS_WATCH
@property(nullable, nonatomic, strong, readonly) id entityDataFieldValue;
@property(nullable, nonatomic, strong, readonly) id <GXEntityDataWithOverrideValues> entityData;
#if !TARGET_OS_WATCH
@property(nonatomic, strong, readonly) UIView *accessoryView;
#endif // !TARGET_OS_WATCH

#pragma mark - Helpers

/// Returns self.caption with text-transform applied from styleClass.
/// @Note Value is cached. Must invalidate if overriding caption property.
@property(nullable, nonatomic, strong, readonly) NSString *captionWithTextTransform;

- (void)invalidateCaptionWithTextTransform;

/**
 * Returns [self.layoutElementData layoutElementFieldSpecifier]
 */
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementDatafieldSpecifier;

/**
 * Replaces self.indexes in [self layoutElementDatafieldSpecifier]
 */
- (nullable NSString *)indexedLayoutElementDatafieldSpecifier;

/**
 * Notifies self.entityDataFieldValue change
 * Called on loadEntityData: if self.entityDataFieldValue changed (changed if entityDataFieldValueIsEqualTo: returns NO)
 * Default implementation calls loadEntityDataFieldValue if [self isViewLoaded]
 */
- (void)onEntityDataFiledValueChanged:(nullable id)oldEntityDataFieldValue;

/*!
 Compares self.entityDataFieldValue with the given value
 
 @param otherEntityDataFieldValue value to compare with self.entityDataFieldValue.
 @result YES if the given value is equal to self.entityDataFieldValue, NO otherwise.
 @discussion Default implementation returns self.entityDataFieldValue == otherEntityDataFieldValue || [self.entityDataFieldValue isEqual:otherEntityDataFieldValue].
 */
- (BOOL)entityDataFieldValueIsEqualTo:(nullable id)otherEntityDataFieldValue;

#pragma mark - Layout

#if !TARGET_OS_WATCH
/**
 * Retuns frame for label view
 * Default implementation calls [self labelFrame:&returnValue editorFrame:NULL accessoryViewFrame:NULL forContentFrame:contentFrame]
 */
- (CGRect)labelFrameWithContentFrame:(CGRect)contentFrame;

/**
 * Retuns frame for editor views
 * Default implementation calls [self labelFrame:NULL editorFrame:&returnValue accessoryViewFrame:NULL forContentFrame:contentFrame]
 */
- (CGRect)editorFrameForContentFrame:(CGRect)contentFrame;

/**
 * Returns labelFrame, editorFrame, accessoryViewFrame and requiredHeight if not NULL for the given contentFrame
 * Default implementation returns label frame taking label position, align and, label theme class into account,
 * editor frame for editor views taking label and accessory view into account and accessoryViewFrame if accessory view is needed
 */
- (void)labelFrame:(nullable CGRect *)labelFrame
	   editorFrame:(nullable CGRect *)editorFrame
 accessoryViewFrame:(nullable CGRect *)accessoryViewFrame
	requiredHeight:(nullable GXControlWithLabelBaseRequiredHeight *)requiredHeight
   forContentFrame:(CGRect)contentFrame;

/**
 * Returns the font to be used in the editor views (if not nil) to vertically align label and editor views
 * Default implementation returns nil
 * Called on labelFrame:editorFrame:accessoryViewFrame:forContentFrame: if labelPosition = left or right
 */
- (nullable UIFont *)editorFontForLabelVerticalAlignment;

/**
 * Returns the edge insets to be applied to control content views (label, editor & accessory view)
 * Default implementation insets:
 *	1. UIKit constant kUITableViewCellContentViewDefaultMarginiPhone to right if label position = None and accessoryViewSize != CGSizeZero
 *	2. UIKit constant kUITableViewCellContentViewDefaultMarginiPhone to left and right if position != None
 *	3. UIEdgeInsetsZero otherwise
 * Called on labelFrame:editorFrame:accessoryViewFrame:forContentFrame:
 */
- (UIEdgeInsets)controlContentsEdgeInsets;

/**
 * Returns the edge insets to be applied to editor view
 * Default implementation insets:
 *	1. UIKit constant kUITableViewCellContentViewDefaultMarginiPhone to left if label position = Left
 *	2. UIKit constant kUITableViewCellContentViewDefaultMarginiPhone to right if label position = Right
 *	3. UIEdgeInsetsZero otherwise
 * Called on labelFrame:editorFrame:accessoryViewFrame:forContentFrame:
 */
- (UIEdgeInsets)controlEditorEdgeInsets;

/**
 * Returns the separation between the accessory view label or editor view
 * Default implementation returns UIKit constant kUITableViewCellSeparatorDefaultWidth / 2
 * Called on labelFrame:editorFrame:accessoryViewFrame:forContentFrame: if accessoryViewSize != CGSizeZero
 */
- (CGFloat)separationToAccessoryView;
#endif // !TARGET_OS_WATCH

#pragma mark - Accessory view override points

#if !TARGET_OS_WATCH
/**
 * Returns the size of the accessoryView if it exists or is needed, CGSizeZero otherwise
 * Default implementation returns:
 *	1. self.accessoryView size, if it's not nil
 *	2. size with width and height of UIButtonTypeDetailDisclosureDefaultBoundSize, if accessory view is required
 *	3. CGSizeZero otherwise
 */
- (CGSize)accessoryViewSize;

/*
 * Returns accessory view image name
 * Default implementation return application theme class promptImage name if controlUserActionAccessoryButtonIdentifier != nil, nil otherwise.
 */
- (nullable NSString *)accessoryViewImageName;
#endif // !TARGET_OS_WATCH

#pragma mark - Abstract Methods

#if !TARGET_OS_WATCH
/**
 * Creates the editor views for the control
 * This views are placed inside a container view, that draws the margin, borde, padding, label and accessory view when necesary
 * For internal use, called in loadContentViewsWithContentFrame:intoContainerView: which is called in loadView
 */
- (void)loadEditorViewsWithEditorFrame:(CGRect)contentFrame intoContainerView:(UIView *)containerView;

/**
 * Layout editor views loaded in loadEditorViewsWithEditorFrame:intoContainerView:
 * Called on layoutContentViewsWithContentFrame:
 */
- (void)layoutEditorViewsWithEditorFrame:(CGRect)editorFrame;
#endif // !TARGET_OS_WATCH

/**
 * Loads self.entityDataFieldValue to control
 * Called on onEntityDataFiledValueChanged: and on viewDidLoad
 */
- (void)loadEntityDataFieldValue;

@end



#pragma mark - User Actions

@protocol GXControlWithLabelBaseUserActions <GXControlBaseUserActions>
#if !TARGET_OS_WATCH
@property(nullable, nonatomic, strong, readonly) NSString *controlUserActionAccessoryButtonIdentifier; // Handled on accessoryView (Button)
#endif // !TARGET_OS_WATCH
@end

@interface GXControlWithLabelBaseMutableUserActions : GXControlBaseMutableUserActions <GXControlWithLabelBaseUserActions>
#if !TARGET_OS_WATCH
- (void)setControlUserActionAccessoryButtonIdentifier:(nullable NSString *)userActionId;
#endif // !TARGET_OS_WATCH
@end

extern NSString *const GXControlWithLabelBaseUserActionIdentifierBusinessComponentRelation;

@interface GXControlWithLabelBase (GXUserActions) <GXControlWithLabelBaseUserActions>

#pragma mark - Control User Actions Override Points

/// Subclasses should override this method instead of loadControlUserActions:
- (void)loadControlWithLabelBaseUserActions:(GXControlWithLabelBaseMutableUserActions *)controlUserActions;

#if !TARGET_OS_WATCH
/// Returns YES if self.controlUserActionTapIdentifier requires an accesoryView, NO otherwise (called on updateUserActionsFrom:).
- (BOOL)controlUserActionTapRequiresAccessoryView;
#endif // !TARGET_OS_WATCH

@end




#pragma mark - Reuse

#if !TARGET_OS_WATCH
@interface GXControlWithLabelBaseReuseContext : GXControlBaseReuseContext

@property(nonatomic, assign) BOOL restoreLayoutElementCaption;

@end

@interface GXControlWithLabelBase (Reuse)

@property(nullable, nonatomic, strong, readonly) GXControlWithLabelBaseReuseContext *labelReuseContext;

@end
#endif // !TARGET_OS_WATCH

NS_ASSUME_NONNULL_END
