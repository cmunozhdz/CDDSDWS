//
//  GXRegEx.h
//  GXStd
//
//  Created by Marcos Crispino on 05/12/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

#import <GXStandardClasses/GXObjectCollection.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXRegEx : NSObject

+ (NSNumber *)lastErrorCode;

+ (NSString *)lastErrorDescription;

+ (GXObjectCollection *)matchInText:(NSString *)text regExp:(NSString *)regExp;

+ (BOOL)isMatchInText:(NSString *)text regExp:(NSString *)regExp;
+ (NSNumber *)gxIsMatch:(NSString *)text regExp:(NSString *)regExp;

+ (NSString *)replaceInText:(NSString *)text regExp:(NSString *)regExp with:(NSString *)repl;

+ (GXObjectCollection *)splitText:(NSString *)text regExp:(NSString *)regExp;

@end

NS_ASSUME_NONNULL_END
