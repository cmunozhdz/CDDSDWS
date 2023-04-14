//
//  GXRemoteEntityDataListProviderProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 19/10/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

#import <GXDataLayer/GXEntityDataListProviderProtocol.h>
#import <GXDataLayer/GXRemoteEntityDataProviderProtocol.h>

NS_ASSUME_NONNULL_BEGIN

#define kTotalCountUnknownRemote (NSIntegerMin + 1)		// The provider has cache data loaded (if any), but has not loaded remote data yet
#define kTotalCountUnknownPendingRemote NSIntegerMax	// The provider has remote data loaded, but there could be more pages to load
extern NSInteger const GXTotalCountUnknownRemote;
extern NSInteger const GXTotalCountUnknownPendingRemote;

@protocol GXRemoteEntityDataListProvider <GXEntityDataListProvider, GXRemoteEntityDataProvider>

/**
 * Makes the provider refresh
 * Helper method for passing options:
 *		GXRemoteEntityProviderForceOptionKey = [NSNumber numberWithBool:force]
 *		GXEntityDataListProviderAllLoadedDataOptionKey = [NSNumber numberWithBool:allLoadedData]
 * Calling refresh:force must be the same as calling refresh:force allLoadedData:NO
 * Calling refreshAllLoadedData:allLoadedData must be the same as calling refresh:NO allLoadedData:allLoadedData
 */
- (void)refresh:(BOOL)force allLoadedData:(BOOL)allLoadedData;

@end

NS_ASSUME_NONNULL_END
