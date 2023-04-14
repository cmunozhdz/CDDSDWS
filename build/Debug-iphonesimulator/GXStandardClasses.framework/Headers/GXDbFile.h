//
//  GXDbFile.h
//  GXStd
//
//  Created by Marcos Crispino on 04/12/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface GXDbFile : NSObject

+ (NSString *)fileName:(NSString *)uri;

+ (NSString *)fileType:(NSString *)uri;

+ (NSString *)uriFromURL:(NSString *)url;

+ (NSString *)uriFromFileName:(NSString *)name type:(NSString *)type;
+ (NSString *)uriFromFileName:(NSString *)name type:(NSString *)type path:(nullable NSString *)path;

+ (NSString *)urlFromBlob:(NSString *)blob uri:(NSString *)uri;

@end

NS_ASSUME_NONNULL_END
