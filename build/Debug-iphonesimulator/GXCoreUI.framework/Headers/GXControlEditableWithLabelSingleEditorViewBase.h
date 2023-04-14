//
//  GXControlEditableWithLabelSingleEditorViewBase.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 12/01/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

#import <GXCoreUI/GXControlEditableWithLabelBase.h>
#import <GXCoreUI/GXControlWithLabelSingleEditorViewProtocol.h>

NS_ASSUME_NONNULL_BEGIN

// SEE GXControlWithLabelSingleEditorView PROTOCOL IF SUBCLASSING

@interface GXControlEditableWithLabelSingleEditorViewBase : GXControlEditableWithLabelBase <GXControlWithLabelSingleEditorView> {
}

#if !TARGET_OS_WATCH
- (UIFont *)controlFont;
#endif // !TARGET_OS_WATCH

#if TARGET_OS_IOS
- (void)presentWebViewControllerWithURL:(NSURL *)url;
#endif

#if !TARGET_OS_WATCH
/**
 * Replaces current loaded editor view with the given view
 * Should not be called if there is not an editor view loaded
 */
- (void)replaceLoadedEditorView:(UIView *)newEditorView;
#endif // !TARGET_OS_WATCH

@end

NS_ASSUME_NONNULL_END
