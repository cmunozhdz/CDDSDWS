//
//  GXDeallocBlockExecution.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 15/01/14.
//  Copyright (c) 2014 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

typedef void(^GXDeallocBlockExecutionCallbackBlock)(void);

@interface GXDeallocBlockExecution : NSObject

- (instancetype)initWithCallbackBlock:(nullable GXDeallocBlockExecutionCallbackBlock)block NS_DESIGNATED_INITIALIZER;

@property(nullable, copy) GXDeallocBlockExecutionCallbackBlock callbackBlock;

@end

NS_ASSUME_NONNULL_END
