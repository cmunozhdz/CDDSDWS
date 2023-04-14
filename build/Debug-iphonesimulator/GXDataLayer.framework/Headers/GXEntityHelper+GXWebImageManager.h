//
//  GXEntityHelper+GXWebImageManager.h
//  GXCoreBL
//
//  Created by Fabian Inthamoussu on 16/3/17.
//  Copyright © 2017 GeneXus. All rights reserved.
//

@import GXObjectsModel;
#import <GXDataLayer/GXWebImageManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXEntityHelper (GXWebImageManager)

/// Calls imageFileURLOrDataFromAbsoluteURL:cacheOptions:downloaderOptions:completion: with empty options
+ (void)imageFileURLOrDataFromAbsoluteURL:(NSURL *)imageAbsoluteURL
							   completion:(void(^)(NSURL * _Nullable imageFileURL, NSData * _Nullable imageData, NSError * _Nullable error))completion;

/// Calls imageFileURLOrDataFromAbsoluteURL:cacheOptions:downloaderOptions:context:completion: with nil context.
+ (void)imageFileURLOrDataFromAbsoluteURL:(NSURL *)imageAbsoluteURL
							 cacheOptions:(GXImageCacheOptions)cacheOptions
						downloaderOptions:(GXWebImageDownloaderOptions)downloaderOptions
							   completion:(void(^)(NSURL * _Nullable imageFileURL, NSData * _Nullable imageData, NSError * _Nullable error))completion;

/*!
 Calls completion with a file URL for the given image URL or data if data if the image has to be downloaded
 
 @param imageAbsoluteURL Absolute URL of the image.
 @param cacheOptions Cache options to query disk cache.
 @param downloaderOptions Downloader options if data has to be downloaded.
 @param context        A context contains different options to perform specify changes or processes, see `GXWebImageContextOption`. This hold the extra objects which `options` enum can not hold.
 @param completion Completion block. imageData is nil if imageFileURL was found.
 @discussion Use imageDataFromAbsoluteURL:cacheOptions:downloaderOptions:completion: if only imageData is required (even if imageFileURL was found).
 */
+ (void)imageFileURLOrDataFromAbsoluteURL:(NSURL *)imageAbsoluteURL
							 cacheOptions:(GXImageCacheOptions)cacheOptions
						downloaderOptions:(GXWebImageDownloaderOptions)downloaderOptions
								  context:(nullable GXWebImageContext)context
							   completion:(void(^)(NSURL * _Nullable imageFileURL, NSData * _Nullable imageData, NSError * _Nullable error))completion;

/// Calls imageDataFromAbsoluteURL:cacheOptions:downloaderOptions:completion: with empty options
+ (void)imageDataFromAbsoluteURL:(NSURL *)imageAbsoluteURL
					  completion:(void(^)(NSData * _Nullable imageData, NSError * _Nullable error))completion;

/// Same as imageFileURLOrDataFromAbsoluteURL:cacheOptions:downloaderOptions:completion: but if imageFileURL is found, data is loaded from disk
+ (void)imageDataFromAbsoluteURL:(NSURL *)imageAbsoluteURL
					cacheOptions:(GXImageCacheOptions)cacheOptions
			   downloaderOptions:(GXWebImageDownloaderOptions)downloaderOptions
					  completion:(void(^)(NSData * _Nullable imageData, NSError * _Nullable error))completion;

/// Same as imageFileURLOrDataFromAbsoluteURL:cacheOptions:downloaderOptions:context:completion: but if imageFileURL is found, data is loaded from disk
+ (void)imageDataFromAbsoluteURL:(NSURL *)imageAbsoluteURL
					cacheOptions:(GXImageCacheOptions)cacheOptions
			   downloaderOptions:(GXWebImageDownloaderOptions)downloaderOptions
						 context:(nullable GXWebImageContext)context
					  completion:(void(^)(NSData * _Nullable imageData, NSError * _Nullable error))completion;

#pragma mark - Synchronic methods

/// Calls imageFileURLOrDataFromAbsoluteURL:cacheOptions:downloaderOptions:fileURL:imageData:error: with empty options. Must not be called on main thread.
+ (BOOL)imageFileURLOrDataFromAbsoluteURL:(NSURL *)imageAbsoluteURL
								  fileURL:(out NSURL * __autoreleasing __nullable * __nullable)fileURL
								imageData:(out NSData * __autoreleasing __nullable * __nullable)imageData
									error:(out NSError * __autoreleasing __nullable * _Nullable)error;

/// Calls imageFileURLOrDataFromAbsoluteURL:cacheOptions:downloaderOptions:context:fileURL:imageData:error: with nil context. Must not be called on main thread.
+ (BOOL)imageFileURLOrDataFromAbsoluteURL:(NSURL *)imageAbsoluteURL
							 cacheOptions:(GXImageCacheOptions)cacheOptions
						downloaderOptions:(GXWebImageDownloaderOptions)downloaderOptions
								  fileURL:(out NSURL * __autoreleasing __nullable * __nullable)fileURL
								imageData:(out NSData * __autoreleasing __nullable * __nullable)imageData
									error:(out NSError * __autoreleasing __nullable * _Nullable)error;

/*!
 Synchronic variation of imageFileURLOrDataFromAbsoluteURL:cacheOptions:downloaderOptions:context:completion:. Must not be called on main thread.
 
 @discussion Must not be called on main thread. Can be called only with fileURL or imageData, but at least one must be non null.
 */
+ (BOOL)imageFileURLOrDataFromAbsoluteURL:(NSURL *)imageAbsoluteURL
							 cacheOptions:(GXImageCacheOptions)cacheOptions
						downloaderOptions:(GXWebImageDownloaderOptions)downloaderOptions
								  context:(nullable GXWebImageContext)context
								  fileURL:(out NSURL * __autoreleasing __nullable * __nullable)fileURL
								imageData:(out NSData * __autoreleasing __nullable * __nullable)imageData
									error:(out NSError * __autoreleasing __nullable * _Nullable)error;

@end

NS_ASSUME_NONNULL_END
