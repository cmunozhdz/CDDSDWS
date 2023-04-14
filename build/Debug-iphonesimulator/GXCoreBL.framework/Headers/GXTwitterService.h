//
//  GXTwitterService.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 2/3/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@protocol GXTwitterService <NSObject>

@property(nullable, nonatomic, strong, readonly) NSString *selectedTwitterAccountIdentifier;

/// Clears selectedTwitterAccountIdentifier
- (void)revokeAccountAuthorization;

#pragma mark Login

- (void)nativeTokenWithCompletion:(void(^)(NSString * _Nullable nativeToken, NSString * _Nullable nativeVerifier, NSError * _Nullable error))completion;

#pragma mark API Actions

- (void)followUserName:(NSString *)userName
  fromTwitterAccountId:(nullable NSString *)accountId
  userInterfaceContext:(nullable GXUserInterfaceContext *)userInterfaceContext
			completion:(void(^ _Nullable)(NSError * _Nullable error))completion;

- (void)postTweet:(NSString *)text
fromTwitterAccountId:(nullable NSString *)accountId
	   completion:(void(^ _Nullable)(NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
