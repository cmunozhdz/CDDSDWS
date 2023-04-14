//
//  GXEntityActionHandler.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 28/07/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import GXCoreBL;
#import <GXCoreUI/GXEntityActionHandlerProtocol.h>

NS_ASSUME_NONNULL_BEGIN

extern GXActionHandlerUserInfoKey GXActionHandlerUserInfoEntityModelKey; // id<GXEntityModel>

@interface GXActionHandler (GXEntityActionHandler) <GXEntityActionHandler>
@end

NS_ASSUME_NONNULL_END
