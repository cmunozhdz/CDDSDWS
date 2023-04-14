//
//  GXSDObjectLocatorProtocol.h
//  GXFlexibleClient
//
//  Created by willy on 4/9/15.
//  Copyright (c) 2015 Artech. All rights reserved.
//

@import Foundation;
@import GXFoundation;

NS_ASSUME_NONNULL_BEGIN

@protocol GXSDObjectLocator <NSObject>

@property(nonatomic, assign, readonly) GXObjectType gxObjectType;
@property(nonatomic, strong, readonly) NSString *gxObjectName;
@property(nonatomic, strong, readonly) NSString *gxObjectFullName;

@end

NS_ASSUME_NONNULL_END
