//
//  GXControlEditableWithLabelAndInputViewBase.h
//  GXCoreUI
//
//  Created by Marcos Crispino on 6/11/20.
//  Copyright © 2020 GeneXus. All rights reserved.
//

#import <GXCoreUI/GXControlEditableWithLabelAndPickerBase.h>
#import <GXCoreUI/GXControlWithInputView.h>
#import <GXCoreUI/GXEditorLabelWithPlaceholderBase.h>
#import <GXCoreUI/GXEditorLabelWithPlaceholderAndInputViewBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXControlEditableWithLabelAndInputViewBase : GXControlEditableWithLabelAndPickerBase <GXControlWithInputView>

@property (nullable, nonatomic, readonly) GXEditorLabelWithPlaceholderAndInputViewBase *loadedEditorWithPlaceholderAndInputView;

#pragma mark - Override points

/**
 Called by -controlEditableHandleEdit:withPicker:
 */
- (void)setupPickerForInputViewDisplay;

@end

NS_ASSUME_NONNULL_END
