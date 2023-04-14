//
//  GXSDTMessages.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 27/5/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

#import <GXObjectsModel/GXCoreModuleConstants.h>

typedef NS_ENUM(uint_least8_t, GXMessageTypes) {
	GXMessageTypeWarning = 0,
	GXMessageTypeError = 1
};

#define kGXSDTMessages_SDTTypeName				kGXCoreModuleName_GeneXus_Common kGXModule_Separator @"Messages"
#define kGXSDTMessages_Message_SDTTypeName		kGXCoreModuleName_GeneXus_Common kGXModule_Separator @"Messages_Message"

extern NSString *const GXSDTMessages_SDTTypeName;

#define GXSDTMessages_Id						@"Id"
#define GXSDTMessages_Type						@"Type"
#define GXSDTMessages_Description				@"Description"
