//
//  GXSynchronizationBlobDownloadService.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 8/1/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@protocol GXSynchronizationBlobDownloadService <NSObject>

- (void)downloadBlobDataFromURLString:(NSString *)urlStr toRelativePath:(NSString *)relPath;

- (void)downloadPendingBlobData;

- (BOOL)hasPendingDownloads;

- (BOOL)hasPendingDownloadForRelativePath:(NSString *)relPath;

@end


extern NSString *const GXSynchronizationBlobDownloadServiceDidFinishNotification;
extern NSString *const GXSynchronizationBlobDownloadServiceURLStringKey;
extern NSString *const GXSynchronizationBlobDownloadServiceLocalPathKey;

extern NSString *const GXSynchronizationBlobDownloadServiceDidFinishAllProcessesNotification;

NS_ASSUME_NONNULL_END
