//
//  GXWebImageDownloaderBaseOperation.h
//  GXCoreBL
//
//  Created by Fabian Inthamoussu on 14/3/17.
//  Copyright © 2017 GeneXus. All rights reserved.
//

@import GXFoundation;
#import <GXDataLayer/GXWebImageDownloader.h>
#import <GXDataLayer/GXWebImageOperation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const GXWebImageDownloadStartNotification;
extern NSString *const GXWebImageDownloadReceiveResponseNotification;
extern NSString *const GXWebImageDownloadStopNotification;
extern NSString *const GXWebImageDownloadFinishNotification;

@interface GXWebImageDownloaderBaseOperation : NSOperation <GXWebImageOperation>

/**
 * The url used by the operation's task.
 */
@property(strong, nonatomic, readonly, nullable) NSURL *url;

@property(assign, nonatomic) BOOL shouldDecompressImages;

@property(assign, nonatomic, readonly) BOOL shouldPostStartStopNotifications;

/**
 * The GXWebImageDownloaderOptions for the receiver.
 */
@property(assign, nonatomic, readonly) GXWebImageDownloaderOptions options;

/// The context for the receiver.
@property(strong, nonatomic, readonly, nullable) GXWebImageContext context;

@property(assign, nonatomic, readonly) BOOL hasCompletedBlock;
@property(assign, nonatomic, readonly) BOOL hasProgressBlock;

- (instancetype)initWithURL:(nullable NSURL *)url
					options:(GXWebImageDownloaderOptions)options
					context:(nullable GXWebImageContext)context
				   progress:(nullable GXWebImageDownloaderProgressBlock)progressBlock
				  completed:(nullable GXWebImageDownloaderCompletedBlock)completedBlock
				  cancelled:(nullable GXWebImageNoParamsBlock)cancelBlock NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

- (void)reportProgressReceivedSize:(NSInteger)receivedSize expectedSize:(NSInteger)expectedSize;

- (void)reportPartialImageDownload:(UIImage *)partialImage;

- (void)completeDownloadOperationWithSucess:(nullable UIImage *)image data:(nullable NSData *)imageData;
- (void)completeDownloadOperationWithError:(nullable NSError *)error;

#pragma mark - Abstract

- (nullable NSError *)downloaderOperationSynchronizedStart;
- (nullable NSError *)downloaderOperationAfterSynchronizedStart;

#pragma mark - Subclasses override points

- (void)reset;

- (void)cancelOnMainThread;
- (void)cancelDownloaderOperation;

@end


@interface GXWebImageDownloaderBaseOperation (GXDeprecated)

// #deprecated: 2021-06-17: trunk; #to-remove: ???
- (instancetype)initWithURL:(nullable NSURL *)url
					options:(GXWebImageDownloaderOptions)options
				   progress:(nullable GXWebImageDownloaderProgressBlock)progressBlock
				  completed:(nullable GXWebImageDownloaderCompletedBlock)completedBlock
				  cancelled:(nullable GXWebImageNoParamsBlock)cancelBlock __attribute__((deprecated("Use initWithURL:options:context:progress:completed:cancelled: instead")));

@end

NS_ASSUME_NONNULL_END
