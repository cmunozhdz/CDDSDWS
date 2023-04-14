//
//  GXEditorLabelWithPlaceholderAndInputViewBase.h
//  GXCoreUI
//
//  Created by Marcos Crispino on 6/10/20.
//  Copyright © 2020 GeneXus. All rights reserved.
//

#import <GXCoreUI/GXEditorLabelWithPlaceholderBase.h>
#import <GXCoreUI/GXControlEditableWithLabelBase.h>
#import <GXCoreUI/GXControlWithInputView.h>
#import <GXCoreUI/GXInlinePickerView.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXEditorLabelWithPlaceholderAndInputViewBase : GXEditorLabelWithPlaceholderBase <UITextInputTraits>

@property(nonatomic, weak) GXControlEditableWithLabelBase<GXControlWithInputView> *gxControl;

#pragma mark - Override points

@property (nonatomic, retain, nullable, readonly) UIView<GXInlinePickerView> *inlinePicker;

- (void)updateGXControlValueFromPicker;
- (void)loadPickerValueFromGXControl;

- (void)cleanPicker;

- (UIView *)setupInputView;

@end

NS_ASSUME_NONNULL_END
