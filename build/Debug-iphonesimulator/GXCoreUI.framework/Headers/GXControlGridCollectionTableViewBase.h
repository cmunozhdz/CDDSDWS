//
//  GXControlGridCollectionTableViewBase.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 16/6/17.
//  Copyright © 2017 GeneXus. All rights reserved.
//

#import <GXCoreUI/GXControlGridCollectionTableView.h>
#import <GXCoreUI/GXControlGridCollectionTableViewCell.h>
#import <GXCoreUI/GXControlGridCollectionTableViewCellAction.h>
#import <GXCoreUI/GXControlGridCollectionTableViewCellEntityData.h>
#import <GXCoreUI/GXControlMultilineSelectionGridBase.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint_least8_t, GXControlGridCollectionTableViewBaseItemSelectionMode) {
	GXControlGridCollectionTableViewBaseItemSelectionModeToggle = 1,
	GXControlGridCollectionTableViewBaseItemSelectionModeSelectOnly = 2,
	GXControlGridCollectionTableViewBaseItemSelectionModeDeselectOnly = 3,
};

@interface GXControlGridCollectionTableViewBase : GXControlMultilineSelectionGridBase <GXEntityDataListOrderProviderDelegate, UIScrollViewDelegate>

@property(nullable, nonatomic, strong, readonly) UIScrollView<GXControlGridCollectionTableView> *gridScrollView;

- (void)updateGridViewContentInsets:(UIScrollView<GXControlGridCollectionTableView> *)gridView;

- (void)updateGridViewDefaultItemSize:(UIScrollView<GXControlGridCollectionTableView> *)gridView;

- (void)reloadGridViewData:(nullable UIScrollView<GXControlGridCollectionTableView> *)gridView;

- (void)performCellViewItemSelection:(NSIndexPath *)vIndexPath
					   selectionMode:(GXControlGridCollectionTableViewBaseItemSelectionMode)mode
			 fireEventWithCompletion:(void (^ _Nullable)(void))completion;

#pragma mark - Abstract

- (void)makeGridViewReloadDelegateSelectors:(UIScrollView<GXControlGridCollectionTableView> *)gridView;

/// Returned class must conform to GXControlGridCollectionTableViewCellEntityData and must be a subclass of the required by gridView (UITableViewCell for UITableView & UICollectionViewCell for UICollectionView)
- (Class)classForCellEntityDataWithReuseIdentifier:(NSString *)identifier;

@end

NS_ASSUME_NONNULL_END
