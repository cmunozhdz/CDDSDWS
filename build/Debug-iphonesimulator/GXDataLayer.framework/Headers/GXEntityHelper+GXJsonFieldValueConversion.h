//
//  GXEntityHelper+GXJsonFieldValueConversion.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 20/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

@import GXFoundation;
@import GXObjectsModel;

@interface GXEntityHelper (GXJsonFieldValueConversion)

+ (id)jsonFieldValueForFieldDescriptor:(id <GXEntityDataFieldDescriptor>)fieldDesc
							  fromData:(id <GXEntityData>)data;

+ (id)jsonFieldValueForFieldDescriptor:(id <GXEntityDataFieldDescriptor>)fieldDesc
							 fromValue:(id)fieldValue;

+ (id)jsonFieldValueForFieldInfo:(id <GXEntityDataFieldInfo>)fieldInfo
					   fromValue:(id)fieldValue;

+ (id)jsonValueFromValue:(id)fieldValue
			 forDataType:(GXDataType)dataType
				decimals:(NSInteger)decimals;

@end
