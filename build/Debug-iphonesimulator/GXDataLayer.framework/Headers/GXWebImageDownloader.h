/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * Modified by Fabian Inthamoussu
 */

#import <Foundation/Foundation.h>
#import <GXDataLayer/GXWebImageCompat.h>
#import <GXDataLayer/GXWebImageCustomURLSchemeManager.h>
#import <GXDataLayer/GXWebImageOperation.h>
#import <GXDataLayer/GXWebImageDefine.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, GXWebImageDownloaderOptions) {
    GXWebImageDownloaderLowPriority = 1 << 0,
    GXWebImageDownloaderProgressiveDownload = 1 << 1,

    /**
     * By default, request prevent the use of NSURLCache. With this flag, NSURLCache
     * is used with default policies.
     */
    GXWebImageDownloaderUseNSURLCache = 1 << 2,

    /**
     * Call completion block with nil image/imageData if the image was read from NSURLCache
     * (to be combined with `GXWebImageDownloaderUseNSURLCache`).
     */

    GXWebImageDownloaderIgnoreCachedResponse = 1 << 3,
    /**
     * In iOS 4+, continue the download of the image if the app goes to background. This is achieved by asking the system for
     * extra time in background to let the request finish. If the background task expires the operation will be cancelled.
     */

    GXWebImageDownloaderContinueInBackground = 1 << 4,

    /**
     * Handles cookies stored in NSHTTPCookieStore by setting 
     * NSMutableURLRequest.HTTPShouldHandleCookies = YES;
     */
    GXWebImageDownloaderHandleCookies = 1 << 5,

    /**
     * Enable to allow untrusted SSL certificates.
     * Useful for testing purposes. Use with caution in production.
     */
    GXWebImageDownloaderAllowInvalidSSLCertificates = 1 << 6,

    /**
     * Put the image in the high priority queue.
     */
    GXWebImageDownloaderHighPriority = 1 << 7,
};

typedef NS_ENUM(NSInteger, GXWebImageDownloaderExecutionOrder) {
    /**
     * Default value. All download operations will execute in queue style (first-in-first-out).
     */
    GXWebImageDownloaderFIFOExecutionOrder,

    /**
     * All download operations will execute in stack style (last-in-first-out).
     */
    GXWebImageDownloaderLIFOExecutionOrder
};

extern NSString *const GXWebImageDownloadStartNotification;
extern NSString *const GXWebImageDownloadStopNotification;

typedef void(^GXWebImageDownloaderProgressBlock)(NSInteger receivedSize, NSInteger expectedSize);

typedef void(^GXWebImageDownloaderCompletedBlock)(UIImage * _Nullable image, NSData * _Nullable data, NSError * _Nullable error, BOOL finished);

typedef NSDictionary * _Nullable (^GXWebImageDownloaderHeadersFilterBlock)(NSURL *url, NSDictionary *headers);

/**
 * Asynchronous downloader dedicated and optimized for image loading.
 */
@interface GXWebImageDownloader : NSObject

/**
 * Decompressing images that are downloaded and cached can improve performance but can consume lot of memory.
 * Defaults to YES. Set this to NO if you are experiencing a crash due to excessive memory consumption.
 */
@property (assign, nonatomic) BOOL shouldDecompressImages;

@property (assign, nonatomic) NSInteger maxConcurrentDownloads;

/**
 * Shows the current amount of downloads that still need to be downloaded
 */
@property (readonly, nonatomic) NSUInteger currentDownloadCount;


/**
 *  The timeout value (in seconds) for the download operation. Default: 15.0.
 */
@property (assign, nonatomic) NSTimeInterval downloadTimeout;


/**
 * Changes download operations execution order. Default value is `GXWebImageDownloaderFIFOExecutionOrder`.
 */
@property (assign, nonatomic) GXWebImageDownloaderExecutionOrder executionOrder;

/**
 *  Singleton method, returns the shared instance
 *
 *  @return global shared instance of downloader class
 */
+ (GXWebImageDownloader *)sharedDownloader;

/**
 *  Set the default URL credential to be set for request operations.
 */
@property (strong, nonatomic, nullable) NSURLCredential *urlCredential;

/**
 * Set username
 */
@property (strong, nonatomic, nullable) NSString *username;

/**
 * Set password
 */
@property (strong, nonatomic, nullable) NSString *password;

/**
 * Set filter to pick headers for downloading image HTTP request.
 *
 * This block will be invoked for each downloading image request, returned
 * NSDictionary will be used as headers in corresponding HTTP request.
 */
@property (nonatomic, copy, nullable) GXWebImageDownloaderHeadersFilterBlock headersFilter;

/**
 * Set a value for a HTTP header to be appended to each download HTTP request.
 *
 * @param value The value for the header field. Use `nil` value to remove the header.
 * @param field The name of the header field to set.
 */
- (void)setValue:(nullable NSString *)value forHTTPHeaderField:(NSString *)field;

/**
 * Returns the value of the specified HTTP header field.
 *
 * @return The value associated with the header field field, or `nil` if there is no corresponding header field.
 */
- (nullable NSString *)valueForHTTPHeaderField:(NSString *)field;

/**
 * Sets a subclass of `GXWebImageDownloaderOperation` as the default
 * `NSOperation` to be used each time GXWebImage constructs a request
 * operation to download an image.
 *
 * @param operationClass The subclass of `GXWebImageDownloaderOperation` to set 
 *        as default. Passing `nil` will revert to `GXWebImageDownloaderOperation`.
 */
- (void)setOperationClass:(nullable Class)operationClass;

/**
 * Sets a subclass of `GXWebImageDownloaderBaseOperation` as the url scheme
 * `NSOperation` to be used each time GXWebImage constructs a request
 * operation to download an image.
 *
 * @param operationClass The subclass of `GXWebImageDownloaderBaseOperation` to set
 *        as url scheme. Passing `nil` will remove the custom class for the given url scheme
 * @param scheme The URL scheme of URL's to be handled with the given `GXWebImageDownloaderBaseOperation` class.
 */
- (void)setOperationClass:(nullable Class)operationClass forCustomURLScheme:(NSString *)scheme;

/*!
 Returns YES if an operationClass has been set for the given shceme
 
 @param scheme The custom URL scheme.
 @result YES if an operationClass has been set for the given shceme, NO otherwise.
 */
- (BOOL)hasOperationClassCustomURLScheme:(NSString *)scheme;

/// Same as downloadImageWithURL:options:context:progress:completed: with nil context
- (nullable id <GXWebImageOperation>)downloadImageWithURL:(nullable NSURL *)url
												  options:(GXWebImageDownloaderOptions)options
												 progress:(nullable GXWebImageDownloaderProgressBlock)progressBlock
												completed:(nullable GXWebImageDownloaderCompletedBlock)completedBlock __attribute__((deprecated("Use context variant instead")));

/**
 * Creates a GXWebImageDownloader async downloader instance with a given URL
 *
 * The delegate will be informed when the image is finish downloaded or an error has happen.
 *
 * @see GXWebImageDownloaderDelegate
 *
 * @param url            The URL to the image to download
 * @param options        The options to be used for this download
 * @param context        A context contains different options to perform specify changes or processes, see `GXWebImageContextOption`. This hold the extra objects which `options` enum can not hold.
 * @param progressBlock  A block called repeatedly while the image is downloading
 * @param completedBlock A block called once the download is completed.
 *                       If the download succeeded, the image parameter is set, in case of error,
 *                       error parameter is set with the error. The last parameter is always YES
 *                       if GXWebImageDownloaderProgressiveDownload isn't use. With the
 *                       GXWebImageDownloaderProgressiveDownload option, this block is called
 *                       repeatedly with the partial image object and the finished argument set to NO
 *                       before to be called a last time with the full image and finished argument
 *                       set to YES. In case of error, the finished argument is always YES.
 *
 * @return A cancellable GXWebImageOperation
 */
- (nullable id <GXWebImageOperation>)downloadImageWithURL:(nullable NSURL *)url
												  options:(GXWebImageDownloaderOptions)options
												  context:(nullable GXWebImageContext)context
												 progress:(nullable GXWebImageDownloaderProgressBlock)progressBlock
												completed:(nullable GXWebImageDownloaderCompletedBlock)completedBlock;

/**
 * Sets the download queue suspension state
 */
- (void)setSuspended:(BOOL)suspended;

/**
 * Cancels all download operations in the queue
 */
- (void)cancelAllDownloads;

@end

NS_ASSUME_NONNULL_END
