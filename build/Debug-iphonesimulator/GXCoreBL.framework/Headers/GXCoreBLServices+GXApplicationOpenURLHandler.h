//
//  GXCoreBLServices+GXApplicationOpenURLHandler.h
//  GXCoreBL
//
//  Created by Fabian Inthamoussu on 15/2/17.
//  Copyright © 2017 GeneXus. All rights reserved.
//

#import <GXCoreBL/GXCoreBLServices.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXApplicationOpenURLHandler <NSObject>

- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey, id> *)options NS_AVAILABLE_IOS(9_0);

@end



@interface GXCoreBLServices (GXApplicationOpenURLHandler)

/// openURLHandler is not retained
+ (void)registerApplicationOpenURLHandler:(id<GXApplicationOpenURLHandler>)openURLHandler forURLScheme:(nullable NSString *)scheme;

+ (void)unregisterApplicationOpenURLHandler:(id<GXApplicationOpenURLHandler>)openURLHandler forURLScheme:(nullable NSString *)scheme;

@end

NS_ASSUME_NONNULL_END
