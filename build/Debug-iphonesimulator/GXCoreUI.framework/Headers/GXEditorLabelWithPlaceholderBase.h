//
//  GXEditorLabelWithPlaceholderBase.h
//  GXCoreUI
//
//  Created by Marcos Crispino on 6/10/20.
//  Copyright © 2020 GeneXus. All rights reserved.
//

#import <GXCoreUI/GXEditorLabelBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXEditorLabelWithPlaceholderBase : GXEditorLabelBase

@property(null_resettable, nonatomic, strong) UIColor *placeholderColor;
@property(nonatomic, strong) NSString *placeholder;
@property(assign, readonly) BOOL textIsPlaceholder;

#if TARGET_OS_IOS
@property(nonatomic, assign) BOOL useTintColorAsTextColor;
#endif

- (UIColor *)updateTextColorForCurrentState;

@end

NS_ASSUME_NONNULL_END
