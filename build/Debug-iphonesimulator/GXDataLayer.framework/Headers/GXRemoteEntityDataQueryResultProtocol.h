//
//  GXRemoteEntityDataQueryResultProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 29/10/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

#import <GXDataLayer/GXEntityDataQueryResultProtocol.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint_least8_t, GXEntityDataQueryResultSourceType) {
	GXEntityDataQueryResultSourceCache,
	GXEntityDataQueryResultSourceServer
};

@protocol GXRemoteEntityDataQueryResult <GXEntityDataQueryResult>

@property(assign, readonly, getter=isUpToDate) BOOL upToDate;
@property(nullable, nonatomic, strong, readonly) NSDate *dataTimeStamp;
@property(nullable, nonatomic, strong, readonly) NSDate *lastModified;
@property(assign, readonly) GXEntityDataQueryResultSourceType source;

@end

NS_ASSUME_NONNULL_END
