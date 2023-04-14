//
//  GXEntityDataQueryInfoProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 26/10/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint_least8_t, GXEntityDataQueryType) {
	GXEntityDataQueryTypeCached,	// Used in Remote Providers
	GXEntityDataQueryTypeFirst,
	GXEntityDataQueryTypeRefresh,
	GXEntityDataQueryTypeMore		// Used in List Providers
};

@protocol GXEntityDataQueryInfo <NSObject>

@property(nonatomic, strong, readonly) id <GXEntityDataSourceDescriptor> dataSource;
@property(assign, readonly) GXEntityDataQueryType type;
@property(nullable, nonatomic, strong, readonly) NSArray *parameters;
@property(assign, readonly) NSUInteger gxid;

- (BOOL)shouldLoad;

@end

@protocol GXEntityDataQuerySingleItemInfo <GXEntityDataQueryInfo>

@property(nonatomic, strong, readonly) id <GXSingleItemEntityDataSourceDescriptor> singleItemDataSource;

@end

@protocol GXEntityDataQueryCollectionInfo <GXEntityDataQueryInfo>

@property(nonatomic, strong, readonly) id <GXCollectionEntityDataSourceDescriptor> collectionDataSource;
/*!
 Indicates if all loaded data should be reloaded

 @discussion If allLoadedData = YES & pageSize > 0, the should load start = 0 & count = MIN(pageSize, loadedEntitiesCount)
 */
@property(nonatomic, assign, readonly) BOOL allLoadedData;
/*!
 Page Size
 
 @discussion pageSize = 0 means paging diabled, loading all at once (start = 0 & count = 0)
 */
@property(nonatomic, assign, readonly) NSUInteger pageSize;
@property(nonatomic, assign, readonly) NSUInteger orderIndex;
@property(nullable, nonatomic, strong, readonly) NSString *searchText;
@property(nonatomic, assign, readonly) NSUInteger searchFieldIndex;
@property(nullable, nonatomic, strong, readonly) NSArray<id<GXEntityListFilterAdvancedFieldValue>> *advancedFilterValues;

/// Returns order at orderIndex in collectionDataSource orders or nil
- (nullable id <GXEntityListOrder>)order;
/// returns search field at searchFieldIndex in collectionDataSource filterSearch or nil
- (nullable id <GXEntityListFilterSearchField>)searchField;

@end

NS_ASSUME_NONNULL_END
