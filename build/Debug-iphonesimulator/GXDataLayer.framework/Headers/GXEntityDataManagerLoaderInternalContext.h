//
//  GXEntityDataManagerLoaderInternalContext.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 01/11/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

#import <GXDataLayer/GXEntityDataManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXEntityDataManagerLoaderInternalContext : NSObject

- (instancetype)initWithLoader:(id)loader
					 queryInfo:(id <GXEntityDataQueryInfo>)queryInfo
					   delgate:(id <GXEntityDataManagerDelegate>)delegate NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

@property(nonatomic, strong, readonly) id loader;
@property(nonatomic, strong, readonly) id queryInfo; // id <GXEntityDataQueryInfo> or NSArray<id<GXEntityDataQueryInfo>>
@property(nonatomic, strong, readonly) id delegate; // id <GXEntityDataManagerDelegate> or NSArray<id<GXEntityDataManagerDelegate>>

@property(nonatomic, strong, readonly) id <GXEntityDataQueryInfo> anyQueryInfo;

- (BOOL)isCollection;

- (void)addQueryInfo:(id <GXEntityDataQueryInfo>)queryInfo delgate:(id <GXEntityDataManagerDelegate>)delegate;
- (void)enumerateQueryInfosAndDelegatesUsingBlock:(void (^)(id <GXEntityDataQueryInfo> queryInfo, id <GXEntityDataManagerDelegate>delegate, BOOL *stop))block;
- (NSUInteger)removeQueryInfo:(id <GXEntityDataQueryInfo>)queryInfo delegate:(id <GXEntityDataManagerDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
