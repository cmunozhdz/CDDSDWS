//
//  GXControlWithLabelSingleEditorViewProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 12/01/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

#import <GXCoreUI/GXControlWithData.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXControlWithLabelSingleEditorView <GXControlWithData>

#if !TARGET_OS_WATCH
@property(nullable, nonatomic, strong, readonly) UIView *loadedEditorView;
#else
@property(nonatomic, strong, readonly) WKInterfaceObject *editorInterfaceObject;
#endif // !TARGET_OS_WATCH

#if !TARGET_OS_WATCH
@property(nonatomic, readonly, getter=isEditorViewLoaded) BOOL editorViewLoaded;
#else
@property(nonatomic, readonly, getter=isEditorInterfaceObjectSameAsRoot) BOOL editorInterfaceObjectSameAsRoot;
#endif // !TARGET_OS_WATCH

#if !TARGET_OS_WATCH
/**
 * Returns frame for editorView created in newEditorViewWithFrame:
 * Default implementation returns GXPixelAlignedFrameWithMainScreenScale(editorFrame)
 * Called in loadEditorViewsWithEditorFrame:intoContainerView: and layoutContentViewsWithEditorFrame:
 * Subclasses could override this method to align editorView inside editorFrame or change it's size if editorView is smalled than editorFrame
 */
- (CGRect)editorViewFrameForEditorFrame:(CGRect)editorFrame;

#pragma mark - Abstract Methods

/**
 * Creates the editor view for the control
 * This views are placed inside a container view, that draws the margin, borde, padding, label and accessory view when necesary
 * For internal use, called in loadEditorViewsWithEditorFrame:intoContainerView:, called in loadContentViewsWithContentFrame:intoContainerView:, called in loadView
 */
- (UIView *)newEditorViewWithFrame:(CGRect)frame;
#endif // !TARGET_OS_WATCH

@end

NS_ASSUME_NONNULL_END
