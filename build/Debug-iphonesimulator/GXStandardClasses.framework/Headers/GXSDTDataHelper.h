//
//  GXSDTDataHelper.h
//  GXStd
//
//  Created by Marcos Crispino on 1/28/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import GXObjectsModel;
#import <GXStandardClasses/GXObjectCollection.h>
#import <GXStandardClasses/GXEmbeddedModelObject.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXSDTDataHelper : NSObject

// #deprecated: 2022-02-16: trunk; #to-remove: ??
+ (id<GXSDTData>)convertSDTData:(id<GXSDTData>)data toClass:(Class)toClass __deprecated_msg("Use `convertSDTData:toClass:embeddedModelObject:` instead");
+ (id<GXSDTData>)convertSDTData:(id<GXSDTData>)data toClass:(Class)toClass embeddedModelObject:(id<GXEmbeddedModelObject>)modelObject;

// #deprecated: 2022-02-16: trunk; #to-remove: ??
+ (GXObjectCollection *)convertSDTData:(id<GXSDTData>)data toObjectCollectionOfType:(NSString *)typeName __deprecated_msg("Use `convertSDTData:toClass:embeddedModelObject:` instead");
+ (GXObjectCollection *)convertSDTData:(id<GXSDTData>)data toObjectCollectionOfType:(NSString *)typeName embeddedModelObject:(id<GXEmbeddedModelObject>)modelObject;

// #deprecated: 2022-02-16: trunk; #to-remove: ??
+ (NSString *)typeNameFromSDTName:(NSString *)sdtName __deprecated_msg("Use `typeNameFromSDTName:embeddedModelObject:` instead");
+ (NSString *)typeNameFromSDTName:(NSString *)sdtName embeddedModelObject:(id<GXEmbeddedModelObject>)modelObject;

// #deprecated: 2022-02-16: trunk; #to-remove: ??
+ (id<GXSDTData>)sdtDataWithTypeName:(NSString *)typeName value:(id)value isCollection:(BOOL)isCollection __deprecated_msg("Use `sdtDataWithTypeName:value:isCollection:embeddedModelObject:` instead");
+ (id<GXSDTData>)sdtDataWithTypeName:(NSString *)typeName value:(id)value isCollection:(BOOL)isCollection embeddedModelObject:(id<GXEmbeddedModelObject>)modelObject;
// #deprecated: 2022-02-16: trunk; #to-remove: ??
+ (id<GXSDTData>)sdtDataWithTypeName:(NSString *)typeName value:(id)value __deprecated_msg("Use `sdtDataWithTypeName:value:embeddedModelObject:` instead");
+ (id<GXSDTData>)sdtDataWithTypeName:(NSString *)typeName value:(id)value embeddedModelObject:(id<GXEmbeddedModelObject>)modelObject;
// #deprecated: 2022-02-16: trunk; #to-remove: ??
+ (id<GXSDTDataCollection>)sdtDataCollectionWithTypeName:(NSString *)typeName value:(id)value __deprecated_msg("Use `sdtDataCollectionWithTypeName:value:embeddedModelObject:` instead");
+ (GXObjectCollection *)sdtDataCollectionWithTypeName:(NSString *)typeName value:(id)value embeddedModelObject:(id<GXEmbeddedModelObject>)modelObject;

+ (NSArray *)arrayFromSDTDataCollection:(id<GXSDTDataCollection>)collection;

@end

NS_ASSUME_NONNULL_END
