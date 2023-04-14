//
//  GXSoapLocation.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 23/04/14.
//  Copyright (c) 2014 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface GXSoapLocation : NSObject

@property(atomic, strong) NSString *name;
@property(atomic, strong) NSString *host;
@property(atomic, assign) NSInteger port;
@property(atomic, strong) NSString *proxyServerHost;
@property(atomic, assign) NSInteger proxyServerPort;
@property(atomic, strong) NSString *baseURL;
@property(atomic, strong) NSString *resourceName;
@property(atomic, assign) NSInteger secure;
@property(atomic, assign) NSInteger timeout;
@property(atomic, assign) NSInteger authenticationMethod;
@property(atomic, strong) NSString *authenticationUser;
@property(atomic, strong) NSString *authenticationRealm;
@property(atomic, strong) NSString *authenticationPassword;
@property(atomic, assign) NSInteger proxyAuthenticationMethod;
@property(atomic, strong) NSString *proxyAuthenticationUser;
@property(atomic, strong) NSString *proxyAuthenticationRealm;
@property(atomic, strong) NSString *proxyAuthenticationPassword;
@property(atomic, strong) NSString *certificate;
@property(atomic, assign) NSInteger authentication;
@property(atomic, assign) NSInteger proxyAuthentication;
@property(atomic, assign) NSInteger cancelOnError;
@property(atomic, strong) NSString *groupLocation;
@property(atomic, strong) NSString *wsdlurl;

@end

NS_ASSUME_NONNULL_END
