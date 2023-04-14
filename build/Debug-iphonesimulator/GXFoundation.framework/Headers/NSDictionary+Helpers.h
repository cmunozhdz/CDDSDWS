//
//  NSDictionary+Helpers.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 27/10/11.
//  Copyright (c) 2011 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface NSDictionary<__covariant KeyType, __covariant ObjectType> (Helpers)

- (NSDictionary<NSString *, ObjectType> *)dictionaryWithLowercaseKeys;

- (NSDictionary<id, ObjectType> *)dictionaryWithKeyConvertionBlock:(id (^)(KeyType key))block;

- (nullable ObjectType)synchronizedObjectForKey:(KeyType)key;

@end

NS_ASSUME_NONNULL_END
