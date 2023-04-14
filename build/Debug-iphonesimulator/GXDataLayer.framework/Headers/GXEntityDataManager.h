//
//  GXEntityDataManager.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 23/11/11.
//  Copyright (c) 2011 Artech. All rights reserved.
//

#import <GXDataLayer/GXEntityDataQueryInfoProtocol.h>
#import <GXDataLayer/GXEntityDataQueryResultProtocol.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const GXEntityDataManagerReleasedAllGXIDReferencesNotification;

extern NSString *const GXEntityDataManagerGXIDKey;

@protocol GXEntityDataManagerDelegate;

@protocol GXEntityDataManagerQueryInfoLoader <NSObject>

- (void)load:(id <GXEntityDataQueryInfo>)queryInfo delegate:(id <GXEntityDataManagerDelegate>)delegate;
- (void)cancelLoad:(id <GXEntityDataQueryInfo>)queryInfo delegate:(id <GXEntityDataManagerDelegate>)delegate;

- (void)cancelAllOperations;

@end

@interface GXEntityDataManager : NSObject <GXEntityDataManagerQueryInfoLoader, GXModelObject>

/// Returns a new unique gxid. Reference count starts at 1 for the new gxid.
- (NSUInteger)obtainNewGXID;
/// Increments the reference count over the given existing gxid.
- (void)retainGXID:(NSUInteger)gxid;
/// Decrements the reference count over the given existing gxid. When count reaches 0, a GXEntityDataManagerRealeasedAllGXIDReferencesNotification is posted
- (void)releaseGXID:(NSUInteger)gxid;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end


@protocol GXEntityDataManagerDelegate <NSObject>

- (void)entityDataManager:(GXEntityDataManager *)manager
	didFinishLoadingQuery:(id <GXEntityDataQueryInfo>)queryInfo
			   withResult:(id <GXEntityDataQueryResult>)result;

@end

@protocol GXInternalEntityDataManager <GXEntityDataManagerQueryInfoLoader>

- (instancetype)init;

@property(nullable, nonatomic, weak, readwrite) GXEntityDataManager *manager;

- (id <GXEntityDataQuerySingleItemResult>)emptySingleItemEntityDataQueryResultWithDataItem:(id <GXEntityData>)dataItem;
- (id <GXEntityDataQueryCollectionResult>)emptyCollectionEntityDataQueryResult;

@end

NS_ASSUME_NONNULL_END
