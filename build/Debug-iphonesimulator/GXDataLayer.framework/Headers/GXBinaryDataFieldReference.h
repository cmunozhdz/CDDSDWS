//
//  GXBinaryDataFieldReference.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 23/05/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint_least8_t, GXBinaryDataFieldReferenceType) {
	GXBinaryDataFieldReferenceTypeSingle,
	GXBinaryDataFieldReferenceTypeComposite
};

@interface GXBinaryDataFieldReference : NSObject // Abstract

@property(nonatomic, assign, readonly) GXBinaryDataFieldReferenceType type;
@property(nonatomic, strong, readonly) NSString *name;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithName:(NSString *)name NS_DESIGNATED_INITIALIZER;

@end

extern NSString *const GXSingleBinaryDataFieldReferenceTypedObjectInfoUserInfoKey;
extern NSString *const GXSingleBinaryDataFieldReferenceCallerTypedObjectInfoUserInfoKey;

@interface GXSingleBinaryDataFieldReference : GXBinaryDataFieldReference

/// objectReference could be of be NSURL or NSData
@property(nonatomic, strong, readonly) NSObject *objectReference;
@property(nullable, nonatomic, strong, readwrite) NSString *uploadedObjectId;
@property(nullable, nonatomic, strong, readwrite) NSDictionary<NSString *, id> *userInfo;

- (instancetype)initWithName:(NSString *)name NS_UNAVAILABLE;
- (instancetype)initWithName:(NSString *)name objectReference:(NSObject *)objectReference NS_DESIGNATED_INITIALIZER;

/**
 * Checks if the reference is valid.
 *
 * @discussion For NSData and remote URLs it always returns YES. For file URLs, checks if the file exists
 */
- (BOOL)isValidReference;

/**
 * Returns the file name, if any
 *
 * @return nil for references that are of type NSData and remote URLs
 * @return the file name if the reference is a local file
 */
- (nullable NSString *)objectReferenceName;

@end

@interface GXCompositeBinaryDataFieldReference : GXBinaryDataFieldReference

- (instancetype)initWithName:(NSString *)name NS_UNAVAILABLE;

- (instancetype)initWithName:(NSString *)name
			objectReferences:(NSArray<GXBinaryDataFieldReference *> *)objectReferences
	 objectReferencesIndexes:(nullable NSIndexSet *)indexSet NS_DESIGNATED_INITIALIZER;

- (void)enumerateObjectReferencesWithBlock:(void(^)(GXBinaryDataFieldReference *objRef, NSUInteger idx, BOOL *stop))block;

@end

NS_ASSUME_NONNULL_END
