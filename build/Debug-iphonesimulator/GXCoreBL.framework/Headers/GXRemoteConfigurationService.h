//
//  GXRemoteConfigurationService.h
//  GXCoreBL
//
//  Created by Marcos Crispino on 7/5/21.
//  Copyright © 2021 GeneXus. All rights reserved.
//

@import GXFoundation;

NS_ASSUME_NONNULL_BEGIN

@protocol GXRemoteConfigurationService <NSObject>

@property(nullable, nonatomic, readonly, strong) NSDate *lastSuccessfulFetch;

- (BOOL)hasValueForKey:(NSString *)key;

- (nullable NSString *)stringValueForKey:(NSString *)key;

- (nullable NSDate *)dateTimeValueForKey:(NSString *)key;

- (nullable NSDate *)dateValueForKey:(NSString *)key;

- (nullable NSNumber *)numberValueForKey:(NSString *)key;

- (nullable NSDecimalNumber *)decimalNumberValueForKey:(NSString *)key;

- (BOOL)boolValueForKey:(NSString *)key defaultValue:(BOOL)defaultValue NS_REFINED_FOR_SWIFT;
- (GXOptionalBoolean)boolValueForKey:(NSString *)key NS_REFINED_FOR_SWIFT;

@end

NS_ASSUME_NONNULL_END
