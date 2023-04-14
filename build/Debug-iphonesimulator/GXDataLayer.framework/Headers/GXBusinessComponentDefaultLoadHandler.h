//
//  GXBusinessComponentDefaultLoadHandler.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 22/10/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

#import <GXDataLayer/GXBusinessComponentHandler.h>

NS_ASSUME_NONNULL_BEGIN

@class GXBusinessComponentDefaultLoadHandler;

@protocol GXBusinessComponentDefaultLoadHandlerDelegate <NSObject>

@optional
- (void)businessComponentDefaultLoadHandler:(GXBusinessComponentDefaultLoadHandler *)loadHandler
			didCreateEntityDataWithDefaults:(id <GXBusinessComponentLevelEntityData>)entityData;
- (void)businessComponentDefaultLoadHandler:(GXBusinessComponentDefaultLoadHandler *)loadHandler
					didFailLoadingWithError:(NSError *)error;

@end

@interface GXBusinessComponentDefaultLoadHandler : GXBusinessComponentHandler

@property(nullable, nonatomic, weak) id<GXBusinessComponentDefaultLoadHandlerDelegate> delegate;
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, id> *inferredValuesByFieldName;

- (instancetype)initWithBusinessComponentLevel:(GXBusinessComponentLevel *)bcLevel
					 inferredValuesByFieldName:(nullable NSDictionary<NSString *, id> *)inferredValuesByFieldName NS_DESIGNATED_INITIALIZER;

#pragma mark - Internal

- (void)onError:(NSError *)error;

- (void)onSuccess:(id <GXBusinessComponentLevelEntityData>)entityData;

@end

NS_ASSUME_NONNULL_END
