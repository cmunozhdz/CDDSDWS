//
//  GXPrivateUtilities.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 10/30/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface GXPrivateUtilities : NSObject

+ (NSString *)toBase64:(NSString *)str;

+ (NSString *)fromBase64:(NSString *)base64Str;

@end

NS_ASSUME_NONNULL_END
