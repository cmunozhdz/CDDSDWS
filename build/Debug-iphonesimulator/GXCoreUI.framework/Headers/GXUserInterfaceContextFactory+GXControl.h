//
//  GXUserInterfaceContextFactory+GXControl.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 4/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

@import GXObjectsModel;
#import <GXCoreUI/GXLayoutControlUserInterfaceContextProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXUserInterfaceContextFactory (GXControl)

+ (nullable id<GXControlBasePropertiesUserInterfaceContext>)userInterfaceContextWithControlBaseProperties:(nullable id<GXControlBaseProperties>)control;

+ (nullable id <GXLayoutControlUserInterfaceContext>)userInterfaceContextWithLayoutControl:(nullable id<GXControl>)control;

+ (nullable id<GXDynamicPropertyOverrideUserInterfaceContext>)userInterfaceContextWithDynamicPropertyOverrideName:(nullable NSString *)lowercasePropName
																									  controlName:(nullable NSString *)lowercaseControlName;

@end

NS_ASSUME_NONNULL_END
