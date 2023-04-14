//
//  ImageManipulation.h
//  ImageManipulation
//
// IG requires Enable bitcode to be false....
// GeneXus "Require Only App-Extension-Safe API" build setting to Yes on the framework target.

//  Created by Felipe Herrera on 30/6/21.
//  Copyright © 2021 DVelop Software Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>
//! Project version number for ImageManipulation.
FOUNDATION_EXPORT double ImageManipulationVersionNumber;

//! Project version string for ImageManipulation.
FOUNDATION_EXPORT const unsigned char ImageManipulationVersionString[];

#import "ImageManipulationUtilAPI.h"

#if TARGET_OS_IOS || TARGET_OS_TV
#import <UIKit/UIKit.h>
#elif TARGET_OS_WATCH
#import <WatchKit/WatchKit.h>
#endif
