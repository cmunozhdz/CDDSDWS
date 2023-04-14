//
//  GXMenuActionHandlerProtocol.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 9/8/18.
//  Copyright © 2018 GeneXus. All rights reserved.
//

@import GXObjectsModel;
#import <GXCoreUI/GXMenuControllerProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXMenuActionHandlerProtocol <GXActionHandler>

@property(nullable, nonatomic, strong, readonly) id<GXMenuContainerProtocol> actionHandlerMenuContainer;

@end

NS_ASSUME_NONNULL_END
