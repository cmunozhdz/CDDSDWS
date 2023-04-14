/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * Modified by Fabian Inthamoussu
 */

#import <GXDataLayer/GXWebImageCompat.h>
#import <GXDataLayer/GXWebImageOperation.h>
#import <GXDataLayer/GXWebImageDownloader.h>
#import <GXDataLayer/GXImageCache.h>
#import <GXDataLayer/GXWebImageDefine.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^GXWebImageCompletionBlock)(UIImage * _Nullable image, NSError * _Nullable error, GXImageCacheType cacheType, NSURL * _Nullable imageURL);

typedef void(^GXWebImageCompletionWithFinishedBlock)(UIImage * _Nullable image, NSError * _Nullable error, GXImageCacheType cacheType, BOOL finished, NSURL * _Nullable imageURL);

typedef NSString * _Nullable (^GXWebImageCacheKeyFilterBlock)(NSURL *url);


@class GXWebImageManager;

@protocol GXWebImageManagerDelegate <NSObject>

@optional

/**
 * Controls which image should be downloaded when the image is not found in the cache.
 *
 * @param imageManager The current `GXWebImageManager`
 * @param imageURL     The url of the image to be downloaded
 *
 * @return Return NO to prevent the downloading of the image on cache misses. If not implemented, YES is implied.
 */
- (BOOL)imageManager:(GXWebImageManager *)imageManager shouldDownloadImageForURL:(NSURL *)imageURL;

/**
 * Allows to transform the image immediately after it has been downloaded and just before to cache it on disk and memory.
 * NOTE: This method is called from a global queue in order to not to block the main thread.
 *
 * @param imageManager The current `GXWebImageManager`
 * @param image        The image to transform
 * @param imageURL     The url of the image to transform
 *
 * @return The transformed image object.
 */
- (UIImage *)imageManager:(GXWebImageManager *)imageManager transformDownloadedImage:(UIImage *)image withURL:(NSURL *)imageURL;

@end

/**
 * The GXWebImageManager is the class behind the UIImageView+WebCache category and likes.
 * It ties the asynchronous downloader (GXWebImageDownloader) with the image cache store (GXImageCache).
 * You can use this class directly to benefit from web image downloading with caching in another context than
 * a UIView.
 *
 * Here is a simple example of how to use GXWebImageManager:
 *
 * @code

GXWebImageManager *manager = [GXWebImageManager sharedManager];
[manager downloadImageWithURL:imageURL
                      options:0
                     progress:nil
                    completed:^(UIImage *image, NSError *error, GXImageCacheType cacheType, BOOL finished, NSURL *imageURL) {
                        if (image) {
                            // do something with image
                        }
                    }];

 * @endcode
 */
@interface GXWebImageManager : NSObject

@property (weak, nonatomic, nullable) id <GXWebImageManagerDelegate> delegate;

@property (strong, nonatomic, readonly) GXImageCache *imageCache;
@property (strong, nonatomic, readonly) GXWebImageDownloader *imageDownloader;

/**
 * The cache filter is a block used each time GXWebImageManager need to convert an URL into a cache key. This can
 * be used to remove dynamic part of an image URL.
 *
 * The following example sets a filter in the application delegate that will remove any query-string from the
 * URL before to use it as a cache key:
 *
 * @code

[[GXWebImageManager sharedManager] setCacheKeyFilter:^(NSURL *url) {
    url = [[NSURL alloc] initWithScheme:url.scheme host:url.host path:url.path];
    return [url absoluteString];
}];

 * @endcode
 */
@property (nonatomic, copy, nullable) GXWebImageCacheKeyFilterBlock cacheKeyFilter;

/**
 * Returns global GXWebImageManager instance.
 *
 * @return GXWebImageManager shared instance
 */
+ (GXWebImageManager *)sharedManager;

/**
 * Allows to specify instance of cache and image downloader used with image manager.
 * @return new instance of `GXWebImageManager` with specified cache and downloader.
 */
- (instancetype)initWithCache:(GXImageCache *)cache downloader:(GXWebImageDownloader *)downloader;

/*!
 Sets a manager for the given custom url scheme
 

 @param manager Manager for allowing extending behavior for custom URL Schemes. Nil removes the manager.
 @param scheme The custom URL scheme
 */
- (void)setCustomURLSchemeManager:(nullable id<GXWebImageCustomURLSchemeManager>)manager forCustomURLScheme:(NSString *)scheme;

/// Same as downloadImageWithURL:options:context:completed: with nil context
- (nullable id <GXWebImageOperation>)downloadImageWithURL:(nullable NSURL *)url
												  options:(GXWebImageOptions)options
												 progress:(nullable GXWebImageDownloaderProgressBlock)progressBlock
												completed:(GXWebImageCompletionWithFinishedBlock)completedBlock;

/**
 * Downloads the image at the given URL if not present in cache or return the cached version otherwise.
 *
 * @param url            The URL to the image
 * @param options        A mask to specify options to use for this request
 * @param context        A context contains different options to perform specify changes or processes, see `GXWebImageContextOption`. This hold the extra objects which `options` enum can not hold.
 * @param progressBlock  A block called while image is downloading
 * @param completedBlock A block called when operation has been completed.
 *
 *   This parameter is required.
 *
 *   This block has no return value and takes the requested UIImage as first parameter.
 *   In case of error the image parameter is nil and the second parameter may contain an NSError.
 *
 *   The third parameter is an `GXImageCacheType` enum indicating if the image was retrieved from the local cache
 *   or from the memory cache or from the network.
 *
 *   The last parameter is set to NO when the GXWebImageProgressiveDownload option is used and the image is
 *   downloading. This block is thus called repeatedly with a partial image. When image is fully downloaded, the
 *   block is called a last time with the full image and the last parameter set to YES.
 *
 * @return Returns an NSObject conforming to GXWebImageOperation. Should be an instance of GXWebImageDownloaderOperation
 */
- (nullable id <GXWebImageOperation>)downloadImageWithURL:(nullable NSURL *)url
												  options:(GXWebImageOptions)options
												  context:(nullable GXWebImageContext)context
												 progress:(nullable GXWebImageDownloaderProgressBlock)progressBlock
												completed:(GXWebImageCompletionWithFinishedBlock)completedBlock;

/**
 * Saves image to cache for given URL
 *
 * @param image The image to cache
 * @param url   The URL to the image
 *
 */

- (void)saveImageToCache:(UIImage *)image forURL:(NSURL *)url;

/**
 * Cancel all current operations
 */
- (void)cancelAll;

/**
 * Check one or more operations running
 */
- (BOOL)isRunning;

/**
 *  Check if image has already been cached
 *
 *  @param url image url
 *
 *  @return if the image was already cached
 */
- (BOOL)cachedImageExistsForURL:(NSURL *)url;

/**
 *  Check if image has already been cached on disk only
 *
 *  @param url image url
 *
 *  @return if the image was already cached (disk only)
 */
- (BOOL)diskImageExistsForURL:(NSURL *)url;

/**
 *  Async check if image has already been cached
 *
 *  @param url              image url
 *  @param completionBlock  the block to be executed when the check is finished
 *  
 *  @note the completion block is always executed on the main queue
 */
- (void)cachedImageExistsForURL:(NSURL *)url
                     completion:(GXWebImageCheckCacheCompletionBlock)completionBlock;

/**
 *  Async check if image has already been cached on disk only
 *
 *  @param url              image url
 *  @param completionBlock  the block to be executed when the check is finished
 *
 *  @note the completion block is always executed on the main queue
 */
- (void)diskImageExistsForURL:(NSURL *)url
                   completion:(GXWebImageCheckCacheCompletionBlock)completionBlock;


/**
 *Return the cache key for a given URL
 */
- (nullable NSString *)cacheKeyForURL:(nullable NSURL *)url;

@end

NS_ASSUME_NONNULL_END
