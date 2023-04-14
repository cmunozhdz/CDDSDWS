//
//  GXRemoteEntityDataQueryInfoProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 26/10/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import GXObjectsModel;
#import <GXDataLayer/GXEntityDataQueryInfoProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXRemoteEntityDataQueryInfo <GXEntityDataQueryInfo>

@property(nonatomic, strong, readonly) id <GXRemoteEntityDataSourceDescriptor> remoteDataSource;
@property(assign, readonly) BOOL force;

@end

@protocol GXRemoteEntityDataQuerySingleItemInfo <GXEntityDataQuerySingleItemInfo, GXRemoteEntityDataQueryInfo>

@property(nonatomic, strong, readonly) id <GXSingleItemEntityDataSourceDescriptor, GXRemoteEntityDataSourceDescriptor> remoteSingleItemDataSource;

@end

@protocol GXRemoteEntityDataQueryCollectionInfo <GXEntityDataQueryCollectionInfo, GXRemoteEntityDataQueryInfo> 

@property(nonatomic, strong, readonly) id <GXCollectionEntityDataSourceDescriptor, GXRemoteEntityDataSourceDescriptor> remoteCollectionDataSource;

@end

NS_ASSUME_NONNULL_END
