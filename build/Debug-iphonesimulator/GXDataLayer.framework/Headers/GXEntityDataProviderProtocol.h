//
//  GXEntityDataProviderProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 16/12/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@protocol GXEntityDataProviderDelegate;
@protocol GXEntityDataListProvider;

typedef NS_OPTIONS(NSUInteger, GXEntityDataProviderWaitingOptions) {
	GXEntityDataProviderWaitingOption_None = 0,
	GXEntityDataProviderWaitingOption_ParentRefresh = 1 << 0,
};

typedef NS_ENUM(NSUInteger, GXEntityDataProviderWaitingForDelegateState) {
	GXEntityDataProviderWaitingForDelegateState_Allowed,
	GXEntityDataProviderWaitingForDelegateState_NotAllowed,
	GXEntityDataProviderWaitingForDelegateState_WaitingForParentClientStart,
	GXEntityDataProviderWaitingForDelegateState_WaitingForParentRefresh,
	GXEntityDataProviderWaitingForDelegateState_WaitingForParentFinishLoading,
};

@protocol GXEntityDataProvider <GXObjectWithParameters>

@property(nullable, nonatomic, weak) id <GXEntityDataProviderDelegate> delegate;

@property(assign, readwrite) BOOL entityDataProviderAutoRefreshEnabled;
@property(nonatomic, assign, readonly) GXConnectivitySupportType entityDataProviderConnectivitySupport;
@property(nonatomic, strong, readonly) id <GXEntityDataSourceDescriptor> entityDataSource;
@property(nullable, nonatomic, weak, readonly) id <GXEntityDataProvider> entityDataParentProvider;

@property(nullable, nonatomic, strong, readonly) NSArray<id<GXEntityDataProvider>> *entityDataComponentsProviders;

/// Time Stamp represents the last query to the data source (Remote Server or Local DB, updated even if data souce returned up to date).
@property(nullable, nonatomic, strong, readonly) NSDate *loadedDataTimeStamp;
/// Time Stamp represents when the last refresh finished successfully.
@property(nullable, nonatomic, strong, readonly) NSDate *lastRefreshTimeStamp;
@property(nonatomic, assign, readonly) BOOL loadedDataBelongsToCurrentInputParameters;

/// YES if a refresh is pending and was not completed, NO otherwise.
@property(nonatomic, assign, readonly, getter=isReloadNeeded) BOOL reloadNeeded;
- (void)markReloadNeededAndReloadIfAutoRefreshEnabled;
- (void)entityDataProviderReloadIfNeeded;

@property(nonatomic, assign, readonly, getter=isLoading) BOOL loading;
- (void)cancelLoading;

@property(nonatomic, assign, readonly, getter=isRefreshing) BOOL refreshing;
- (void)refresh; // Same as calling refreshWithOptions: with default user info
- (void)refreshWithOptions:(nullable NSDictionary *)userInfo;

/*!
 Returns a state value indicating whether the provider is waiting for the delegate to allow loading.
 
 @discussion This value is updated when providers tries to load calling delegate's entityDataProvider:canLoadWaitingWithOptions:
 */
@property(nonatomic, assign, readonly) GXEntityDataProviderWaitingForDelegateState loadWaitingForDelegateState;

/*!
 Stops waiting for delegate to continue (or abort) loading
 
 @param resume YES to continue loading. NO to abort with the given error.
 @param error reason to abort loading.
 @discussion Resuming calls entityDataProvider:canLoadWaitingWithOptions: again.
 */
- (void)stopWaitingForDelegate:(BOOL)resume withError:(nullable NSError *)error;

- (nullable id <GXEntityDataListProvider>)entityDataListProviderForDataProviderName:(NSString *)dpName;

@end


@protocol GXEntityDataProviderDelegate <NSObject>

- (GXEntityDataProviderWaitingForDelegateState)entityDataProvider:(id <GXEntityDataProvider>)provider
										canLoadWaitingWithOptions:(GXEntityDataProviderWaitingOptions)options;

@end

extern NSString *const GXEntityDataProviderDidFinishLoadingNotification;

extern NSString *const GXEntityProviderErrorKey;					// NSError with the fail reason

NS_ASSUME_NONNULL_END
