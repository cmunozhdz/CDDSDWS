//
//  NSDate+Helpers.h
//  GXStd
//
//  Created by Marcos Crispino on 26/06/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface NSDate (Helpers)

- (NSDate *)gxDateByAddingDateComponents:(NSDateComponents *)components;
- (NSDate *)gxDateTimeByAddingDateComponents:(NSDateComponents *)components;

@end

NS_ASSUME_NONNULL_END
