//
//  GXEntityDataDetailProviderProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 16/10/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

#import <GXDataLayer/GXEntityDataProviderProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXEntityDataDetailProviderDelegate;

@protocol GXEntityDataDetailProvider <GXEntityDataProvider>

@property(nonatomic, strong, readonly) id <GXSingleItemEntityDataSourceDescriptor> detailEntityDataSource;

@property(nullable, nonatomic, weak, readonly) id <GXEntityDataDetailProviderDelegate> detailDelegate;

@property(nullable, nonatomic, strong, readonly) id <GXEntityDataWithOverrideValues> loadedEntityData;

- (void)loadEntityData;
- (void)reloadEntityData;

@end

@protocol GXEntityDataDetailProviderDelegate <GXEntityDataProviderDelegate>
@optional
- (void)entityDataDetailProviderDidLoadEntityData:(id <GXEntityDataDetailProvider>)provider;
- (void)entityDataDetailProvider:(id <GXEntityDataDetailProvider>)provider didFailLoadingWithError:(NSError *)error;

- (void)entityDataDetailProviderLoadedEntityDataUpdated:(id <GXEntityDataDetailProvider>)provider;
- (void)entityDataDetailProviderLoadedEntityDataDeleted:(id <GXEntityDataDetailProvider>)provider;

- (void)entityDataDetailProviderDidUnloadEntityData:(id <GXEntityDataDetailProvider>)provider;

@end

NS_ASSUME_NONNULL_END
