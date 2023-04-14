/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * Modified by Fabian Inthamoussu
 */

@import UIKit;
@import GXDataLayer;

NS_ASSUME_NONNULL_BEGIN

typedef UIView *_Nonnull(^GXWebImageActivityIndicatorViewBuilderBlock)(UIView *forSuperview);

/**
 * Integrates GXWebImage async downloading and caching of remote images with UIImageView.
 *
 * Usage with a UITableViewCell sub-class:
 *
 * @code
 
 #import <GXWebImage/UIImageView+WebCache.h>
 
 ...
 
 - (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
 {
 static NSString *MyIdentifier = @"MyIdentifier";
 
 UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:MyIdentifier];
 
 if (cell == nil) {
 cell = [[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:MyIdentifier]
 autorelease];
 }
 
 // Here we use the provided gxSetImageWithURL: method to load the web image
 // Ensure you use a placeholder image otherwise cells will be initialized with no image
 [cell.imageView gxSetImageWithURL:[NSURL URLWithString:@"http://example.com/image.jpg"]
 placeholderImage:[UIImage imageNamed:@"placeholder"]];
 
 cell.textLabel.text = @"My Text";
 return cell;
 }
 
 * @endcode
 */
@interface UIImageView (WebCache)

/**
 * Get the current image URL.
 *
 * Note that because of the limitations of categories this property can get out of sync
 * if you use gxSetImage: directly.
 */
- (nullable NSURL *)gxImageURL;

/**
 * Set the imageView `image` with an `url`.
 *
 * The download is asynchronous and cached.
 *
 * @param url The url for the image.
 */
- (void)gxSetImageWithURL:(nullable NSURL *)url;

/**
 * Set the imageView `image` with an `url` and a placeholder.
 *
 * The download is asynchronous and cached.
 *
 * @param url         The url for the image.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @see gxSetImageWithURL:placeholderImage:options:
 */
- (void)gxSetImageWithURL:(nullable NSURL *)url
		 placeholderImage:(nullable UIImage *)placeholder;

/**
 * Set the imageView `image` with an `url`, placeholder and custom options.
 *
 * The download is asynchronous and cached.
 *
 * @param url         The url for the image.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @param options     The options to use when downloading the image. @see GXWebImageOptions for the possible values.
 */
- (void)gxSetImageWithURL:(nullable NSURL *)url
		 placeholderImage:(nullable UIImage *)placeholder
				  options:(GXWebImageOptions)options;

/**
 * Set the imageView `image` with an `url`.
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
- (void)gxSetImageWithURL:(nullable NSURL *)url
				completed:(nullable GXWebImageCompletionBlock)completedBlock;

/**
 * Set the imageView `image` with an `url`, placeholder.
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
- (void)gxSetImageWithURL:(nullable NSURL *)url
		 placeholderImage:(nullable UIImage *)placeholder
				completed:(nullable GXWebImageCompletionBlock)completedBlock;

/**
 * Set the imageView `image` with an `url`, placeholder and custom options.
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
- (void)gxSetImageWithURL:(nullable NSURL *)url
		 placeholderImage:(nullable UIImage *)placeholder
				  options:(GXWebImageOptions)options
				completed:(nullable GXWebImageCompletionBlock)completedBlock;

/**
 * Set the imageView `image` with an `url`, placeholder and custom options.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param placeholder    The image to be set initially, until the image request finishes.
 * @param options        The options to use when downloading the image. @see GXWebImageOptions for the possible values.
 * @param progressBlock  A block called while image is downloading
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original image url.
 */
- (void)gxSetImageWithURL:(nullable NSURL *)url
		 placeholderImage:(nullable UIImage *)placeholder
				  options:(GXWebImageOptions)options
				 progress:(nullable GXWebImageDownloaderProgressBlock)progressBlock
				completed:(nullable GXWebImageCompletionBlock)completedBlock;

/**
 * Set the imageView `image` with an `url`, placeholder and custom options.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param placeholder    The image to be set initially, until the image request finishes.
 * @param options        The options to use when downloading the image. @see GXWebImageOptions for the possible values.
 * @param context        A context contains different options to perform specify changes or processes, see `GXWebImageContextOption`. This hold the extra objects which `options` enum can not hold.
 * @param progressBlock  A block called while image is downloading
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original image url.
 */
- (void)gxSetImageWithURL:(nullable NSURL *)url
		 placeholderImage:(nullable UIImage *)placeholder
				  options:(GXWebImageOptions)options
				  context:(nullable GXWebImageContext)context
				 progress:(nullable GXWebImageDownloaderProgressBlock)progressBlock
				completed:(nullable GXWebImageCompletionBlock)completedBlock;

/**
 * Set the imageView `image` with an `url` and optionally a placeholder image.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param placeholder    The image to be set initially, until the image request finishes.
 * @param options        The options to use when downloading the image. @see GXWebImageOptions for the possible values.
 * @param progressBlock  A block called while image is downloading
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original image url.
 */
- (void)gxSetImageWithPreviousCachedImageWithURL:(nullable NSURL *)url
								placeholderImage:(nullable UIImage *)placeholder
										 options:(GXWebImageOptions)options
										progress:(nullable GXWebImageDownloaderProgressBlock)progressBlock
									   completed:(nullable GXWebImageCompletionBlock)completedBlock;

/**
 * Set the imageView `image` with an `url` and optionally a placeholder image.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param placeholder    The image to be set initially, until the image request finishes.
 * @param options        The options to use when downloading the image. @see GXWebImageOptions for the possible values.
 * @param context        A context contains different options to perform specify changes or processes, see `GXWebImageContextOption`. This hold the extra objects which `options` enum can not hold.
 * @param progressBlock  A block called while image is downloading
 * @param completedBlock A block called when operation has been completed. This block has no return value
 *                       and takes the requested UIImage as first parameter. In case of error the image parameter
 *                       is nil and the second parameter may contain an NSError. The third parameter is a Boolean
 *                       indicating if the image was retrieved from the local cache or from the network.
 *                       The fourth parameter is the original image url.
 */
- (void)gxSetImageWithPreviousCachedImageWithURL:(nullable NSURL *)url
								placeholderImage:(nullable UIImage *)placeholder
										 options:(GXWebImageOptions)options
										 context:(nullable GXWebImageContext)context
										progress:(nullable GXWebImageDownloaderProgressBlock)progressBlock
									   completed:(nullable GXWebImageCompletionBlock)completedBlock;

/**
 * Download an array of images and starts them in an animation loop
 *
 * @param arrayOfURLs An array of NSURL
 */
- (void)gxSetAnimationImagesWithURLs:(NSArray<NSURL *> *)arrayOfURLs;

/**
 * Cancel the current download
 */
- (void)gxCancelCurrentImageLoad;

- (void)gxCancelCurrentAnimationImagesLoad;

/**
 *  Show activity UIActivityIndicatorView
 */
@property(nonatomic, assign) BOOL gxShowActivityIndicatorView;

/**
 *  set desired UIActivityIndicatorViewStyle
 *
 *  @param style The style of the UIActivityIndicatorView
 */
- (void)setIndicatorStyle:(UIActivityIndicatorViewStyle)style;

/*!
 Set activity indicator view builder
 
 @param builderBlock The activity indicator view builder.
 @discussion If non null, this block is used intead an UIActivityIndicatorView
 */
- (void)gxSetActivityIndicatorViewBuilder:(nullable GXWebImageActivityIndicatorViewBuilderBlock)builderBlock;

/*!
 Override point for subclasses
 
 @discussion If non null, this block is used intead an UIActivityIndicatorView
 */
+ (GXWebImageActivityIndicatorViewBuilderBlock)gxDefaultActivityIndicatorViewBuilder;

@end

NS_ASSUME_NONNULL_END
