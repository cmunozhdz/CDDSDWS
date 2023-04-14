//
//  GXFoundation.h
//  GXFoundation
//
//  Created by Fabian Inthamoussu on 3/11/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

#import <Foundation/Foundation.h>
#if TARGET_OS_IOS || TARGET_OS_TV
#import <UIKit/UIKit.h>
#elif TARGET_OS_WATCH
#import <WatchKit/WatchKit.h>
#endif

//! Project version number for GXFoundation.
FOUNDATION_EXPORT double GXFoundationVersionNumber;

//! Project version string for GXFoundation.
FOUNDATION_EXPORT const unsigned char GXFoundationVersionString[];

#import <GXFoundation/GXAvailability.h>
#import <GXFoundation/GXCommon.h>
#import <GXFoundation/GXConstants.h>
#import <GXFoundation/GXDataSetterOperation.h>
#import <GXFoundation/GXDeallocBlockExecution.h>
#import <GXFoundation/GXFoundationObjcConstants.h>
#import <GXFoundation/GXFoundationNotifications.h>
#import <GXFoundation/WKTGeometry.h>
#import <GXFoundation/GXKeyChainStore.h>
#import <GXFoundation/GXLoginHandler.h>
#import <GXFoundation/GXLoginHandlerCredentials.h>
#import <GXFoundation/GXObjectHelper.h>
#import <GXFoundation/GXParseJsonOperation.h>
#import <GXFoundation/GXParseXmlOperation.h>
#import <GXFoundation/GXReachability.h>
#import <GXFoundation/GXReadWriteLock.h>
#import <GXFoundation/GXTargetAction.h>
#import <GXFoundation/GXTimerProxy.h>
#import <GXFoundation/GXTimeZone.h>
#import <GXFoundation/GXUnretainedWrapper.h>
#import <GXFoundation/GXURLRequestOperation.h>
#import <GXFoundation/GXUtilities.h>
#import <GXFoundation/GXUtilities+CoreGraphics.h>
#import <GXFoundation/GXUUID.h>
#import <GXFoundation/GXWeakWrapper.h>

#import <GXFoundation/NSArray+WeakReferences.h>
#import <GXFoundation/NSAttributedString+GXFont.h>
#import <GXFoundation/NSData+Base64.h>
#import <GXFoundation/NSData+ImageContentType.h>
#import <GXFoundation/NSDictionary+Helpers.h>
#import <GXFoundation/NSException+Swift.h>
#import <GXFoundation/NSInvocation+CWVariableArguments.h>
#import <GXFoundation/NSObject+GXHelpers.h>
#import <GXFoundation/NSOperation+Helpers.h>
#import <GXFoundation/NSString+Base64.h>
#import <GXFoundation/NSString+GXFont.h>
#import <GXFoundation/OAuthCore.h>
#import <GXFoundation/OAuth+Additions.h>
#import <GXFoundation/UIBezierPath+GXBordersRadius.h>
#import <GXFoundation/UIColor+GXSystemColors.h>
#import <GXFoundation/UIFont+Helpers.h>
#import <GXFoundation/UIImage+Alpha.h>
#import <GXFoundation/UIImage+Color.h>
#import <GXFoundation/UIImage+GIF.h>
#import <GXFoundation/UIImage+MultiFormat.h>
#import <GXFoundation/UIImage+Resizing.h>
#import <GXFoundation/WKTLine.h>
#import <GXFoundation/WKTLineM.h>
#import <GXFoundation/WKTParser.h>
#import <GXFoundation/WKTPoint.h>
#import <GXFoundation/WKTPointM.h>
#import <GXFoundation/WKTPolygon.h>
#import <GXFoundation/ZipArchive.h>
