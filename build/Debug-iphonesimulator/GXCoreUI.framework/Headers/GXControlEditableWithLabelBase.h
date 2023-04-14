//
//  GXControlEditableWithLabelBase.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 17/06/11.
//  Copyright 2011 Artech. All rights reserved.
//

#import <GXCoreUI/GXControlWithDataEditable.h>
#import <GXCoreUI/GXControlWithLabelBase.h>

@interface GXControlEditableWithLabelBase : GXControlWithLabelBase <GXControlWithDataEditable> {
	BOOL _allowsNull;
    BOOL _readOnly;
}

/// Override point for subclasses to react to read only change. Default implementation invalidates resolved style class, user actions and resigns focus if the control supports focus.
- (void)onReadOnlyChanged;
/// Override point for subclasses to react to allows null change.
- (void)onAllowsNullChanged;

/// Helper to be called form controls which supports focus (isFocus). Default implementation invalidates resolved style class if supports focus and view is loaded.
- (void)onFocusChanged;

/// Calls [self updateEntityDataResolvedFieldWithValue:newValue forceEntityDataUpdate:NO]
- (void)updateEntityDataResolvedFieldWithValue:(nullable id)newValue;

/// Calls [self updateEntityDataResolvedFieldWithValue:newValue forceEntityDataUpdate:forceUpdate cancelEditingUIContextCommitChanges:NO];
- (void)updateEntityDataResolvedFieldWithValue:(nullable id)newValue
						 forceEntityDataUpdate:(BOOL)forceUpdate;

/**
 * Updates entity data with the given newValue
 * @param newValue The value to set
 * @param forceUpdate if YES, the value is updated even if the control is read-only
 * @param cancelEditingUIContextCommitChanges if YES, id<GXEditingUserInterfaceContext> is added to control value changed event ui context which cancels ui commit changes
 */
- (void)updateEntityDataResolvedFieldWithValue:(nullable id)newValue
						 forceEntityDataUpdate:(BOOL)forceUpdate
		   cancelEditingUIContextCommitChanges:(BOOL)cancelEditingUIContextCommitChanges;

@end


#pragma mark - Control User Actions

extern NSString *const __nonnull GXControlEditableWithLabelBaseUserActionIdentifierEditFieldValue;
extern NSString *const __nonnull GXControlEditableWithLabelBaseUserActionIdentifierEditFieldValueWithPicker;

@interface GXControlEditableWithLabelBase (GXUserActions)

#pragma mark - Override points

/// Default implementation returns userActionId == nil
- (BOOL)shouldUseEditActionActionInsteadOfAction:(nullable NSString *)userActionId;

/// Default implementation returns NO
- (BOOL)controlEditableCanEditFieldValue:(nonnull BOOL *)editWithPicker;

/// Handles GXControlEditableWithLabelBaseUserActionIdentifierEditFieldValue & GXControlEditableWithLabelBaseUserActionIdentifierEditFieldValueWithPicker actions
- (BOOL)controlEditableHandleEdit:(nullable id)sender withPicker:(BOOL)editWithPicker;

#if !TARGET_OS_WATCH
/// Creates a new picker to display to select the value for the control
- (nullable UIViewController<GXEntityDataFieldEditorViewController> *)newPickerEditorViewController;

/*!
 Updates the given presentation context for the given picker before presenting
 
 @param context Context to update
 @param pickerEditorViewController Picker editor view controller
 @param sender The sender from where the picker action was started
 @discussion Default implementation adds sender and self to the user interface context. Sets popover on iPad if gxAllowsPopupPresentation, else sets modal if [pickerViewController.navigationItem hidesBackButton] and gxAllowsModalPresentation.
 */
- (void)updatePresentationContext:(nonnull GXPresentationContext *)context
	forPickerEditorViewController:(nonnull UIViewController<GXEntityDataFieldEditorViewController> *)pickerEditorViewController
						   sender:(nullable id)sender;

/*!
 Presents the given picker editor view controller
 
 @param pickerEditorViewController Picker editor view controller to present
 @param sender The sender from where the picker action was started
 @param completion Completion block
 @result YES if picker was presented, NO otherwise
 @discussion Default sets self as delegate, sets shouldDelayEntityDataUpdatesUntilDissmissed = YES if has action for ControlValueChanged event, creates a new presentation context and calls updatePresentationContext:forPickerEditorViewController:sender:, and then presents the picker using self.controlDelegate.controlControllerPresentationHandler
 */
- (BOOL)presentPickerEditorViewController:(nonnull UIViewController<GXEntityDataFieldEditorViewController> *)pickerEditorViewController
								   sender:(nullable id)sender
							   completion:(void (^ __nullable)(void))completion;
#endif // !TARGET_OS_WATCH

@end

#pragma mark - Reuse

#if !TARGET_OS_WATCH
@interface GXControlEditableWithLabelBaseReuseContext : GXControlWithLabelBaseReuseContext

@property(nonatomic, assign) BOOL restoreLayoutElementReadOnly;

@end

@interface GXControlEditableWithLabelBase (Reuse)

@property(nonatomic, strong, readonly, nullable) GXControlEditableWithLabelBaseReuseContext *editableWithLabelReuseContext;

@end
#endif // !TARGET_OS_WATCH
