//
//  GXBusinessComponentDeleteHandler.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 05/02/11.
//  Copyright 2011 Artech. All rights reserved.
//

#import <GXDataLayer/GXBusinessComponentWithKeyHandler.h>

NS_ASSUME_NONNULL_BEGIN

@class GXBusinessComponentDeleteHandler;

@protocol GXBusinessComponentDeleteHandlerDelegate <NSObject>

@optional
- (void)businessComponentDeleteHandlerDidDelete:(GXBusinessComponentDeleteHandler *)deleteHandler;
- (void)businessComponentDeleteHandler:(GXBusinessComponentDeleteHandler *)deleteHandler didFailDeletingWithError:(NSError *)error;

@end

@interface GXBusinessComponentDeleteHandler : GXBusinessComponentWithKeyHandler

@property(nullable, weak) id <GXBusinessComponentDeleteHandlerDelegate> delegate;

#pragma mark - Internal

- (void)onError:(NSError *)error;

- (void)onErrorAndCancelOperationsOnMainThread:(NSArray *)params;

- (void)onSuccess;

@end

NS_ASSUME_NONNULL_END
