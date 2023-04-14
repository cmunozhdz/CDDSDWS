//
//  GXAudioBL.h
//  GXAudioBL
//
//  Created by Marcos Crispino on 3/1/17.
//  Copyright © 2017 GeneXus. All rights reserved.
//

#import <Foundation/Foundation.h>
//! Project version number for GXAudioBL.
FOUNDATION_EXPORT double GXAudioBLVersionNumber;

//! Project version string for GXAudioBL.
FOUNDATION_EXPORT const unsigned char GXAudioBLVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <GXAudioBL/PublicHeader.h>


#if TARGET_OS_IOS || TARGET_OS_TV
#import <UIKit/UIKit.h>
#elif TARGET_OS_WATCH
#import <WatchKit/WatchKit.h>
#endif

#import <GXAudioBL/GXActionExObjAudioRecorderHandler.h>
#import <GXAudioBL/GXAudioManager.h>
#import <GXAudioBL/GXSDTAudioPlayerCustomAction.h>
#import <GXAudioBL/GXSDTAudioPlayerSettings.h>
#import <GXAudioBL/GXSDTMediaItem.h>
#import <GXAudioBL/GXSDTMediaItemFinishedInfo.h>
#import <GXAudioBL/GXSDTMediaQueue.h>
#import <GXAudioBL/GXSDTMediaQueueState.h>
