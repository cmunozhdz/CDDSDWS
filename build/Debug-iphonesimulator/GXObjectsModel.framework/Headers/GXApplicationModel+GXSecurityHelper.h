//
//  GXApplicationModel+GXSecurityHelper.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 16/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

#import <GXObjectsModel/GXApplicationModel.h>


NS_ASSUME_NONNULL_BEGIN

@interface GXApplicationModel (GXSecurityHelper)

- (nullable NSError *)validateApplicationModelSecurityProperties;

@property(nonatomic, assign, readonly) BOOL applicationEntryPointIntegratedSecurityEnabled;
@property(nonatomic, assign, readonly) BOOL applicationEntryPointIntegratedSecurityAnonymousLoginEnabled;
@property(nonatomic, strong, readonly) NSString *applicationEntryPointLoginObjectName;
@property(nullable, nonatomic, strong, readonly) NSString *applicationEntryPointNotAuthorizedObjectName;
@property(nullable, nonatomic, strong, readonly) NSString *applicationEntryPointChangePasswordObjectName;
@property(nullable, nonatomic, strong, readonly) NSString *applicationEntryPointIntegratedSecurityClientId;
@property(nonatomic, assign, readonly) BOOL applicationEntryPointShareSessionToWebView;

@property(nonatomic, assign, readonly) BOOL applicationEntryPointIntegratedSecurityEnableBiometrics;
@property(nonatomic, assign, readonly) NSInteger applicationEntryPointIntegratedSecurityBiometricsReuseDuration;
@property(nonatomic, assign, readonly) BOOL applicationEntryPointBlurOnBackground;

+ (BOOL)applicationEntryPointIntegratedSecurityEnabled:(id<GXApplicationEntryPoint>)appEntryPoint;
+ (BOOL)applicationEntryPointIntegratedSecurityAnonymousLoginEnabled:(id<GXApplicationEntryPoint>)appEntryPoint;
+ (NSString *)applicationEntryPointLoginObjectName:(id<GXApplicationEntryPoint>)appEntryPoint;
+ (nullable NSString *)applicationEntryPointNotAuthorizedObjectName:(id<GXApplicationEntryPoint>)appEntryPoint;
+ (nullable NSString *)applicationEntryPointChangePasswordObjectName:(id<GXApplicationEntryPoint>)appEntryPoint;
+ (nullable NSString *)applicationEntryPointIntegratedSecurityClientId:(id<GXApplicationEntryPoint>)appEntryPoint;
+ (BOOL)applicationEntryPointShareSessionToWebView:(id<GXApplicationEntryPoint>)appEntryPoint;

+ (BOOL)applicationEntryPointIntegratedSecurityEnableBiometrics:(id<GXApplicationEntryPoint>)appEntryPoint;
+ (NSInteger)applicationEntryPointIntegratedSecurityBiometricsReuseDuration:(id<GXApplicationEntryPoint>)appEntryPoint;
+ (BOOL)applicationEntryPointBlurOnBackground:(id<GXApplicationEntryPoint>)appEntryPoint;

@end

NS_ASSUME_NONNULL_END
