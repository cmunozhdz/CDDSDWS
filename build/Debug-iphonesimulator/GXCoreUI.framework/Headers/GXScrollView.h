//
//  GXScrollView.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 28/12/11.
//  Copyright (c) 2011 Artech. All rights reserved.
//

@import UIKit;
#import <GXCoreUI/GXControlScrollIntoViewTypes.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXScrollView : UIScrollView

@property(nullable, nonatomic, strong) UIView *backgroundView;
@property(nonatomic, assign) BOOL scaleBackgroundViewToContentSize;

@end

// #deprecated: 2021-08-05: v17u6; #to-remove: v17u9
void GXScrollToMakeViewVisible(UIView * _Nonnull viewToMakeVisible, UIView * _Nullable upToView, BOOL animated) __deprecated_msg("Use GXScrollToMakeViewVisibleWithPosition(viewToMakeVisible, upToView, GXScrollIntoViewPositionUndefined, animated)"); // Same as GXScrollToMakeViewRectVisible(viewToMakeVisible.frame, viewToMakeVisible.superview, upToView, animated) if viewToMakeVisible.superview != nil.

// #deprecated: 2021-08-05: v17u6; #to-remove: v17u9
void GXScrollToMakeViewRectVisible(CGRect rectToMakeVisible, UIView * _Nonnull rectToMakeVisibleView, UIView * _Nullable upToView, BOOL animated) __deprecated_msg("Use GXScrollToMakeViewRectVisibleWithPosition(rectToMakeVisible, rectToMakeVisibleView, GXScrollIntoViewPositionUndefined, animated)");

void GXScrollToMakeViewVisibleWithPosition(UIView * _Nonnull viewToMakeVisible, UIView * _Nullable upToView, GXScrollIntoViewPosition position, BOOL animated); // Same as GXScrollToMakeViewRectVisible(viewToMakeVisible.frame, viewToMakeVisible.superview, upToView, position, animated) if viewToMakeVisible.superview != nil.

void GXScrollToMakeViewRectVisibleWithPosition(CGRect rectToMakeVisible, UIView * _Nonnull rectToMakeVisibleView, UIView * _Nullable upToView, GXScrollIntoViewPosition position, BOOL animated);

NS_ASSUME_NONNULL_END
