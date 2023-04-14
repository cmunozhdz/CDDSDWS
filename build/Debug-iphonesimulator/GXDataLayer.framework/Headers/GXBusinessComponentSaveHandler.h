//
//  GXBusinessComponentSaveHandler.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 25/03/11.
//  Copyright 2011 Artech. All rights reserved.
//

#import <GXDataLayer/GXBusinessComponentWithKeyHandler.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXBusinessComponentSaveHandler : GXBusinessComponentWithKeyHandler

- (instancetype)initWithBusinessComponentLevel:(GXBusinessComponentLevel *)bcLevel
									entityData:(id <GXBusinessComponentLevelEntityData>)entityData;

#pragma mark - Internal

- (void)onError:(NSError *)error;

- (void)onErrorAndCancelOperationsOnMainThread:(NSArray *)params;

- (void)onSuccess:(id <GXBusinessComponentLevelEntityData>)entityData;

@end

NS_ASSUME_NONNULL_END
