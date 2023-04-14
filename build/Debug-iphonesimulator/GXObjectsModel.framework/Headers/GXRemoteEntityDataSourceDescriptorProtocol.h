//
//  GXRemoteEntityDataSourceDescriptorProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 17/10/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXEntityDataSourceDescriptorProtocol.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint_least8_t, GXEntityDataCachingFrecuencyType)  {
	GXEntityDataCachingFrecuencyEveryTime,
	GXEntityDataCachingFrecuencyAfterElipsedTime
};

@protocol GXRemoteEntityDataSourceDescriptor <GXEntityDataSourceDescriptor>

// Caching
@property(nonatomic, assign, readonly) BOOL entityDataSourceCacheEnabled;
@property(nonatomic, assign, readonly) GXEntityDataCachingFrecuencyType entityDataSourceCachingFrequencyType;
@property(nonatomic, assign, readonly) NSUInteger entityDataSourceCachingFrequencyAfterElipsedTime; // In minutes

@end

NS_ASSUME_NONNULL_END
