//
//  GXEntityDataProviderHelper.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 4/23/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

#import <GXDataLayer/GXEntityDataListProviderProtocol.h>
#import <GXDataLayer/GXEntityDataListSearchProviderProtocol.h>

NS_ASSUME_NONNULL_BEGIN

#define kSearchProviderNewFiltersDefaultDelayLocal			0.3
#define kSearchProviderNewFiltersDefaultDelayRemoteCache	0.1
#define kSearchProviderNewFiltersDefaultDelayRemote			0.4

@interface GXEntityDataProviderHelper : NSObject

/**
 * Returns minimum totalCount constant for unloaded state for the given provider
 */
+ (NSInteger)totalCountUnloadedConstantForProvider:(id<GXEntityDataListProvider>)provider;

/**
 * Returns minimum totalCount constant for unloaded state for the given data source
 */
+ (NSInteger)totalCountUnloadedConstantForDataSource:(id <GXCollectionEntityDataSourceDescriptor>)listEntityDataSource;

/**
* Returns totalCount constant for unknown pending items for the given provider
*/
+ (NSInteger)totalCountUnknownPendingConstantForProvider:(id<GXEntityDataListProvider>)provider;

/**
 * Returns totalCount constant for unknown pending items for the given data source
 */
+ (NSInteger)totalCountUnknownPendingConstantForDataSource:(id <GXCollectionEntityDataSourceDescriptor>)listEntityDataSource;

/**
 * Returns the default recomended delay for applying new filters to search provider while typing
 */
+ (NSTimeInterval)defaultDelayForApplyNewFiltersToSearchProvider:(id<GXEntityDataListSearchProvider>)provider;

/**
 * Returns the default recomended delay for applying new filters to search provider while typing with the given search text
 */
+ (NSTimeInterval)defaultDelayForApplyNewFiltersToSearchProvider:(id<GXEntityDataListSearchProvider>)provider
													  searchText:(nullable NSString *)searchText;

@end

NS_ASSUME_NONNULL_END
