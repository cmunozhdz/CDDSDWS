//
//  GXLoginHandlerCredentials.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 14/1/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface GXLoginHandlerCredentials : NSObject
@end

@protocol GXLoginUsernameAndPasswordHandlerCredentials <NSObject>

@property(nullable, nonatomic, strong, readonly) NSString *username;
@property(nullable, nonatomic, strong, readonly) NSString *password;

@end

@interface GXLoginUsernameAndPasswordHandlerCredentials : GXLoginHandlerCredentials <GXLoginUsernameAndPasswordHandlerCredentials>

- (instancetype)initWithUser:(nullable NSString *)username password:(nullable NSString *)password NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END