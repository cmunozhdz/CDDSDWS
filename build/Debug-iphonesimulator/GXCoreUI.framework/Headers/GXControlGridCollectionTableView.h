//
//  GXControlGridCollectionTableView.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 20/6/17.
//  Copyright © 2017 GeneXus. All rights reserved.
//

#import <GXCoreUI/GXControlGridCollectionTableViewCell.h>
#import <GXCoreUI/GXBackgroundViewContainerProtocol.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, GXControlGridCollectionTableViewScrollPosition) {
	GXControlGridCollectionTableViewScrollPositionNone,
	GXControlGridCollectionTableViewScrollPositionBegin,
	GXControlGridCollectionTableViewScrollPositionMiddle,
	GXControlGridCollectionTableViewScrollPositionEnd,
};

@protocol GXControlGridCollectionTableView <GXBackgroundViewContainer, NSObject>

- (void)gxRegisterClass:(nullable Class)cellClass forCellWithReuseIdentifier:(NSString *)identifier;
- (__kindof UIView<GXControlGridCollectionTableViewCell> *)gxDequeueReusableCellWithReuseIdentifier:(NSString *)identifier forIndexPath:(NSIndexPath *)indexPath;

@property(nullable, nonatomic, readonly) NSArray<NSIndexPath *> *gxIndexPathsForSelectedItems;
- (void)gxSelectItemAtIndexPath:(nullable NSIndexPath *)indexPath animated:(BOOL)animated scrollPosition:(GXControlGridCollectionTableViewScrollPosition)scrollPosition;
- (void)gxDeselectItemAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated;

- (void)gxReloadData; // gxReloadData:NO
- (void)gxReloadData:(BOOL)forceDataSourceDelegateUpdates;

@property(nonatomic, readonly) NSInteger gxNumberOfSections;
- (NSInteger)gxNumberOfItemsInSection:(NSInteger)section;

- (nullable NSIndexPath *)gxIndexPathForCell:(__kindof UIView<GXControlGridCollectionTableViewCell> *)cell;

- (nullable __kindof UIView<GXControlGridCollectionTableViewCell> *)gxCellForItemAtIndexPath:(NSIndexPath *)indexPath;

@property(nonatomic, readonly) NSArray<__kindof UIView<GXControlGridCollectionTableViewCell> *> *gxVisibleCells;
@property(nonatomic, readonly) NSArray<NSIndexPath *> *gxIndexPathsForVisibleItems;


- (void)gxScrollToItemAtIndexPath:(NSIndexPath *)indexPath
				 atScrollPosition:(GXControlGridCollectionTableViewScrollPosition)scrollPosition
						 animated:(BOOL)animated;

- (void)gxInsertSections:(NSIndexSet *)sections;
- (void)gxDeleteSections:(NSIndexSet *)sections;
- (void)gxReloadSections:(NSIndexSet *)sections; // animated: NO
- (void)gxReloadSections:(NSIndexSet *)sections animated:(BOOL)animated;
- (void)gxMoveSection:(NSInteger)section toSection:(NSInteger)newSection;

- (void)gxInsertItemsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths;
- (void)gxDeleteItemsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths;
- (void)gxReloadItemsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths; // animated: NO
- (void)gxReloadItemsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths animated:(BOOL)animated;
- (void)gxMoveItemAtIndexPath:(NSIndexPath *)indexPath toIndexPath:(NSIndexPath *)newIndexPath;

- (void)gxPerformBatchUpdates:(void (^ __nullable)(void))updates completion:(void (^ __nullable)(BOOL finished))completion; // allows multiple insert/delete/reload/move calls to be animated simultaneously. Nestable.

@end

NS_ASSUME_NONNULL_END
