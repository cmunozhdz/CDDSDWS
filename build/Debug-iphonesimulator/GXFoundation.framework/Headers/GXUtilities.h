//
//  GXUtilities.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 17/11/10.
//  Copyright 2010 Artech. All rights reserved.
//

#define CURRENT_DEVICE_IPAD [GXUtilities currentDeviceIPAD]
#define CURRENT_DEVICE_IPHONE [GXUtilities currentDeviceIPHONE]
#define CURRENT_DEVICE_IPHONE_4INCH [GXUtilities currentDeviceIPHONE_4INCH]
#define CURRENT_DEVICE_IPHONE_4_7INCH [GXUtilities currentDeviceIPHONE_4_7INCH]
#define CURRENT_DEVICE_IPHONE_5_5INCH [GXUtilities currentDeviceIPHONE_5_5INCH]
#define GXTHROW_ABSTRACT_METHOD_EXCEPTION() @throw [NSException exceptionWithName:NSInvalidArgumentException reason:[NSString stringWithFormat:@"%s must be overridden in a subclass.", __PRETTY_FUNCTION__] userInfo:nil]

#if __IPHONE_OS_VERSION_MIN_REQUIRED >= __IPHONE_6_0
#define gx_dispatch_release(object)
#else
#define gx_dispatch_release(object) dispatch_release(object)
#endif

#import <GXFoundation/GXCommon.h>
@import CoreLocation;
@import MapKit;

NS_ASSUME_NONNULL_BEGIN

@class GXHTTPWarningHeader;

#define GXDeviceSystemVersion15_0	150000
#define GXDeviceSystemVersion14_0	140000
#define GXDeviceSystemVersion13_0	130000
#define GXDeviceSystemVersion11_0	110000
#define GXDeviceSystemVersion10_0	100000
#define GXDeviceSystemVersion9_0	90000
#define GXDeviceSystemVersion8_1	80100
#define GXDeviceSystemVersion8_0	80000
#define GXDeviceSystemVersion7_1	70100
#define GXDeviceSystemVersion7_0	70000
#define GXDeviceSystemVersion6_1_4	60104
#define GXDeviceSystemVersion6_1_3	60103
#define GXDeviceSystemVersion6_1_2	60102
#define GXDeviceSystemVersion6_1_1	60101
#define GXDeviceSystemVersion6_1	60100
#define GXDeviceSystemVersion6_0_2	60002
#define GXDeviceSystemVersion6_0_1	60001
#define GXDeviceSystemVersion6_0	60000
#define GXDeviceSystemVersion5_1_1	50101
#define GXDeviceSystemVersion5_1	50100
#define GXDeviceSystemVersion5_0_1	50001
#define GXDeviceSystemVersion5_0	50000
#define GXDeviceSystemVersion4_3_5	40305
#define GXDeviceSystemVersion4_3_4	40304
#define GXDeviceSystemVersion4_3_3	40303
#define GXDeviceSystemVersion4_3_2	40302
#define GXDeviceSystemVersion4_3_1	40301
#define GXDeviceSystemVersion4_3	40300


// https://developer.apple.com/library/ios/documentation/General/Reference/InfoPlistKeyReference/Articles/iPhoneOSKeys.html#//apple_ref/doc/uid/TP40009252-SW22
#define GXAppBackgroundMode_Audio @"audio"
#define GXAppBackgroundMode_Location @"location"
#define GXAppBackgroundMode_Voip @"voip"
#define GXAppBackgroundMode_NewsstandContent @"newsstand-content"
#define GXAppBackgroundMode_ExternalAccessory @"external-accessory"
#define GXAppBackgroundMode_BluetoothCentral @"bluetooth-central"
#define GXAppBackgroundMode_BluetoothPeripheral @"bluetooth-peripheral"
#define GXAppBackgroundMode_Fetch @"fetch"
#define GXAppBackgroundMode_SilentRemoteNotification @"remote-notification" // Silent Notifications

#define GXBoolFromValue(value, defaultValue) (value ? [value boolValue] : defaultValue)
#define GXIntFromValue(value, defaultValue) (value ? [value intValue] : defaultValue)

#define kNSURLAboutBlankAbsoluteString @"about:blank"

extern NSUInteger const GXFlexibleClientMajorVersionNumber;
extern NSUInteger const GXFlexibleClientMinorVersionNumber;
extern NSUInteger const GXFlexibleClientRevisionNumber;

int GXIntCeilFromFloat(float f);

void gx_dispatch_on_background(dispatch_block_t block, dispatch_block_t _Nullable callbackBlock);
void gx_dispatch_on_background_with_priority(dispatch_block_t block, dispatch_queue_priority_t priotity, dispatch_block_t _Nullable callbackBlock);
void gx_dispatch_on_global_queue_with_priority(dispatch_block_t block, dispatch_queue_priority_t priotity, dispatch_block_t _Nullable callbackBlock);
void gx_dispatch_sync_on_main_queue(dispatch_block_t block);
void gx_dispatch_on_main_queue(dispatch_block_t block);
void gx_dispatch_group_notify_on_main_or_global_default_priority_queue(dispatch_group_t group, dispatch_block_t block);

@interface GXUtilities : NSObject

+ (NSString *)stringWithGXFormat:(NSString *)format, ... NS_REQUIRES_NIL_TERMINATION;
+ (NSString *)stringWithGXFormat:(NSString *)format arguments:(va_list)argList;

#if TARGET_IPHONE_SIMULATOR
@property(class, nonatomic, assign, readonly) CGFloat simulatorAnimationDragCoefficient;
#endif // TARGET_IPHONE_SIMULATOR

@end

NS_ASSUME_NONNULL_END
