//
//  GXWorkWithEntityDataProviderHelper.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 09/11/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import GXObjectsModel;
#import <GXDataLayer/GXBaseEntityDataProvider.h>
#import <GXDataLayer/GXBaseListEntityDataProvider.h>
#import <GXDataLayer/GXBaseEntityDataProvider.h>
#import <GXDataLayer/GXWorkWithDataSource.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXWorkWithEntityDataProviderHelper : NSObject

@property(nullable, weak, readonly) GXBaseEntityDataProvider *provider;
@property(nonatomic, strong, readonly) GXWorkWithModel *workWithModel;
@property(nonatomic, strong, readonly) GXWorkWithDetail *workWithDetail;
@property(nonatomic, strong, readonly) GXWorkWithDataSource *workWithDataSource;

- (instancetype)initWithBaseEntityDataProvider:(GXBaseEntityDataProvider *)provider
								workWithDetail:(GXWorkWithDetail *)wwDetail NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

- (nullable GXBaseListEntityDataProvider *)newListProviderWithDataProviderName:(NSString *)dpName; // Abstract

// Default implementation calls newListProviderWithDataProviderName: and sets provider as parent provider
- (nullable id<GXEntityDataListProvider>)entityDataListProviderForDataProviderName:(NSString *)dpName;

@end

NS_ASSUME_NONNULL_END
