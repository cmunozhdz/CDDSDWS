//
//  GXGAM.h
//  GXGAM
//
//  Created by Fabian Inthamoussu on 11/2/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

#import <Foundation/Foundation.h>
#if TARGET_OS_IOS || TARGET_OS_TV
#import <UIKit/UIKit.h>
#elif TARGET_OS_WATCH
#import <WatchKit/WatchKit.h>
#endif
//! Project version number for GXGAM.
FOUNDATION_EXPORT double GXGAMVersionNumber;

//! Project version string for GXGAM.
FOUNDATION_EXPORT const unsigned char GXGAMVersionString[];

#import <GXGAM/GXEOGAMUserData.h>
#import <GXGAM/GXGAMConstants.h>
#import <GXGAM/GXGAMLoginHandler+Public.h>
#import <GXGAM/GXGAMSecurityService.h>
