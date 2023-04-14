//
//  GXEntityHelper+GXEntityDataFieldInfo.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 13/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

#import <GXObjectsModel/GXEntityHelper.h>
#import <GXObjectsModel/GXEntityDataFieldInfoProtocol.h>


NS_ASSUME_NONNULL_BEGIN

@interface GXEntityHelper (GXEntityDataFieldInfo)

/// Returns YES if the fieldInfo represents a GXSDTData field (data type is GXDataTypeSDT or field is collection)
+ (BOOL)fieldInfoIsSDTData:(id <GXEntityDataFieldInfo>)fieldInfo;

/// Returns YES if the fieldInfo represents an image field (data type is GXDataTypeBitmap)
+ (BOOL)isImageFieldInfo:(id<GXEntityDataFieldInfo>)fieldInfo;

/// Returns YES if the fieldInfo represents a DateTime with time component (data type is GXDataTypeDateTime & entityDataFieldInfoLength != 0) and current application model's settings convertTimesFromUTC is YES
+ (BOOL)shouldConvertTimeZonesForFieldInfo:(id <GXEntityDataFieldInfo>)fieldInfo;

@end

NS_ASSUME_NONNULL_END
