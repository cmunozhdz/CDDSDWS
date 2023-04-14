//
//  GXViewController.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 28/02/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import GXObjectsModel;
@import GXObjectsModel.Swift;
@import GXCoreBL;
#import <GXCoreUI/GXApplicationBarsAppearance.h>
#import <GXCoreUI/GXCallerDelegate.h>
#import <GXCoreUI/GXControllerProtocol.h>
#import <GXCoreUI/GXWindow.h>
#import <GXCoreUI/UIViewController+GXPropertiesObject.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(uint_least8_t, GXViewControllerBarType) {
	GXViewControllerBarTypeNavigationBar = 1 << 0,
	GXViewControllerBarTypeToolbar = 1 << 1
};

@interface GXViewController : UIViewController <GXControllerProtocol, GXControllerPresentationHandlerProtocol, GXActionHandlerUserInterfaceControllerProtocol, GXActionHandlerUIDelegate> {
@protected
	GXConnectivitySupportType _connSupport;
}

@property(nullable, nonatomic, weak) id <GXCallerDelegate> callerDelegate;
@property(assign, readonly) GXViewVisibleStateType viewVisibleState;
@property(assign, readonly) NSUInteger viewAppearedCount; // Number of times that viewDidAppear was triggered for this panel
@property(nullable, nonatomic, strong, readonly) UIView *contentView;
@property(nonatomic, strong, readonly) id <GXMutablePropertiesObject> properties;
@property(nonatomic, assign, readonly) GXConnectivitySupportType connectivitySupport; // Resolved connectivity support (Online or Offline)
@property(nullable, nonatomic, strong, readonly) NSString *formClassFullNameForCurrentMode;
@property(nullable, nonatomic, strong, readonly) GXStyleClass *formClassForCurrentMode;
@property(nonatomic, assign, readonly) GXObjectType gxObjectType;
@property(nonatomic, strong, readonly) NSString *gxObjectName;
@property(nonatomic, strong, readonly) NSString *gxObjectFullName;
@property(nonatomic, assign) GXActionHandlerConcurrencyMode defaultActionConcurrencyMode;
@property(nonatomic, assign) BOOL startExecuted;

#if TARGET_OS_IOS
/// If YES, updates modalInPresentation (or modalInPopover before iOS 13) automatically (on updateModalInPresentationIfNeeded). Defaults to YES
@property(nonatomic, assign) BOOL gxUpdatesModalInPresentation;
/// Updates modalInPresentation (or modalInPopover before iOS 13) if self.gxUpdatesModalInPresentation = YES. Default implementation is based on self.gxBackEventType.
- (void)updateModalInPresentationIfNeeded;
#endif // TARGET_OS_IOS

- (void)viewWillLayoutSubviews __attribute__((objc_requires_super));
- (void)viewDidLayoutSubviews __attribute__((objc_requires_super));

- (void)onApplicationDidBecomeActive __attribute__((objc_requires_super));

- (nullable id <GXEventDescriptor>)backEventDescriptor;
- (void)updateStateWithCurrentBackEventDescriptor;


- (NSDictionary<GXActionHandlerUserInfoKey, id> *)newActionHandlerUserInfo;

- (BOOL)executeAction:(id<GXActionHandler>)actionHandler
withContextEntityData:(nullable id<GXEntityDataWithOverrideValues>)entityData
			   sender:(nullable id)sender
 userInterfaceContext:(nullable GXUserInterfaceContext *)uiContext;

- (BOOL)onActionHandler:(id<GXActionHandler>)actionHandler didFinishExecutingWithError:(nullable NSError *)error;

- (BOOL)isActionExecuting:(id <GXActionHandler>)actionHandler;

// Sets the navigationItem title or titleView with the given title. Retuns YES if title was updated, NO otherwise
- (BOOL)setNavigationTitle:(nullable NSString *)title;

/**
 * Delegates the task to current root controller
 */
- (void)clearViewControllerLeftNavigationItemAnimated:(BOOL)animated;
- (void)clearViewControllerRightNavigationItemAnimated:(BOOL)animated;

/**
 * If item is nil calls corresponding clearViewControllerLeftNavigationItemAnimated,
 * Otherwise sets self.navigationItem left/right item
 */
- (void)setLeftNavigationItem:(nullable UIBarButtonItem *)item animated:(BOOL)animated;
- (void)setRightNavigationItem:(nullable UIBarButtonItem *)item animated:(BOOL)animated;

/**
 * If items is empty (or nil) calls corresponding clearViewControllerLeftNavigationItemAnimated,
 * Otherwise sets self.navigationItem left/right items
 */
- (void)setLeftNavigationItems:(nullable NSArray<UIBarButtonItem *> *)items animated:(BOOL)animated;
- (void)setRightNavigationItems:(nullable NSArray<UIBarButtonItem *> *)items animated:(BOOL)animated;

#pragma mark Actions UI Items

#if TARGET_OS_IOS
- (void)refreshToolbarVisibility:(BOOL)animated; // If viewVisibleState is Appeared or Appearing, then sets the toolbar visible/hidden if there are toolbar items and self.showGxApplicationBars
#endif // TARGET_OS_IOS

- (BOOL)actionBarAnimationNeeded; // Returns YES if viewVisibleState is Appeared or Appearing & not canIgnoreActionBarAnimation, NO otherwise
- (BOOL)canIgnoreActionBarAnimation; // Returns YES if viewAppearedCount is 0 and is first and only controller in navigation controller, NO otherwise

- (void)updateActionBarActionsDefaultAppBarThemeClass;

/// Applies current app bar class
- (void)applyApplicationBarStyle:(BOOL)animated;

#pragma mark Standard Actions UI Items

#if TARGET_OS_IOS
- (BOOL)hidesStandardBackButton;

- (UIBarButtonItem *)gxCloseBarButtonItem;
- (void)handleGXCloseEvent:(nullable id)sender;
#endif // TARGET_OS_IOS

@end

NS_ASSUME_NONNULL_END
