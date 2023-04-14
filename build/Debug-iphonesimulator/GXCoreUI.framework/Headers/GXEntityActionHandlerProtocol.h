//
//  GXEntityActionHandlerProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 19/11/15.
//  Copyright © 2015 Artech. All rights reserved.
//

@import GXObjectsModel;
#import <GXCoreUI/GXEntityModelProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXEntityActionHandler <GXActionHandler>

@property(nullable, nonatomic, strong, readonly) id <GXEntityModel> actionHandlerEntityModel;

@end

NS_ASSUME_NONNULL_END
