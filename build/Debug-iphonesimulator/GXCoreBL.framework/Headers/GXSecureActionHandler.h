//
//  GXSecureActionHandler.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 24/01/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@protocol GXEntityData;
@protocol GXActionHandlerDelegate;

@protocol GXSecureActionHandler <NSObject>

- (void)actionAuthorizedExecuteWithContext:(id<GXEntityData>)contextEntityData
								  delegate:(id<GXActionHandlerDelegate>)delegate;

- (NSString *)securityLevel;

@property(nonatomic, strong) id <NSObject> authorizationRequestObject; // Setter should do the same as setAuthorizationRequestObject:newValue cancelCurrentRequest:YES
- (void)setAuthorizationRequestObject:(id <NSObject>)requestObject cancelCurrentRequest:(BOOL)cancel;

@end
