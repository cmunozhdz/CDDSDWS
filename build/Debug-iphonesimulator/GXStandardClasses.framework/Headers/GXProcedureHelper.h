//
//  GXProcedureHelper.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 25/09/14.
//  Copyright (c) 2014 Artech. All rights reserved.
//

@import GXFoundation;
@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@class GXProcedure;

/// Allowed value types are GXProcedureExecutionOptions or NSDictionary<NSString*, GXProcedureExecutionOptions *> being the keys the lowercase proc names
extern NSString *const GXActionHandlerUserInfoProcedureOptionsKey;

@interface GXProcedureHelper : NSObject

/// Must be called from a GXOfflineThread
+ (nonnull NSArray *)executeOfflineProcedureInstance:(GXProcedure *)gxProc
									 fromModelObject:(id<GXModelObject>)modelObject
									  withParameters:(nullable NSArray *)gxProcParams;

@end

NS_ASSUME_NONNULL_END
