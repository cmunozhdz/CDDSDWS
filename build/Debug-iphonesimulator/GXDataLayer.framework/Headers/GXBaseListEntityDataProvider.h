//
//  GXBaseGridEntityDataProvider.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 09/12/11.
//  Copyright (c) 2011 Artech. All rights reserved.
//

#import <GXDataLayer/GXBaseEntityDataProvider.h>
#import <GXDataLayer/GXEntityDataListProviderProtocol.h>
#import <GXDataLayer/GXEntityDataListSearchProviderProtocol.h>
#import <GXDataLayer/GXEntityDataListOrderProviderProtocol.h>
#import <GXDataLayer/GXEntityDataListBreakByProviderProtocol.h>
#import <GXDataLayer/GXEntityDataListAdvancedFilterProviderProtocol.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint_least8_t, GXEntityDataListProviderState) {
	GXEntityDataListProviderStateIdle,
	GXEntityDataListProviderStateLoading
};

@interface GXBaseListEntityDataProvider : GXBaseEntityDataProvider <GXEntityDataListProvider, GXEntityDataListSearchProvider, GXEntityDataListOrderProvider, GXEntityDataListBreakByProvider, GXEntityDataListAdvancedFilterProvider>

// GXEntityDataListProvider
@property(nullable, nonatomic, strong, readonly) NSArray<NSArray<id<GXEntityDataWithOverrideValues>> *> *loadedEntities;
@property(nonatomic, assign, readonly) NSUInteger loadedEntitiesCount;
@property(nonatomic, assign) NSUInteger pageSize;

// GXEntityDataListSearchProvider
@property(nullable, nonatomic, strong, readonly) NSString *searchText;
@property(nonatomic, assign, readonly) NSUInteger searchFieldIndex;
@property(nullable, nonatomic, strong, readonly) NSArray<NSArray<id<GXEntityDataWithOverrideValues>> *> *filteredLoadedEntities;
@property(nonatomic, assign, readonly) NSUInteger filteredLoadedEntitiesCount;

// GXEntityDataListOrderProvider
@property(nonatomic, assign, readonly) NSUInteger orderIndex;
@property(nullable, nonatomic, strong, readonly) NSArray<NSString *> *loadedAlphaIndexTitles;
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, NSValue *> *loadedAlphaIndexRangesByTitle; // NSValue has rangeValue (NSRange)

// GXEntityDataListAdvancedFilterProvider
@property(nullable, nonatomic, strong, readonly) NSArray<id<GXEntityListFilterAdvancedFieldValue>> *advancedFilterValues;

// Common
@property(nonatomic, assign, readonly) GXEntityDataListProviderState state;
@property(nullable, nonatomic, strong, readonly) id <GXEntityDataQueryCollectionInfo> currentQueryCollectionInfo;
@property(nullable, nonatomic, strong, readonly) id <GXEntityDataQueryCollectionInfo> lastQueryCollectionInfo;
@property(nullable, nonatomic, strong, readonly) id <GXEntityDataQueryCollectionResult> lastQueryCollectionResult;

#pragma mark - Override Points

/**
 * Returns the initial query type for the current state
 */
- (GXEntityDataQueryType)queryTypeForCurrentState;

/**
 * Called in onDidFinishLoadingQuerySuccesfully:withResult:context:
 * Default implementations returns queryInfo.type == GXEntityDataQueryTypeFirst || queryInfo.type == GXEntityDataQueryTypeRefresh && !queryInfo.allLoadedData
 */
- (BOOL)shouldAddLoadedInfoRefreshKeepOnDidFinishLoadingQuerySuccesfully:(id<GXEntityDataQueryCollectionInfo>)queryInfo
																  result:(id<GXEntityDataQueryCollectionResult>)result
																 context:(NSMutableDictionary *)context;

@end

NS_ASSUME_NONNULL_END
