//
//  GXCoreModule_Common_Log.h
//  GXCoreModule_Common_Log
//
//  Created by Marcos Crispino on 16/1/18.
//  Copyright © 2018 GeneXus. All rights reserved.
//

#import <Foundation/Foundation.h>
//! Project version number for GXCoreModule_Common_Log.
FOUNDATION_EXPORT double GXCoreModule_Common_LogVersionNumber;

//! Project version string for GXCoreModule_Common_Log.
FOUNDATION_EXPORT const unsigned char GXCoreModule_Common_LogVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <GXCoreModule_Common_Log/PublicHeader.h>


#if TARGET_OS_IOS || TARGET_OS_TV
#import <UIKit/UIKit.h>
#elif TARGET_OS_WATCH
#import <WatchKit/WatchKit.h>
#endif
