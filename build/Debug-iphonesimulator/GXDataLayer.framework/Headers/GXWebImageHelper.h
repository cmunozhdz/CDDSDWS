//
//  GXWebImageHelper.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 15/1/15.
//  Copyright (c) 2015 Artech. All rights reserved.
//

@import UIKit;
@import CoreGraphics;

NS_ASSUME_NONNULL_BEGIN

@interface GXWebImageHelper : NSObject

#if TARGET_OS_WATCH
+ (NSString *)specificSizeKeyForKey:(NSString *)key size:(CGSize)size;
#else
+ (NSString *)specificSizeKeyForKey:(NSString *)key size:(CGSize)size contentMode:(UIViewContentMode)contentMode;
#endif

@end

NS_ASSUME_NONNULL_END
