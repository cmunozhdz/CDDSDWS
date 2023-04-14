//
//  GXApplicationHelper.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 03/11/10.
//  Copyright 2010 Artech. All rights reserved.
//

#import <GXObjectsModel/GXApplicationProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXApplicationHelper : NSObject

+ (NSString *)applicationKey:(id<GXApplication>)application;
+ (BOOL)compareApplication:(nullable id<GXApplication>)app1 toApplication:(nullable id<GXApplication>)app2;

+ (nullable NSURL *)serverBaseURLFromString:(NSString *)urlString;
+ (nullable NSURL *)serverBaseURLFromURL:(nullable NSURL *)url;

/**
 * Returns:
 *   - NSOrderedAscending  if the metadata version is smaller than the given version
 *   - NSOrderedSame       if they are equal
 *   - NSOrderedDescending if the metadata version is grater than the given version
 */
+ (NSComparisonResult)compareMetadataVersion:(NSString *)version1 toVersion:(NSString *)version2;

/// #deprecated: 2022-01-11: trunk; #to-remove: ??
+ (NSComparisonResult)compareCurrentMetadataVersionToVersion:(NSString *)version2 __attribute__((deprecated("Use compareMetadataVersion:toVersion: instead")));

@end

NS_ASSUME_NONNULL_END
