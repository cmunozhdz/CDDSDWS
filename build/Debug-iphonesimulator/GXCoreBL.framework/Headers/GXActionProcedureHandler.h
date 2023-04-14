//
//  GXActionProcedureHandler.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 09/03/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import GXObjectsModel;
@import GXDataLayer;
@import GXStandardClasses;
#import <GXCoreBL/GXActionHandler.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXActionProcedureHandler : GXActionHandler <GXMultilineActionHandler,
														GXObjectUploaderDelegate,
														GXURLRequestOperationDelegate,
														GXParseJsonOperationDelegate>

@property(nullable, nonatomic, readonly) GXProcedureModel *procModel;
@property(nullable, nonatomic, readonly) GXProcedureExecutionOptions *procExecutionOptions;

@end

@protocol GXActionProcedureHandlerOptionals <NSObject>

@optional
- (BOOL)waitForMultilineActionEntities; // action execution sould continue in continueExecutingActionWithEntities: if returns YES
- (void)clearMultilineActionSelection;

@end

@interface GXActionProcedureHandler (Internal) <GXActionProcedureHandlerOptionals>

- (BOOL)executeOfflineGXProcedure;
- (BOOL)executeOfflineMultilineProcedure:(nullable NSArray<id <GXEntityData>> *)entities;

- (BOOL)procedureInParameters:(NSArray<GXProcedureParameter *> * _Nullable * _Nullable)parameters indexes:(NSIndexSet * _Nullable * _Nullable)indexes;

- (void)performRequestWithBody:(nullable NSData *)requestBody url:(NSURL*)procURL;

@end

NS_ASSUME_NONNULL_END
