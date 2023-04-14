//
//  NSString+GXStd.h
//  GXStd
//
//  Created by Marcos Crispino on 27/06/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface NSString (GXStd)


// #deprecated: 2021-10-26: trunk; #to-remove: ??
- (NSNumber *)gxAsciiValue __attribute__((deprecated("Use gxUnicodeValue instead")));
// #deprecated: 2021-10-26: trunk; #to-remove: ??
+ (NSString *)gxFromAsciiValue:(NSNumber *)val __attribute__((deprecated("Use gxFromUnicodeValue: instead")));

- (NSString *)gxStringByConcatenatingWithString:(NSString *)str separator:(nullable NSString *)sep;
- (NSString *)gxStringByConcatenatingWithString:(NSString *)str;

- (BOOL)gxIsLikeString:(NSString *)pattern;
- (BOOL)gxIsLikeString:(NSString *)pattern useEscapeCharacter:(BOOL)useEscChar;

- (NSString *)gxStringByTrimmingRight;
- (NSString *)gxStringByTrimmingLeft;
- (NSString *)gxStringByTrimming;

+ (NSString *)gxStringWithFormat:(NSString *)format, ...;
+ (NSString *)gxStringWithFormat:(NSString *)format arguments:(va_list)argList;
+ (NSString *)gxStringWithFormat:(NSString *)format values:(NSArray *)values;

+ (NSString *)gxNewLine;

- (NSString *)gxStringOfLengthByAppendingBlanksOnLeft:(NSNumber *)length;
- (NSString *)gxStringOfLength:(NSNumber *)length byAppendingLeftOccurrencesOfString:(NSString *)str;

- (NSString *)gxStringOfLengthByAppendingBlanksOnRight:(NSNumber *)length;
- (NSString *)gxStringOfLength:(NSNumber *)length byAppendingRightOccurrencesOfString:(NSString *)str;

+ (NSString *)gxStringFromNumber:(NSNumber *)num;
+ (NSString *)gxStringFromNumber:(NSNumber *)num totalLength:(NSNumber *)length;
+ (NSString *)gxStringFromNumber:(NSNumber *)num totalLength:(NSNumber *)length decimals:(NSNumber *)dec;
+ (NSString *)gxStringFromNumber:(NSNumber *)num totalLength:(NSNumber *)length decimals:(NSNumber *)dec decimalSeparator:(NSString *)dSep thousandSeparator:(NSString *)tSep;

- (NSNumber *)gxSearchFor:(NSString *)searchString;
- (NSNumber *)gxSearchFor:(NSString *)searchString start:(NSNumber *)start;
- (NSNumber *)gxSearchBackwardFor:(NSString*)searchString;
- (NSNumber *)gxSearchBackwardFor:(NSString*)searchString start:(NSNumber *)start;

- (NSString *)gxSearchAndReplace:(NSString *)searchString with:(NSString *)replaceString;

- (NSString *)gxSubstringFrom:(NSNumber *)from;
- (NSString *)gxSubstringFrom:(NSNumber *)from length:(NSNumber *)len;

- (NSNumber *)gxNumericValue;
- (NSNumber *)gxNumericValueWithSeparator:(NSString*)sep;

- (NSDecimalNumber *)gxDecimalValue;
- (NSDecimalNumber *)gxDecimalValueWithSeparator:(NSString*)sep;

- (NSNumber *)gxBooleanValue;

- (NSNumber *)gxLength;
- (NSNumber *)gxIsEmpty;

- (NSString *)gxStringByRemovingDiacritics;

- (NSString *)gxJSONEncode;

- (BOOL)gxStartsWith:(NSString *)str;
- (NSNumber *)gxStartsWith2:(NSString *)str;

- (BOOL)gxEndsWith:(NSString *)str;
- (NSNumber *)gxEndsWith2:(NSString *)str;

- (BOOL)gxContains:(NSString *)str;
- (NSNumber *)gxContains2:(NSString *)str;

- (NSString *)gxCharAt:(NSNumber *)idx;

@end

@interface NSString (CommonImplementations)

// This methods are used both from NSString+GXStd and Swift's String+GXStd extensions
// The NSString extension is used for evaluating expressions and the String extension is used in Swift generated code

// #deprecated: 2021-11-05: trunk; #to-remove: ??
- (NSInteger)impl_gxAsciiValue __attribute__((deprecated("Use gxUnicodeValue instead")));
 
- (NSString *)impl_gxStringOfLength:(NSInteger)length byAppendingLeftOccurrencesOfString:(NSString *)str;

- (NSString *)impl_gxStringOfLength:(NSInteger)length byAppendingRightOccurrencesOfString:(NSString *)str;

- (NSInteger)impl_gxSearchFor:(NSString *)searchString start:(NSInteger)start;
- (NSInteger)impl_gxSearchBackwardFor:(NSString *)searchString start:(NSInteger)start;

@end

NS_ASSUME_NONNULL_END
