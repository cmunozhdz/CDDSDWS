//
//  GXLanguage.h
//  GXFlexibleClient
//
//  Created by Guillermo Pasquero on 11/1/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXNamedModelObjectChild.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXLanguage : GXNamedModelObjectChild

- (instancetype)initWithName:(NSString *)name
				translations:(NSDictionary<NSString *, NSString *>*)translations
				languageCode:(nullable NSString *)languageCode
				 countryCode:(nullable NSString *)countryCode
				  properties:(nullable NSDictionary<NSString *, id> *)properties
			  forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithName:(nullable NSString *)name forModelObject:(nullable id<GXModelObject>)modelObject NS_UNAVAILABLE;

- (NSString *)translationFor:(NSString *)message; // Same as [self translationFor:message notFoundMessage:message]
- (nullable NSString *)translationFor:(NSString *)message notFoundMessage:(nullable NSString *)notFoundTranslationMessage;

@property(nonnull, nonatomic, strong, readonly) NSString *name;
@property(nullable, nonatomic, strong, readonly) NSString *languageCode;
@property(nullable, nonatomic, strong, readonly) NSString *countryCode;
@property(nullable, nonatomic, strong, readonly) NSString *dateFormat;
@property(nullable, nonatomic, strong, readonly) NSString *timeFormat;

@end

NS_ASSUME_NONNULL_END
