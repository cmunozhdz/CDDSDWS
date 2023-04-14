//
//  GXDynamicCallHelper.h
//  GXDataLayer
//
//  Created by Fabian Inthamoussu on 18/1/18.
//  Copyright © 2018 GeneXus. All rights reserved.
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@interface GXDynamicCallHelper : NSObject

+ (nullable NSString *)dynamicObjectTypePrefixFromObjectTypeEnum:(GXObjectType)objType;

+ (NSString *)dynamicObjectPrefixedNameWithObjectName:(NSString *)objectName objectType:(GXObjectType)objectType;

+ (NSString *)dynamicObjectLinkWithDynamicObjectName:(NSString *)dynamicObjectName
									 parameterValues:(NSArray *)paramsValues
								parameterDescriptors:(NSArray<id<GXActionParameterDescriptor>> *)paramsDescriptors
										   fromModel:(GXKBObjectsModel *)model;

+ (void)parseDynamicCallString:(NSString *)dynamicCallString
			  objectTypePrefix:(out NSString * __autoreleasing _Nullable * _Nullable)outObjType
					objectName:(out NSString * __autoreleasing _Nullable * _Nullable)outObjName
			  objectParameters:(out NSArray<id<GXActionParameterDescriptorConstant>> * __autoreleasing _Nullable * _Nullable)outObjParams
				forModelObject:(id<GXModelObject>)modelObject;

+ (nullable GXWorkWithModel *)resolveSdDynamicCallFromObjectName:(NSString *)objNameString
												workWithCallMode:(out GXWorkWithModeType * _Nullable)callMode
											   workWithComponent:(out NSString * __autoreleasing _Nullable * _Nullable)workWithComponent
													   fromModel:(GXKBObjectsModel *)model;

@end

NS_ASSUME_NONNULL_END
