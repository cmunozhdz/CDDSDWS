//
//  GXModelManager.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 01/11/10.
//  Copyright 2010 Artech. All rights reserved.
//

#import <GXObjectsModel/GXModel.h>

NS_ASSUME_NONNULL_BEGIN

@class GXModel;
@protocol GXModelManagerDelegate;

@interface GXModelManager : NSObject

@property(class, nonatomic, strong, readonly) GXModelManager *sharedManager;

#pragma mark - Model Loading

- (nullable GXModel *)loadModelForApplication:(id <GXApplication>)application
									 delegate:(id <GXModelManagerDelegate>)delegate;
- (nullable GXModel *)loadModelForApplication:(id <GXApplication>)application
									 delegate:(id <GXModelManagerDelegate>)delegate
									 useCache:(BOOL)cache;
- (BOOL)cancelLoadingModelForApplication:(id <GXApplication>)application;

#pragma mark - Model Helpers

- (void)executeWithModelLoaded:(void(^)(GXModel * _Nullable, NSError * _Nullable))block;
- (void)executeWithModelLoadedWaitIfError:(void(^)(GXModel * _Nonnull))block;

@end

@protocol GXModelManagerDelegate <NSObject>

@optional
- (void)modelManager:(GXModelManager *)manager didLoadModel:(GXModel *)model;
- (void)modelManager:(GXModelManager *)manager didFailLoadingApplication:(id <GXApplication>)application withError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
