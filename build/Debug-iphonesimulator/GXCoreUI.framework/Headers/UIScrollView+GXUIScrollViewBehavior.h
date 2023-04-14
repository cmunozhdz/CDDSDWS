//
//  UIScrollView+GXUIScrollViewBehavior.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 3/7/18.
//  Copyright © 2018 GeneXus. All rights reserved.
//

#import <GXCoreUI/UIScrollView+GXHelpers.h>
#import <GXCoreUI/GXScrollableControlProtocol.h>
#import <GXCoreUI/GXControlScrollIntoViewTypes.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXUIScrollViewBehavior

@property(nonatomic, assign) CGPoint gxContentOffset;
@property(nonatomic, assign) CGSize gxContentSize;
@property(nonatomic, assign) UIEdgeInsets gxContentInset;
@property(nonatomic, readonly) UIEdgeInsets gxAdjustedContentInset;

- (void)gxSetContentOffset:(CGPoint)contentOffset animated:(BOOL)animated;

- (void)gxScrollRectToVisible:(CGRect)rect position:(GXScrollIntoViewPosition)pos animated:(BOOL)animated;

@optional
// #deprecated: 2021-08-05: v17u6; #to-remove: v17u9
- (void)gxScrollRectToVisible:(CGRect)rect animated:(BOOL)animated __deprecated_msg("Implement gxScrollRectToVisible:position:animated:");

@end


@interface UIScrollView (GXUIScrollViewBehavior) <GXUIScrollViewBehavior>

+ (BOOL)gxContentAllowsScrolling:(__kindof UIView<GXUIScrollViewBehavior> *)scrollView;
+ (BOOL)gxContentAllowsHorizontalScrolling:(__kindof UIView<GXUIScrollViewBehavior> *)scrollView;
+ (BOOL)gxContentAllowsVerticalScrolling:(__kindof UIView<GXUIScrollViewBehavior> *)scrollView;

+ (BOOL)gxContentAllowsScrollingWithBoundsSize:(CGSize)boundsSize
								   contentSize:(CGSize)contentSize
						  adjustedContentInset:(UIEdgeInsets)adjustedContentInset
									horizontal:(BOOL)horizontal
									  vertical:(BOOL)vertical;

+ (BOOL)gxScrollEnabledRequiredForScrollView:(__kindof UIView<GXUIScrollViewBehavior> *)scrollView;

+ (CGPoint)gxConstrainedContentOffset:(CGPoint)contentOffset
						forScrollView:(__kindof UIView<GXUIScrollViewBehavior> *)scrollView; // Vertical & Horizontal
+ (CGPoint)gxConstrainedContentOffset:(CGPoint)contentOffset
						   horizontal:(BOOL)horizontal
							 vertical:(BOOL)vertical
						forScrollView:(__kindof UIView<GXUIScrollViewBehavior> *)scrollView;
+ (BOOL)gxIsValidContentOffset:(CGPoint)contentOffset
				 forScrollView:(__kindof UIView<GXUIScrollViewBehavior> *)scrollView; // Vertical & Horizontal
+ (BOOL)gxIsValidContentOffset:(CGPoint)contentOffset
					horizontal:(BOOL)horizontal
					  vertical:(BOOL)vertical
				 forScrollView:(__kindof UIView<GXUIScrollViewBehavior> *)scrollView;

+ (CGPoint)gxContentOffsetForScrollRectToVisible:(CGRect)rect
										position:(GXScrollIntoViewPosition)pos
								   forScrollView:(__kindof UIView<GXUIScrollViewBehavior> *)scrollView;

@end

NS_ASSUME_NONNULL_END
