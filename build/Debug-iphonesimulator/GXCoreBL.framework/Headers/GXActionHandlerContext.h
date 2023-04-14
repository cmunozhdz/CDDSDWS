//
//  GXActionHandlerContext.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 09/03/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@interface GXActionHandlerContext : NSObject <GXActionHandlerContext>

- (instancetype)initWithEntityData:(nullable id<GXEntityDataWithOverrideValues>)entityData
							sender:(nullable id<GXActionSender>)sender NS_DESIGNATED_INITIALIZER;

@end

@protocol GXActionHandlerContextWrapperOptionals <NSObject>

@optional
+ (id<GXActionHandlerUIContext>)uiActionHandlerWrapperFromContext:(id<GXActionHandlerContext>)context;

@end

@interface GXActionHandlerContextWrapper : NSObject <GXActionHandlerContext, GXActionHandlerContextWrapperOptionals>

@property(nonatomic, strong, readonly) id<GXActionHandlerContext> innerActionHandlerContext;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithActionHandlerContext:(id<GXActionHandlerContext>)context NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
