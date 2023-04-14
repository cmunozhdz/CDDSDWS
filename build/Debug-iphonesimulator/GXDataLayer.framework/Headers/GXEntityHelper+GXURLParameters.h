//
//  GXEntityHelper+GXURLParameters.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 29/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, GXEntityHelperURLParameterFormat) {
	GXEntityHelperURLParameterFormatJSON,
	GXEntityHelperURLParameterFormatWeb
};

@interface GXEntityHelper (GXURLParameters)

+ (NSDictionary<NSString *, NSString *> *)urlParametersFromDescriptor:(id <GXEntityDataDescriptor>)descriptor
																 data:(id <GXEntityData>)data; // format:JSON
+ (NSDictionary<NSString *, NSString *> *)urlParametersFromDescriptor:(id <GXEntityDataDescriptor>)descriptor
																 data:(id <GXEntityData>)data
															   format:(GXEntityHelperURLParameterFormat)format;

+ (NSDictionary<NSString *, NSString *> *)urlParametersFromFieldsDescriptors:(NSArray<id<GXEntityDataFieldDescriptor>> *)fieldsDescriptors
																fieldsValues:(NSArray *)fieldsValues; // format:JSON
+ (NSDictionary<NSString *, NSString *> *)urlParametersFromFieldsDescriptors:(NSArray<id<GXEntityDataFieldDescriptor>> *)fieldsDescriptors
																fieldsValues:(NSArray *)fieldsValues
																	  format:(GXEntityHelperURLParameterFormat)format;

+ (void)urlParametersFromFieldsDescriptors:(NSArray<id<GXEntityDataFieldDescriptor>> *)fieldsDescriptors
							  fieldsValues:(NSArray *)fieldsValues
						 urlParameterNames:(out NSArray<NSString *> * __autoreleasing __nonnull * __nonnull)urlParamNames
						urlParameterValues:(out NSArray<NSString *> * __autoreleasing __nonnull * __nonnull)urlParamValues; // format:JSON
+ (void)urlParametersFromFieldsDescriptors:(NSArray<id<GXEntityDataFieldDescriptor>> *)fieldsDescriptors
							  fieldsValues:(NSArray *)fieldsValues
									format:(GXEntityHelperURLParameterFormat)format
						 urlParameterNames:(out NSArray<NSString *> * __autoreleasing __nonnull * __nonnull)urlParamNames
						urlParameterValues:(out NSArray<NSString *> * __autoreleasing __nonnull * __nonnull)urlParamValues;

+ (NSArray<NSString *> *)urlParametersArrayFromEntityDataKey:(id <GXEntityDataKey>)key; // format:JSON
+ (NSArray<NSString *> *)urlParametersArrayFromEntityDataKey:(id <GXEntityDataKey>)key
													  format:(GXEntityHelperURLParameterFormat)format;

+ (NSArray<NSString *> *)urlParametersArrayFromFieldsDescriptors:(NSArray<id<GXEntityDataFieldDescriptor>> *)fieldsDescriptors
													fieldsValues:(NSArray *)fieldsValues; // format:JSON
+ (NSArray<NSString *> *)urlParametersArrayFromFieldsDescriptors:(NSArray<id<GXEntityDataFieldDescriptor>> *)fieldsDescriptors
													fieldsValues:(NSArray *)fieldsValues
														  format:(GXEntityHelperURLParameterFormat)format;

+ (NSArray<NSString *> *)urlParametersArrayFromFieldsInfo:(NSArray<id<GXEntityDataFieldInfo>> *)fieldsInfo
											 fieldsValues:(NSArray *)fieldsValues; // format:JSON
+ (NSArray<NSString *> *)urlParametersArrayFromFieldsInfo:(NSArray<id<GXEntityDataFieldInfo>> *)fieldsInfo
											 fieldsValues:(NSArray *)fieldsValues
												  format:(GXEntityHelperURLParameterFormat)format;

@end

NS_ASSUME_NONNULL_END
