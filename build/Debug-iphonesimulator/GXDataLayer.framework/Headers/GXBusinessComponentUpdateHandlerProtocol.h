//
//  GXBusinessComponentUpdateHandlerProtocol.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 09/10/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

#import <GXDataLayer/GXBusinessComponentSaveHandler.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXBusinessComponentUpdateHandler;

@protocol GXBusinessComponentUpdateHandlerDelegate <NSObject>

@optional
- (void)businessComponentUpdateHandler:(GXBusinessComponentSaveHandler<GXBusinessComponentUpdateHandler> *)updateHandler
							 didUpdate:(id <GXBusinessComponentLevelEntityData>)updatedEntityData;
- (void)businessComponentUpdateHandler:(GXBusinessComponentSaveHandler<GXBusinessComponentUpdateHandler> *)updateHandler
			  didFailUpdatingWithError:(NSError *)error;

@end

@protocol GXBusinessComponentUpdateHandler

@property(nullable, weak) id <GXBusinessComponentUpdateHandlerDelegate> updateDelegate;

@end

NS_ASSUME_NONNULL_END
