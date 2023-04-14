//
//  GXDataLayerRemote.h
//  GXDataLayerRemote
//
//  Created by Fabian Inthamoussu on 21/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

#import <Foundation/Foundation.h>
#if TARGET_OS_IOS || TARGET_OS_TV
#import <UIKit/UIKit.h>
#elif TARGET_OS_WATCH
#import <WatchKit/WatchKit.h>
#endif
//! Project version number for GXDataLayerRemote.
FOUNDATION_EXPORT double GXDataLayerRemoteVersionNumber;

//! Project version string for GXDataLayerRemote.
FOUNDATION_EXPORT const unsigned char GXDataLayerRemoteVersionString[];

#import <GXDataLayerRemote/GXEntityHelper+GXBusinessComponentREST.h>
#import <GXDataLayerRemote/GXModel+GXCoreDataCache.h>
