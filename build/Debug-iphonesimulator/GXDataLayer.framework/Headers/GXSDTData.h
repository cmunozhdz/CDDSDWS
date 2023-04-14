//
//  GXSDTData.h
//  GXFlexibleClient
//
//  Created by willy on 8/17/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@interface GXSDTData : NSObject <GXSDTData>

- (instancetype)init NS_UNAVAILABLE;

/*!
 Returns a not nil instance of id <GXSDTData> (even if value is nil) from value for the given fieldInfo.
 
 @param fieldInfo Field info of the SDTData. Must be not nil and entityDataFieldInfoIsCollection = YES or based on SDT level.
 @param value Value to initialize the SDTData. Must be nil, [NSNull null], id <GXSDTData>, a NSString with the JSON representation, a NSArray/NSOrderedSet if is a collection or NSDictionary if is not a collection.
 @result A not nill instance of id <GXSDTData>.
 @discussion If the given value conforms to GXSDTData protocol, it is returned, otherwise a new instance is created.
 */
+ (id <GXSDTData>)sdtDataFromFieldInfo:(id <GXEntityDataFieldInfo>)fieldInfo value:(nullable id)value;

/*!
 Returns a not nil instance of id <GXSDTData> (even if value is nil) from value for the given SDT field info.
 
 @param sdtFieldInfo SDT field info. Must be not nil.
 @param value Value to initialize the collection. Must be nil, [NSNull null], id <GXSDTData>, a NSString with the JSON representation, a NSArray/NSOrderedSet if is a collection or NSDictionary if is not a collection.
 @param fieldIsCollection YES if the field is marked as collection (entityDataFieldInfoIsCollection of the field which resolved into sdtFieldInfo, NOT sdtFieldInfo.entityDataFieldInfoIsCollection), and NO otherwise.
 @result A new instace initialized with the given value.
 @discussion If the given value conforms to GXSDTData protocol, it is returned, otherwise a new instance is created. If both fieldIsCollection and sdtFieldInfo.entityDataFieldInfoIsCollection equals YES, then is a collection of a collection SDT level.
 */
+ (id <GXSDTData>)sdtDataFromStructureDataTypeFieldInfo:(id<GXEntityDataSDTFieldInfo>)sdtFieldInfo value:(nullable id)value fieldIsCollection:(BOOL)fieldIsCollection;

/*!
 Returns a not nil instance of id <GXSDTData> (even if value is nil) from value for the given level info.
 
 @param sdtLevelInfo SDT level info. Must be not nil.
 @param value Value to initialize the collection. Must be nil, [NSNull null], id <GXSDTData>, a NSString with the JSON representation, a NSArray/NSOrderedSet if is a collection or NSDictionary if is not a collection.
 @param fieldIsCollection YES if the field is marked as collection (entityDataFieldInfoIsCollection), and NO otherwise.
 @result A new instace initialized with the given value.
 @discussion Consider using sdtDataFromStructureDataTypeFieldInfo:value:fieldIsCollection: instead. If the given value conforms to GXSDTData protocol, it is returned, otherwise a new instance is created. If both fieldIsCollection and [levelInfo isCollection] equals YES, then is a collection of a collection SDT level.
 */
+ (id <GXSDTData>)sdtDataFromStructureDataTypeLevelInfo:(GXStructureDataTypeLevelInfo *)sdtLevelInfo value:(nullable id)value fieldIsCollection:(BOOL)fieldIsCollection;

/*!
 Creates a new GXSDTData from value for the given fieldInfo.
 
 @param fieldInfo Field info of the SDTData. Must be not nil and entityDataFieldInfoIsCollection = YES or based on SDT level.
 @result A new GXSDTData instance.
 */
+ (__kindof GXSDTData *)newEmptySdtDataFromFieldInfo:(id<GXEntityDataFieldInfo>)fieldInfo;

/*!
 Creates a new GXSDTData from value for the given SDT field info.
 
 @param sdtFieldInfo SDT field info. Must be not nil.
 @param fieldIsCollection YES if the field is marked as collection (entityDataFieldInfoIsCollection), and NO otherwise.
 @result A new GXSDTData instance.
 @discussion If both fieldIsCollection and sdtFieldInfo.entityDataFieldInfoIsCollection equals YES, then is a collection of a collection SDT level.
 */
+ (__kindof GXSDTData *)newEmptySdtDataFromStructureDataTypeFieldInfo:(id<GXEntityDataSDTFieldInfo>)sdtFieldInfo fieldIsCollection:(BOOL)fieldIsCollection;

/// Consider using newEmptySdtDataFromStructureDataTypeFieldInfo:fieldIsCollection: instead

/*!
 Creates a new GXSDTData from value for the given SDT level info.
 
 @param sdtLevelInfo SDT level info. Must be not nil.
 @param fieldIsCollection YES if the field is marked as collection (entityDataFieldInfoIsCollection), and NO otherwise.
 @result A new GXSDTData instance.
 @discussion Consider using newEmptySdtDataFromStructureDataTypeFieldInfo:fieldIsCollection: instead. If both fieldIsCollection and [levelInfo isCollection] equals YES, then is a collection of a collection SDT level.
 */
+ (__kindof GXSDTData *)newEmptySdtDataFromStructureDataTypeLevelInfo:(GXStructureDataTypeLevelInfo *)sdtLevelInfo fieldIsCollection:(BOOL)fieldIsCollection;

@end



@interface GXSDTDataCollection : GXSDTData <GXSDTDataCollection>
@end



@interface GXSDTData (Helpers)

/// Returns YES if the fieldInfo represents a GXSDTData field (data type is GXDataTypeSDT or field is collection)
+ (BOOL)fieldInfoIsSDTData:(id<GXEntityDataFieldInfo>)fieldInfo;

/// Helper method, implementation looks for a the GXEntityDataSDTFieldInfo given typeName in modelObject  and calls sdtDataFromStructureDataTypeLeveInfo:value:fieldIsCollection:
+ (id<GXSDTData>)sdtDataFromStructureDataTypeName:(NSString *)typeName
									  modelObject:(id<GXModelObject>)modelObject
											value:(nullable id)value
								fieldIsCollection:(BOOL)fieldIsCollection;

// #deprecated: 2022-02-01: trunk; #to-remove: ??
+ (id<GXSDTData>)sdtDataFromStructureDataTypeName:(NSString *)typeName
											value:(nullable id)value
								fieldIsCollection:(BOOL)fieldIsCollection __attribute__((deprecated("Use sdtDataFromStructureDataTypeName:modelObject:value:fieldIsCollection: instead")));

/// Helper method, implementation looks for a the GXEntityDataSDTFieldInfo given typeName and calls newEmptySdtDataFromStructureDataTypeFieldInfo:fieldIsCollection:
+ (__kindof GXSDTData *)newEmptySdtDataFromStructureDataTypeName:(NSString *)typeName
													 modelObject:(id<GXModelObject>)modelObject
											   fieldIsCollection:(BOOL)fieldIsCollection;

// #deprecated: 2022-02-01: trunk; #to-remove: ??
+ (__kindof GXSDTData *)newEmptySdtDataFromStructureDataTypeName:(NSString *)typeName
											   fieldIsCollection:(BOOL)fieldIsCollection __attribute__((deprecated("Use newEmptySdtDataFromStructureDataTypeName:modelObject:fieldIsCollection: instead")));

/// Returns YES if both, sdtData and object (SDTData or String), represents the same SDT (excluding sdtLastModifiedDate)
+ (BOOL)sdtData:(id<GXSDTData>)sdtData isEqualToObject:(id)object;

@end

NS_ASSUME_NONNULL_END
