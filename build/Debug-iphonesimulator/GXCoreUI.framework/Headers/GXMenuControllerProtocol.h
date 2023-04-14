//
//  GXMenuControllerProtocol.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 10/1/17.
//  Copyright © 2017 GeneXus. All rights reserved.
//

@import GXObjectsModel;
#import <GXCoreUI/GXControl.h>
#import <GXCoreUI/GXControllerProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXMenuContainerProtocol <NSObject>

@property(nonatomic, strong, readonly) id<GXMenu> gxMenu;
@property(nonatomic, strong, readonly) id<GXControlRuntimePropertiesProxy> gxMenuControlRuntimePropertiesProxy;

@end

@protocol GXMenuControllerProtocol <GXMenuContainerProtocol, GXControllerProtocol>
@end

NS_ASSUME_NONNULL_END
