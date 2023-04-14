//
//  GXConfig.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 5/10/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint_least8_t, GXConfigTimeFormatType) {
    GXConfigTimeFormatAmPm,
    GXConfigTimeFormat24Hs,
};

@interface GXConfig : NSObject

+ (instancetype)sharedInstance;

- (NSString *)dateFormat;

- (GXConfigTimeFormatType)timeFormat;

- (NSString *)decimalSeparator;

- (NSString *)thousandsSeparator;

- (NSNumber *)yearLimit;

- (BOOL)autocommit;

/*!
 Returns the locale identifier (like 'es_ES') form the language name
 
 @param lang The language name, expressed as a three letter code ('spa') or as the full name ('Spanish')
 @result The locale identifier associated to the given language name, or nil if it cannot find the corresponding languuage code
 */
- (NSString *)localeIdentifierFromLanguage:(NSString *)lang;

/*!
 Returns the configuration properties for the current language
 */
- (NSDictionary *)propertiesForCurrentLanguage;

/**
 * Returns the character to be used as a escape character in 'like' comparissions that happen on the client code
 *
 * @return The escape character if set, nil otherwise
 */
- (NSString *)likeEscapeCharacter;

@end

NS_ASSUME_NONNULL_END
