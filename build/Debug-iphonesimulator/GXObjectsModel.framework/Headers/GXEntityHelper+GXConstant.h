//
//  GXEntityHelper+GXConstant.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 8/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

@import GXFoundation;
#import <GXObjectsModel/GXEntityHelper.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXEntityHelper (GXConstant)

+ (nullable NSDate *)dateValueFromGXConstant:(NSString *)constant;

+ (nullable NSNumber *)numberValueFromGXConstant:(NSString *)constant;

+ (BOOL)parseValue:(id __nullable * __nullable)value
		  dataType:(nullable GXDataType *)dataType
	fromGXConstant:(nullable NSString *)constant;

/// Returns the GX empty value for the given data type
+ (id)emptyValueForDataType:(GXDataType)dType;

/// Returns true if the value parameter is the empty value for the given data type
+ (BOOL)value:(id)value isEmptyValueForDataType:(GXDataType)dType isCollection:(BOOL)isCollection;

@end

NS_ASSUME_NONNULL_END
