//
//  GXTwitterHelper.h
//  GXFlexibleClient
//
//  Created by Alejandro Panizza on 2/12/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import Foundation;
@import GXObjectsModel;
#import <GXCoreBL/GXTwitterService.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXTwitterHelper : NSObject

+ (BOOL)isTwitterServiceAvailable;

@end


@interface GXTwitterHelper (GXLogin)

+ (void)nativeTokenWithCompletion:(void(^)(NSString * _Nullable nativeToken, NSString * _Nullable nativeVerifier, NSError * _Nullable error))completion;

@end


@interface GXTwitterHelper (GXTwitterAPIActions)

+ (void)followUserName:(NSString *)userName
  fromTwitterAccountId:(nullable NSString *)accountId
  userInterfaceContext:(nullable GXUserInterfaceContext *)userInterfaceContext
			completion:(void(^ _Nullable)(NSError * _Nullable error))completion;

+ (void)followUserNameFromSelectedTwitterAccount:(NSString *)userName
							userInterfaceContext:(nullable GXUserInterfaceContext *)userInterfaceContext
									  completion:(void(^ _Nullable)(NSError * _Nullable error))completion;


+ (void)postTweet:(NSString *)text
fromTwitterAccountId:(nullable NSString *)accountId
	   completion:(void(^ _Nullable)(NSError * _Nullable error))completion;

+ (void)postTweetFromSelectedTwitterAccount:(NSString *)text
								 completion:(void(^ _Nullable)(NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
