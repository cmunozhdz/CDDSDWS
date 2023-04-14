//
//  GXSynchronization.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 8/5/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface GXSynchronization : NSObject

+ (NSInteger)send;

+ (NSInteger)receive;

+ (NSInteger)status;

+ (NSInteger)setcheckpoint;

@end

NS_ASSUME_NONNULL_END
