//
//  NSString+Base64.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 23/11/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;

@interface NSString (Base64)

+ (NSString *)base64StringFromData:(NSData *)data;

@end
