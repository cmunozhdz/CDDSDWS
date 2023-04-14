//
//  GXUserInterfaceContext+GXControl.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 4/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

@import GXObjectsModel;
#import <GXCoreUI/GXLayoutControlUserInterfaceContextProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXControl;
@protocol GXControlBaseProperties;
@protocol GXDynamicPropertyOverrideUserInterfaceContext;

@interface GXUserInterfaceContext (GXControl)

- (void)addUserInterfaceContextWithControlBaseProperties:(id <GXControlBaseProperties>)control;

- (void)addUserInterfaceContextWithLayoutControl:(id <GXControl>)control;

- (nullable id<GXDynamicPropertyOverrideUserInterfaceContext>)addUserInterfaceContextWithDynamicPropertyOverrideName:(NSString *)lowercasePropName
																										 controlName:(NSString *)lowercaseControlName;

@end

NS_ASSUME_NONNULL_END
