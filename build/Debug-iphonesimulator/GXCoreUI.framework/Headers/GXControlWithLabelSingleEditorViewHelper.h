//
//  GXControlWithLabelSingleEditorViewHelper.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 12/01/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

#import <GXCoreUI/GXControlWithLabelBase.h>
#import <GXCoreUI/GXControlWithLabelSingleEditorViewProtocol.h>

NS_ASSUME_NONNULL_BEGIN

// Default Implementation for GXControlWithLabelSingleEditorView Protocol

@interface GXControlWithLabelSingleEditorViewHelper : NSObject

+ (UIView *)newEditorViewForControl:(GXControlWithLabelBase<GXControlWithLabelSingleEditorView> *)control
						editorFrame:(CGRect)editorFrame
				  intoContainerView:(UIView *)containerView;

+ (void)layoutSingleEditorViewControl:(GXControlWithLabelBase<GXControlWithLabelSingleEditorView> *)control
					  withEditorFrame:(CGRect)editorFrame;

@end

NS_ASSUME_NONNULL_END
