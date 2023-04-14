//
//  NSException+Swift.h
//  GXFoundation
//
//  Created by Fabian Inthamoussu on 16/11/20.
//  Copyright © 2020 GeneXus. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface NSException (Swift)

+ (void)gxTryBlock:(void(^_Nullable)(void))tryBlock;

+ (void)gxTryBlock:(void(^_Nullable)(void))tryBlock
		catchBlock:(void(^_Nullable)(NSException *))catchBlock;

+ (void)gxTryBlock:(void(^_Nullable)(void))tryBlock
	  finallyBlock:(void(^_Nullable)(void))finallyBlock;

+ (void)gxTryBlock:(void(^_Nullable)(void))tryBlock
		catchBlock:(void(^_Nullable)(NSException *))catchBlock
	  finallyBlock:(void(^_Nullable)(void))finallyBlock;

@end

NS_ASSUME_NONNULL_END
