//
//  GXControlGridCollectionTableViewBase+GXGridViewDelegate.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 26/6/17.
//  Copyright © 2017 GeneXus. All rights reserved.
//

#import <GXCoreUI/GXControlGridCollectionTableViewBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXControlGridCollectionTableViewBase (GXGridViewDelegate)

- (CGSize)gridView:(UIScrollView<GXControlGridCollectionTableView> *)gridView sizeForItemAtIndexPath:(NSIndexPath *)vIndexPath;
- (CGFloat)gridView:(UIScrollView<GXControlGridCollectionTableView> *)gridView heightForItemAtIndexPath:(NSIndexPath *)vIndexPath;

- (BOOL)gridView:(UIScrollView<GXControlGridCollectionTableView> *)gridView shouldHighlightItemAtIndexPath:(NSIndexPath *)vIndexPath;
- (BOOL)gridView:(UIScrollView<GXControlGridCollectionTableView> *)gridView shouldSelectItemAtIndexPath:(NSIndexPath *)vIndexPath;

- (void)gridView:(UIScrollView<GXControlGridCollectionTableView> *)gridView didSelectItemAtIndexPath:(NSIndexPath *)vIndexPath;

- (void)gridView:(UIScrollView<GXControlGridCollectionTableView> *)gridView willDisplayCell:(UIView<GXControlGridCollectionTableViewCell> *)cell forItemAtIndexPath:(NSIndexPath *)vIndexPath;
- (void)gridView:(UIScrollView<GXControlGridCollectionTableView> *)gridView didEndDisplayingCell:(UIView<GXControlGridCollectionTableViewCell> *)cell forItemAtIndexPath:(NSIndexPath *)vIndexPath;

#if TARGET_OS_TV
- (BOOL)gridView:(UIScrollView<GXControlGridCollectionTableView> *)gridView canFocusItemAtIndexPath:(NSIndexPath *)vIndexPath;
#endif // TARGET_OS_TV

@end

NS_ASSUME_NONNULL_END
