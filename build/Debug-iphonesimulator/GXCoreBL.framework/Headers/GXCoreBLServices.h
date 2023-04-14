//
//  GXCoreBLServices.h
//  GXCoreBL
//
//  Created by Fabian Inthamoussu on 11/2/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import Foundation;
#import <GXCoreBL/GXAnalyticsService.h>
#import <GXCoreBL/GXApplicationEntryPointServiceProtocol.h>
#import <GXCoreBL/GXAudioManagerService.h>
#import <GXCoreBL/GXAudioRecordingService.h>
#import <GXCoreBL/GXDeviceAuthenticationService.h>
#import <GXCoreBL/GXFacebookServices.h>
#import <GXCoreBL/GXRemoteConfigurationService.h>
#import <GXCoreBL/GXTwitterService.h>
#import <GXCoreBL/GXWeChatService.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXCoreBLServices : NSObject

+ (id <GXApplicationEntryPointService>)applicationEntryPointService;
+ (nullable id <GXAnalyticsService>)analyticsService;
+ (nullable id <GXAudioManagerService>)audioManagerService;
+ (nullable id <GXAudioRecordingService>)audioRecordingService;
+ (nullable id <GXDeviceAuthenticationService>)deviceAuthenticationService;
+ (nullable id <GXFacebookServices>)facebookServices;
+ (nullable id <GXRemoteConfigurationService>)remoteConfigurationService;
+ (nullable id <GXTwitterService>)twitterService;
+ (nullable id <GXWeChatService>)weChatService;

@end

NS_ASSUME_NONNULL_END
