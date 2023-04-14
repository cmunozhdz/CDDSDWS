//
//  GXLocationManager.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 05/08/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import Foundation;
@import CoreLocation;

NS_ASSUME_NONNULL_BEGIN

@interface GXLocationManager : NSObject <CLLocationManagerDelegate>

@property (nonatomic, strong, readonly) CLLocationManager *locationManager;

#if TARGET_OS_IOS
- (void)processLocationNotification:(NSDictionary *)dict;
#endif // TARGET_OS_IOS

// Singleton
+ (GXLocationManager *)shared;

// Helper methods
+ (nullable CLLocation *)newLocationFromString:(NSString *)location;
#if TARGET_OS_IOS
+ (NSString *)proximityAlertKeyWithCoordinate:(CLLocationCoordinate2D)coordinate;
#endif // TARGET_OS_IOS

// Current proximity alert information management
#if TARGET_OS_IOS
- (void)saveCurrentProximityAlertInfo:(NSDictionary *)info;
- (void)removeCurrentProximityAlertInfo;
- (nullable NSDictionary *)currentProximityAlertInfo;
- (BOOL)hasGeolocationProximityAlerts;
#endif // TARGET_OS_IOS

// Tracking
#if TARGET_OS_IOS
- (BOOL)startTrackingWithChangesInterval:(NSTimeInterval)changesInterval
                                distance:(CLLocationDistance)distance
                              actionName:(NSString *)actionName
                          actionInterval:(NSTimeInterval)actionInterval
								accuracy:(CLLocationAccuracy)accuracy;
- (void)endTracking;
- (void)clearTrackingLocations;
- (void)enumerateTrackingLocationsWithBlock:(void(^)(CLLocation *location))bock;
#endif // TARGET_OS_IOS

NS_ASSUME_NONNULL_END

@end
