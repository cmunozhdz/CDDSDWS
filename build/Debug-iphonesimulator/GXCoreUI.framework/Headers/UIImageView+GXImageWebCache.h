//
//  UIImageView+GXImageWebCache.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 30/8/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import UIKit;
@import GXObjectsModel;
@import GXCoreBL;
#import <GXCoreUI/UIImageView+HighlightedWebCache.h>
#import <GXCoreUI/UIImageView+WebCache.h>

NS_ASSUME_NONNULL_BEGIN

typedef UIImage * _Nonnull (^GXImageWebCacheTransformImage)(UIImage *image, GXImage * _Nullable gxImage, BOOL isEmbededImage);
typedef UIImage * _Nullable (^GXImageWebCachePlaceholderImageProvider)(NSString * __autoreleasing _Nullable * _Nullable placeholderImageName,
																	   NSURL * __autoreleasing _Nullable * _Nullable placeholderImageURL,
																	   GXImage *  __autoreleasing _Nullable * _Nullable placeholderGxImage);
typedef void (^GXImageWebCacheUIImageViewReloadHandler)(UIImageView *imageView, GXLocalizedImageObject *gxImage);
typedef void (^GXImageWebCacheUIImageViewHighlightedReloadHandler)(UIImageView *imageView, GXLocalizedImageObject *gxImage, BOOL reloadImage, BOOL reloadHighlightedImage);

@interface UIImageView (GXImageWebCache)

- (nullable GXImageWebCacheTransformImage)gxDefaultImageTransformWithBackgroundMode:(GXBackgroundImageMode)bgMode
																		  scaleType:(GXImageScaleType)scaleType
																	  renderingMode:(GXImageRenderingMode)renderingMode
																		flipsForRTL:(GXOptionalBoolean)flipsForRTL NS_REFINED_FOR_SWIFT;

- (nullable GXImageWebCacheTransformImage)gxDefaultImageTransformWithBackgroundMode:(GXBackgroundImageMode)bgMode NS_REFINED_FOR_SWIFT;
- (nullable GXImageWebCacheTransformImage)gxDefaultImageTransformWithScaleType:(GXImageScaleType)scaleType NS_REFINED_FOR_SWIFT;
- (nullable GXImageWebCacheTransformImage)gxDefaultImageTransformWithRenderingMode:(GXImageRenderingMode)renderingMode NS_REFINED_FOR_SWIFT;
- (nullable GXImageWebCacheTransformImage)gxDefaultImageTransformWithFlipsForRTL:(GXOptionalBoolean)flipsForRTL NS_REFINED_FOR_SWIFT;

- (nullable GXImageWebCacheTransformImage)gxDefaultImageTransformWithStyleClass:(nullable GXStyleClass *)styleClass
										 resolvingToDefaultWithPropertyResolver:(nullable id<GXStyleClassPropertyDefaultResolver>)resolver;

+ (nullable GXImageWebCachePlaceholderImageProvider)gxPlaceholderImageProviderWithImage:(nullable UIImage *)image;
+ (nullable GXImageWebCachePlaceholderImageProvider)gxPlaceholderImageProviderWithImageName:(nullable NSString *)imageName
																				modelObject:(nullable id<GXModelObject>)modelObject;
/// If modelObject == nil, it tries to get the model object using GXStyleClassHelper.modelObjectFromStyleClass(from:resolver:) with the given styleClass and resolver
+ (nullable GXImageWebCachePlaceholderImageProvider)gxPlaceholderImageProviderWithStyleClass:(nullable GXStyleClass *)styleClass
													  resolvingToDefaultWithPropertyResolver:(nullable id<GXStyleClassPropertyDefaultResolver>)resolver
																				 modelObject:(nullable id<GXModelObject>)modelObject;

@end



@interface UIImageView (GXImageWebCache_DEPRECATED)

/// #deprecated: 2022-01-26: trunk; #to-remove: ??
+ (nullable GXImageWebCachePlaceholderImageProvider)gxPlaceholderImageProviderWithImageName:(nullable NSString *)imageName
__attribute__((deprecated("Use gxPlaceholderImageProviderWithImageName:modelObject: instead")));
/// #deprecated: 2022-01-26: trunk; #to-remove: ??
+ (nullable GXImageWebCachePlaceholderImageProvider)gxPlaceholderImageProviderWithStyleClass:(nullable GXStyleClass *)styleClass
													  resolvingToDefaultWithPropertyResolver:(nullable id<GXStyleClassPropertyDefaultResolver>)resolver __attribute__((deprecated("Use gxPlaceholderImageProviderWithStyleClass:resolvingToDefaultWithPropertyResolver:modelObject: instead")));

#pragma mark - Image & Highlighted Image with name

// #deprecated: 2021-09-22: v17u6; #to-remove: v17u9
- (void)gxSetImageNamed:(nullable NSString *)imageName
  highlightedImageNamed:(nullable NSString *)hImageName
	   placeholderImage:(nullable GXImageWebCachePlaceholderImageProvider)placeholderImageProvider __attribute__((deprecated("Use gxSetImageNamed:highlightedImageNamed:placeholderImage:reloadHandler: instead")));

// #deprecated: 2021-09-22: v17u6; #to-remove: v17u9
- (void)gxSetImageNamed:(nullable NSString *)imageName
  highlightedImageNamed:(nullable NSString *)hImageName
	   placeholderImage:(nullable GXImageWebCachePlaceholderImageProvider)placeholderImageProvider
		 transformImage:(UIImage *(^ _Nullable)(UIImage *image, GXImage * _Nullable gxImage, BOOL isEmbededImage, BOOL isHighlightedImage))transformImage __attribute__((deprecated("Use gxSetImageNamed:highlightedImageNamed:placeholderImage:transformImage:reloadHandler: instead")));

#pragma mark - Image with name

// #deprecated: 2021-09-22: v17u6; #to-remove: v17u9
- (void)gxSetImageNamed:(nullable NSString *)imageName
	   placeholderImage:(nullable GXImageWebCachePlaceholderImageProvider)placeholderImageProvider __attribute__((deprecated("Use gxSetImageNamed:placeholderImage:reloadHandler: instead")));

// #deprecated: 2021-09-22: v17u6; #to-remove: v17u9
- (void)gxSetImageNamed:(nullable NSString *)imageName
	   placeholderImage:(nullable GXImageWebCachePlaceholderImageProvider)placeholderImageProvider
		 transformImage:(nullable GXImageWebCacheTransformImage)transformImage __attribute__((deprecated("Use gxSetImageNamed:placeholderImage:transformImage:reloadHandler: instead")));

// #deprecated: 2021-09-22: v17u6; #to-remove: v17u9
- (void)gxSetImageNamed:(nullable NSString *)imageName
	   placeholderImage:(nullable GXImageWebCachePlaceholderImageProvider)placeholderImageProvider
		 transformImage:(nullable GXImageWebCacheTransformImage)transformImage
				options:(GXWebImageOptions)options
			   progress:(nullable GXWebImageDownloaderProgressBlock)progressBlock
			  completed:(nullable GXWebImageCompletionBlock)completedBlock __attribute__((deprecated("Use gxSetImageNamed:placeholderImage:transformImage:reloadHandler:options:progress:completed: instead")));

// #deprecated: 2021-09-22: v17u6; #to-remove: v17u9
- (void)gxSetImageNamed:(nullable NSString *)imageName
			 styleClass:(nullable GXStyleClass *)styleClass
resolvingToDefaultWithPropertyResolver:(nullable id<GXStyleClassPropertyDefaultResolver>)resolver __attribute__((deprecated("Use gxSetImageNamed:styleClass:resolvingToDefaultWithPropertyResolver:reloadHandler: instead")));
// #deprecated: 2021-06-17: v17u5; #to-remove: v17u8
- (void)gxSetImageNamed:(nullable NSString *)imageName themeClass:(nullable GXThemeClass *)themeClass __attribute__((deprecated("Use gxSetImageNamed:styleClass:resolvingToDefaultWithPropertyResolver: instead")));

#pragma mark - Highlighted Image with name

// #deprecated: 2021-09-22: v17u6; #to-remove: v17u9
- (void)gxSetHighlightedImageNamed:(nullable NSString *)imageName
					transformImage:(nullable GXImageWebCacheTransformImage)transformImage __attribute__((deprecated("Use gxSetHighlightedImageNamed:transformImage:reloadHandler: instead")));

// #deprecated: 2021-09-22: v17u6; #to-remove: v17u9
- (void)gxSetHighlightedImageNamed:(nullable NSString *)imageName
					transformImage:(nullable GXImageWebCacheTransformImage)transformImage
						   options:(GXWebImageOptions)options
						  progress:(nullable GXWebImageDownloaderProgressBlock)progressBlock
						 completed:(nullable GXWebImageCompletionBlock)completedBlock __attribute__((deprecated("Use gxSetHighlightedImageNamed:transformImage:reloadHandler:options:progress:completed: instead")));

@end

@interface UIImageView (GXEntityDataImageWebCache_DEPRECATED)

// #deprecated: 2021-09-22: v17u6; #to-remove: v17u9
- (void)gxSetImageFromEntityDataFieldValue:(nullable id)entityDataFieldValue
						  placeholderImage:(nullable GXImageWebCachePlaceholderImageProvider)placeholderImageProvider
							transformImage:(nullable GXImageWebCacheTransformImage)transformImage __attribute__((deprecated("Use gxSetImageFromEntityDataFieldValue:placeholderImage:transformImage:reloadHandler: instead")));

// #deprecated: 2021-09-22: v17u6; #to-remove: v17u9
- (void)gxSetImageFromEntityDataFieldValue:(nullable id)entityDataFieldValue
						  placeholderImage:(nullable GXImageWebCachePlaceholderImageProvider)placeholderImageProvider
							transformImage:(nullable GXImageWebCacheTransformImage)transformImage
								   options:(GXWebImageOptions)options
								  progress:(nullable GXWebImageDownloaderProgressBlock)progressBlock
								 completed:(nullable GXWebImageCompletionBlock)completedBlock __attribute__((deprecated("Use gxSetImageFromEntityDataFieldValue:placeholderImage:transformImage:reloadHandler:options:progress:completed: instead")));

// #deprecated: 2021-09-22: v17u6; #to-remove: v17u9
- (void)gxSetImageFromEntityDataFieldValue:(nullable id)entityDataFieldValue
								styleClass:(nullable GXStyleClass *)styleClass
	resolvingToDefaultWithPropertyResolver:(nullable id<GXStyleClassPropertyDefaultResolver>)resolver __attribute__((deprecated("Use gxSetImageFromEntityDataFieldValue:styleClass:resolvingToDefaultWithPropertyResolver:reloadHandler: instead")));

@end

NS_ASSUME_NONNULL_END
