//
//  WKTParser.h
//
//  WKTParser Library
//
//  The MIT License (MIT)
//
//  Copyright (c) 2014 Alejandro Fdez Carrera
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.

#import <GXFoundation/WKTGeometry.h>
#import <GXFoundation/WKTLine.h>
#import <GXFoundation/WKTPoint.h>
#import <GXFoundation/WKTPolygon.h>

/** 
 This class represent Class Parser Utilities.
 
 It is recommend use generic method.
 */

@interface WKTParser : NSObject

/// @name Generic Method

/**
 Return Geometry from String parsed.
 
 @param input String for generate WKTGeometry
 @return WKTGeometry parsed
 */
+ (WKTGeometry *)parseGeometry:(NSString *)input error:(out NSError **)error;

/// @name Generic Method

/**
 Return Geometry from String parsed.
 
 @param input String for generate WKTGeometry
 @return WKTGeometry parsed
 */
+ (WKTGeometry *)parseGeometry:(NSString *)input;


@end

