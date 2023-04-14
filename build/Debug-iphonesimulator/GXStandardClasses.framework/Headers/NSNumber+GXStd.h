//
//  NSNumber+GXStd.h
//  GXStd
//
//  Created by Marcos Crispino on 27/06/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;

@interface NSNumber (GXStd)

#pragma clang assume_nonnull begin

- (NSDecimalNumber *)gxNumberToDecimal;

- (NSNumber *)gxModule:(NSNumber *)divisor;

+ (NSDecimalNumber *)gxDecimalByAddingTo:(NSNumber *)n1 number:(NSNumber *)n2;
+ (NSDecimalNumber *)gxDecimalBySubstractingFrom:(NSNumber *)n1 number:(NSNumber *)n2;
+ (NSDecimalNumber *)gxDecimalByMultiplying:(NSNumber *)n1 by:(NSNumber *)n2;
+ (NSDecimalNumber *)gxDecimalByDividing:(NSNumber *)n1 by:(NSNumber *)n2;
+ (NSDecimalNumber *)gxDecimalByNegating:(NSNumber *)n;
+ (NSDecimalNumber *)gxDecimal:(NSNumber *)b toThePower:(NSNumber *)n;

+ (NSNumber *)gxNumberByAddingTo:(NSNumber *)n1 number:(NSNumber *)n2;
+ (NSNumber *)gxNumberBySubstractingFrom:(NSNumber *)n1 number:(NSNumber *)n2;
+ (NSNumber *)gxNumberByMultiplying:(NSNumber *)n1 by:(NSNumber *)n2;
+ (NSNumber *)gxNumberByDividing:(NSNumber *)n1 by:(NSNumber *)n2;
+ (NSNumber *)gxNumberByNegating:(NSNumber *)n;
+ (NSNumber *)gxNumber:(NSNumber *)b toThePower:(NSNumber *)n;

- (NSNumber *)gxIsEmpty;

#pragma clang assume_nonnull end

@end
