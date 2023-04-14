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

@interface NSObject (WebCacheOperation)

/**
 *  Set the image load operation (storage in a NSObject based dictionary)
 *
 *  @param operation the operation
 *  @param key       key for storing the operation
 */
- (void)gxSetImageLoadOperation:(id)operation forKey:(NSString *)key;

/**
 *  Cancel all operations for the current NSObject and key
 *
 *  @param key key for identifying the operations
 */
- (void)gxCancelImageLoadOperationWithKey:(NSString *)key;

/**
 *  Just remove the operations corresponding to the current NSObject and key without cancelling them
 *
 *  @param key key for identifying the operations
 */
- (void)gxRemoveImageLoadOperationWithKey:(NSString *)key;

/// Remove image load operation if matches
- (void)gxRemoveImageLoadOperation:(id)operation forKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
