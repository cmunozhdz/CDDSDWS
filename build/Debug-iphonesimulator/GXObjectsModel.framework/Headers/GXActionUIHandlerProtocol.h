//
//  GXActionUIHandlerProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 2/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

@import UIKit;
#if TARGET_OS_WATCH
@import WatchKit;
#endif // !TARGET_OS_WATCH
#import <GXObjectsModel/GXActionHandlerProtocol.h>
#import <GXObjectsModel/GXUserInterfaceContext.h>
#import <GXObjectsModel/GXCommonTypes.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXActionHandler;
@protocol GXActionHandlerDelegate;
@protocol GXActionSender;
@protocol GXControllerPresentationHandlerProtocol;
@class GXUserInterfaceContext;

@protocol GXActionHandlerUserInterfaceControllerProtocol <GXControllerPresentationHandlerProtocol>

/// Returns the caller's user interface controller of the action handler which may be nil. Note it could be different from actionSenderUserInterfaceContext.
@property(nullable, nonatomic, strong, readonly) GXUserInterfaceController *actionHandlerUserInterfaceController;

@end


@protocol GXActionHandlerUIDelegate <GXActionHandlerDelegate>

@optional
- (nullable id <GXControllerPresentationHandlerProtocol>)actionHandlerControllerPresentationHandler:(id <GXActionHandler>)actionHandler;
- (nullable id <GXActionHandlerUserInterfaceControllerProtocol>)actionHandlerUserInterfaceController:(id <GXActionHandler>)actionHandler;

@end


@protocol GXActionUISender <GXActionSender>

/// User interface context in which to execute the action provided by the caller.
@property(nonatomic, strong, readonly) GXUserInterfaceContext *actionSenderUserInterfaceContext;

@end


@protocol GXActionHandlerUIContext <GXActionHandlerContext>

@property(nullable, nonatomic, strong, readonly) id <GXActionUISender> actionHandlerUIContextSender;

@end


@protocol GXActionUIHandler <GXActionHandler>

@property(nullable, nonatomic, weak, readonly) id <GXActionHandlerUIDelegate> uiDelegate;
@property(nullable, nonatomic, strong, readonly) id <GXActionHandlerUIContext> actionHandlerUIContext;

@end

NS_ASSUME_NONNULL_END
