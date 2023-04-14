//
//  GXGAMLoginHandler+Public.h
//  GXGAM
//
//  Created by Fabian Inthamoussu on 23/2/18.
//  Copyright © 2018 GeneXus. All rights reserved.
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@interface GXGAMLoginHandler : GXLoginHandler

- (instancetype)init NS_UNAVAILABLE;

@end



@interface GXGAMLoginHandler (Helpers)

+ (BOOL)gettingTokensMayBlockCallingThreadForModel:(nullable GXModel *)model;
+ (BOOL)hasSecurityTokenForModel:(nullable GXModel *)model;
+ (nullable NSString *)securityTokenForModel:(nullable GXModel *)model;
+ (BOOL)hasValidSecurityTokenForModel:(nullable GXModel *)model;
+ (nullable NSString *)validSecurityTokenForModel:(nullable GXModel *)model;
+ (void)invalidateTokenForModel:(nullable GXModel *)model;
+ (BOOL)hasDeviceToken:(nullable GXModel *)model; // A Login Token is stored from a Device Login
+ (nullable NSDate *)tokenTimeStampForModel:(nullable GXModel *)model;

+ (BOOL)hasValidRefreshTokenForModel:(nullable GXModel *)model;
+ (nullable NSString *)validRefreshTokenForModel:(nullable GXModel *)model;

+ (nullable NSString *)validGAMUserGUIDForModel:(nullable GXModel *)model;
+ (nullable NSDictionary<NSString *, id> *)gamLoadedUserInformationFromModel:(nullable GXModel *)model;

@end

NS_ASSUME_NONNULL_END
