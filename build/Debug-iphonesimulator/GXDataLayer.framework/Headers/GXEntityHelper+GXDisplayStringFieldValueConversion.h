//
//  GXEntityHelper+GXDisplayStringFieldValueConversion.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 4/4/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import GXObjectsModel;

@interface GXEntityHelper (GXDisplayStringFieldValueConversion)

+ (NSString *)displayStringFieldValue:(id <GXEntityDataFieldDescriptor>)fieldDesc
							 fromData:(id <GXEntityData>)data
					   fieldSpecifier:(NSString *)fieldSpecifier;

/**
 * Returns a string representation for the fieldValue converted according to the fieldDescriptor
 * Do not use this method if the descriptor is a SDT
 */
+ (NSString *)displayStringFieldValue:(id <GXEntityDataFieldDescriptor>)fieldDesc
					   fromFieldValue:(id)fieldValue;

/**
 * Returns a string representation for the fieldValue converted according to the fieldDescriptor
 * If it is a SDT, applies the fieldSpecifier for the given indexer
 */
+ (NSString *)displayStringFieldValue:(id <GXEntityDataFieldDescriptor>)fieldDesc
					   fromFieldValue:(id)fieldValue
					   fieldSpecifier:(NSString *)fieldSpecifier
							  indexer:(NSArray *)indexer;

+ (NSString *)displayStringFieldValueForAttribute:(GXAttributeInfo *)attInfo
								   fromFieldValue:(id)fieldValue;

+ (NSString *)displayStringFieldValueForFieldInfo:(id <GXEntityDataFieldInfo>)fieldInfo
								   fromFieldValue:(id)fieldValue;

@end
