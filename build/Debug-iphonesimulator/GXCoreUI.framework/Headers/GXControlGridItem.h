//
//  GXControlGridItem.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 16/3/15.
//  Copyright (c) 2015 Artech. All rights reserved.
//

#import <GXCoreUI/GXControlTableGridItem.h>
#if TARGET_OS_WATCH
#import <GXCoreUI/GXControlInterfaceObjectsProvider.h>
#endif // TARGET_OS_WATCH

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(uint_least8_t, GXControlGridItemHighlightStyleModifierFlags) {
	GXControlGridItemHighlightStyleModifierHighlightAllowed = 1 << 0,
	GXControlGridItemHighlightStyleModifierSelectAllowed = 1 << 1,
};

@protocol GXControlGridItemDelegate;

@protocol GXControlGridReusableItem <NSObject>

@property(nonatomic, strong, readonly, nullable) NSString *gridItemReuseIdentifier;

@end

@protocol GXControlGridItem <GXControlGridReusableItem>

@property(nonatomic, weak, nullable) id <GXControlGridItemDelegate> gridItemDelegate;

#if !TARGET_OS_WATCH
@property(nonatomic, strong, readonly) UIView *gridItemView;
#else
@property(nonatomic, strong, readonly) id<GXControlInterfaceObjectsProvider> gridItemInterfaceObjectsProvider;
#endif // !TARGET_OS_WATCH
@property(nonatomic, strong, readonly, nullable) GXControlTableGridItem *gridItemTable;

@property(nonatomic, strong, nullable) GXStyleClass *gridItemStyleClass;

#if !TARGET_OS_WATCH
@property(nonatomic, assign) CGSize gridItemRelativeSizeForPercentDimension;

@property(nonatomic, assign) BOOL gridItemSelected;
- (void)setGridItemSelected:(BOOL)selected animated:(BOOL)animated;

@property(nonatomic, assign, readonly) GXHighlightStyleType gridItemHighlightStyle;
@property(nonatomic, assign) GXControlGridItemHighlightStyleModifierFlags gridItemHighlightStyleModifiers;

@optional
@property(nonatomic, assign) BOOL showGridItemMultilineSelector;
#endif // !TARGET_OS_WATCH

@end


@protocol GXControlGridItemDelegate <NSObject>

#if !TARGET_OS_WATCH
- (void)gridItem:(id <GXControlGridItem>)gridItem needsHeightAdjustment:(CGFloat)requiredHeight;
#endif // !TARGET_OS_WATCH

@end


#if !TARGET_OS_WATCH
// Helper Base Implemetation
@interface GXControlGridItemView : UIView <GXControlGridItem>
@end
#endif // !TARGET_OS_WATCH

NS_ASSUME_NONNULL_END
