//
//  GXControllerProtocol.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 28/12/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import GXObjectsModel;
@import GXObjectsModel.Swift;
#if !TARGET_OS_WATCH
@import UIKit;
#import <GXCoreUI/GXApplicationBarsAppearance.h>
#import <GXCoreUI/GXWindow.h>
#else
@import WatchKit;
#endif // !TARGET_OS_WATCH

@protocol GXCallerDelegate;

NS_ASSUME_NONNULL_BEGIN

#if TARGET_OS_WATCH
@protocol GXControllerProtocol <GXModelObject, GXControllerPresentationHandlerProtocol, GXInheritedConnectivitySupportResolver, GXSDObjectLocator>
#else
@protocol GXControllerProtocol <GXModelObject, GXControllerPresentationHandlerProtocol, GXInheritedConnectivitySupportResolver, GXSDObjectLocator, GXApplicationBarsAppearance, GXViewControllerAdaptativePresentation, GXAllowLowContrastTintColor>
#endif // TARGET_OS_WATCH

#if TARGET_OS_WATCH
@property(nonatomic, assign, readonly) BOOL gxActive;
#endif // TARGET_OS_WATCH
@property(nonatomic, assign, readonly) BOOL gxVisible;
@property(nonatomic, assign, readonly) GXViewVisibleStateType gxVisibleState;
@property(nonatomic, assign, readonly) NSUInteger gxAppearedCount;

@property(nonatomic, strong, readonly) id <GXMutablePropertiesObject> gxProperties;

@property(nonatomic, strong, readonly) GXUserInterfaceController *gxUserInterfaceController;

@property(nullable, nonatomic, weak) id<GXCallerDelegate> callerDelegate;

@property(nonatomic, assign, readonly) GXConnectivitySupportType connectivitySupport;

@property(nonatomic, assign, readonly) GXControllerBackEventType gxBackEventType;

@property(nonatomic, assign) GXControllerReturnState gxReturnState;

#pragma mark - Action Handling

@property(nonatomic, strong, readonly) NSArray<id<GXActionHandler>> *gxExecutingActions;

- (BOOL)executeAction:(id<GXActionHandler>)actionHandler
withContextEntityData:(nullable id<GXEntityDataWithOverrideValues>)entityData
			   sender:(nullable id)sender
 userInterfaceContext:(nullable GXUserInterfaceContext *)uiContext;

- (nullable id <GXActionHandler>)executeNotificationWithActionName:(NSString *)actionName parameters:(nullable NSDictionary<NSString *, id> *)parameters concurrencyMode:(GXActionHandlerConcurrencyMode)concurrencyMode;
- (nullable id <GXActionHandler>)executeEventWithActionName:(NSString *)actionName parameters:(nullable NSDictionary<NSString *, id> *)parameters concurrencyMode:(GXActionHandlerConcurrencyMode)concurrencyMode;
#if TARGET_OS_IOS
- (nullable id <GXActionHandler>)executeShortcutWithName:(NSString *)shortcutName parameters:(nullable NSDictionary<NSString *, id> *)parameters concurrencyMode:(GXActionHandlerConcurrencyMode)concurrencyMode;
#endif // TARGET_OS_IOS
- (nullable id <GXActionHandler>)executeDynamicObjectCall:(NSString *)dynamicCallString;

@end

NS_ASSUME_NONNULL_END
