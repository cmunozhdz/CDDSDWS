//
//  GXWebImageDefine.h
//  GXDataLayer
//
//  Created by Fabian Inthamoussu on 23/11/21.
//  Copyright © 2021 GeneXus. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, GXWebImageOptions) {
	/**
	 * By default, when a URL fail to be downloaded, the URL is blacklisted so the library won't keep trying.
	 * This flag disable this blacklisting.
	 */
	GXWebImageRetryFailed = 1 << 0,

	/**
	 * By default, image downloads are started during UI interactions, this flags disable this feature,
	 * leading to delayed download on UIScrollView deceleration for instance.
	 */
	GXWebImageLowPriority = 1 << 1,

	/**
	 * This flag disables on-disk caching
	 */
	GXWebImageCacheMemoryOnly = 1 << 2,

	/**
	 * This flag enables progressive download, the image is displayed progressively during download as a browser would do.
	 * By default, the image is only displayed once completely downloaded.
	 */
	GXWebImageProgressiveDownload = 1 << 3,

	/**
	 * Even if the image is cached, respect the HTTP response cache control, and refresh the image from remote location if needed.
	 * The disk caching will be handled by NSURLCache instead of GXWebImage leading to slight performance degradation.
	 * This option helps deal with images changing behind the same request URL, e.g. Facebook graph api profile pics.
	 * If a cached image is refreshed, the completion block is called once with the cached image and again with the final image.
	 *
	 * Use this flag only if you can't make your URLs static with embedded cache busting parameter.
	 */
	GXWebImageRefreshCached = 1 << 4,

	/**
	 * In iOS 4+, continue the download of the image if the app goes to background. This is achieved by asking the system for
	 * extra time in background to let the request finish. If the background task expires the operation will be cancelled.
	 */
	GXWebImageContinueInBackground = 1 << 5,

	/**
	 * Handles cookies stored in NSHTTPCookieStore by setting
	 * NSMutableURLRequest.HTTPShouldHandleCookies = YES;
	 */
	GXWebImageHandleCookies = 1 << 6,

	/**
	 * Enable to allow untrusted SSL certificates.
	 * Useful for testing purposes. Use with caution in production.
	 */
	GXWebImageAllowInvalidSSLCertificates = 1 << 7,

	/**
	 * By default, images are loaded in the order in which they were queued. This flag moves them to
	 * the front of the queue.
	 */
	GXWebImageHighPriority = 1 << 8,
	
	/**
	 * By default, placeholder images are loaded while the image is loading. This flag will delay the loading
	 * of the placeholder image until after the image has finished loading.
	 */
	GXWebImageDelayPlaceholder = 1 << 9,

	/**
	 * We usually don't call transformDownloadedImage delegate method on animated images,
	 * as most transformation code would mangle it.
	 * Use this flag to transform them anyway.
	 */
	GXWebImageTransformAnimatedImage = 1 << 10,
	
	/**
	 * By default, image is added to the imageView after download. But in some cases, we want to
	 * have the hand before setting the image (apply a filter or add it with cross-fade animation for instance)
	 * Use this flag if you want to manually set the image in the completion when success
	 */
	GXWebImageAvoidAutoSetImage = 1 << 11,
	
	/**
	 * By default, the image is resized to device main screen size
	 * Use this flag if you want to the image not to be resized
	 */
	GXWebImageFullSizeImage = 1 << 12,
};

typedef NSString *const GXWebImageContextOption NS_TYPED_EXTENSIBLE_ENUM;
typedef NSDictionary<GXWebImageContextOption, id> * GXWebImageContext;
typedef NSMutableDictionary<GXWebImageContextOption, id> * GXWebImageMutableContext;

/// A CGFloat raw value which specify the image scale factor. The number should be greater than 0. If not provide or the number is invalid, we will use the cache key to specify the scale factor. (NSNumber)
extern GXWebImageContextOption GXWebImageContextImageScaleFactor;

NS_ASSUME_NONNULL_END
