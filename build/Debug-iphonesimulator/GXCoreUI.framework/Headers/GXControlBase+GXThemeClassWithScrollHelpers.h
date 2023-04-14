//
//  GXControlBase+GXThemeClassWithScrollHelpers.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 5/7/18.
//  Copyright © 2018 GeneXus. All rights reserved.
//

#import <GXCoreUI/GXControlBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXControlBase (GXThemeClassWithScrollHelpers)

/// Loaded scroll view to apply GXThemeClassWithScroll. Default implementation checks if self.loadedView is UIScrollView.
@property(nullable, nonatomic, strong, readonly) UIScrollView *loadedUIScrollView;

/// Applies GXStyleClassWithScroll properies to self.loadedUIScrollView if non nil
- (void)applyStyleClassWithScrollToLoadedUIScrollView;

/// Scroll Indicators Style to be applied to self.loadedUIScrollView
- (GXScrollIndicatorsStyle)scrollIndicatorsStyleWithStyleClassWithScroll:(nullable id<GXStyleClassWithScroll>)styleClassWithScroll;

/// Scroll Indicators Visibility to be applied to self.loadedUIScrollView
- (GXScrollIndicatorsVisibility)scrollIndicatorsVisibilityWithStyleClassWithScroll:(nullable id<GXStyleClassWithScroll>)styleClassWithScroll;

/// Scroll Bouncing Style to be applied to self.loadedUIScrollView
- (GXScrollBouncingStyle)scrollBouncingStyleWithStyleClassWithScroll:(nullable id<GXStyleClassWithScroll>)styleClassWithScroll;

/// Should return a value different of GXScrollIndicatorsVisibilityDefault. Default implementation returns GXScrollIndicatorsVisibilityBoth.
@property(nonatomic, assign, readonly) GXScrollIndicatorsVisibility resolvedScrollIndicatorsVisibilityDefault;
/// Should return a value different of GXScrollBouncingStyleDefault. Default implementation returns GXScrollBouncingStyleWhenContentAllowsScrolling.
@property(nonatomic, assign, readonly) GXScrollBouncingStyle resolvedScrollBouncingStyleDefault;

// Updates the value of self.loadedUIScrollView.scrollEnabled (if loadedUIScrollView is not nil). Default implementation calls [UIScrollView gxScrollEnabledRequiredForScrollView:self.loadedUIScrollView]
- (void)updateLoadedScrollViewScrollEnabled;

@end

NS_ASSUME_NONNULL_END
