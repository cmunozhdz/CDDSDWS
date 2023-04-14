//
//  GXBusinessComponentWithKeyHandler.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 24/10/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

#import <GXDataLayer/GXBusinessComponentHandler.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXBusinessComponentWithKeyHandler : GXBusinessComponentHandler

@property(nonatomic, strong, readonly) id <GXEntityDataKey> key;

- (instancetype)initWithBusinessComponentLevel:(GXBusinessComponentLevel *)bcLevel
									   withKey:(id <GXEntityDataKey>)key NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithBusinessComponentLevel:(GXBusinessComponentLevel *)bcLevel NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
