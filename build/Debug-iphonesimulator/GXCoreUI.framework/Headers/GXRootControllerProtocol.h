//
//  GXRootControllerProtocol.h
//  GXFlexibleClient
//
//  Created by willy on 4/26/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import Foundation;
#if !TARGET_OS_WATCH
@import UIKit;
#else
@import WatchKit;
#endif // !TARGET_OS_WATCH
@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@protocol GXModelObject;

typedef void(^GXReturnToHandlerWithCompletion)(BOOL animated, void (^ _Nullable completion)(void));

@protocol GXRootControllerProtocol <NSObject, GXModelObject>

@property(nullable, nonatomic, strong, readonly) NSString *rootControllerStyle;

- (id)initWithModel:(GXModel *)model;

#if !TARGET_OS_WATCH
- (void)reloadControllerWithModel:(GXModel *)model;
- (void)returnToInitialState:(BOOL)animated completion:(void (^ _Nullable)(void))completion;
#endif // !TARGET_OS_WATCH

#if !TARGET_OS_WATCH
- (BOOL)presentViewController:(UIViewController *)controller
					  context:(GXPresentationContext *)context
				   completion:(void (^ _Nullable)(void))completion;
- (BOOL)dismissUserInterfaceController:(UIViewController *)controller
							  animated:(BOOL)animated
							completion:(void (^ _Nullable)(void))completion;
#else
- (BOOL)presentInterfaceControllerWithName:(NSString *)controllerName
				interfaceControllerContext:(nullable id)interfaceControllerContext
					   presentationContext:(GXPresentationContext *)presentationContext
								completion:(void (^ _Nullable)(void))completion;
- (BOOL)presentInterfaceControllerWithNames:(NSArray<NSString *> *)controllerNames
				interfaceControllerContexts:(nullable NSArray *)interfaceControllerContexts
						presentationContext:(GXPresentationContext *)presentationContext
								 completion:(void (^ _Nullable)(void))completion;
- (BOOL)dismissUserInterfaceController:(WKInterfaceController *)controller
							  animated:(BOOL)animated
							completion:(void (^ _Nullable)(void))completion;
#endif // !TARGET_OS_WATCH

#if !TARGET_OS_WATCH
- (BOOL)isKnownTarget:(NSString *)targetName;
#endif // !TARGET_OS_WATCH

@optional

@property(nullable, nonatomic, strong, readonly) GXUserInterfaceController *applicationEntryPointUserInterfaceController;

/// completionHandler isn't called if return value is nil
- (nullable id<GXActionHandler>)executeApplicationEntryPointNotificationWithName:(NSString *)eventName
																	  parameters:(nullable NSDictionary<NSString *,id> *)parameters
																 concurrencyMode:(GXActionHandlerConcurrencyMode)concurrencyMode
															   completionHandler:(void (^ _Nullable)(id<GXActionHandler> _Nullable))completionHandler;
/// completionHandler isn't called if return value is nil
- (nullable id<GXActionHandler>)executeApplicationEntryPointEventWithName:(NSString *)eventName
															   parameters:(nullable NSDictionary<NSString *,id> *)parameters
														  concurrencyMode:(GXActionHandlerConcurrencyMode)concurrencyMode
														completionHandler:(void (^ _Nullable)(id<GXActionHandler> _Nullable))completionHandler;
#if TARGET_OS_IOS
/// completionHandler isn't called if return value is nil
- (nullable id<GXActionHandler>)executeApplicationEntryPointShortcutWithName:(NSString *)eventName
																  parameters:(nullable NSDictionary<NSString *,id> *)parameters
															 concurrencyMode:(GXActionHandlerConcurrencyMode)concurrencyMode
														   completionHandler:(void (^ _Nullable)(id<GXActionHandler> _Nullable))completionHandler;
#endif // TARGET_OS_IOS
/// completionHandler isn't called if return value is nil
- (nullable id<GXActionHandler>)executeApplicationEntryPointDynamicObjectCall:(NSString *)dynamicCallString
															completionHandler:(void (^ _Nullable)(id<GXActionHandler> _Nullable))completionHandler;


#if !TARGET_OS_WATCH
- (void)applicationWillDismissRootController;

- (void)clearViewControllerLeftNavigationItem:(UIViewController *)viewController animated:(BOOL)animated;
- (void)clearViewControllerRightNavigationItem:(UIViewController *)viewController animated:(BOOL)animated;

/**
 * Called (GXRootControllerHelper) just before presenting viewController modal with context from presentingViewController.
 * Returns the view controller to present from.
 * This method could be used to change the presentingViewController or to perform any action before a modal controller is presented.
 */
- (UIViewController *)willPresentViewControllerModal:(UIViewController *)viewController
											 context:(GXPresentationContext *)context
									  fromController:(UIViewController *)presentingViewController;
#endif // !TARGET_OS_WATCH

- (void)showCallTargetWithName:(NSString *)targetName
					  animated:(BOOL)animated
					completion:(void (^ _Nullable)(void))completion;

- (void)hideCallTargetWithName:(NSString *)targetName
					  animated:(BOOL)animated
					completion:(void (^ _Nullable)(void))completion;

- (void)expandCallTargetWithName:(NSString *)targetName
						animated:(BOOL)animated
					  completion:(void (^ _Nullable)(void))completion;

- (void)collapseCallTargetWithName:(NSString *)targetName
						  animated:(BOOL)animated
						completion:(void (^ _Nullable)(void))completion;

#if !TARGET_OS_WATCH
- (nullable GXReturnToHandlerWithCompletion)returnToHandlerWithComplition:(NSString *)returnTo
														   fromController:(nullable UIViewController *)fromController;
#endif // !TARGET_OS_WATCH

@end

@protocol GXRootControllerWithTabsProtocol <GXRootControllerProtocol>

- (void)setBadgeText:(nullable NSString *)text toTabIndex:(NSUInteger)tabIndex;
- (void)setBadgeText:(nullable NSString *)text toTabIndex:(NSUInteger)tabIndex withDuration:(NSUInteger)duration;
@property(nonatomic, assign) NSUInteger selectedTabIndex; // If the "More" navigation controller is selected, this property contains the value NSNotFound
- (void)goHomeAllTabs;
@property(nonatomic, assign, readonly) NSUInteger tabCount; // Visible + Hidden items

@end

NS_ASSUME_NONNULL_END
