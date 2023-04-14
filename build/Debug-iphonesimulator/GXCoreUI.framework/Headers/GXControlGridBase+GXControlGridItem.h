//
//  GXControlGridBase+GXControlGridItem.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 11/5/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

#import <GXCoreUI/GXControlGridBase.h>
#if !TARGET_OS_WATCH
#import <GXCoreUI/GXControlGridBase+GXHeightCalculationHelper.h>
#endif // !TARGET_OS_WATCH
#import <GXCoreUI/GXControlGridItem.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXControlGridBase (GXControlGridItem) <GXControlGridItemDelegate>

/// Returns the index path for the given grid item. Default implementation returns nil.
- (nullable NSIndexPath *)indexPathForGridItem:(id <GXControlGridItem>)gridItem;

/// Returns YES if the given grid item belongs to the filtered state, NO other wise. Default implementation returns [self.entityDataListSearchProvider searchText] != nil.
- (BOOL)gridItemIsFiltered:(id <GXControlGridItem>)gridItem;

#if !TARGET_OS_WATCH
/*!
 Override point called in GXControlGridItemDelegate's gridItem:needsHeightAdjustment: when grid item height changed to dynamic at runtime.
 
 @param gridItemHelper Grid item height calculation helper which height became dynamic.
 @discussion Default implementation calls reloadData if view is lodaded
 */
- (void)onGridItemHeightDidBecomeDynamic:(GXControlGridItemHeightCalculationHelper *)gridItemHelper;
#endif // !TARGET_OS_WATCH

@end

NS_ASSUME_NONNULL_END
