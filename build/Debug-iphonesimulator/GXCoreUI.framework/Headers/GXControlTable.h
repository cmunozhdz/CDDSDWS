//
//  GXEntityDataViewController.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 07/04/11.
//  Copyright 2011 Artech. All rights reserved.
//

#import <GXCoreUI/GXControlContainerBase.h>
#if !TARGET_OS_WATCH
#import <GXCoreUI/GXScrollableControlProtocol.h>
#endif // !TARGET_OS_WATCH

NS_ASSUME_NONNULL_BEGIN

// Abstract Class
#if !TARGET_OS_WATCH
@interface GXControlTableBase : GXControlContainerBase <GXViewLayoutDelegate,
														GXControlAutoHeight,
														UIScrollViewDelegate,
														GXScrollableControl>
#else
@interface GXControlTableBase : GXControlContainerBase
#endif // !TARGET_OS_WATCH

@property(nonatomic, strong, readonly) id <GXLayoutElementTable> tableLayout;
#if !TARGET_OS_WATCH
@property(nonatomic, assign, readonly) GXLayoutDimension tableLayoutElementTableWidth; // Default implementation returns tableLayout.layoutElementTableWidth
@property(nonatomic, assign, readonly) GXLayoutDimension tableLayoutElementTableHeight; // Default implementation returns tableLayout.layoutElementTableHeight
@property(nonatomic, assign) BOOL autoGrow;
#endif // !TARGET_OS_WATCH

#ifdef DEBUG
@property (nullable, nonatomic, strong) NSString *annotation;
#endif

- (nullable GXStyleClass *)styleClassFromLayoutElement;
- (void)applyStyleClassFromLayoutElement;

#if !TARGET_OS_WATCH
- (void)setFrame:(CGRect)frame additionalHeight:(CGFloat)additionalHeight;
@property(nonatomic, assign, readonly) CGFloat additionalHeightForCurrentFrame;

/* Abstract
@property (nonatomic, readonly) id<GXEntityDataWithOverrideValues> containerLoadedEntityData;
*/

- (CGFloat)firstRowHeight;
#endif // !TARGET_OS_WATCH

#if !TARGET_OS_WATCH
- (void)layoutControls;
#endif // !TARGET_OS_WATCH


@end

@interface GXControlTable : GXControlTableBase

@end

NS_ASSUME_NONNULL_END
