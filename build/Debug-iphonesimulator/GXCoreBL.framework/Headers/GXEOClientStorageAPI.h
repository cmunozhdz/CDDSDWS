//
//  GXEOClientStorageAPI.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 11/04/14.
//  Copyright (c) 2014 Artech. All rights reserved.
//

@import GXStandardClasses;

NS_ASSUME_NONNULL_BEGIN

@interface GXEOClientStorageAPI : GXExternalObjectBase
@end

@interface GXEOClientStorageAPI (OfflineGenerator)

+ (void)set:(NSString *)key :(NSString *)value GX_WARN_GXOFFLINETHREAD_ONLY_METHOD;

+ (void)secureSet:(NSString *)key :(NSString *)value GX_WARN_GXOFFLINETHREAD_ONLY_METHOD;

+ (NSString *)get:(NSString *)key GX_WARN_GXOFFLINETHREAD_ONLY_METHOD;

+ (void)remove:(NSString *)key GX_WARN_GXOFFLINETHREAD_ONLY_METHOD;

+ (void)clear GX_WARN_GXOFFLINETHREAD_ONLY_METHOD;

@end

NS_ASSUME_NONNULL_END
