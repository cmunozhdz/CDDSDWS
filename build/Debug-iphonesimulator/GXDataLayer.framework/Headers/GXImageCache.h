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
#import <GXDataLayer/GXWebImageDefine.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, GXImageCacheType) {
	/**
	 * The image wasn't available the GXWebImage caches, but was downloaded from the web.
	 */
	GXImageCacheTypeNone,
	/**
	 * The image was obtained from the disk cache.
	 */
	GXImageCacheTypeDisk,
	/**
	 * The image was obtained from the memory cache.
	 */
	GXImageCacheTypeMemory
};

typedef NS_OPTIONS(NSInteger, GXImageCacheOptions) {
	GXImageCacheOptionFullSizeImage = 1 << 0,
};

typedef void(^GXWebImageQueryCompletedBlock)(UIImage * _Nullable image, GXImageCacheType cacheType);

typedef void(^GXWebImageCheckCacheCompletionBlock)(BOOL isInCache);

typedef void(^GXWebImageCalculateSizeBlock)(NSUInteger fileCount, NSUInteger totalSize);

extern NSString *const GXImageCacheDidCreateCacheDirectoryNotification;
extern NSString *const GXImageCacheDirectoryPathKey;

/**
 * GXImageCache maintains a memory cache and an optional disk cache. Disk cache write operations are performed
 * asynchronous so it doesn’t add unnecessary latency to the UI.
 */
@interface GXImageCache : NSObject

/**
 * Decompressing images that are downloaded and cached can improve performance but can consume lot of memory.
 * Defaults to YES. Set this to NO if you are experiencing a crash due to excessive memory consumption.
 */
@property (assign, nonatomic) BOOL shouldDecompressImages;

/**
 *  disable iCloud backup [defaults to YES]
 */
@property (assign, nonatomic) BOOL shouldDisableiCloud;

/**
 * use memory cache [defaults to YES]
 */
@property (assign, nonatomic) BOOL shouldCacheImagesInMemory;

/**
 * The maximum "total cost" of the in-memory image cache. The cost function is the number of pixels held in memory.
 */
@property (assign, nonatomic) NSUInteger maxMemoryCost;

/**
 * The maximum number of objects the cache should hold.
 */
@property (assign, nonatomic) NSUInteger maxMemoryCountLimit;

/**
 * The maximum length of time to keep an image in the cache, in seconds
 */
@property (assign, nonatomic) NSInteger maxCacheAge;

/**
 * The maximum size of the cache, in bytes.
 */
@property (assign, nonatomic) NSUInteger maxCacheSize;

/**
 * Returns global shared cache instance
 *
 * @return GXImageCache global instance
 */
+ (GXImageCache *)sharedImageCache;

/**
 * Init a new cache store with a specific namespace
 *
 * @param ns The namespace to use for this cache store
 */
- (instancetype)initWithNamespace:(NSString *)ns;

/**
 * Init a new cache store with a specific namespace and directory
 *
 * @param ns        The namespace to use for this cache store
 * @param directory Directory to cache disk images in
 */
- (instancetype)initWithNamespace:(NSString *)ns diskCacheDirectory:(nullable NSString *)directory NS_DESIGNATED_INITIALIZER;

- (NSString *)makeDiskCachePath:(NSString *)fullNamespace;

/**
 * Add a read-only cache path to search for images pre-cached by GXImageCache
 * Useful if you want to bundle pre-loaded images with your app
 *
 * @param path The path to use for this read-only cache path
 */
- (void)addReadOnlyCachePath:(NSString *)path;

/**
 * Store an image into memory and disk cache at the given key.
 *
 * @param image The image to store
 * @param key   The unique image cache key, usually it's image absolute URL
 */
- (void)storeImage:(nullable UIImage *)image forKey:(nullable NSString *)key;

/**
 * Store an image into memory and optionally disk cache at the given key.
 *
 * @param image  The image to store
 * @param key    The unique image cache key, usually it's image absolute URL
 * @param toDisk Store the image to disk cache if YES
 */
- (void)storeImage:(nullable UIImage *)image forKey:(nullable NSString *)key toDisk:(BOOL)toDisk;

/**
 * Store an image into memory and optionally disk cache at the given key.
 *
 * @param image       The image to store
 * @param recalculate BOOL indicates if imageData can be used or a new data should be constructed from the UIImage
 * @param imageData   The image data as returned by the server, this representation will be used for disk storage
 *                    instead of converting the given image object into a storable/compressed image format in order
 *                    to save quality and CPU
 * @param key         The unique image cache key, usually it's image absolute URL
 * @param toDisk      Store the image to disk cache if YES
 */
- (void)storeImage:(nullable UIImage *)image
recalculateFromImage:(BOOL)recalculate
		 imageData:(nullable NSData *)imageData
			forKey:(nullable NSString *)key
			toDisk:(BOOL)toDisk;

- (void)storeImage:(nullable UIImage *)image
recalculateFromImage:(BOOL)recalculate
		 imageData:(nullable NSData *)imageData
			forKey:(nullable NSString *)key
			toDisk:(BOOL)toDisk
	   withOptions:(GXImageCacheOptions)options;

/**
 * Store image NSData into disk cache at the given key.
 *
 * @param imageData The image data to store
 * @param key   The unique image cache key, usually it's image absolute URL
 */
- (void)storeImageDataToDisk:(nullable NSData *)imageData
					  forKey:(nullable NSString *)key;

- (void)storeImageDataToDisk:(nullable NSData *)imageData
					  forKey:(nullable NSString *)key
				 withOptions:(GXImageCacheOptions)options;

/**
 * Query the disk cache asynchronously.
 *
 * @param key The unique key used to store the wanted image
 */
- (nullable NSOperation *)queryDiskCacheForKey:(nullable NSString *)key
										  done:(nullable GXWebImageQueryCompletedBlock)doneBlock;

- (nullable NSOperation *)queryDiskCacheForKey:(nullable NSString *)key
									   options:(GXImageCacheOptions)options
										  done:(nullable GXWebImageQueryCompletedBlock)doneBlock;

- (nullable NSOperation *)queryDiskCacheForKey:(nullable NSString *)key
									   options:(GXImageCacheOptions)options
									   context:(nullable GXWebImageContext)context
										  done:(nullable GXWebImageQueryCompletedBlock)doneBlock;

/**
 * Query the memory cache synchronously.
 *
 * @param key The unique key used to store the wanted image
 */
- (nullable UIImage *)imageFromMemoryCacheForKey:(nullable NSString *)key;

/**
 * Query the disk cache synchronously after checking the memory cache.
 *
 * @param key The unique key used to store the wanted image
 */
- (nullable UIImage *)imageFromDiskCacheForKey:(nullable NSString *)key;

- (nullable UIImage *)imageFromDiskCacheForKey:(nullable NSString *)key
								   withOptions:(GXImageCacheOptions)options;

- (nullable UIImage *)imageFromDiskCacheForKey:(nullable NSString *)key
								   withOptions:(GXImageCacheOptions)options
									   context:(nullable GXWebImageContext)context;

- (nullable NSURL *)imageFileURLFromDiskCacheForKey:(nullable NSString *)key;

- (nullable NSURL *)imageFileURLFromDiskCacheForKey:(nullable NSString *)key
										withOptions:(GXImageCacheOptions)options;

- (nullable NSURL *)imageFileURLFromDiskCacheForKey:(nullable NSString *)key
										withOptions:(GXImageCacheOptions)options
											context:(nullable GXWebImageContext)context;

/**
 * Remove the image from memory and disk cache asynchronously
 *
 * @param key The unique image cache key
 */
- (void)removeImageForKey:(nullable NSString *)key;


/**
 * Remove the image from memory and disk cache asynchronously
 *
 * @param key             The unique image cache key
 * @param completion      An block that should be executed after the image has been removed (optional)
 */
- (void)removeImageForKey:(nullable NSString *)key withCompletion:(nullable GXWebImageNoParamsBlock)completion;

/**
 * Remove the image from memory and optionally disk cache asynchronously
 *
 * @param key      The unique image cache key
 * @param fromDisk Also remove cache entry from disk if YES
 */
- (void)removeImageForKey:(nullable NSString *)key fromDisk:(BOOL)fromDisk;

/**
 * Remove the image from memory and optionally disk cache asynchronously
 *
 * @param key             The unique image cache key
 * @param fromDisk        Also remove cache entry from disk if YES
 * @param completion      An block that should be executed after the image has been removed (optional)
 */
- (void)removeImageForKey:(nullable NSString *)key fromDisk:(BOOL)fromDisk withCompletion:(nullable GXWebImageNoParamsBlock)completion;

/**
 * Clear all memory cached images
 */
- (void)clearMemory;

/**
 * Clear all disk cached images. Non-blocking method - returns immediately.
 * @param completion    An block that should be executed after cache expiration completes (optional)
 */
- (void)clearDiskOnCompletion:(nullable GXWebImageNoParamsBlock)completion;

/**
 * Clear all disk cached images
 * @see clearDiskOnCompletion:
 */
- (void)clearDisk;

/**
 * Remove all expired cached image from disk. Non-blocking method - returns immediately.
 * @param completionBlock An block that should be executed after cache expiration completes (optional)
 */
- (void)cleanDiskWithCompletionBlock:(nullable GXWebImageNoParamsBlock)completionBlock;

/**
 * Remove all expired cached image from disk
 * @see cleanDiskWithCompletionBlock:
 */
- (void)cleanDisk;

/**
 * Get the size used by the disk cache
 */
- (NSUInteger)getSize;

/**
 * Get the number of images in the disk cache
 */
- (NSUInteger)getDiskCount;

/**
 * Asynchronously calculate the disk cache's size.
 */
- (void)calculateSizeWithCompletionBlock:(GXWebImageCalculateSizeBlock)completionBlock;

/**
 *  Async check if image exists in disk cache already (does not load the image)
 *
 *  @param key             the key describing the url
 *  @param completionBlock the block to be executed when the check is done.
 *  @note the completion block will be always executed on the main queue
 */
- (void)diskImageExistsWithKey:(nullable NSString *)key completion:(GXWebImageCheckCacheCompletionBlock)completionBlock;

/**
 *  Check if image exists in disk cache already (does not load the image)
 *
 *  @param key the key describing the url
 *
 *  @return YES if an image exists for the given key
 */
- (BOOL)diskImageExistsWithKey:(nullable NSString *)key;

/**
 *  Get the cache path for a certain key (needs the cache path root folder)
 *
 *  @param key  the key (can be obtained from url using cacheKeyForURL)
 *  @param path the cache path root folder
 *
 *  @return the cache path
 */
- (NSString *)cachePathForKey:(NSString *)key inPath:(NSString *)path;

/**
 *  Get the default cache path for a certain key
 *
 *  @param key the key (can be obtained from url using cacheKeyForURL)
 *
 *  @return the default cache path
 */
- (NSString *)defaultCachePathForKey:(NSString *)key;

/**
 *  Get the full size cache path for a certain cache path
 *
 *  @param cachePath the cache path (can be obtained from defaultCachePathForKey: or cachePathForKey:inPath:)
 *
 *  @return the full size cache path
 */
- (NSString *)fullSizePathForCachePath:(NSString *)cachePath;

@end

NS_ASSUME_NONNULL_END
