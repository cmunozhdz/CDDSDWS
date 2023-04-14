/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * Modified by Fabian Inthamoussu
 */

#import <GXDataLayer/GXWebImageDownloaderBaseOperation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXWebImageDownloaderOperation : GXWebImageDownloaderBaseOperation <NSURLSessionTaskDelegate, NSURLSessionDataDelegate>

/**
 * The request used by the operation's task.
 */
@property (strong, nonatomic, readonly, nullable) NSURLRequest *request;

/**
 * The operation's task
 */
@property (strong, nonatomic, readonly, nullable) NSURLSessionTask *dataTask;

/**
 * The credential used for authentication challenges in `-connection:didReceiveAuthenticationChallenge:`.
 *
 * This will be overridden by any shared credentials that exist for the username or password of the request URL, if present.
 */
@property (nonatomic, strong, nullable) NSURLCredential *credential;

/**
 * The expected size of data.
 */
@property (assign, nonatomic) NSInteger expectedSize;

/**
 * The response returned by the operation's connection.
 */
@property (strong, nonatomic, nullable) NSURLResponse *response;

/**
 *  Initializes a `GXWebImageDownloaderOperation` object
 *
 *  @see GXWebImageDownloaderOperation
 *
 *  @param request        the URL request
 *  @param session        the URL session in which this operation will run
 *  @param options        downloader options
 *  @param progressBlock  the block executed when a new chunk of data arrives.
 *                        @note the progress block is executed on a background queue
 *  @param completedBlock the block executed when the download is done.
 *                        @note the completed block is executed on the main queue for success. If errors are found, there is a chance the block will be executed on a background queue
 *  @param cancelBlock    the block executed if the download (operation) is cancelled
 *
 *  @return the initialized instance
 */
- (instancetype)initWithRequest:(nullable NSURLRequest *)request
					  inSession:(nullable NSURLSession *)session
						options:(GXWebImageDownloaderOptions)options
						context:(nullable GXWebImageContext)context
					   progress:(nullable GXWebImageDownloaderProgressBlock)progressBlock
					  completed:(nullable GXWebImageDownloaderCompletedBlock)completedBlock
					  cancelled:(nullable GXWebImageNoParamsBlock)cancelBlock NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithURL:(nullable NSURL *)url
					options:(GXWebImageDownloaderOptions)options
					context:(nullable GXWebImageContext)context
				   progress:(nullable GXWebImageDownloaderProgressBlock)progressBlock
				  completed:(nullable GXWebImageDownloaderCompletedBlock)completedBlock
				  cancelled:(nullable GXWebImageNoParamsBlock)cancelBlock NS_UNAVAILABLE;

- (instancetype)initWithURL:(nullable NSURL *)url
					options:(GXWebImageDownloaderOptions)options
				   progress:(nullable GXWebImageDownloaderProgressBlock)progressBlock
				  completed:(nullable GXWebImageDownloaderCompletedBlock)completedBlock
				  cancelled:(nullable GXWebImageNoParamsBlock)cancelBlock NS_UNAVAILABLE;

@end


@interface GXWebImageDownloaderBaseOperation (GXDeprecated)

// #deprecated: 2021-06-17: trunk; #to-remove: ???
- (instancetype)initWithRequest:(nullable NSURLRequest *)request
					  inSession:(nullable NSURLSession *)session
						options:(GXWebImageDownloaderOptions)options
					   progress:(nullable GXWebImageDownloaderProgressBlock)progressBlock
					  completed:(nullable GXWebImageDownloaderCompletedBlock)completedBlock
					  cancelled:(nullable GXWebImageNoParamsBlock)cancelBlock __attribute__((deprecated("Use initWithRequest:inSession:options:context:progress:completed:cancelled: instead")));

@end

NS_ASSUME_NONNULL_END
