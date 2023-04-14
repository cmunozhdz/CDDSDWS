//
//  GXEncryption.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 13/01/14.
//  Copyright (c) 2014 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface GXEncryption : NSObject

+ (NSString *)getNewKey;

+ (NSString *)encrypt64:(NSString *)text key:(NSString *)key;

+ (NSString *)decrypt64:(NSString *)text key:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
