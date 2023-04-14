//
//  GXApplicationProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 02/09/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

#define kAppEntryPointPropertyIsMain @"isMain"
#define kAppEntryPointPropertyAppTitle @"appTitle"
#define kAppEntryPointPropertyAppIcon @"appIcon"
#define kAppEntryPointPropertyAppWelcomImage @"appWelcomeImage"
#define kAppEntryPointPropertyAppEnableAds @"appEnableAdds"
#define kAppEntryPointPropertyAppEnableNotifications @"appEnableNotifications"
#define kAppEntryPointPropertySilentNotificationsEnabledKey @"appSilentNotifEnabled"
#define kAppEntryPointPropertyNotificationsRegistrationModeKey @"appNotifRegistMode"
#define kAppEntryPointPropertyAppNotificationHandler @"appNotifRegHandler"
#define kAppEntryPointPropertyAppEnableIntegratedSecurity @"appEnableIntSec"
#define kAppEntryPointPropertyAppIntSecObjClientId @"appIntSecObjClientId"
#define kAppEntryPointPropertyAppIntSecAnonymous @"appIntSecAnonymous"
#define kAppEntryPointPropertyAppShareSessionToWebView @"appShareSessionToWebView"
#define kAppEntryPointPropertyAppThemeName @"appThemeName"
#define kAppEntryPointPropertyLoginSDObject @"appGAMLoginObj"
#define kAppEntryPointPropertyNotAuthorizedSDObject @"appGAMNotAuthObj"
#define kAppEntryPointPropertyChangePassSDObject @"appGAMChangePassObj"
#define kAppEntryPointPropertyEnableGAMBiometrics @"appGAMEnableBiometrics"
#define kAppEntryPointPropertyGAMBiometricsReuseDuration @"appGAMBiometricsReuseDuration"
#define kAppEntryPointPropertyBlurOnBackground @"appBlurOnBackground"
#define kAppEntryPointPropertyFacebookAppId @"appFbAppId"
#define kAppEntryPointPropertyFacebookAppSuffix @"appFbAppSF"
#define kAppEntryPointPropertyWeChatAppId @"WeChat_AppId"
#define kAppEntryPointPropertyAppEnableAnalytics @"appEnableAnalytics"
#define kAppEntryPointPropertyAppAnalyticsPeriod @"appAnalyticsPeriod"
#define kAppEntryPointPropertyIDEConnectionString @"appIDEConnStr"
#define kAppEntryPointPropertyAppEnableAnalyticsAppId @"appAnalyticsAppId"
#define kAppEntryPointPropertyAppAnalyticsProviderName @"appAnalyticsProvider"
#define kAppEntryPointPropertyAppDefaultInterfaceOrientation @"appDefaultInterfaceOrientation"
#define kAppEntryPointPropertySyncReceiveCriteria @"appSyncReceiveCriteria"
#define kAppEntryPointPropertySyncReceiveMinTime @"appSyncReceiveMinTime"
#define kAppEntryPointPropertySyncReceiveTimeout @"appSyncReceiveTimeout"
#define kAppEntryPointPropertySyncSendCriteria @"appSyncSendCriteria"
#define kAppEntryPointPropertySyncSendMinTime @"appSyncSendMinTime"
#define kAppEntryPointPropertySyncSendTimeout @"appSyncSendTimeout"
#define kAppEntryPointPropertyEncryptOfflineDatabase @"appEncryptOfflineDatabase"
#define kAppEntryPointPropertyClientInfoAppId @"appId"
#define kAppEntryPointPropertyClientInfoAppVersionCode @"appVersionCode"
#define kAppEntryPointPropertyClientInfoAppVersionName @"appVersionName"
#define kAppEntryPointPropertyEnableTestMode @"appEnableTestMode"
#define kAppEntryPointPropertyDeepLinkBaseURL @"appDeepLinkBaseURL"
#define kAppEntryPointPropertyAppleMapsApi @"AppleMapsApi"
#define kAppEntryPointPropertyAppleMapsApiKey @"AppleMapsApiKey"
#if TARGET_OS_IOS
#define kAppEntryPointPropertyAppShortcutsMenu @"appShortcutsMenu"
#endif // TARGET_OS_IOS
#define kAppEntryPointPropertyAdsProvider @"adsProvider"
#define kAppEntryPointPropertyBaseColorScheme @"appBaseColorScheme"
#define kAppEntryPointPropertyPreferredColorSchemeEnabled @"appPreferredColorSchemeEnabled"
#define kAppEntryPointPropertyContactsNoteEntitlement @"appContactsNoteEntitlement"

typedef NS_ENUM(NSInteger, GXApplicationServerType) {
	GXApplicationServerType_Unknown = 0,
	GXApplicationServerType_Java = 12,
	GXApplicationServerType_DotNet = 15,
	GXApplicationServerType_DotNetCore = 41
};

typedef NS_ENUM(uint_least8_t, GXApplicationEntryPointType) {
	GXApplicationEntryPointMenu,
	GXApplicationEntryPointWorkWith
};

typedef NS_ENUM(uint_least8_t, GXApplicationEntryPointNotificationReg) {
	GXApplicationEntryPointNotificationRegAuto,
	GXApplicationEntryPointNotificationRegManual
};

@protocol GXApplicationEntryPoint <NSObject>

@property(nonatomic, assign, readonly) GXApplicationEntryPointType appEntryPointType;
@property(nonatomic, strong, readonly) NSString *appEntryPointName;

@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, id> *appEntryPointProperties;
- (nullable id)valueForAppEntryPointProperty:(NSString *)property;

@end

NS_SWIFT_NAME(GXApplicationProtocol)
@protocol GXApplication <NSObject>

@property(nullable, nonatomic, strong, readonly) NSURL *appServerBaseUrl;
@property(nullable, nonatomic, strong, readonly) NSString *appName;
@property(nullable, nonatomic, strong, readonly) id <GXApplicationEntryPoint> appEntryPoint;

@optional
@property(nullable, nonatomic, strong, readonly) NSString *appDescription;
@property(nullable, nonatomic, strong, readonly) NSString *appUser;
@property(nullable, nonatomic, strong, readonly) NSString *appUUID;
@property(nonatomic, assign, readonly) NSUInteger appVersion;
@property(nonatomic, assign, readonly) GXApplicationServerType appServerType;
@property(nonatomic, assign, readonly) BOOL appEnableTestMode;

#if !TARGET_OS_WATCH
/// Returns the Mini App identifier
/// @discussion: This property should be implemented for Mini App applications returning its identifier
@property(nullable, nonatomic, strong, readonly) NSString *appMiniAppId;
#endif

@end

NS_ASSUME_NONNULL_END
