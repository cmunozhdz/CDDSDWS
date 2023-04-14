//
//  GXLayoutLocatorProtocol.h
//  GXFlexibleClient
//
//  Created by willy on 4/9/15.
//  Copyright (c) 2015 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXSDObjectLocatorProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXLayoutLocator <GXSDObjectLocator>

@property(nullable, nonatomic, strong, readonly) NSString *layoutLocatorLayoutId;

@end

NS_ASSUME_NONNULL_END
