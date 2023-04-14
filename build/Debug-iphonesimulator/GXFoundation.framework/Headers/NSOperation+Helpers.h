//
//  NSOperation+Helpers.h
//  GXFoundation
//
//  Created by José Echagüe on 11/23/22.
//  Copyright © 2022 GeneXus. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface NSBlockOperation (Helpers)

+ (instancetype)blockOperationWithBlock:(void (^)(void))block signPostName:(NSString *)signPostName intervalName:(NSString *)intervalName;

@end

NS_ASSUME_NONNULL_END
