//
//  GXRootControllerHelper.h
//  GXFlexibleClient
//
//  Created by willy on 12/11/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import UIKit;
@import GXObjectsModel;
#import <GXCoreUI/GXRootControllerProtocol.h>
#if !TARGET_OS_WATCH
#import <GXCoreUI/GXViewController.h>
#import <GXCoreUI/UIViewController+GXCallOptions.h>
#endif // !TARGET_OS_WATCH

NS_ASSUME_NONNULL_BEGIN

#if !TARGET_OS_WATCH
typedef UIViewController<GXRootControllerProtocol> * GXRootControllerInstanceRef;
#else
typedef id<GXRootControllerProtocol> GXRootControllerInstanceRef;
#endif // !TARGET_OS_WATCH


@interface GXRootControllerHelper : NSObject

#if !TARGET_OS_WATCH
+ (BOOL)presentViewController:(UIViewController *)controller
					  context:(GXPresentationContext *)context
		   fromRootController:(UIViewController <GXRootControllerProtocol> *)rootController
				   completion:(void (^_Nullable)(void))completion;
#else
+ (BOOL)presenInterfaceControllerWithName:(NSString *)controllerName
			   interfaceControllerContext:(nullable id)interfaceControllerContext
					  presentationContext:(GXPresentationContext *)presentationContext
					   fromRootController:(id<GXRootControllerProtocol>)rootController
							   completion:(void (^_Nullable)(void))completion;

+ (BOOL)presenInterfaceControllerWithNames:(NSArray<NSString *> *)controllerNames
			   interfaceControllerContexts:(nullable NSArray *)interfaceControllerContexts
					   presentationContext:(GXPresentationContext *)presentationContext
						fromRootController:(id<GXRootControllerProtocol>)rootController
								completion:(void (^_Nullable)(void))completion;
#endif // !TARGET_OS_WATCH

+ (BOOL)dismissUserInterfaceController:(GXUserInterfaceController *)controller
							  animated:(BOOL)animated
							completion:(void (^_Nullable)(void))completion;

#if !TARGET_OS_WATCH
+ (void)updateAndValidateContext:(GXPresentationContext *)context
	 forPresentingViewController:(UIViewController *)controller;
#else
+ (void)updateAndValidateContext:(GXPresentationContext *)context
 forPresentingControllerWithName:(NSString *)controllerName
	  interfaceControllerContext:(nullable id)interfaceControllerContext;

+ (void)updateAndValidateContext:(GXPresentationContext *)context
forPresentingControllerWithNames:(NSArray<NSString *> *)controllerNames
	 interfaceControllerContexts:(nullable NSArray *)interfaceControllerContexts;
#endif // !TARGET_OS_WATCH

#if !TARGET_OS_WATCH
+ (void)cleanAfterViewController:(UIViewController *)controller
					   presented:(BOOL)presented
					 withContext:(GXPresentationContext *)context;
#else
+ (void)cleanAfterControllerWithName:(NSString *)controllerName
		  interfaceControllerContext:(nullable id)interfaceControllerContext
						   presented:(BOOL)presented
				 presentationContext:(GXPresentationContext *)presentationContext;

+ (void)cleanAfterControllerWithNames:(NSArray<NSString *> *)controllerNames
		  interfaceControllerContexts:(nullable NSArray *)interfaceControllerContexts
							presented:(BOOL)presented
				  presentationContext:(GXPresentationContext *)presentationContext;
#endif // !TARGET_OS_WATCH

+ (void)cleanAfterDismissUserInterfaceController:(GXUserInterfaceController *)controller;

#if !TARGET_OS_WATCH
+ (void)clearViewControllerLeftNavigationItem:(UIViewController *)viewController animated:(BOOL)animated;
+ (void)clearViewControllerRightNavigationItem:(UIViewController *)viewController animated:(BOOL)animated;
#endif // !TARGET_OS_WATCH

+ (void)fireNavigationTargetShownEvent:(NSString *)targetName;
+ (void)fireNavigationTargetHiddenEvent:(NSString *)targetName;
+ (void)fireNavigationTargetExpandedEvent:(NSString *)targetName;
+ (void)fireNavigationTargetCollapsedEvent:(NSString *)targetName;

@end

NS_ASSUME_NONNULL_END
