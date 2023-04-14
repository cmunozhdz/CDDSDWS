//
//  GXWebImageCustomURLSchemeManager.h
//  GXCoreBL
//
//  Created by Fabian Inthamoussu on 15/3/17.
//  Copyright © 2017 GeneXus. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@protocol GXWebImageCustomURLSchemeManager <NSObject>

@optional
/**
 * Subclass of `GXWebImageDownloaderBaseOperation` as the url scheme
 * `NSOperation` to be used each time GXWebImage constructs a request
 * operation to download an image.
 *
 * @param scheme The URL scheme of URL's to be handled with the returned `GXWebImageDownloaderBaseOperation` class.
 */
- (Class)imageDownloaderOperationClassForCustomURLScheme:(NSString *)scheme;

- (BOOL)disablesOnDiskCacheForCustomURLScheme:(NSString *)scheme;

@end

NS_ASSUME_NONNULL_END
