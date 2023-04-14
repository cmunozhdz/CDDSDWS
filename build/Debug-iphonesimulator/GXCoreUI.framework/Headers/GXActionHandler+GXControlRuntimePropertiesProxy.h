//
//  GXActionHandler+GXControlRuntimePropertiesProxy.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 9/8/18.
//  Copyright © 2018 GeneXus. All rights reserved.
//

@import GXCoreBL;
#import <GXCoreUI/GXControl.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXActionHandler (GXControlRuntimePropertiesProxy)

@property(nullable, nonatomic, strong, readonly) id<GXControlRuntimePropertiesProxy> actionHandlerControlRuntimePropertiesProxy;

@end

NS_ASSUME_NONNULL_END
