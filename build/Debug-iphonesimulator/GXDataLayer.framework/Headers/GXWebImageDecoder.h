/*
 * This file is part of the SdWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * Created by james <https://github.com/mystcolor> on 9/28/11.
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * Modified by Fabian Inthamoussu
 */

#import <Foundation/Foundation.h>
#import <GXDataLayer/GXWebImageCompat.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (ForceDecode)

+ (nullable UIImage *)decodedImageWithImage:(nullable UIImage *)image;

@end

NS_ASSUME_NONNULL_END
