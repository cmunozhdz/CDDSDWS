//
//  GXControlGridCollectionTableViewBase+GXGridViewDataSourceDelegate.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 26/6/17.
//  Copyright © 2017 GeneXus. All rights reserved.
//

#import <GXCoreUI/GXControlGridCollectionTableViewBase.h>
#import <GXCoreUI/GXControlGridBaseWithSelection+GXGridViewDataSourceDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXControlGridCollectionTableViewBase (GXGridViewDataSourceDelegate)

- (NSInteger)numberOfSectionsInSearchMode:(BOOL)searching;
- (NSInteger)numberOfSectionsInGridView:(UIScrollView<GXControlGridCollectionTableView> *)gridView;

- (NSInteger)numberOfItemsInSection:(NSInteger)pSection searchMode:(BOOL)searching;
- (NSInteger)gridView:(UIScrollView<GXControlGridCollectionTableView> *)gridView numberOfItemsInSection:(NSInteger)vSection;

- (__kindof UIView<GXControlGridCollectionTableViewCell> *)gridView:(UIScrollView<GXControlGridCollectionTableView> *)gridView
											 cellForItemAtIndexPath:(NSIndexPath *)vIndexPath;

- (nullable NSString *)gridView:(UIScrollView<GXControlGridCollectionTableView> *)gridView titleForHeaderInSection:(NSInteger)section;

- (nullable NSArray<NSString *> *)indexTitlesForGridView:(UIScrollView<GXControlGridCollectionTableView> *)gridView;
- (NSIndexPath *)gridView:(UIScrollView<GXControlGridCollectionTableView> *)gridView indexPathForIndexTitle:(NSString *)title atIndex:(NSInteger)index;

@end

NS_ASSUME_NONNULL_END
