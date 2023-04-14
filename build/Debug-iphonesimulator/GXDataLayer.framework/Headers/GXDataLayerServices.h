//
//  GXDataLayerServices.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 4/1/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import Foundation;
#import <GXDataLayer/GXObjectUploaderService.h>
#import <GXDataLayer/GXSynchronizationBlobDownloadService.h>
#import <GXDataLayer/GXSynchronizationReceiveService.h>
#import <GXDataLayer/GXSynchronizationSendService.h>

@interface GXDataLayerServices : NSObject

+ (nullable id <GXObjectUploaderService>)objectUploaderService;

// #deprecated: 2022-03-16: trunk; #to-remove: ??
+ (nullable id <GXSynchronizationReceiveService>)synchronizationReceiveService __deprecated_msg("Use GXModel.synchronizationServices instead");;
// #deprecated: 2022-03-16: trunk; #to-remove: ??
+ (nullable id <GXSynchronizationSendService>)synchronizationSendService __deprecated_msg("Use GXModel.synchronizationServices instead");;
// #deprecated: 2022-03-16: trunk; #to-remove: ??
+ (nullable id <GXSynchronizationBlobDownloadService>)synchronizationBlobDownloadService __deprecated_msg("Use GXModel.synchronizationServices instead");;

@end
