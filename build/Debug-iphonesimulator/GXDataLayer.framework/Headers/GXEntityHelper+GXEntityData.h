//
//  GXEntityHelper+GXEntityData.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 20/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

@import GXObjectsModel;
#import <GXDataLayer/GXEntityDataDetailProviderProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXEntityHelper (GXEntityData)

+ (BOOL)isEntityData:(nullable id<GXEntityData>)data1
		 equalToData:(nullable id<GXEntityData>)data2
		  descriptor:(nullable id<GXEntityDataDescriptor>)descriptor; // nilDescMeansEquals = NO

+ (BOOL)isEntityData:(nullable id<GXEntityData>)data1
		 equalToData:(nullable id<GXEntityData>)data2
		  descriptor:(nullable id<GXEntityDataDescriptor>)descriptor
  nilDescMeansEquals:(BOOL)nilDescriptorMeansEquals;

+ (BOOL)isEntityData:(nullable id<GXEntityData>)data1
		 equalToData:(nullable id<GXEntityData>)data2
comparingFieldDescriptors:(NSArray<id<GXEntityDataFieldDescriptor>> *)fieldDescriptors;

/*!
 Checks if the given entity data is empty and has no fields
 
 @param entityData Entity data to check
 @result YES if the given entity data is empty and has no fields, NO otherwise
 @discussion An entity data is considered empty if valueForEntityDataFieldName: will return always nil, and to have no field if hasValueForEntityDataFieldName: will return allways NO. Passing nil returns YES.
 */
+ (BOOL)isEntityDataEmptyWithoutFields:(nullable id<GXEntityData>)entityData;

+ (nullable NSArray *)entityDataFieldsValuesForDescriptor:(nullable id<GXEntityDataDescriptor>)descriptor
													 data:(nullable id<GXEntityData>)data;

+ (NSArray *)entityDataFieldsValuesForFieldNames:(nullable NSArray<NSString *> *)fieldNames
								  fromEntityData:(nullable id <GXEntityData>)data;


+ (nullable id)updateEntityData:(id<GXEntityDataWithOverrideValues>)entityData
			 forFieldDescriptor:(id<GXEntityDataFieldDescriptor>)fieldDescriptor
		 indexedFfieldSpecifier:(nullable NSString *)fieldSpecifier
			  resolvedFieldInfo:(id<GXEntityDataFieldInfo>)resolvedFieldInfo
					  withValue:(nullable id)newValue; // allowNull == YES

+ (nullable id)updateEntityData:(id<GXEntityDataWithOverrideValues>)entityData
			 forFieldDescriptor:(id<GXEntityDataFieldDescriptor>)fieldDescriptor
		 indexedFfieldSpecifier:(nullable NSString *)fieldSpecifier
			  resolvedFieldInfo:(id<GXEntityDataFieldInfo>)resolvedFieldInfo
					  withValue:(nullable id)newValue
					  allowNull:(BOOL)allowNull;

+ (nullable id<GXEntityDataWithOverrideValues>)entityDataFromEntityDataDetailProvider:(id<GXEntityDataDetailProvider>)provider
																				 mode:(GXModeType)mode;

@end

NS_ASSUME_NONNULL_END
