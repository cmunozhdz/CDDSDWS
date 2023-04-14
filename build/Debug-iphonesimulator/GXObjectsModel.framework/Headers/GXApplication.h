//
//  GXApplication.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 02/09/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXApplicationProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXApplicationEntryPoint : NSObject <NSCoding, GXApplicationEntryPoint>

@property(nonatomic, strong, readonly) NSString *entryPointName;

- (instancetype)initWithName:(NSString *)name
				  properties:(nullable NSDictionary<NSString *, id> *)properties NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

@interface GXApplicationEntryPoint_Menu : GXApplicationEntryPoint
@end

@interface GXApplicationEntryPoint_WorkWith : GXApplicationEntryPoint
@end

@interface GXApplication : NSObject <GXApplication>

@property(nullable, nonatomic, strong) NSURL *serverBaseUrl;
@property(nullable, nonatomic, strong) NSString *desc;
@property(nullable, nonatomic, strong) NSString *user;
@property(nonatomic, assign) NSUInteger mainEntryPointIndex;
@property(nullable, nonatomic, strong) NSArray<__kindof GXApplicationEntryPoint *> *entryPoints;

- (instancetype)initWithServerBaseUrl:(nullable NSURL *)serverBaseUrl NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
