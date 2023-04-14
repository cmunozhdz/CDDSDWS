//
//  GXHttpClient.h
//  GXStd
//
//  Created by Marcos Crispino on 21/11/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;
#import <GXStandardClasses/GXEmbeddedModelObject.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint_least8_t, GXHttpClientAuthenticationType) {
	GXHttpClientAuthenticationBasic = 0,
	GXHttpClientAuthenticationDigest = 1,
	GXHttpClientAuthenticationNtlm = 2,
};

@class GXHttpClient;

@protocol GXHTTPClientDelegate <NSObject>

@optional

- (nullable NSString *)stringBodyForHTTPClient:(nullable GXHttpClient *)client;

@end

#pragma mark -

@interface GXHttpClient: GXEmbeddedModelNSObject

@property (nonatomic, strong) NSString *host;
@property (nonatomic, strong) NSString *baseURL;
@property (nonatomic, strong) NSString *url;
@property (nonatomic, assign) NSInteger port;
@property (nonatomic, assign) BOOL secure;
@property (nonatomic, assign) NSInteger timeout;

@property (nonatomic, assign, readonly) NSInteger statusCode;
@property (nonatomic, strong, readonly) NSString *reasonLine;

@property (nonatomic, assign, readonly) NSInteger errCode;
@property (nonatomic, strong, readonly) NSString *errDescription;

@property (nonatomic, strong) NSString *proxyServerHost;
@property (nonatomic, assign) NSInteger proxyServerPort;

@property (nonatomic, weak, nullable) id<GXHTTPClientDelegate> httpClientDelegate;

@property (nonatomic, strong) NSString *wsdlurl;

@property (nonatomic, assign) BOOL includeCookies;

- (void)addAuthentication:(GXHttpClientAuthenticationType)type realm:(nullable NSString *)realm name:(nullable NSString *)name value:(nullable NSString *)value;

- (void)addHeader:(NSString *)name value:(NSString *)value;

- (void)addVariable:(NSString *)name value:(NSString *)value;

- (void)addString:(NSString *)value NS_SWIFT_NAME(addString(_:));

- (void)addFile:(NSString *)name;

- (void)addFile:(NSString *)name variableName:(NSString *)varName NS_SWIFT_NAME(addFile(_:_:));

- (void)execute:(NSString *)method url:(NSString *)urlStr;

- (NSString *)getHeader:(NSString *)name;

- (NSDictionary *)getHeaders;

- (NSString *)getString;

- (nullable NSData *)getData;

- (BOOL)toFile:(NSString *)path;

@end

NS_ASSUME_NONNULL_END
