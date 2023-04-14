//
//  GXControlGridCollectionTableViewBase+GXLoadingItem.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 21/6/17.
//  Copyright © 2017 GeneXus. All rights reserved.
//

#import <GXCoreUI/GXControlGridCollectionTableViewBase.h>
#import <GXCoreUI/GXControlGridCollectionTableViewCellAction.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXControlGridCollectionTableViewBase (GXLoadingItem)

+ (NSString *)gridLoadingCellReuseIdentifier;

@property(nonatomic, readonly) BOOL gridLoadingCellSupported; // Defaults to NO
@property(nonatomic, readonly) BOOL gridShouldAutoLoadOnLastCellVisible; // Defaults to !self.gridLoadingCellSupported

- (BOOL)isGridLoadingItem:(UIView<GXControlGridReusableItem> *)gridViewCell;

- (BOOL)isGridLoadingItemAtIndex:(NSUInteger)pIndex section:(NSUInteger)pSection;
- (BOOL)isGridLoadingItemAtIndex:(NSUInteger)pIndex section:(NSUInteger)pSection filtered:(BOOL)filtered;

- (void)updateLoadingCellAction:(UIView<GXControlGridCollectionTableViewCellAction> *)cell
					   gridView:(UIScrollView<GXControlGridCollectionTableView> *)gridView
					  asyncLoad:(BOOL)asyncLoad;

- (void)updateLoadingCellAction:(UIView<GXControlGridCollectionTableViewCellAction> *)cell
					   gridView:(UIScrollView<GXControlGridCollectionTableView> *)gridView; // asyncLoad = NO;

- (void)autoLoadOnLastCellVisibleIfNeededWithVisibleCell:(__kindof UIView<GXControlGridCollectionTableViewCell> *)cell
											 atIndexPath:(NSIndexPath *)vIndexPath
												gridView:(UIScrollView<GXControlGridCollectionTableView> *)gridView
											   asyncLoad:(BOOL)asyncLoad;

@end

NS_ASSUME_NONNULL_END
