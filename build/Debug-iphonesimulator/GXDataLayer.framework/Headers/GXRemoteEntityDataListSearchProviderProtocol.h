//
//  GXRemoteEntityDataListSearchProviderProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 05/11/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

#import <GXDataLayer/GXEntityDataListSearchProviderProtocol.h>
#import <GXDataLayer/GXRemoteEntityDataListProviderProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXRemoteEntityDataListSearchProvider <GXEntityDataListSearchProvider, GXRemoteEntityDataListProvider>

/// The source type for the filtered loaded data.
@property(nonatomic, assign, readonly) GXRemoteEntityDataSourceType filteredLoadedDataSource;
/// Time Stamp represents the last query to the data source (Remote Server) that returned filtered data (not up to date).
@property(nullable, nonatomic, strong, readonly) NSDate *filteredLoadedDataLastUpdateTimeStamp;
/// Represents the header returned by the data source (Remote Server) for the filtered loaded data.
@property(nullable, nonatomic, strong, readonly) NSDate *filteredLoadedDataLastModified;

@end


NS_ASSUME_NONNULL_END
