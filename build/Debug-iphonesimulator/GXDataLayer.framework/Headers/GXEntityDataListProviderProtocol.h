//
//  GXEntityDataListProviderProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 16/10/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

#import <GXDataLayer/GXEntityDataProviderProtocol.h>
#import <GXDataLayer/GXDynamicPropertiesCollection.h>

NS_ASSUME_NONNULL_BEGIN

#define kTotalCountUnknownLocal NSIntegerMin	// This state means the provider has nothing loaded yet
#define kTotalCountUnknownPending NSIntegerMax	// The provider has data loaded, but there could be more pages to load
extern NSInteger const GXTotalCountUnknownLocal;
extern NSInteger const GXTotalCountUnknownPending;

@protocol GXEntityDataListProviderDelegate;

@protocol GXEntityDataListProvider <GXEntityDataProvider>

@property(nonatomic, strong, readonly) id <GXCollectionEntityDataSourceDescriptor> listEntityDataSource;

@property(nullable, nonatomic, weak, readonly) id <GXEntityDataListProviderDelegate> listDelegate;

// Async loading
@property(nonatomic, assign, readonly) NSUInteger numberOfLoadedSections;
- (NSUInteger)numberOfLoadedEntitiesInSection:(NSInteger)section;
- (NSUInteger)indexInAllSectionOfEntityAtIndex:(NSUInteger)index section:(NSUInteger)section;
/**
 * If allPagesLoaded returns YES then totalCount returns the total number of loaded items in all sections,
 * otherwise totalCount is a constant representing the loaded state (kTotalCountUnknownLocal or if provider conforms to GXRemoteEntityDataListProvider also could return kTotalCountUnknownRemote or kTotalCountUnknownPendingRemote)
 */
@property(nonatomic, assign, readonly) NSInteger totalCount;

/**
 * Returns YES if all pages are loaded, NO otherwise
 */
@property(nonatomic, assign, readonly) BOOL allPagesLoaded;

- (void)load;

/**
 * Makes the provider refresh
 * Helper method for passing option GXEntityDataListProviderAllLoadedDataOptionKey = [NSNumber numberWithBool:allLoadedData]
 * Calling [self refresh] must be the same as calling refreshAllLoadedData: with allLoadedData = NO
 */
- (void)refreshAllLoadedData:(BOOL)allLoadedData;

// Access loaded data
- (nullable id <GXEntityDataWithOverrideValues>)entityDataAtIndex:(NSUInteger)index section:(NSUInteger)section;
/**
 * Returns all entities from all sections
 * It creates an array on each call to join all sections
 */
- (NSArray<id<GXEntityDataWithOverrideValues>> *)allEntitiesDataInAllSections;
/**
 * Executes a given block using each loaded entity
 */
- (void)enumerateLoadedEntitiesUsingBlock:(void (^)(id <GXEntityDataWithOverrideValues> entityData, NSUInteger idx, NSUInteger section, BOOL *stop))block;

@end

@protocol GXEntityDataListFieldBasedProvider <GXEntityDataListProvider>

@property(nonatomic, strong, readonly) id<GXEntityDataFieldDescriptor> entityDataListFieldDescriptor;

@end

@protocol GXEntityDataListFieldBasedProviderWithDynamicProperties <GXEntityDataListFieldBasedProvider>

/**
 * Returns an string containing a JSON array of triplets of [control name, property name, value]
 * For example: [ ["Ctldescription","Class","AttributeRed"], ["Ctldescription","Enabled","False"] ]
 * Consider using entityDataListFieldDynamicPropertiesCollectionAtIndex: instead.
 */
- (nullable NSString *)entityDataListFieldDynamicPropertiesAtIndex:(NSUInteger)index;

@optional
- (nullable GXDynamicPropertiesCollection *)entityDataListFieldDynamicPropertiesCollectionAtIndex:(NSUInteger)index;

@end

@protocol GXEntityDataListSDTProvider <GXEntityDataListFieldBasedProviderWithDynamicProperties>

@property(nonatomic, strong, readonly) id<GXEntityDataFieldDescriptor> entityDataListSDTFieldDescriptor;
@property(nonatomic, strong, readonly) NSString *entityDataListSDTFieldName;
@property(nullable, nonatomic, strong, readonly) NSString *entityDataListSDTFieldSpecifier;

@end

#pragma mark - GXEntityDataListProviderDelegate

@protocol GXEntityDataListProviderDelegate <GXEntityDataProviderDelegate>

- (nullable id <GXEntityData>)entityDataListProviderComposeParentEntityData:(id <GXEntityDataListProvider>)provider;

@optional
- (void)entityDataListProviderWillLoadEntityData:(id <GXEntityDataListProvider>)provider;
- (void)entityDataListProviderDidLoadEntityData:(id <GXEntityDataListProvider>)provider loadInfo:(nullable NSDictionary<NSString *, id> *)loadInfo;
- (void)entityDataListProvider:(id <GXEntityDataListProvider>)provider didFailLoadingWithError:(NSError *)error;
- (void)entityDataListProviderDidUnloadEntityData:(id <GXEntityDataListProvider>)provider;

@end


extern NSString *const GXEntityDataListProviderAllLoadedDataOptionKey;					// NSNumber with bool for using pigeSize = MIN(pageSize, allLoadedDataCount), default NO

extern NSString *const GXEntityDataListProviderInsertedIndexesKey;						// NSSet of NSIndexPath of new loaded entities
extern NSString *const GXEntityDataListProviderDeletedIndexesKey;						// NSSet of NSIndexPath of removed loaded entities
extern NSString *const GXEntityDataListProviderMovedIndexesKey;							// NSDictionary with new NSIndexPath by old NSIndexPath of moved loaded entities
extern NSString *const GXEntityDataListProviderTotalCountKey;							// NSNumber with old value of providers totalCount (or filteredTotalCount)
extern NSString *const GXEntityDataListProviderLoadedCountKey;							// NSNumber with old number of loaded entities
extern NSString *const GXEntityDataListProviderSectionsCountKey;						// NSArray of NSNumbers corresponding the old number of loaded entities for each section
extern NSString *const GXEntityDataListProviderRefreshKeepKey;							// NSNumber with bool
extern NSString *const GXEntityDataListProviderAllowOldEntityDataMatchingByIndexKey;	// NSNumber with bool

NS_ASSUME_NONNULL_END
