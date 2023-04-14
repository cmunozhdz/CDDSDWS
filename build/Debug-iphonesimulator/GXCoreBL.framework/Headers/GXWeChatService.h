//
//  GXWeChatService.h
//  GXCoreBL
//
//  Created by José Echagüe on 1/21/20.
//  Copyright © 2020 GeneXus. All rights reserved.
//


NS_ASSUME_NONNULL_BEGIN

@protocol GXWeChatService <NSObject>

#pragma mark Login

- (void)nativeTokenWithCompletion:(void(^)(NSString * _Nullable nativeToken, NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
