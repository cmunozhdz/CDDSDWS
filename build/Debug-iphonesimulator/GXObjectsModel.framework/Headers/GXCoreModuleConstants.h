//
//  GXCoreModuleConstants.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 5/1/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Core Module names

#define kGXModule_Separator @"."
#define kGXLevel_Separator @"."

#define kGXRootModuleName_General						@"General"
#define kGXRootModuleName_General_Services				kGXRootModuleName_General kGXModule_Separator @"Services"

#define kGXCoreModuleName_GeneXus						@"GeneXus"
#define kGXCoreModuleName_GeneXus_Client				kGXCoreModuleName_GeneXus kGXModule_Separator @"Client"
#define kGXCoreModuleName_GeneXus_Common				kGXCoreModuleName_GeneXus kGXModule_Separator @"Common"
#define kGXCoreModuleName_GeneXus_Common_UI				kGXCoreModuleName_GeneXus_Common kGXModule_Separator @"UI"
#define kGXCoreModuleName_GeneXus_SD					kGXCoreModuleName_GeneXus kGXModule_Separator @"SD"
#define kGXCoreModuleName_GeneXus_SD_iOS				kGXCoreModuleName_GeneXus_SD kGXModule_Separator @"iOS"
#define kGXCoreModuleName_GeneXus_SD_Media				kGXCoreModuleName_GeneXus_SD kGXModule_Separator @"Media"
#define kGXCoreModuleName_GeneXus_SD_Notifications		kGXCoreModuleName_GeneXus_SD kGXModule_Separator @"Notifications"
#define kGXCoreModuleName_GeneXus_SD_Offline			kGXCoreModuleName_GeneXus_SD kGXModule_Separator @"Offline"
#define kGXCoreModuleName_GeneXus_SD_Store				kGXCoreModuleName_GeneXus_SD kGXModule_Separator @"Store"
#define kGXCoreModuleName_GeneXus_SD_Synchronization	kGXCoreModuleName_GeneXus_SD kGXModule_Separator @"Synchronization"
#define kGXCoreModuleName_GeneXus_Social				kGXCoreModuleName_GeneXus kGXModule_Separator @"Social"

extern NSString *const GXModule_Separator;

extern NSString *const GXRootModuleName_General;
extern NSString *const GXRootModuleName_General_Services;

extern NSString *const GXCoreModuleName_GeneXus;
extern NSString *const GXCoreModuleName_GeneXus_Client;
extern NSString *const GXCoreModuleName_GeneXus_Common;
extern NSString *const GXCoreModuleName_GeneXus_Common_UI;
extern NSString *const GXCoreModuleName_GeneXus_SD;
extern NSString *const GXCoreModuleName_GeneXus_SD_iOS;
extern NSString *const GXCoreModuleName_GeneXus_SD_Media;
extern NSString *const GXCoreModuleName_GeneXus_SD_Notifications;
extern NSString *const GXCoreModuleName_GeneXus_SD_Offline;
extern NSString *const GXCoreModuleName_GeneXus_SD_Store;
extern NSString *const GXCoreModuleName_GeneXus_SD_Synchronization;
extern NSString *const GXCoreModuleName_GeneXus_Social;

#pragma mark - Core Module object names

#define kGXCoreModule_eo_Client_ClientInformation_Name	kGXCoreModuleName_GeneXus_Client kGXModule_Separator @"ClientInformation"
#define kGXCoreModule_eo_Client_ClientStorage_Name		kGXCoreModuleName_GeneXus_Client kGXModule_Separator @"ClientStorage"
#define kGXCoreModule_eo_Client_Socket_Name				kGXCoreModuleName_GeneXus_Client kGXModule_Separator @"Socket"

extern NSString *const GXCoreModule_eo_Client_ClientInformation_Name;
extern NSString *const GXCoreModule_eo_Client_ClientStorage_Name;
extern NSString *const GXCoreModule_eo_Client_Client_Socket_Name;

#define kGXCoreModule_eo_Common_Analytics_Name			kGXCoreModuleName_GeneXus_Common kGXModule_Separator @"Analytics"
#define kGXCoreModule_eo_Common_Clipboard_Name			kGXCoreModuleName_GeneXus_Common kGXModule_Separator @"Clipboard"
#define kGXCoreModule_eo_Common_DynamicCall_Name		kGXCoreModuleName_GeneXus_Common kGXModule_Separator @"DynamicCall"
#define kGXCoreModule_eo_Common_Maps_Name				kGXCoreModuleName_GeneXus_Common kGXModule_Separator @"Maps"
#define kGXCoreModule_eo_Common_Geolocation_Name		kGXCoreModuleName_GeneXus_Common kGXModule_Separator @"Geolocation"
#define kGXCoreModule_eo_Common_Log_Name				kGXCoreModuleName_GeneXus_Common kGXModule_Separator @"Log"
#define kGXCoreModule_eo_Common_Runtime_Name			kGXCoreModuleName_GeneXus_Common kGXModule_Separator @"Runtime"
#define kGXCoreModule_sdt_Common_Messages_Name			kGXCoreModuleName_GeneXus_Common kGXModule_Separator @"Messages"
#define kGXCoreModule_sdt_Common_Messages_Message_Name	kGXCoreModule_sdt_Common_Messages_Name kGXLevel_Separator @"Message"

extern NSString *const GXCoreModule_eo_Common_Analytics_Name;
extern NSString *const GXCoreModule_eo_Common_Clipboard_Name;
extern NSString *const GXCoreModule_eo_Common_DynamicCall_Name;
extern NSString *const GXCoreModule_eo_Common_Maps_Name;
extern NSString *const GXCoreModule_eo_Common_Geolocation_Name;
extern NSString *const GXCoreModule_eo_Common_Log_Name;
extern NSString *const GXCoreModule_eo_Common_Runtime_Name;
extern NSString *const GXCoreModule_sdt_Common_Messages_Name;
extern NSString *const GXCoreModule_sdt_Common_Messages_Message_Name;

#define kGXCoreModule_eo_Common_UI_Appearance_Name		kGXCoreModuleName_GeneXus_Common_UI kGXModule_Separator @"Appearance"
#define kGXCoreModule_eo_Common_UI_DesignSystem_Name	kGXCoreModuleName_GeneXus_Common_UI kGXModule_Separator @"DesignSystem"
#define kGXCoreModule_eo_Common_UI_Navigation_Name		kGXCoreModuleName_GeneXus_Common_UI kGXModule_Separator @"Navigation"
#define kGXCoreModule_eo_Common_UI_Progress_Name		kGXCoreModuleName_GeneXus_Common_UI kGXModule_Separator @"Progress"

extern NSString *const GXCoreModule_eo_Common_UI_Appearance_Name;
extern NSString *const GXCoreModule_eo_Common_UI_DesignSystem_Name;
extern NSString *const GXCoreModule_eo_Common_UI_Navigation_Name;
extern NSString *const GXCoreModule_eo_Common_UI_Progress_Name;

#define kGXCoreModule_eo_SD_Actions_Name				kGXCoreModuleName_GeneXus_SD kGXModule_Separator @"Actions"
#define kGXCoreModule_eo_SD_Ads_Name					kGXCoreModuleName_GeneXus_SD kGXModule_Separator @"Ads"
#define kGXCoreModule_eo_SD_AppLifecycle_Name			kGXCoreModuleName_GeneXus_SD kGXModule_Separator @"AppLifecycle"
#define kGXCoreModule_eo_SD_ARPreview_Name				kGXCoreModuleName_GeneXus_SD kGXModule_Separator @"ARPreview"
#define kGXCoreModule_eo_SD_Beacons_Name				kGXCoreModuleName_GeneXus_SD kGXModule_Separator @"Beacons"
#define kGXCoreModule_eo_SD_Calendar_Name				kGXCoreModuleName_GeneXus_SD kGXModule_Separator @"Calendar"
#define kGXCoreModule_eo_SD_Contacts_Name				kGXCoreModuleName_GeneXus_SD kGXModule_Separator @"Contacts"
#define kGXCoreModule_eo_SD_DeepLink_Name				kGXCoreModuleName_GeneXus_SD kGXModule_Separator @"DeepLink"
#define kGXCoreModule_eo_SD_DeviceAuthentication_Name	kGXCoreModuleName_GeneXus_SD kGXModule_Separator @"DeviceAuthentication"
#define kGXCoreModule_eo_SD_Interop_Name				kGXCoreModuleName_GeneXus_SD kGXModule_Separator @"Interop"
#define kGXCoreModule_eo_SD_Network_Name				kGXCoreModuleName_GeneXus_SD kGXModule_Separator @"Network"
#define kGXCoreModule_eo_SD_RemoteConfig_Name			kGXCoreModuleName_GeneXus_SD kGXModule_Separator @"RemoteConfig"
#define kGXCoreModule_eo_SD_Scanner_Name				kGXCoreModuleName_GeneXus_SD kGXModule_Separator @"Scanner"
#define kGXCoreModule_eo_SD_CardScanner_Name			kGXCoreModuleName_GeneXus_SD kGXModule_Separator @"CardScanner"
#define kGXCoreModule_eo_SD_Search_Name					kGXCoreModuleName_GeneXus_SD kGXModule_Separator @"Search"
#define kGXCoreModule_eo_SD_WebBrowser_Name				kGXCoreModuleName_GeneXus_SD kGXModule_Separator @"WebBrowser"
#define kGXCoreModule_sdt_SD_CardInfo_Name				kGXCoreModuleName_GeneXus_SD kGXModule_Separator @"CardInformation"

#define KGXCoreModule_sdt_SD_LoginExternalAdditionalParameters 			kGXCoreModuleName_GeneXus_SD kGXModule_Separator @"LoginExternalAdditionalParameters"
#define KGXCoreModule_sdt_SD_LoginExternalAdditionalParametersProperty 	KGXCoreModule_sdt_SD_LoginExternalAdditionalParameters kGXModule_Separator @"Property"

extern NSString *const GXCoreModule_eo_SD_Actions_Name;
extern NSString *const GXCoreModule_eo_SD_Ads_Name;
extern NSString *const GXCoreModule_eo_SD_AppLifecycle_Name;
extern NSString *const GXCoreModule_eo_SD_ARPreview_Name;
extern NSString *const GXCoreModule_eo_SD_Beacons_Name;
extern NSString *const GXCoreModule_eo_SD_Calendar_Name;
extern NSString *const GXCoreModule_eo_SD_Contacts_Name;
extern NSString *const GXCoreModule_eo_SD_DeepLink_Name;
extern NSString *const GXCoreModule_eo_SD_DeviceAuthentication_Name;
extern NSString *const GXCoreModule_eo_SD_Interop_Name;
extern NSString *const GXCoreModule_eo_SD_Network_Name;
extern NSString *const GXCoreModule_eo_SD_RemoteConfig_Name;
extern NSString *const GXCoreModule_eo_SD_Scanner_Name;
extern NSString *const GXCoreModule_eo_SD_CardScanner_Name;
extern NSString *const GXCoreModule_eo_SD_Search_Name;
extern NSString *const GXCoreModule_eo_SD_WebBrowser_Name;
extern NSString *const GXCoreModule_sdt_SD_CardInfo_Name;

extern NSString *const GXCoreModule_sdt_SD_LoginExternalAdditionalParameters;
extern NSString *const GXCoreModule_sdt_SD_LoginExternalAdditionalParametersProperty;

#define kGXCoreModule_eo_SD_iOS_Permissions_Name		kGXCoreModuleName_GeneXus_SD_iOS kGXModule_Separator @"Permissions"

extern NSString *const GXCoreModule_eo_SD_iOS_Permissions_Name;

#define kGXCoreModule_eo_SD_Media_Audio_Name				kGXCoreModuleName_GeneXus_SD_Media kGXModule_Separator @"Audio"
#define kGXCoreModule_eo_SD_Media_AudioRecorder_Name		kGXCoreModuleName_GeneXus_SD_Media kGXModule_Separator @"AudioRecorder"
#define kGXCoreModule_eo_SD_Media_Camera_Name				kGXCoreModuleName_GeneXus_SD_Media kGXModule_Separator @"Camera"
#define kGXCoreModule_eo_SD_Media_Files_Name				kGXCoreModuleName_GeneXus_SD_Media kGXModule_Separator @"Files"
#define kGXCoreModule_eo_SD_Media_PhotoLibrary_Name			kGXCoreModuleName_GeneXus_SD_Media kGXModule_Separator @"PhotoLibrary"
#define kGXCoreModule_eo_SD_Media_VideoOperations_Name		kGXCoreModuleName_GeneXus_SD_Media kGXModule_Separator @"VideoOperations"
#define kGXCoreModule_sdt_SD_Media_ImagesCollection_Name	kGXCoreModuleName_GeneXus_SD_Media kGXModule_Separator @"ImagesCollection"

extern NSString *const GXCoreModule_eo_SD_Media_Audio_Name;
extern NSString *const GXCoreModule_eo_SD_Media_AudioRecorder_Name;
extern NSString *const GXCoreModule_eo_SD_Media_Camera_Name;
extern NSString *const GXCoreModule_eo_SD_Media_Files_Name;
extern NSString *const GXCoreModule_eo_SD_Media_PhotoLibrary_Name;
extern NSString *const GXCoreModule_eo_SD_Media_VideoOperations_Name;
extern NSString *const GXCoreModule_sdt_SD_Media_ImagesCollection_Name;

#define kGXCoreModule_eo_SD_Notifications_LocalNotifications_Name	kGXCoreModuleName_GeneXus_SD_Notifications kGXModule_Separator @"LocalNotifications"

extern NSString *const GXCoreModule_eo_SD_Notifications_LocalNotifications_Name;

#define kGXCoreModule_eo_SD_Offline_Database_Name	kGXCoreModuleName_GeneXus_SD_Offline kGXModule_Separator @"DataBase"

extern NSString *const GXCoreModule_eo_SD_Offline_Database_Name;

#define kGXCoreModule_eo_SD_Store_Store_Name			kGXCoreModuleName_GeneXus_SD_Store kGXModule_Separator @"StoreManager"
#define kGXCoreModule_eo_SD_StoreInterop_Name           kGXCoreModuleName_GeneXus_SD_Store kGXModule_Separator @"StoreInterop"

extern NSString *const GXCoreModule_eo_SD_Store_Store_Name;
extern NSString *const GXCoreModule_eo_SD_Store_StoreInterop_Name;

#define kGXCoreModule_eo_Social_Facebook_Name			kGXCoreModuleName_GeneXus_Social kGXModule_Separator @"Facebook"
#define kGXCoreModule_eo_Social_Share_Name				kGXCoreModuleName_GeneXus_Social kGXModule_Separator @"Share"
#define kGXCoreModule_eo_Social_Twitter_Name			kGXCoreModuleName_GeneXus_Social kGXModule_Separator @"Twitter"
#define kGXCoreModule_eo_Social_WeChat_Name			kGXCoreModuleName_GeneXus_Social kGXModule_Separator @"WeChat"

extern NSString *const GXCoreModule_eo_Social_Facebook_Name;
extern NSString *const GXCoreModule_eo_Social_Share_Name;
extern NSString *const GXCoreModule_eo_Social_Twitter_Name;
extern NSString *const GXCoreModule_eo_Social_WeChat_Name;

#define kGXCoreModule_eo_SD_Synchronization_Synchronization_Name	kGXCoreModuleName_GeneXus_SD_Synchronization kGXModule_Separator @"Synchronization"
#define kGXCoreModule_eo_Synchronization_SynchronizationEvents_Name		kGXCoreModuleName_GeneXus_SD_Synchronization kGXModule_Separator @"SynchronizationEvents"

extern NSString *const GXCoreModule_eo_SD_Synchronization_Synchronization_Name;
extern NSString *const GXCoreModule_eo_Synchronization_SynchronizationEvents_Name;

#define kGXCoreModule_eo_GlobalEvents_Name				kGXRootModuleName_General kGXModule_Separator @"GlobalEvents"
#define kGXCoreModule_eo_GlobalEvents_LegacyName		@"GlobalEvents"

/// #deprecated: 2022-09-12: trunk; #to-remove: ??
extern NSString *const GXCodeModule_eo_GlobalEvents_Name __attribute__((deprecated("Use GXCoreModule_eo_GlobalEvents_Name instead")));
extern NSString *const GXCoreModule_eo_GlobalEvents_Name;
extern NSString *const GXCoreModule_eo_GlobalEvents_LegacyName;

NS_ASSUME_NONNULL_END
