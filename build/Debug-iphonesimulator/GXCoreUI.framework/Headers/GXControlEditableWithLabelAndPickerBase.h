//
//  GXControlEditableWithLabelAndPickerBase.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 26/01/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

#import <GXCoreUI/GXControlEditableWithLabelSingleEditorViewBase.h>
#import <GXCoreUI/GXInlinePickerView.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXControlEditableWithLabelAndPickerBase : GXControlEditableWithLabelSingleEditorViewBase

#pragma mark - Abstract

/**
 * Returns a string with the value to be displayed in the control
 */
- (nullable NSString *)fieldValueToLoad;

#pragma mark - Inline picker asbtract

@property (nullable, nonatomic, readonly) UIView<GXInlinePickerView> *picker;

#pragma mark - Inline picker override points

/**
 * Returns wheather the control can present an inline picker.
 * Default implementation returns NO
 */
- (BOOL)canShowInlinePicker;

/**
 * Returns whether the controls is displaying an inline picker
 * Default implementation returns NO
 */
- (BOOL)isShowingInlinePicker;

/**
 * Sets the inline picker frame (in case it is showing) to the required height
 * Default implementation does nothing
 */
- (void)setInlinePickerFrameIfNeeded;

/**
 * Returns the default height for the associated inline picker
 */
- (CGFloat)defaultPickerHeight;

#pragma mark - Inline picker helpers

- (CGRect)inlinePickerFrame;

@end

NS_ASSUME_NONNULL_END
