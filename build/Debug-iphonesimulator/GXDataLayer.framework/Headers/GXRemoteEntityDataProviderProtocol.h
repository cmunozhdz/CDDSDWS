//
//  GXRemoteEntityDataProviderProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 17/10/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import GXObjectsModel;
#import <GXDataLayer/GXEntityDataProviderProtocol.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint_least8_t, GXRemoteEntityDataSourceType) {
	GXRemoteEntityDataSourceUnknown,
	GXRemoteEntityDataSourceCache,
	GXRemoteEntityDataSourceRemote
};

@protocol GXRemoteEntityDataProvider <GXEntityDataProvider>

@property(nonatomic, strong, readonly) id <GXRemoteEntityDataSourceDescriptor> remoteEntityDataSource;

/// The source type for the loaded data.
@property(nonatomic, assign, readonly) GXRemoteEntityDataSourceType loadedDataSource;
/// Time Stamp represents the last query to the data source (Remote Server) that returned data (not up to date).
@property(nullable, nonatomic, strong, readonly) NSDate *loadedDataLastUpdateTimeStamp;
/// Represents the header returned by the data source (Remote Server).
@property(nullable, nonatomic, strong, readonly) NSDate *loadedDataLastModified;

/**
 * Makes the provider refresh
 * Helper method for passing option GXRemoteEntityProviderForceOptionKey = [NSNumber numberWithBool:force]
 * Calling [self refresh] must be the same as calling refresh: with force = NO
 */
- (void)refresh:(BOOL)force;

@end

extern NSString *const GXRemoteEntityProviderForceOptionKey;					// NSNumber with bool for ignoring data source caching properties, default NO

NS_ASSUME_NONNULL_END
