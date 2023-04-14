//
//  GXModel+GXActionsManager.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 22/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

@import GXObjectsModel;
#import <GXCoreBL/GXActionsManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXModel (GXActionsManager)

@property(nonatomic, strong, readonly) GXActionsManager *actionsManager;

@end

NS_ASSUME_NONNULL_END
