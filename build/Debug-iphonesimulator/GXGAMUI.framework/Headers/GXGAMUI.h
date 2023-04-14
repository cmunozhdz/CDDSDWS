//
//  GXGAMUI.h
//  GXGAMUI
//
//  Created by Fabian Inthamoussu on 20/2/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

#import <Foundation/Foundation.h>
#if TARGET_OS_IOS || TARGET_OS_TV
#import <UIKit/UIKit.h>
#elif TARGET_OS_WATCH
#import <WatchKit/WatchKit.h>
#endif
//! Project version number for GXGAMUI.
FOUNDATION_EXPORT double GXGAMUIVersionNumber;

//! Project version string for GXGAMUI.
FOUNDATION_EXPORT const unsigned char GXGAMUIVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <GXGAMUI/PublicHeader.h>