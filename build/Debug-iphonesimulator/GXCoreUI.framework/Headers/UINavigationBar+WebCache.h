//
//  UINavigationBar+WebCache.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 5/9/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import UIKit;
@import GXDataLayer;

NS_ASSUME_NONNULL_BEGIN

/**
 * Integrates GXWebImage async downloading and caching of remote images with UINavigationBar.
 */
@interface UINavigationBar (WebCache)
/**
 * Set the backgroundImageView `image` with an `url`.
 *
 * The download is asynchronous and cached.
 *
 * @param url   The url for the image.
 */
- (void)gxSetBackgroundImageWithURL:(nullable NSURL *)url
					 forBarPosition:(UIBarPosition)topOrBottom
						 barMetrics:(UIBarMetrics)barMetrics;

/**
 * Set the backgroundImageView `image` with an `url` and a placeholder.
 *
 * The download is asynchronous and cached.
 *
 * @param url         The url for the image.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @see gxSetImageWithURL:placeholderImage:options:
 */
- (void)gxSetBackgroundImageWithURL:(nullable NSURL *)url
					 forBarPosition:(UIBarPosition)topOrBottom
						 barMetrics:(UIBarMetrics)barMetrics
				   placeholderImage:(nullable UIImage *)placeholder;

/**
 * Set the backgroundImageView `image` with an `url`, placeholder and custom options.
 *
 * The download is asynchronous and cached.
 *
 * @param url         The url for the image.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @param options     The options to use when downloading the image. @see GXWebImageOptions for the possible values.
 */
- (void)gxSetBackgroundImageWithURL:(nullable NSURL *)url
					 forBarPosition:(UIBarPosition)topOrBottom
						 barMetrics:(UIBarMetrics)barMetrics
				   placeholderImage:(nullable UIImage *)placeholder
							options:(GXWebImageOptions)options;

/**
 * Set the backgroundImageView `image` with an `url`.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original image url.
 */
- (void)gxSetBackgroundImageWithURL:(nullable NSURL *)url
					 forBarPosition:(UIBarPosition)topOrBottom
						 barMetrics:(UIBarMetrics)barMetrics
						  completed:(nullable GXWebImageCompletionBlock)completedBlock;

/**
 * Set the backgroundImageView `image` with an `url`, placeholder.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param placeholder    The image to be set initially, until the image request finishes.
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original image url.
 */
- (void)gxSetBackgroundImageWithURL:(nullable NSURL *)url
					 forBarPosition:(UIBarPosition)topOrBottom
						 barMetrics:(UIBarMetrics)barMetrics
				   placeholderImage:(nullable UIImage *)placeholder
						  completed:(nullable GXWebImageCompletionBlock)completedBlock;

/**
 * Set the backgroundImageView `image` with an `url`, placeholder and custom options.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param placeholder    The image to be set initially, until the image request finishes.
 * @param options        The options to use when downloading the image. @see GXWebImageOptions for the possible values.
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original image url.
 */
- (void)gxSetBackgroundImageWithURL:(nullable NSURL *)url
					 forBarPosition:(UIBarPosition)topOrBottom
						 barMetrics:(UIBarMetrics)barMetrics
				   placeholderImage:(nullable UIImage *)placeholder
							options:(GXWebImageOptions)options
						  completed:(nullable GXWebImageCompletionBlock)completedBlock;

/**
 * Set the backgroundImageView `image` with an `url`, placeholder and custom options.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param placeholder    The image to be set initially, until the image request finishes.
 * @param options        The options to use when downloading the image. @see GXWebImageOptions for the possible values.
 * @param context        A context contains different options to perform specify changes or processes, see `GXWebImageContextOption`. This hold the extra objects which `options` enum can not hold.
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original image url.
 */
- (void)gxSetBackgroundImageWithURL:(nullable NSURL *)url
					 forBarPosition:(UIBarPosition)topOrBottom
						 barMetrics:(UIBarMetrics)barMetrics
				   placeholderImage:(nullable UIImage *)placeholder
							options:(GXWebImageOptions)options
							context:(nullable GXWebImageContext)context
						  completed:(nullable GXWebImageCompletionBlock)completedBlock;

/**
 * Cancel the current backgroundImage download
 */
- (void)gxCancelBackgroundImageLoadForBarPosition:(UIBarPosition)topOrBottom barMetrics:(UIBarMetrics)barMetrics;

@end

NS_ASSUME_NONNULL_END
