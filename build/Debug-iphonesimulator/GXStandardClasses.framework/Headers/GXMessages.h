//
//  GXMessages.h
//  GXStd
//
//  Created by Marcos Crispino on 21/08/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface GXMessages : NSObject

+ (NSString *)getMessage:(NSString *)msgKey;
+ (NSString *)getMessage:(NSString *)msgKey language:(NSString *)lang;
+ (NSString *)getMessage:(NSString *)msgKey arguments:(NSArray *)args;

@end

NS_ASSUME_NONNULL_END
