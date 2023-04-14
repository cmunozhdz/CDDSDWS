//
//  GXFoundationObjcConstants.h
//  GXFoundation
//
//  Created by Fabian Inthamoussu on 12/11/20.
//  Copyright © 2020 GeneXus. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - NSError

extern NSString *const GXErrorDomain;
extern NSString *const GXModelErrorDomain;
extern NSString *const GXFatalErrorDomain;
extern NSString *const GXHTTPURLResponseErrorDomain;

extern NSErrorUserInfoKey const GXErrUserInfoKey;

/// User defined values must be >= 100
typedef NSInteger const GXErrCode NS_TYPED_EXTENSIBLE_ENUM;

extern GXErrCode GXErrCodeNoError;
extern GXErrCode GXErrCodeGenericError;
extern GXErrCode GXErrCodeUserCancelled;
extern GXErrCode GXErrCodeInvalidParameter;

typedef NSUInteger GXBackgroundTaskIdentifier;

NS_ASSUME_NONNULL_END
