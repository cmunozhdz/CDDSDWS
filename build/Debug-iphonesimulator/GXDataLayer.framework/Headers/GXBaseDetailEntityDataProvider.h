//
//  GXBaseDetailEntityDataProvider.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 09/12/11.
//  Copyright (c) 2011 Artech. All rights reserved.
//

#import <GXDataLayer/GXBaseEntityDataProvider.h>
#import <GXDataLayer/GXBusinessComponentManager.h>
#import <GXDataLayer/GXMutableEntityDataDetailProviderProtocol.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint_least8_t, GXEntityDataDetailProviderState) {
	GXEntityDataDetailProviderStateIdle,
	GXEntityDataDetailProviderStateLoading,
	GXEntityDataDetailProviderStateMutableLoading,
	GXEntityDataDetailProviderStateMutableNewLoading,
	GXEntityDataDetailProviderStateSaving,
	GXEntityDataDetailProviderStateDeleting
};

@interface GXBaseDetailEntityDataProvider : GXBaseEntityDataProvider <GXMutableEntityDataDetailProvider, GXBusinessComponentManagerDelegate>

@property(nonatomic, assign, readonly) GXEntityDataDetailProviderState state;
@property(nullable, nonatomic, strong, readonly) id<GXEntityDataQuerySingleItemInfo> currentQuerySingleItemInfo;
@property(nullable, nonatomic, strong, readonly) id<GXEntityDataQuerySingleItemInfo> lastQuerySingleItemInfo;
@property(nullable, nonatomic, strong, readonly) id<GXEntityDataQuerySingleItemResult> lastQuerySingleItemResult;

// Mutable
- (nullable GXBusinessComponentLevel *)mutableBusinessComponentLevel;

- (BOOL)isInputParametersEntityDataValidForLoadingMutable;

#pragma mark - Override Points

/**
 * Returns options dictionary for loading mutable
 * See: GXRemoteEntityProviderForceOptionKey
 * Default implementation retuns nil
 */
- (nullable NSDictionary *)mutableLoadOptions;

/**
 * Default implementation calls updateLastRefresh:nil
 */
- (void)updateLastRefreshWithProviderConnectivitySupport;

/**
 * Unloads current loadedEntityData
 */
- (BOOL)cleanLoadedEntityData;

/**
 * Unloads current loadedMutableEntityData
 */
- (BOOL)cleanLoadedMutableEntityData;

// Default implementation returns currentRefreshQueryType
- (GXEntityDataQueryType)queryTypeForLoadingEntityData;

#pragma mark - GXEntityDataManagerDelegate Helpers

/**
 * Default implementations calls refreshWithRefreshFlagsIfRequired and notifies delegate if result.dataItem,
 * otherwise, notifies delegate with default error
 */
- (void)onAfterDidFinishLoadingQuerySuccesfully:(id<GXEntityDataQuerySingleItemInfo>)queryInfo
									 withResult:(id<GXEntityDataQuerySingleItemResult>)result
										context:(NSMutableDictionary *)context;

@end

NS_ASSUME_NONNULL_END
