//
//  GXCoreUIPhotoLibrary.h
//  GXCoreUIPhotoLibrary
//
//  Created by Fabian Inthamoussu on 08/07/2019.
//  Copyright © 2019 GeneXus. All rights reserved.
//

#import <Foundation/Foundation.h>
//! Project version number for GXCoreUIPhotoLibrary.
FOUNDATION_EXPORT double GXCoreUIPhotoLibraryVersionNumber;

//! Project version string for GXCoreUIPhotoLibrary.
FOUNDATION_EXPORT const unsigned char GXCoreUIPhotoLibraryVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <GXCoreUIPhotoLibrary/PublicHeader.h>


#if TARGET_OS_IOS || TARGET_OS_TV
#import <UIKit/UIKit.h>
#elif TARGET_OS_WATCH
#import <WatchKit/WatchKit.h>
#endif

#if TARGET_OS_IOS
#import <GXCoreUIPhotoLibrary/GXEntityDataFieldImagePickerController.h>
#endif // TARGET_OS_IOS
