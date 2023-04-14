//
//  UITabBar+WebCache.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 5/9/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import UIKit;
@import GXDataLayer;

NS_ASSUME_NONNULL_BEGIN

/**
 * Integrates GXWebImage async downloading and caching of remote images with UITabBar.
 */
@interface UITabBar (WebCache)

/**
 * Set the backgroundImageView `image` with an `url`.
 *
 * The download is asynchronous and cached.
 *
 * @param url   The url for the image.
 */
- (void)gxSetBackgroundImageWithURL:(nullable NSURL *)url;

/**
 * Set the backgroundImageView `image` with an `url` and a placeholder.
 *
 * The download is asynchronous and cached.
 *
 * @param url         The url for the image.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @see gxSetImageWithURL:placeholderImage:options:
 */
- (void)gxSetBackgroundImageWithURL:(nullable NSURL *)url placeholderImage:(nullable UIImage *)placeholder;

/**
 * Set the backgroundImageView `image` with an `url`, placeholder and custom options.
 *
 * The download is asynchronous and cached.
 *
 * @param url         The url for the image.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @param options     The options to use when downloading the image. @see GXWebImageOptions for the possible values.
 */
- (void)gxSetBackgroundImageWithURL:(nullable NSURL *)url placeholderImage:(nullable UIImage *)placeholder options:(GXWebImageOptions)options;

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
- (void)gxSetBackgroundImageWithURL:(nullable NSURL *)url completed:(nullable GXWebImageCompletionBlock)completedBlock;

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
				   placeholderImage:(nullable UIImage *)placeholder
							options:(GXWebImageOptions)options
							context:(nullable GXWebImageContext)context
						  completed:(nullable GXWebImageCompletionBlock)completedBlock;

/**
 * Set the selection indicator `image` with an `url`.
 *
 * The download is asynchronous and cached.
 *
 * @param url   The url for the image.
 */
- (void)gxSetSelectionIndicatorImageWithURL:(nullable NSURL *)url;

/**
 * Set the selection indicator `image` with an `url`, custom options.
 *
 * The download is asynchronous and cached.
 *
 * @param url         The url for the image.
 * @param options     The options to use when downloading the image. @see GXWebImageOptions for the possible values.
 */
- (void)gxSetSelectionIndicatorImageWithURL:(nullable NSURL *)url options:(GXWebImageOptions)options;

/**
 * Set the selection indicator `image` with an `url`.
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
- (void)gxSetSelectionIndicatorImageWithURL:(nullable NSURL *)url completed:(nullable GXWebImageCompletionBlock)completedBlock;

/**
 * Set the selection indicator `image` with an `url`, custom options.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param options        The options to use when downloading the image. @see GXWebImageOptions for the possible values.
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original image url.
 */
- (void)gxSetSelectionIndicatorImageWithURL:(nullable NSURL *)url
									options:(GXWebImageOptions)options
								  completed:(nullable GXWebImageCompletionBlock)completedBlock;

/**
 * Set the selection indicator `image` with an `url`, custom options.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param options        The options to use when downloading the image. @see GXWebImageOptions for the possible values.
 * @param context        A context contains different options to perform specify changes or processes, see `GXWebImageContextOption`. This hold the extra objects which `options` enum can not hold.
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original image url.
 */
- (void)gxSetSelectionIndicatorImageWithURL:(nullable NSURL *)url
									options:(GXWebImageOptions)options
									context:(nullable GXWebImageContext)context
								  completed:(nullable GXWebImageCompletionBlock)completedBlock;

/**
 * Cancel the current background image download
 */
- (void)gxCancelBackgroundImageLoad;

/**
 * Cancel the current selection indicator image download
 */
- (void)gxCancelSelectionIndicatorImageLoad;

@end

NS_ASSUME_NONNULL_END
