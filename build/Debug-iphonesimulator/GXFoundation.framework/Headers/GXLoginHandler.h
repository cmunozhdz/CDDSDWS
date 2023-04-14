//
//  GXLoginHandler.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 02/12/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;
#import <GXFoundation/GXLoginHandlerCredentials.h>

@class GXLoginHandler;

NS_ASSUME_NONNULL_BEGIN

@protocol GXLoginHandlerDelegate <NSObject>

@optional
- (void)loginDidSuccess:(GXLoginHandler *)handler;
- (void)login:(GXLoginHandler *)handler didFailWithError:(NSError *)error;
- (void)login:(GXLoginHandler *)handler didFailWithUserMustChangePasswordError:(NSError *)error;
- (void)login:(GXLoginHandler *)handler didFailWithUserMustProvideSecondFactorError:(NSError *)error;

- (void)logoutDidSuccess:(GXLoginHandler *)handler;
- (void)logout:(GXLoginHandler *)handler didFailWithError:(NSError *)error;

@end


@interface GXLoginHandler : NSObject

@property(nullable, nonatomic, strong, readonly) GXLoginHandlerCredentials *loginCredentials;
@property(nonatomic, assign, readonly, getter=isActive) BOOL active; // Abstract
@property(nullable, weak) id <GXLoginHandlerDelegate> delegate;

- (void)loginWithCredentials:(GXLoginHandlerCredentials *)credentials; // Base implementation only assigns self.loginCredentials = credentials
- (void)logout; // Base implementation only clears self.loginCredentials = nil
- (void)cancel; // Base implementation only clears self.loginCredentials = nil

@end

NS_ASSUME_NONNULL_END
