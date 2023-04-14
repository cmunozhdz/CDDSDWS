//
//  GXBusinessComponentLoadHandler.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 28/02/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

#import <GXDataLayer/GXBusinessComponentWithKeyHandler.h>

NS_ASSUME_NONNULL_BEGIN

@class GXBusinessComponentLoadHandler;

@protocol GXBusinessComponentLoadHandlerDelegate <NSObject>

@optional
- (void)businessComponentLoadHandler:(GXBusinessComponentLoadHandler *)loadHandler
							 didLoad:(id <GXBusinessComponentLevelEntityData>)loadedEntityData;
- (void)businessComponentLoadHandler:(GXBusinessComponentLoadHandler *)loadHandler
			 didFailLoadingWithError:(NSError *)error;

@end

#pragma mark -

@interface GXBusinessComponentLoadHandler : GXBusinessComponentWithKeyHandler

@property(nullable, nonatomic, weak) id<GXBusinessComponentLoadHandlerDelegate> delegate;

#pragma mark - Internal

- (void)onError:(NSError *)error;

- (void)onSuccess:(id <GXBusinessComponentLevelEntityData>)entityData;

@end

NS_ASSUME_NONNULL_END
