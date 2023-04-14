//
//  GXRemoteMutableEntityDataDetailProviderProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 05/11/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

#import <GXDataLayer/GXMutableEntityDataDetailProviderProtocol.h>
#import <GXDataLayer/GXRemoteEntityDataProviderProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXRemoteMutableEntityDataDetailProvider <GXMutableEntityDataDetailProvider, GXRemoteEntityDataProvider>

@property(nonatomic, assign, readonly) GXRemoteEntityDataSourceType loadedMutableDataSource;

@end

NS_ASSUME_NONNULL_END
