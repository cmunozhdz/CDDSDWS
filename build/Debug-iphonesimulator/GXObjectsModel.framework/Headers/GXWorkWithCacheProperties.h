//
//  GXWorkWithCacheProperties.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 24/01/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXRemoteEntityDataSourceDescriptorProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXWorkWithCacheProperties : NSObject <NSCoding>

- (instancetype)init NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@property(assign, readonly) BOOL cacheEnabled;
@property(assign, readonly) GXEntityDataCachingFrecuencyType frequencyType;
@property(assign, readonly) NSUInteger frequencyAfterElipsedTime; // In minutes

+ (BOOL)defaultCacheEnabled;
+ (GXEntityDataCachingFrecuencyType)defaultFrequencyType;
+ (NSUInteger)defaultFrequencyAfterElipsedTimeForFrequencyType:(GXEntityDataCachingFrecuencyType)frequencyType;

/**
 * Returns an instance of GXWorkWithCacheProperties if properties are not default, nil otherwise
 */
+ (nullable GXWorkWithCacheProperties *)cachePropertiesFromMetadata:(id)metadata;

// Helper methods
/**
 * Returns cacheEnabled for the given cache properties if not nil, defaultCacheEnabled otherwise
 */
+ (BOOL)isCacheEnabledForProperties:(nullable GXWorkWithCacheProperties *)cacheProperties;
/**
 * Returns frequencyType for the given cache properties if not nil, defaultFrequencyType otherwise
 */
+ (GXEntityDataCachingFrecuencyType)frequencyTypeForProperties:(nullable GXWorkWithCacheProperties *)cacheProperties;
/**
 * Returns frequencyAfterElipsedTime for the given cache properties if not nil, defaultFrequencyAfterElipsedTimeForFrequencyType:[self defaultFrequencyType] otherwise
 */
+ (GXEntityDataCachingFrecuencyType)frequencyAfterElipsedTimeForProperties:(nullable GXWorkWithCacheProperties *)cacheProperties;

@end

NS_ASSUME_NONNULL_END
