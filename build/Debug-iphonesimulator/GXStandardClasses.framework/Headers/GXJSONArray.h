//
//  GXJSONArray.h
//  GXStd
//
//  Created by Marcos Crispino on 30/10/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface GXJSONArray : NSObject

- (id)initWithJSONString:(NSString *)jsonStr;

- (NSString *)toJSONString;

- (void)fromJSONString:(NSString *)jsonString;

@end

NS_ASSUME_NONNULL_END
