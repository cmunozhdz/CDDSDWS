//
//  GXUUID.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 8/2/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface GXUUID : NSObject

+ (instancetype)createUUID;
+ (instancetype)emptyUUID;
+ (instancetype)fromString:(NSString *)uuidString;

- (instancetype)initWithString:(NSString *)uuidString NS_DESIGNATED_INITIALIZER;

@property(strong, readonly) NSString *uuidString;
@property(nonatomic, assign, readonly, getter=isEmpty) BOOL empty;

- (NSString *)stringValue;

@end

NS_ASSUME_NONNULL_END
