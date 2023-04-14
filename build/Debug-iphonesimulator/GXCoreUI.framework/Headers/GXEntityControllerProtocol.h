//
//  GXEntityControllerProtocol.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 28/12/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import GXObjectsModel;
#import <GXCoreUI/GXControllerProtocol.h>
#import <GXCoreUI/GXEntityModelProtocol.h>

@protocol GXControlComponent;
@protocol GXControlInterfaceObjectsProvider;

NS_ASSUME_NONNULL_BEGIN

@protocol GXEntityControllerProtocol <GXControllerProtocol, GXObjectWithParameters>
	
@property(nonatomic, strong, readonly) id<GXEntityModel> gxEntityModel;
@property(nonatomic, assign, readonly) GXModeType gxMode;
@property(nonatomic, strong, readonly) id<GXControlComponent> gxRootControl;
#if TARGET_OS_WATCH
@property(nonatomic, strong, readonly) id<GXControlInterfaceObjectsProvider> gxInterfaceObjectsProvider;
#endif // TARGET_OS_WATCH

@end

NS_ASSUME_NONNULL_END
