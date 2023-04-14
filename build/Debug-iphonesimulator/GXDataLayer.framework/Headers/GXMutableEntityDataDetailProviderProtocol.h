//
//  GXMutableEntityDataDetailProviderProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 16/10/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

#import <GXDataLayer/GXEntityDataDetailProviderProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXMutableEntityDataDetailProviderDelegate;

@protocol GXMutableEntityDataDetailProvider <GXEntityDataDetailProvider>

@property(nullable, nonatomic, weak, readonly) id <GXMutableEntityDataDetailProviderDelegate> mutableDelegate;

@property(nullable, nonatomic, strong, readonly) id <GXEntityDataWithOverrideValues, GXMutableEntityData> loadedMutableEntityData;
- (void)reloadMutableEntityData;
- (BOOL)isLoadedMutableEntityDataUpdated;
- (BOOL)isLoadedMutableEntityDataNew;
- (BOOL)isSavingLoadedMutableEntityData;
- (BOOL)isDeletingLoadedMutableEntityData;

- (void)loadMutableEntityData;
- (void)loadNewMutableEntityData;
- (BOOL)saveLoadedMutableEntityData:(out NSError * _Nullable * _Nullable)error;
- (BOOL)deleteLoadedMutableEntityData:(out NSError * _Nullable * _Nullable)error;

@optional
- (void)setInferredFieldValuesByName:(NSDictionary<NSString *, id> *)inferredFieldValuesByName;

@end

@protocol GXMutableEntityDataDetailProviderDelegate <GXEntityDataDetailProviderDelegate>

@optional
- (void)mutableEntityDataDetailProviderDidSave:(id <GXMutableEntityDataDetailProvider>)provider;
- (BOOL)mutableEntityDataDetailProvider:(id <GXMutableEntityDataDetailProvider>)provider
                 didFailSavingWithError:(NSError *)error;
- (void)mutableEntityDataDetailProviderDidDelete:(id <GXMutableEntityDataDetailProvider>)provider;
- (BOOL)mutableEntityDataDetailProvider:(id <GXMutableEntityDataDetailProvider>)provider
               didFailDeletingWithError:(NSError *)error;

@end

extern NSString *const GXMutableEntityDataDetailProviderDidFinishSavingNotification;
extern NSString *const GXMutableEntityDataDetailProviderDidFinishDeletingNotification;

NS_ASSUME_NONNULL_END
