//
//  GXStandardClasses.h
//  GXStandardClasses
//
//  Created by Fabian Inthamoussu on 30/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

#import <Foundation/Foundation.h>
#if TARGET_OS_IOS || TARGET_OS_TV
#import <UIKit/UIKit.h>
#elif TARGET_OS_WATCH
#import <WatchKit/WatchKit.h>
#endif
//! Project version number for GXStandardClasses.
FOUNDATION_EXPORT double GXStandardClassesVersionNumber;

//! Project version string for GXStandardClasses.
FOUNDATION_EXPORT const unsigned char GXStandardClassesVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <GXStandardClasses/PublicHeader.h>

#import <GXStandardClasses/GXBusinessComponent.h>
#import <GXStandardClasses/GXConfig.h>
#import <GXStandardClasses/GXDBCommand.h>
#import <GXStandardClasses/GXDBConnection.h>
#import <GXStandardClasses/GXDbFile.h>
#import <GXStandardClasses/GXDBManager.h>
#import <GXStandardClasses/GXDelimitedFile.h>
#import <GXStandardClasses/GXDirectory.h>
#import <GXStandardClasses/GXEmbeddedModelObject.h>
#import <GXStandardClasses/GXEncryption.h>
#import <GXStandardClasses/GXEnumeration.h>
#import <GXStandardClasses/GXExternalObjectBase.h>
#import <GXStandardClasses/GXFile.h>
#import <GXStandardClasses/GXFileSystemObject.h>
#import <GXStandardClasses/GXHttpClient.h>
#import <GXStandardClasses/GXHTTPContext.h>
#import <GXStandardClasses/GXJSONArray.h>
#import <GXStandardClasses/GXMessageList.h>
#import <GXStandardClasses/GXMessages.h>
#import <GXStandardClasses/GXObjectCollection.h>
#import <GXStandardClasses/GXOfflineDynamicCallHelper.h>
#import <GXStandardClasses/GXOfflineHelper.h>
#import <GXStandardClasses/GXOfflineSession.h>
#import <GXStandardClasses/GXPrivateUtilities.h>
#import <GXStandardClasses/GXProcedure.h>
#import <GXStandardClasses/GXProcedureHelper.h>
#import <GXStandardClasses/GXProperties.h>
#import <GXStandardClasses/GXProperty.h>
#import <GXStandardClasses/GXRegEx.h>
#import <GXStandardClasses/GXRegExMatch.h>
#import <GXStandardClasses/GXReorganization.h>
#if TARGET_OS_IOS
#import <GXStandardClasses/GXReport.h>
#endif // TARGET_OS_IOS
#import <GXStandardClasses/GXSdtBusinessComponent.h>
#import <GXStandardClasses/GXSDTDataHelper.h>
#import <GXStandardClasses/GXSoapLocation.h>
#import <GXStandardClasses/GXStringCollection.h>
#import <GXStandardClasses/GXSynchronization.h>
#import <GXStandardClasses/GXThemeHelper+GXStd.h>
#import <GXStandardClasses/GXUserType.h>
#import <GXStandardClasses/GXUtilities+GXFileSystemObject.h>
#import <GXStandardClasses/GXUUID+GXStd.h>
#import <GXStandardClasses/GXXMLReader.h>
#import <GXStandardClasses/GXXMLWriter.h>

#import <GXStandardClasses/NSDate+GXStd.h>
#import <GXStandardClasses/NSDate+Helpers.h>
#import <GXStandardClasses/NSDateFormatter+GXDBManager.h>
#import <GXStandardClasses/NSNumber+GXStd.h>
#import <GXStandardClasses/NSObject+GXStd.h>
#import <GXStandardClasses/NSString+GXStd.h>
#import <GXStandardClasses/UIImage+GXFileSystemObject.h>
