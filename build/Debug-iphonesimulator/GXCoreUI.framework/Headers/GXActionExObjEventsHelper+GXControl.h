//
//  GXActionExObjEventsHelper+GXControl.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 21/4/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import GXCoreBL;
#import <GXCoreUI/GXControlContainer.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXActionExObjEventsHelper (GXControl)

+ (void)proccessExternalObjectNotification:(NSNotification *)notification
					 withActionsDispatcher:(id<GXControlActionsDispatcher>)actionsDispatcher;

@end

NS_ASSUME_NONNULL_END
