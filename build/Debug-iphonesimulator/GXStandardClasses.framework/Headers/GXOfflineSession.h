//
//  GXOfflineSession.h
//  GXStd
//
//  Created by Marcos Crispino on 19/09/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface GXOfflineSession : NSObject

+ (instancetype)sharedInstance;

+ (instancetype)offlineSession;

- (void)setValueForKey:(NSString *)key value:(nullable id)val;

- (id)getValueForKey:(NSString *)key;

- (void)setObjectForKey:(NSString *)key value:(nullable id)val;

- (id)getObjectForKey:(NSString *)key;

- (void)remove:(NSString *)key;

- (void)clear;

- (void)destroy;

@end

NS_ASSUME_NONNULL_END
