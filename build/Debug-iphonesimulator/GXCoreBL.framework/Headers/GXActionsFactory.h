//
//  GXActionsFactory.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 07/02/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import GXObjectsModel;
#import <GXCoreBL/GXActionHandler.h>

@protocol GXEntityModel;

NS_ASSUME_NONNULL_BEGIN

@interface GXActionsFactory : NSObject

+ (nullable GXActionHandler *)newActionHandlerWithDescriptor:(nullable id <GXActionDescriptor>)actionDesc
													userInfo:(nullable NSDictionary<GXActionHandlerUserInfoKey, id> *)userInfo;

@end

NS_ASSUME_NONNULL_END
