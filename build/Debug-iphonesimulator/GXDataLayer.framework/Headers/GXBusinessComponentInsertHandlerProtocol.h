//
//  GXBusinessComponentInsertHandlerProtocol.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 09/10/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

#import <GXDataLayer/GXBusinessComponentSaveHandler.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXBusinessComponentInsertHandler;

@protocol GXBusinessComponentInsertHandlerDelegate <NSObject>

@optional
- (void)businessComponentInsertHandler:(GXBusinessComponentSaveHandler<GXBusinessComponentInsertHandler> *)insertHandler
							 didInsert:(id <GXBusinessComponentLevelEntityData>)insertedEntityData;
- (void)businessComponentInsertHandler:(GXBusinessComponentSaveHandler<GXBusinessComponentInsertHandler> *)insertHandler
			 didFailInsertingWithError:(NSError *)error;

@end

@protocol GXBusinessComponentInsertHandler

@property(nullable, weak) id <GXBusinessComponentInsertHandlerDelegate> insertDelegate;

@end

NS_ASSUME_NONNULL_END
