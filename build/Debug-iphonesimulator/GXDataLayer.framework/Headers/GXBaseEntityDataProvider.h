//
//  GXBaseEntityDataProvider.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 09/12/11.
//  Copyright (c) 2011 Artech. All rights reserved.
//

@import GXObjectsModel;
#import <GXDataLayer/GXEntityDataManager.h>
#import <GXDataLayer/GXEntityDataProviderProtocol.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(uint_least8_t, GXEntityDataProviderRefreshFlags) {
	GXEntityDataProviderRefreshFlagsNone = 0,
	GXEntityDataProviderRefreshFlagsReloadNeeded = 1 << 0,
	GXEntityDataProviderRefreshFlagsForce = 1 << 1,			// Used in Remote Providers
	GXEntityDataProviderRefreshFlagsAllLoadedData = 1 << 2	// Used in List Providers
};

@interface GXBaseEntityDataProvider : NSObject <GXEntityDataProvider, GXModelObject, GXEntityDataManagerDelegate>

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithDataSource:(id<GXEntityDataSourceDescriptor, GXModelObject>)dataSource NS_DESIGNATED_INITIALIZER;

+ (GXConnectivitySupportType)connectivitySupport;

@property(nonatomic, strong, readonly) id <GXEntityDataDescriptor> dataSourceOnlyInOrInoutParamersDataDescriptor;
@property(nullable, nonatomic, strong, readonly) id <GXEntityDataQueryInfo> currentQueryInfo;
@property(nullable, nonatomic, strong, readonly) id <GXEntityDataQueryInfo> lastQueryInfo;
@property(nullable, nonatomic, strong, readonly) id <GXEntityDataQueryResult> lastQueryResult;
@property(nonatomic, strong, readonly) GXEntityDataManager *entityDataManager;
@property(assign, readonly) BOOL firstLoadComplete;
@property(nonatomic, assign, readonly) NSUInteger gxid;
@property(nonatomic, assign, readonly) NSUInteger rootGxid;

/**
 * GXEntityDataProvider Abstract Methods
 
 - (BOOL)isLoading;
 - (void)cancelLoading;
 - (void)refreshWithOptions:(NSDictionary *)userInfo;
 
 */
#pragma mark - Loading Helpers

- (id<GXEntityDataQueryInfo>)newQueryInfoWithType:(GXEntityDataQueryType)type options:(nullable NSDictionary *)options; // Abstract
- (void)unloadProviderData:(BOOL)notifyDelegate; // Abstract
- (void)unloadProviderDataAsyncIfLoadedDataDoesNotBelongToCurrentInputParameters;

/**
 * Loads a new query with given type and options
 * Default implementation:
 *		1. Creates a new query with the given type and options, and sets it as the currentQueryInfo
 *		2. Ask if can load the query (canLoadQueryInfo:)
 *			2.a If YES, makes the entityDataManager load  the query
 *			2.b Otherwise, waits for parent provider
 */
- (void)loadQueryWithType:(GXEntityDataQueryType)type options:(nullable NSDictionary *)options;

/*!
 Aborts current operation with the given error
 
 @param error Error causing the current operation to stop (nil means no error to notify)
 @discussion Default implementation cancels currentQueryInfo, setting it to nil and stoping waiting for delegate (loadIsWaitingForDelegate = NO)
 */
- (void)abortCurrentOperationWithError:(nullable NSError *)error;
- (void)cancelCurrentOperation:(BOOL)notifyUserCancelledError; // Calls [self abortCurrentOperationWithError:[NSError userCancelledError]]
- (void)cancelCurrentOperation; // Calls [self cancelCurrentOperation:YES];

- (BOOL)retryWaitingForDelegateOperation;
- (void)updateLoadIsWaitingForDelegateWaitingForParentRefresh:(BOOL)waitForParentRefresh;

- (BOOL)isInputParametersEntityDataValidForLoading; // self.inputParametersEntityData != nil || [[self.dataSourceOnlyInOrInoutParamersDataDescriptor entityDataFieldDescriptors] count] == 0;

/// Updates loadedDataBelongsToCurrentInputParameters flag to YES and clears onInputParametersEntityDataChangedAddedRefreshFlags
- (void)markLoadedDataBelongsToCurrentInputParameters;

- (BOOL)hasDataLoaded;
/**
 * Called with input parameters change
 * Default implementation:
 *		1. Cancel current loading operation
 *		2. Sets loadedDataBelongsToCurrentInputParameters = NO
 *		3. If [self hasDataLoaded] calls:
 *			3.1. [self addOnInputParametersEntityDataChangedRefreshFlags:GXEntityDataProviderRefreshFlagsReloadNeeded]
 *			3.2. Calls async performAutomaticRefreshOnInputParametersEntityDataChangedIfNeeded
 */
- (void)onInputParametersEntityDataChanged:(nullable id<GXEntityData>)oldInputParametersEntityData __attribute__((objc_requires_super));
/// Current refresh flags added on input parameters change, this refresh flags are removed if a manual refresh is performed
@property(assign, readonly) GXEntityDataProviderRefreshFlags onInputParametersEntityDataChangedAddedRefreshFlags;
/// Updates onInputParametersEntityDataChangedAddedRefreshFlags and refreshFlags
- (void)addOnInputParametersEntityDataChangedRefreshFlags:(GXEntityDataProviderRefreshFlags)flags;

/**
 * Performs automatic refresh on inpunt parameters change if needed
 * Default implementation:
 *		1. Checks if automatic refresh is needed: !self.loadedDataBelongsToCurrentInputParameters && ![self isLoading]
 *		2. If YES, calls refreshWithRefreshFlagsIfRequired
 *		3. If automatic refresh is still needed: !self.loadedDataBelongsToCurrentInputParameters && ![self isLoading], calls [self unloadProviderData:YES]
 */
- (void)performAutomaticRefreshOnInputParametersEntityDataChangedIfNeeded;

#pragma mark - Refresh Flags

/**
 * Pending Refresh Flags
 * Indicates if there is a reloadNeeded, if should force server check, and in case of list provider, if should reload all load data
 * After successful refresh, these flags should be updated. See updateRefreshFlagsWithResult:forQuery:
 */
@property(assign, readonly) GXEntityDataProviderRefreshFlags refreshFlags;

/**
 * Refresh Flags Helper
 * Returns YES if refreshFlags & GXEntityDataProviderRefreshFlagsReloadNeeded, NO otherwise
 * Setting YES makes refreshFlags |= GXEntityDataProviderRefreshFlagsReloadNeeded
 * Setting NO makes refreshFlags = GXEntityDataProviderRefreshFlagsNone
 */
@property(nonatomic, assign, readwrite, getter=isReloadNeeded) BOOL reloadNeeded;

/**
 * Marks reload needed and updates refresh flags with the given options
 * See: GXRemoteEntityProviderForceOptionKey && GXEntityDataListProviderAllLoadedDataOptionKey
 */
- (void)markReloadNeededWithOptions:(nullable NSDictionary *)options;

/**
 * Returns a refresh options dictionary for the current refresh flags
 * See: GXRemoteEntityProviderForceOptionKey && GXEntityDataListProviderAllLoadedDataOptionKey
 */
- (nullable NSDictionary *)refreshOptionsForCurrentRefreshFlags;

/**
 * Updates Refresh Flags
 * If result is successful, is refresh or first, and if matches refreshFlags makes refreshFlags = GXEntityDataProviderRefreshFlagsNone
 */
- (void)updateRefreshFlagsWithResult:(id<GXEntityDataQueryResult>)result
							forQuery:(id<GXEntityDataQueryInfo>)queryInfo;


/**
 * Returns if refresh with refreshFlags should be performed
 * Called on refreshWithRefreshFlagsIfRequired if reloadNeeded
 * Default implementation checks if reload is needed, server connection is available and provider is not currently loading
 */
- (BOOL)shouldRefreshWithRefreshFlags;

/**
 * Executes refresh with refreshFlags
 */
- (void)refreshWithRefreshFlags;

/**
 * Executes refresh with refreshFlags if required
 * Called on entityDataProviderReloadIfNeeded
 * Default implementation calls refreshWithRefreshFlags if shouldRefreshWithRefreshFlags returns YES
 */
- (void)refreshWithRefreshFlagsIfRequired;

/// Default implementation calls [self markReloadNeededWithOptions:userInfo]
- (void)refreshWithOptions:(nullable NSDictionary *)userInfo __attribute__((objc_requires_super));

// Helper Methods

- (nullable GXBusinessComponentLevel *)businessComponentLevel;
- (nullable NSArray *)parametersForContextEntityData;
/**
 * Posts a notification with self as object and given userInfo
 */
- (void)postNotification:(NSString *)name userInfo:(nullable NSDictionary *)userInfo;
/**
 * Posts a notification with self as object and with error (if not nil) in userInfo for GXEntityProviderErrorKey
 */
- (void)postNotification:(NSString *)name withError:(nullable NSError *)error;
/**
 * Updates firstLoadComplete flag to YES
 */
- (void)markFirstLoadCompleted;
/**
 * Returns GXEntityDataQueryTypeRefresh if self.firstLoadComplete, GXEntityDataQueryTypeFirst otherwise
 */
- (GXEntityDataQueryType)currentRefreshQueryType;

#pragma mark - Auto-Refresh

/**
 * Returns if auto-refresh should be performed
 * Called on each auto-refresh tick (after entityDataSourceRefreshTimeoutLapse)
 * Default implementation checks if auto-refresh is enabled, application state is Active,
 *		server connection is available if online and provider is not currently loading
 */
- (BOOL)shouldAutoRefresh;

/**
 * Executes Auto-Refresh
 * Called on each auto-refresh tick (after entityDataSourceRefreshTimeoutLapse) if shouldAutoRefresh returned YES
 * Default implementation calls refresh
 */
- (void)performAutoRefresh;

/**
 * Updates refreshFlags for Auto-Refresh required
 * Called on each auto-refresh tick (after entityDataSourceRefreshTimeoutLapse) if shouldAutoRefresh returned NO
 * Default implementation calls setReloadNeeded:YES
 */
- (void)updateRefreshFlagsForAutoRefreshRequired;

/**
 * Updates refreshFlags for reload required
 * Called on markReloadNeededAndReloadIfAutoRefreshEnabled
 * Default implementation calls setReloadNeeded:YES
 */
- (void)updateRefreshFlagsForReloadRequired;

#pragma mark - Notifications

/**
 * Pair methods helpers for notifications
 * should... methods returns YES if should observe notifications
 * notify... methods are called on notifications if should... methods returned YES
 */

- (BOOL)shouldNotifyApplicationWillResignActive; // Default dataSource's entityDataSourceRefreshTimeoutLapse > 0
// Default implementation invalidates refresh timer (if exists)
- (void)notifyApplicationWillResignActive:(NSNotification *)notification;

- (BOOL)shouldNotifyApplicationDidBecomeActive; // Default dataSource's entityDataSourceRefreshTimeoutLapse > 0
// Default implementation re-schedules refresh timer (if current is invalid)
- (void)notifyApplicationDidBecomeActive:(NSNotification *)notification;

- (BOOL)shouldNotifyApplicationDidEnterBackground; // Default YES
// Default implementation if isLoading, calls cancelLoading and sets reload needed
- (void)notifyApplicationDidEnterBackground:(NSNotification *)notification;

- (BOOL)shouldNotifyApplicationWillEnterForeground; // Default YES
// Default implementation calls refreshWithRefreshFlagsIfRequired if self.entityDataProviderAutoRefreshEnabled
- (void)notifyApplicationWillEnterForeground:(NSNotification *)notification;

- (BOOL)shouldNotifyModelWillClearCache; // Default NO
- (void)notifyModelWillClearCache:(NSNotification *)notification;

#pragma mark - GXEntityDataManagerDelegate Helpers

/**
 * Default implementation of entityDataManager:didFinishLoadingQuery:withResult: calls
 * shouldHandleEntityDataManager:didFinishLoadingQuery:withResult:context: and if returns YES:
 *		- calls onDidFinishLoadingQuery:withResult:context:
 *		- if result is successful, calls onDidFinishLoadingQuerySuccesfully:withResult:context:
 *			otherwise, calls onDidFinishLoadingQuery:withResult:withError:context:
 */

// Default implementations returns YES if queryInfo == self.currentQueryInfo, NO otherwise
- (BOOL)shouldHandleEntityDataManager:(GXEntityDataManager *)manager
				didFinishLoadingQuery:(id<GXEntityDataQueryInfo>)queryInfo
						   withResult:(id<GXEntityDataQueryResult>)result
							  context:(NSMutableDictionary *)context;
/**
 * Default implementation updates lastQueryResult and lastQueryInfo with
 * the given parameters and sets currentQueryInfo to nil
 */
- (void)onDidFinishLoadingQuery:(id<GXEntityDataQueryInfo>)queryInfo
					 withResult:(id<GXEntityDataQueryResult>)result
						context:(NSMutableDictionary *)context;
/**
 * Default implementations calls:
 * 1. loadResultsFromSuccessfulQuery:result:context:
 * 2. updateLoadedStateOnDidFinishLoadingQuerySuccesfully:result:context:
 * 3. updateLastRefreshOnDidFinishLoadingQuerySuccesfully:result:context:
 * 4. shouldMarkFirstLoadCompletedOnDidFinishLoadingQuerySuccesfully:result:context:
 *		4.1 if YES, calls markFirstLoadCompleted
 */
- (void)onDidFinishLoadingQuerySuccesfully:(id <GXEntityDataQueryInfo>)queryInfo
								withResult:(id <GXEntityDataQueryResult>)result
								   context:(NSMutableDictionary *)context;
// Default implementation does nothing
- (void)onDidFinishLoadingQuery:(id<GXEntityDataQueryInfo>)queryInfo
					 withResult:(id<GXEntityDataQueryResult>)result
					  withError:(NSError *)error
						context:(NSMutableDictionary *)context;

/**
 * Called in onDidFinishLoadingQuerySuccesfully:withResult:context:
 * Default implementations returns queryInfo.type == GXEntityDataQueryTypeFirst
 */
- (BOOL)shouldMarkFirstLoadCompletedOnDidFinishLoadingQuerySuccesfully:(id<GXEntityDataQueryInfo>)queryInfo
																result:(id<GXEntityDataQueryResult>)result
															   context:(NSMutableDictionary *)context;
/**
 * Updates provider loaded data from result
 * Called in onDidFinishLoadingQuerySuccesfully:withResult:context:
 * Default implementation does nothing
 */
- (void)loadResultsFromSuccessfulQuery:(id<GXEntityDataQueryInfo>)queryInfo
								result:(id<GXEntityDataQueryResult>)result
							   context:(NSMutableDictionary *)context;
/**
 * Updates loaded state
 * Called in onDidFinishLoadingQuerySuccesfully:withResult:context:
 * Default implementation does nothing
 */
- (void)updateLoadedStateOnDidFinishLoadingQuerySuccesfully:(id<GXEntityDataQueryInfo>)queryInfo
												 withResult:(id<GXEntityDataQueryResult>)result
													context:(NSMutableDictionary *)context;
/**
 * Updates lastRefresh based on given result and queryInfo if needed
 * Called in onDidFinishLoadingQuerySuccesfully:withResult:context:
 * Default implementation calls updateLastRefresh: with given result's timeStamp if queryInfo.type is First or Refresh
 */
- (void)updateLastRefreshOnDidFinishLoadingQuerySuccesfully:(id<GXEntityDataQueryInfo>)queryInfo
												 withResult:(id<GXEntityDataQueryResult>)result
													context:(NSMutableDictionary *)context;

@end

NS_ASSUME_NONNULL_END
