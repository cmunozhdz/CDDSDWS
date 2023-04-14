//
//  GXEntityDataListSearchProviderProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 16/10/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

#import <GXDataLayer/GXEntityDataListProviderProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXEntityDataListSearchProvider <GXEntityDataListProvider>

@property(nullable, nonatomic, strong, readonly) NSString *searchText;
@property(nonatomic, assign, readonly) NSUInteger searchFieldIndex;
@property(nullable, nonatomic, strong, readonly) id <GXEntityListFilterSearchField> searchField;
- (BOOL)applySearchFilterForFieldAtIndex:(NSUInteger)searchFieldIndex
							  searchText:(nullable NSString *)searchText;
//- (NSArray *)searchFieldNames;
//- (BOOL)applySearchFilterForFieldNames:(NSArray *)fieldNames
//							searchText:(NSString *)searchText;
- (BOOL)filterBySearchText:(nullable NSString *)searchText;
- (void)removeSearchFilter;

// Async search filtered loading
@property(nonatomic, assign, readonly) NSUInteger numberOfFilteredLoadedSections;
- (NSUInteger)numberOfFilteredLoadedEntitiesInSection:(NSInteger)section;
- (NSUInteger)indexInAllSectionOfFilteredEntityAtIndex:(NSUInteger)index section:(NSUInteger)section;

@property(nonatomic, assign, readonly) NSInteger filteredTotalCount;
@property(nonatomic, assign, readonly) BOOL allFilteredPagesLoaded;

// Access search filtered loaded data
- (nullable id <GXEntityDataWithOverrideValues>)filteredEntityDataAtIndex:(NSUInteger)index section:(NSUInteger)section;

/**
 * Returns all filtered entities from all sections
 * It creates an array on each call to join all sections
 */
@property(nonatomic, copy, readonly) NSArray<id<GXEntityDataWithOverrideValues>> *allFilteredEntitiesDataInAllSections;

@property(nullable, nonatomic, strong, readonly) NSDate *filteredLoadedDataTimeStamp;

/**
 * Executes a given block using each loaded entity
 */
- (void)enumerateFilteredLoadedEntitiesWithBlock:(void (^)(id <GXEntityDataWithOverrideValues> entityData, NSUInteger idx, NSUInteger section, BOOL *stop))block;

@end

#pragma mark - GXEntityDataListSearchProviderDelegate

@protocol GXEntityDataListSearchProviderDelegate <GXEntityDataListProviderDelegate>

@optional
- (void)entityDataListProviderDidLoadFilteredEntityData:(id <GXEntityDataListSearchProvider>)provider;

- (void)entityDataListProviderSearchFilterDidChange:(id <GXEntityDataListSearchProvider>)provider;

@end

NS_ASSUME_NONNULL_END
