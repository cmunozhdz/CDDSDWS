//
//  GXActionHandler+GXMenuActionHandlerProtocol.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 9/8/18.
//  Copyright © 2018 GeneXus. All rights reserved.
//

@import GXCoreBL;
#import <GXCoreUI/GXMenuActionHandlerProtocol.h>

extern GXActionHandlerUserInfoKey GXActionHandlerUserInfoMenuContainerKey; // id<GXMenuContainerProtocol>

NS_ASSUME_NONNULL_BEGIN

@interface GXActionHandler (GXMenuActionHandlerProtocol) <GXMenuActionHandlerProtocol>

@end

NS_ASSUME_NONNULL_END
