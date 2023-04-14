//
//  GXControlWithDataEditable.h
//  GXFlexibleClient
//
//  Created by willy on 5/5/11.
//  Copyright 2011 Artech. All rights reserved.
//

#import <GXCoreUI/GXControlWithData.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXControlWithDataEditable <GXControlWithData>

@property(nonatomic, assign) BOOL readOnly;
@property(nonatomic, assign) BOOL allowsNull;
#if !TARGET_OS_WATCH
@property(nonatomic, assign, readonly) UITextAutocorrectionType autoCorrection;
@property(nonatomic, assign, readonly) UITextAutocapitalizationType autoCapitalization;
#endif // !TARGET_OS_WATCH

@optional

/**
 * Placehoder text is used to display an invite message when the field is empty and is in edit mode
 */
@property(nullable, nonatomic, strong) NSString *placeholder;

/**
 * Checks if control can receive focus (become first responder)
 * Called to determinate then next focusable control in GXLayoutElementDataEnterEventGoToNextField behaviour
 */
- (BOOL)canReceiveFocus;

/// Returns whether the control has focus (first responder)
@property(nonatomic, readonly, getter=isFocused) BOOL focused;

/// Sets or resigns the control as the first responder based on the given focus parameter, and displays or hides the keyboard if appropiate
- (void)setFocus:(BOOL)focus;

/**
 * Returns YES if the empty item should be added to the valid values of the control
 */
- (BOOL)shouldAddEmptyItem;

/**
 * Returs the text that should be displayed for the empty item
 */
- (NSString *)emptyItemText;

@end

NS_ASSUME_NONNULL_END
