//
//  GXNamedElement.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 16/12/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface GXNamedElement : NSObject <NSCoding>

@property(nullable, nonatomic, strong, readonly) NSString *name;

- (instancetype)initWithName:(nullable NSString *)name NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
