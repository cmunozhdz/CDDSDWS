//
//  GXProperty.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 10/01/14.
//  Copyright (c) 2014 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface GXProperty : NSObject

@property (nonatomic, strong) NSString *key;
@property (nonatomic, strong) NSString *value;

- (instancetype)initWithKey:(NSString *)key value:(NSString *)value NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END