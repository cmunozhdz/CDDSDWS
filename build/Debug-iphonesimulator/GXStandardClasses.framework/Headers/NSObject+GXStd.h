//
//  NSObject+GXStd.h
//  GXStd
//
//  Created by Marcos Crispino on 27/06/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (GXStd)

+ (BOOL)gxObjectIsNull:(nullable NSObject *)obj;

- (NSComparisonResult)gxCompare:(id)obj;

@end

NS_ASSUME_NONNULL_END
