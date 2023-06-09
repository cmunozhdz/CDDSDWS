//
//  WKTGeometry.h
//
//  WKTParser Geometry
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

@import Foundation;

/**
 This class represent Meta Class WKTGeometry on WKT Format.
 
 It has not String representation.
 
 Parent class of: WKTPoint, WKTPointM, WKTPolygon, WKTPolygonM, WKTLine, WKTLineM, WKTGeometryCollection
 
 */
@interface WKTGeometry : NSObject

/// @name Properties

/**
 Dimensions property
 
 Range is 2 - 3
 */
@property (nonatomic, readwrite) int dimensions;

/**
 isEmpty property: returns True when self.dimensions == 0 (equivalent of toWKT == "<WKT_TYPE> EMTPY"
 */
@property (nonatomic, readonly) BOOL isEmpty;

/**
 Type property
 
 Range is Line, MultiLine, Point, MultiPoint, Polygon, MultiPolygon and GeometryCollection
 */
@property (nonatomic, readwrite, strong) NSString *type;

/**
 GIS property
 
 Range is WGS or EPSG or other Georeference system
 */
@property (nonatomic, readwrite, strong) NSString *gis;

/// @name Constructor

/**
 Basic Constructor that set default values to new instance.
 @return WKTGeometry instance
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;
+ (instancetype)emptyGeography;
+ (NSString *)emptyValue;

@end
