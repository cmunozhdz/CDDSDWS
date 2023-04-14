//
//  GXCallerDelegate.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 01/03/11.
//  Copyright 2011 Artech. All rights reserved.
//
@import GXObjectsModel;
#import <GXCoreUI/GXControllerProtocol.h>
#import <GXCoreUI/GXEntityControllerProtocol.h>
#if !TARGET_OS_WATCH
@class GXViewController;
@class GXEntityViewController;
#endif // !TARGET_OS_WATCH

NS_ASSUME_NONNULL_BEGIN

@protocol GXCallerDelegate <GXOptionalConditionalInheritedConnectivitySupportResolver>

/*!
 Notifies delegate that controller has been dismissed
 
 @param controller The controller dismissed
 @discussion This method is called from controller's dealloc and it's unsafe to make UI changes (presenting or dismissing another controller), consider delaying one event loop. Also note this method may be called in any thread.
 */
- (void)calledGXControllerDismissed:(id<GXControllerProtocol>)controller;

@optional
- (BOOL)dismissCalledGXController:(id<GXControllerProtocol>)controller animated:(BOOL)animated completion:(void(^ _Nullable)(void))completion;
- (BOOL)calledGXController:(id<GXControllerProtocol>)controller willExecuteAction:(id <GXActionHandler>)actionHandler;
- (void)calledGXController:(id<GXControllerProtocol>)controller willBeReplacedWithController:(id<GXControllerProtocol>)newController;
- (id <GXActionHandler>)calledGXControllerCallerActionHandler:(id<GXControllerProtocol>)controller;

@end


@protocol GXEntityCallerDelegate <GXCallerDelegate>

@optional
- (void)entityGXController:(id<GXEntityControllerProtocol>)controller
	   didInsertEntityData:(id <GXEntityData>)insertedEntityData;
- (void)entityGXControllerDidCancelInsert:(id<GXEntityControllerProtocol>)controller;

- (void)entityGXController:(id<GXEntityControllerProtocol>)controller
	   didUpdateEntityData:(id <GXEntityData>)updatedEntityData;
- (void)entityGXControllerDidCancelUpdate:(id<GXEntityControllerProtocol>)controller;

- (void)entityGXControllerDidDeleteEntityData:(id<GXEntityControllerProtocol>)controller;
- (void)entityGXControllerDidCancelDelete:(id<GXEntityControllerProtocol>)controller;

- (BOOL)entityGXController:(id<GXEntityControllerProtocol>)controller
		 didPickEntityData:(id <GXEntityData>)pickedEntityData;

@end

extern NSString *const GXUserInterfaceControllerDismissedNotification; /// This notification is posted after calledGXControllerDismissed: is called, the same considerations applies
extern NSString *const GXUserInterfaceControllerWillPresentNotification;

NS_ASSUME_NONNULL_END
