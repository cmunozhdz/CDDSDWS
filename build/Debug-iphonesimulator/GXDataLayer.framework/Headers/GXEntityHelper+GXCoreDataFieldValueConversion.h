//
//  GXEntityHelper+GXCoreDataFieldValueConversion.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 12/11/15.
//  Copyright © 2015 Artech. All rights reserved.
//

@import GXObjectsModel;

typedef NS_ENUM(uint_least8_t, GXEntityHelperSDTType) {
	GXEntityHelperSDTTypeAny,
	GXEntityHelperSDTTypeString,
	GXEntityHelperSDTTypeSDTData
};

@interface GXEntityHelper (GXCoreDataFieldValueConversion)

+ (id)coreDataFieldValue:(id <GXEntityDataFieldDescriptor>)fieldDesc
			   fromValue:(id)value;

+ (id)coreDataFieldValueForFieldInfo:(id <GXEntityDataFieldInfo>)fieldInfo
						   fromValue:(id)value NS_SWIFT_NAME(coreDataFieldValueForFieldInfo(_:fromValue:));

+ (id)coreDataFieldValueForFieldInfo:(id <GXEntityDataFieldInfo>)fieldInfo
						   fromValue:(id)value
							 sdtType:(GXEntityHelperSDTType)sdtType NS_SWIFT_NAME(coreDataFieldValueForFieldInfo(_:fromValue:sdtType:)); // allowNull == YES

+ (id)coreDataFieldValueForFieldInfo:(id <GXEntityDataFieldInfo>)fieldInfo
						   fromValue:(id)value
							 sdtType:(GXEntityHelperSDTType)sdtType
						   allowNull:(BOOL)allowNull NS_SWIFT_NAME(coreDataFieldValueForFieldInfo(_:fromValue:sdtType:allowNull:));

+ (id)coreDataEmptyFieldValueForFieldInfo:(id <GXEntityDataFieldInfo>)fieldInfo
								  sdtType:(GXEntityHelperSDTType)sdtType;

@end
