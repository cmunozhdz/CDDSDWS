//
//  GXSecurityHelper+GXActionHandler.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 19/2/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import GXObjectsModel;
#import <GXCoreBL/GXActionHandler.h>
#import <GXCoreBL/GXSecureActionHandler.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXSecurityHelper (GXActionHandler)

+ (void)secureActionHandlerExecute:(GXActionHandler<GXSecureActionHandler> *)handler;

@end

NS_ASSUME_NONNULL_END
