//
//  GXActionsManager.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 07/02/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import GXObjectsModel;
#import <GXCoreBL/GXActionHandler.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXActionsManager : NSObject <GXActionHandlerDelegate>

- (void)manageActionHandler:(GXActionHandler *)actionHandler;

@end

NS_ASSUME_NONNULL_END
