//
//  GXFacebookHelper.h
//  GXFlexibleClient
//
//  Created by Alejandro Panizza on 12/14/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;
@import GXObjectsModel;
#import <GXCoreBL/GXFacebookServices.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXFacebookHelper : NSObject

+ (nullable NSString *)currentModelAppId;

@end

/// https://developers.facebook.com/docs/sharing/ios
@interface GXFacebookHelper (GXSharing)

+ (BOOL)shareServiceAvailable;

+ (void)postToWall:(nullable NSString *)name
		   caption:(nullable NSString *)caption
	   description:(nullable NSString *)description
			  link:(nullable NSString *)link
	imageReference:(nullable NSString *)imageReference
		 uiContext:(nullable GXUserInterfaceContext *)uiContext
		completion:(void(^ _Nullable)(NSError * _Nullable error))completion;

+ (void)shareLink:(nonnull NSString *)link
		uiContext:(nullable GXUserInterfaceContext *)uiContext
	   completion:(void(^ _Nullable)(NSError * _Nullable error))completion;

+ (void)shareImageReference:(nonnull NSString *)imageRef
				  uiContext:(nullable GXUserInterfaceContext *)uiContext
				 completion:(void(^ _Nullable)(NSError * _Nullable error))completion;

+ (void)shareVideoReference:(nonnull NSString *)videoRef
				  uiContext:(nullable GXUserInterfaceContext *)uiContext
				 completion:(void(^ _Nullable)(NSError * _Nullable error))completion;

@end

/// Reference: https://developers.facebook.com/docs/facebook-login/ios
@interface GXFacebookHelper (GXLogin)

+ (BOOL)loginServiceAvailable;

+ (void)nativeTokenWithCompletion:(void(^)(NSString * _Nullable nativeToken, NSError * _Nullable error))completion;

@end

/// Reference: https://developers.facebook.com/docs/graph-api/reference/user
@interface GXFacebookHelper (GXGraphAPI_User)

+ (BOOL)coreServiceAvailable;

+ (void)fetchUserDataWithFields:(nullable NSString *)fields
					 completion:(void(^)(NSDictionary * _Nullable userData, NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
