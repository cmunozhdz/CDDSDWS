//
//  GXLayoutControlUserInterfaceContextProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 4/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

@import GXObjectsModel;
#import <GXCoreUI/GXControlBasePropertiesUserInterfaceContextProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXControl;
@protocol GXControlBasePropertiesUserInterfaceContext;

@protocol GXLayoutControlUserInterfaceContext <GXControlBasePropertiesUserInterfaceContext, GXControlUserInterfaceContext, GXViewUserInterfaceContext>

@property(nullable, nonatomic, strong, readonly) id <GXControl> userInterfaceContextControl;

@end

NS_ASSUME_NONNULL_END
