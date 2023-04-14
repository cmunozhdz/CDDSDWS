//
//  GXCoreBL.h
//  GXCoreBL
//
//  Created by Fabian Inthamoussu on 29/1/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

#import <Foundation/Foundation.h>
#if TARGET_OS_IOS || TARGET_OS_TV
#import <UIKit/UIKit.h>
#elif TARGET_OS_WATCH
#import <WatchKit/WatchKit.h>
#endif
//! Project version number for GXCoreBL.
FOUNDATION_EXPORT double GXCoreBLVersionNumber;

//! Project version string for GXCoreBL.
FOUNDATION_EXPORT const unsigned char GXCoreBLVersionString[];

#import <GXCoreBL/GXActionExObjEventsHelper.h>
#if TARGET_OS_IOS || TARGET_OS_TV
#import <GXCoreBL/GXActionExObjWebSocket.h>
#endif // TARGET_OS_IOS || TARGET_OS_TV
#import <GXCoreBL/GXActionExternalObjectHandler.h>
#import <GXCoreBL/GXActionHandler.h>
#import <GXCoreBL/GXActionHandler+GXActionHandlerContextHelpers.h>
#import <GXCoreBL/GXActionHandlerContext.h>
#import <GXCoreBL/GXActionHandlerSender.h>
#import <GXCoreBL/GXActionProcedureHandler.h>
#import <GXCoreBL/GXActionsFactory.h>
#import <GXCoreBL/GXActionsManager.h>
#import <GXCoreBL/GXAnalyticsService.h>
#import <GXCoreBL/GXAudioManagerService.h>
#import <GXCoreBL/GXAudioRecordingService.h>
#import <GXCoreBL/GXCameraAPIQualityType.h>
#import <GXCoreBL/GXCoreBLServices.h>
#if TARGET_OS_IOS || TARGET_OS_TV
#import <GXCoreBL/GXCoreBLServices+GXApplicationOpenURLHandler.h>
#endif // TARGET_OS_IOS || TARGET_OS_TV
#import <GXCoreBL/GXCoreBLServices+GXAnalyticsService.h>
#import <GXCoreBL/GXDeviceAuthenticationService.h>
#import <GXCoreBL/GXEntityModelHelper.h>
#import <GXCoreBL/GXEOClientStorageAPI.h>
#import <GXCoreBL/GXEOiOSPermissions.h>
#import <GXCoreBL/GXEONetworkAPI.h>
#import <GXCoreBL/GXFacebookHelper.h>
#import <GXCoreBL/GXFacebookServices.h>
#import <GXCoreBL/GXLocationManager.h>
#import <GXCoreBL/GXModel+GXActionsManager.h>
#import <GXCoreBL/GXRemoteConfigurationService.h>
#import <GXCoreBL/GXSecureActionHandler.h>
#import <GXCoreBL/GXSecurityHelper+GXActionHandler.h>
#import <GXCoreBL/GXThreadExpressionEvaluatorHelper.h>
#import <GXCoreBL/GXTwitterHelper.h>
#import <GXCoreBL/GXTwitterService.h>
#import <GXCoreBL/GXUserNotificationsManager.h>
#import <GXCoreBL/GXUserNotificationsManager+GXUserNotificationsDelegateHelper.h>
#import <GXCoreBL/GXUserNotificationsManager+Optionals.h>
#import <GXCoreBL/GXWeChatService.h>

#if TARGET_OS_IOS || TARGET_OS_TV
#import <GXCoreBL/SRWebSocket.h>
#endif // TARGET_OS_IOS || TARGET_OS_TV
