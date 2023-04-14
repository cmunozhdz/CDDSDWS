//
//  GXClientInformation.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 28/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXModelObjectProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXClientInformation : NSObject

+ (nullable NSString *)deviceUUIDForModelObject:(id<GXModelObject>)modelObject NS_SWIFT_NAME(deviceUUID(for:));
+ (NSString *)osName;
+ (NSString *)osVersion;
+ (NSString *)deviceLanguage;
+ (NSUInteger)deviceType;
+ (NSString *)platformNameForModelObject:(id<GXModelObject>)modelObject NS_SWIFT_NAME(platformName(for:));
+ (NSString *)appIdentifierForModelObject:(id<GXModelObject>)modelObject NS_SWIFT_NAME(appIdentifier(for:));
+ (NSString *)appVersionCodeForModelObject:(id<GXModelObject>)modelObject NS_SWIFT_NAME(appVersionCode(for:));
+ (NSString *)appVersionNameForModelObject:(id<GXModelObject>)modelObject NS_SWIFT_NAME(appVersionName(for:));
+ (NSString *)installationIdentifierForModelObject:(id<GXModelObject>)modelObject NS_SWIFT_NAME(installationIdentifier(for:));

@end

@interface GXClientInformation (GXDeprecated)

// #deprecated: 2022-02-21: trunk; #to-remove: ??
+ (nullable NSString *)deviceUUID __attribute__((deprecated("Use deviceUUID(for:) instead")));
// #deprecated: 2022-02-21: trunk; #to-remove: ??
+ (nullable NSString *)platformName __attribute__((deprecated("Use platformName(for:) instead")));
// #deprecated: 2022-02-21: trunk; #to-remove: ??
+ (NSString *)appID __attribute__((deprecated("Use appIdentifierForModelObject(for:) instead")));
// #deprecated: 2022-02-21: trunk; #to-remove: ??
+ (nullable NSString *)appVersionCode __attribute__((deprecated("Use appVersionCode(for:) instead")));
// #deprecated: 2022-02-21: trunk; #to-remove: ??
+ (nullable NSString *)appVersionName __attribute__((deprecated("Use appVersionName(for:) instead")));
// #deprecated: 2022-02-21: trunk; #to-remove: ??
+ (NSString *)installationUUID __attribute__((deprecated("Use installationIdentifier(for:) instead")));

@end

NS_ASSUME_NONNULL_END
