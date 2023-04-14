//
//  GXSdtBusinessComponent.h
//  GXStd
//
//  Created by Alejandro Panizza on 8/7/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import GXFoundation;
@import GXObjectsModel;
#import <GXStandardClasses/GXBusinessComponent.h>
#import <GXStandardClasses/GXFile.h>
#import <GXStandardClasses/GXMessageList.h>
#import <GXStandardClasses/GXEmbeddedModelObject.h>
#import <GXStandardClasses/GXProperties.h>
#import <GXStandardClasses/GXXMLReader.h>
#import <GXStandardClasses/GXXMLWriter.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const GXSdtBusinessComponentDidSaveNotification;
extern NSString *const GXSdtBusinessComponentDidDeleteNotification;
extern NSString *const GXSdtBusinessComponentNotificationModeUserInfoKey; // NSString with GXMode

// Subclasses are generated. Definition must be in ObjC to support XCFrameworks with iOS deployment target lower than 13.0
@interface GXSdtBusinessComponent : GXEmbeddedModelNSObject <GXBCRootSDTDataProtocol, NSCopying> {
@private
	NSDate *_sdtLastModifiedDate;
}

@property (nonatomic, readonly) NSArray<NSString *> *sdtLevelPathNames;
@property (nonatomic, readonly) NSDictionary<NSString *, NSString *> *sdtPropertiesNameMapping;
@property (nonatomic, strong) GXBusinessComponent *transaction;

@property (nonatomic, assign) NSInteger nSOAPErr;
@property (nonatomic, strong) NSString *sSOAPErrMsg;

#pragma mark - Business Components API

// #deprecated: 2021-10-07: Trunk; #to-remove: ???
+ (instancetype)createWithBCName:(NSString *)bcName __deprecated_msg("Use `create(typeName:embeddedModelObject:)` instead");

// #deprecated: 2022-02-16: trunk; #to-remove: ??
+ (nullable instancetype)createWithTypeName:(NSString *)typeName __deprecated_msg("Use `create(typeName:embeddedModelObject:)` instead") NS_SWIFT_NAME(create(typeName:));

+ (nullable GXSdtBusinessComponent *)createWithTypeName:(NSString *)typeName
									embeddedModelObject:(nullable id<GXEmbeddedModelObject>)modelObject NS_SWIFT_NAME(create(typeName:embeddedModelObject:));

- (void)loadKey:(NSArray *)key;

- (void)save;
- (void)delete;
- (void)check;

- (BOOL)insert;
- (BOOL)update;
- (BOOL)insertOrUpdate;

- (BOOL)fail;
- (BOOL)success;

- (NSString *)getMode;

- (NSString *)toJSONString:(BOOL)includeState;
- (NSString *)toJSONString:(BOOL)includeState includeNonInitialized:(BOOL)includeNonInitialized NS_SWIFT_NAME(toJSONString(_:_:));

- (BOOL)fromJSONString:(NSString *)string;
- (BOOL)fromJSONString:(NSString *)string messages:(nullable GXObjectCollection *)messages;

- (BOOL)fromJSONFile:(GXFile *)file;
- (BOOL)fromJSONFile:(GXFile *)file messages:(nullable GXObjectCollection *)messages;

- (NSString *)toxml;
- (NSString *)toxmlIncludeHeader:(BOOL)inclHeader includeState:(BOOL)inclState header:(nullable NSString *)header nameSpace:(nullable NSString *)ns;

- (BOOL)fromxml:(NSString *)xml;
- (BOOL)fromxml:(NSString *)xml messages:(nullable GXObjectCollection *)messages;

- (BOOL)fromxmlfile:(GXFile *)file;
- (BOOL)fromxmlfile:(GXFile *)file messages:(nullable GXObjectCollection *)messages;

- (NSString *)getvalue:(NSString *)fieldName;
- (void)setvalueForKey:(NSString *)key value:(id)value;

- (GXMessageList *)getMessages;

- (void)setDirty:(NSString *)fieldName;
- (BOOL)isDirty:(NSString *)fieldName;

#pragma mark - Abstract methods

- (nullable GXProperties *)getMetadata;

- (nullable id)objectValueForPropertyName:(nonnull NSString *)propName;

- (void)setObjectValue:(nonnull id)value forPropertyName:(nonnull NSString *)propName;

#pragma mark - Helper methods

- (void)loadDefaultValues;

- (id)gxSerialize;
- (id)gxJSONSerialize;
- (id)restParamSerialize;

- (void)loadFromEntiyData:(id<GXEntityData>)entityData;

- (void)loadContentsOfFileWithPath:(NSString *)path onAttributeWithName:(NSString *)attName;

- (void)loadFromSDTData:(id<GXSDTData>)data;
- (BOOL)loadFromValue:(id)value;
- (BOOL)loadFromValue:(id)value error:(out NSError * _Nullable __autoreleasing * _Nullable)error;
- (BOOL)loadFromValue:(id)value useNameConversion:(GXSDTDataUseNameConversionType)useNameConversion error:(out NSError * _Nullable __autoreleasing * _Nullable)error;

- (void)generateSynchronizationSendMessage:(out NSString * _Nonnull __autoreleasing * _Nullable)jsonMsg
							   filesToSend:(out NSArray * _Nullable __autoreleasing * _Nullable)files
						 placeholderFormat:(nullable NSString *)placeholder;

- (nullable id)objectValueForLowercaseFieldName:(NSString *)fieldName;

#pragma mark - Read & write XML (Swift generator base methods)

- (NSInteger)readxml:(GXXMLReader *)reader :(NSString *)name;
- (void)writexml:(GXXMLWriter *)writer :(NSString *)name :(NSString *)nameSpace;
- (void)writexml:(GXXMLWriter *)writer :(NSString *)name :(NSString *)nameSpace :(BOOL)inclState;
- (BOOL)useGeneratedXmlMethods;

@end

NS_ASSUME_NONNULL_END
