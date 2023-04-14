//
//  GXFacebookServices.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 2/3/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import Foundation;
@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@protocol GXFacebookCoreService;
@protocol GXFacebookLoginService;
@protocol GXFacebookShareService;

@protocol GXFacebookServices <NSObject>

@property(nonatomic, strong, readonly) id <GXFacebookCoreService> core;
@property(nullable, nonatomic, strong, readonly) id <GXFacebookLoginService> login;
@property(nullable, nonatomic, strong, readonly) id <GXFacebookShareService> share;

@end



#if TARGET_OS_IOS || TARGET_OS_TV

@protocol GXApplicationOpenURLHandler;

@protocol GXFacebookCoreService <GXApplicationOpenURLHandler>
#else
@protocol GXFacebookCoreService <NSObject>
#endif // TARGET_OS_IOS || TARGET_OS_TV

#pragma mark - Graph API

/// Reference: https://developers.facebook.com/docs/graph-api/reference/user
@property(nonatomic, strong, readonly) NSDictionary<NSString *, NSString *> *defaultUserDataFieldsByPermission;

- (void)fetchUserDataWithFields:(nullable NSString *)fields
					 completion:(void(^)(NSDictionary * _Nullable userData, NSError * _Nullable error))completion;

#pragma mark - UIApplication

#if TARGET_OS_IOS || TARGET_OS_TV
- (BOOL)application:(UIApplication *)app didFinishLaunchingWithOptions:(nullable NSDictionary *)launchOptions;
#endif // TARGET_OS_IOS || TARGET_OS_TV

@end



/// Reference: https://developers.facebook.com/docs/facebook-login/ios
@protocol GXFacebookLoginService <NSObject>

- (void)nativeTokenWithCompletion:(void(^)(NSString * _Nullable nativeToken, NSError * _Nullable error))completion;

@end



/// https://developers.facebook.com/docs/sharing/ios
@protocol GXFacebookShareService <NSObject>

- (void)postToWall:(nullable NSString *)name
		   caption:(nullable NSString *)caption
	   description:(nullable NSString *)description
			  link:(nullable NSString *)link
	imageReference:(nullable NSString *)imageReference
		 uiContext:(nullable GXUserInterfaceContext *)uiContext
		completion:(void(^ _Nullable)(NSError * _Nullable error))completion;

- (void)shareLink:(nonnull NSString *)link
		uiContext:(nullable GXUserInterfaceContext *)uiContext
	   completion:(void(^ _Nullable)(NSError * _Nullable error))completion;

- (void)shareImageReference:(nonnull NSString *)imageReference
				  uiContext:(nullable GXUserInterfaceContext *)uiContext
				 completion:(void(^ _Nullable)(NSError * _Nullable error))completion;

- (void)shareVideoReference:(nonnull NSString *)videoURLStr
				  uiContext:(nullable GXUserInterfaceContext *)uiContext
				 completion:(void(^ _Nullable)(NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
