//
//  GXControlGridBaseLoadedInfo.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 9/5/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import Foundation;
@import CoreGraphics;

@interface GXControlGridBaseLoadedInfo : NSObject

@property(nonatomic, assign) NSUInteger numberOfLoadedSectionsWithoutSupplementaryElements;
@property(nonatomic, assign, readonly) NSUInteger numberOfLoadedSections;

- (NSUInteger)numberOfLoadedItemsInSection:(NSUInteger)section;
- (NSUInteger)numberOfLoadedItemsWithoutSupplementaryElements:(NSUInteger)section;
- (void)setNumberOfLoadedItemsWithoutSupplementaryElements:(NSUInteger)itemsCount inSection:(NSUInteger)section;

/**
 * Given an absolute index, returns the index path for that item.
 *
 * The 'absolute index' is obtained by enumerating the items in each section and counting them, order by section and row number
 *
 * For example, if the loaded info contains {section: 0, count: 3; section: 1, count: 2; section 2: count: 4} then the index 0
 * would be {section: 0, row: 0}, and index 5 would be {section: 2, row: 0}.
 *
 * Returns nil if not found.
 */
- (nullable NSIndexPath *)indexPathForItemAtAbsoluteIndex:(NSUInteger)index;

/**
 * Given an absolute index, returns the reversed index path for that item.
 *
 * The 'absolute index' is obtained by enumerating the items in each section and counting them, order by section and row number
 *
 * The 'reversed index path' is obtained by enumerating the sections in reverse order, and the rows in each section in reverse order
 *
 * For example, if the loaded info contains {section: 0, count: 3; section: 1, count: 2; section 2: count: 4} then the index 5 would 
 * have a reversed indez path of {section: 0, row: 3}.
 *
 * Returns nil if not found.
 */
- (nullable NSIndexPath *)reversedIndexPathForItemAtAbsoluteIndex:(NSUInteger)index;

/**
 * Given an index path, returns the absolute index for that item.
 *
 * The 'absolute index' is obtained by enumerating the items in each section and counting them, order by section and row number
 *
 * For example, if the loaded info contains {section: 0, count: 3; section: 1, count: 2; section 2: count: 4} then the index 0
 * would be {section: 0, row: 0}, and index 5 would be {section: 1, row: 1}.
 *
 * Returns NSNotFound if not found.
 */
- (NSUInteger)absoluteIndexForIndexPath:(nonnull NSIndexPath *)indexPath;

- (NSUInteger)absoluteIndexForReversedIndexPath:(nonnull NSIndexPath *)revIndexPath;

/**
 * Returns the total number of items in all sections
 */
- (NSUInteger)totalCount;

@end


#if !TARGET_OS_WATCH
#define kGXControlGridItemHeightLoadedInfoIndexPathNotFound -1.0

@interface GXControlGridItemHeightLoadedInfo : NSObject

- (CGFloat)heightForItemAtIndexPath:(nonnull NSIndexPath *)indexPath; // If index path is not found, returns kGXControlGridItemHeightLoadedInfoIndexPathNotFound
- (void)setHeight:(CGFloat)itemHeight forItemAtIndexPath:(nonnull NSIndexPath *)indexPath;
- (void)removeHeightForItemAtIndexPath:(nonnull NSIndexPath *)indexPath;

@end


@interface GXControlGridBaseLoadedInfo (ItemHeight)

@property(nonatomic, strong, readonly, nonnull) GXControlGridItemHeightLoadedInfo *calculatedItemHeights;
@property(nonatomic, strong, readonly, nonnull) GXControlGridItemHeightLoadedInfo *runtimeItemHeights;

/// Returns runtime (or calulated if there is no runtime stored height) for the given index path. If index path is not found, returns kGXControlGridItemHeightLoadedInfoIndexPathNotFound
- (CGFloat)heightForItemAtIndexPath:(nonnull NSIndexPath *)indexPath;

@end
#endif // !TARGET_OS_WATCH
