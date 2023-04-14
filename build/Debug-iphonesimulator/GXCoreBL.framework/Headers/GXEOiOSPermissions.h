//
//  GXEOiOSPermissions.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 24/9/14.
//  Copyright (c) 2014 Artech. All rights reserved.
//

@import GXStandardClasses;
@import CoreLocation;

NS_ASSUME_NONNULL_BEGIN

@interface GXEOiOSPermissions : GXExternalObjectBase

+ (void)requestUserNotificationsPermission;
+ (void)requestLocationPermissionWhenInUse;
+ (void)requestLocationPermissionAlways;
+ (void)requestRemoteNotificationsPermission;

@end

@interface GXEOiOSPermissions (Helpers)

/*!
 Request permissions if iOS 8 and if needed only
 
 @param whenInUse YES to request WhenInUse permission, NO to request Always permission.
 @param fallbackToAlways If YES and whenInUse = YES and there is no usage description for WhenInUse, it request Always permission. Ignored since iOS 11 as WhenInUse description is also required for Always permission.
 @result If could not request permission because the required usage description is not included, returns an error, nil otherwise.
 @discussion If iOS version is lower than 8 or permission has already been asked, this method does nothing.
 */
+ (nullable NSError *)requestLocationPermissionIfNeededWhenInUse:(BOOL)whenInUse
												fallbackToAlways:(BOOL)fallbackToAlways;
+ (nullable NSError *)requestLocationPermissionIfNeededWhenInUse:(BOOL)whenInUse
												fallbackToAlways:(BOOL)fallbackToAlways
											   completionHandler:(nullable void(^)(void))completionHandler;


+ (nullable NSError *)locationWhenInUseUsageDescriptionError;
+ (nullable NSError *)locationAlwaysUsageDescriptionError;
+ (nullable NSError *)calendarsUsageDescriptionError;
+ (nullable NSError *)cameraUsageDescriptionError;
+ (nullable NSError *)contactsUsageDescriptionError;
+ (nullable NSError *)faceIDUsageDescriptionError;
+ (nullable NSError *)microphoneUsageDescriptionError;
+ (nullable NSError *)photoLibraryAddUsageDescriptionError;
+ (nullable NSError *)photoLibraryUsageDescriptionError;

@end

NS_ASSUME_NONNULL_END
