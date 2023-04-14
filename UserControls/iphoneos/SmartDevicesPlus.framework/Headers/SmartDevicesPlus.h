//
//  SmartDevicesPlus.h
//  SmartDevicesPlus
//
// IG requires Enable bitcode to be false....
// GeneXus "Require Only App-Extension-Safe API" build setting to Yes on the framework target.

//  Created by Felipe Herrera on 6/6/17.
//  Copyright © 2017 DVelop Software Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>
//! Project version number for SmartDevicesPlus.
FOUNDATION_EXPORT double SmartDevicesPlusVersionNumber;

//! Project version string for SmartDevicesPlus.
FOUNDATION_EXPORT const unsigned char SmartDevicesPlusVersionString[];

#if TARGET_OS_IOS || TARGET_OS_TV
#import <UIKit/UIKit.h>
#elif TARGET_OS_WATCH
#import <WatchKit/WatchKit.h>
#endif
