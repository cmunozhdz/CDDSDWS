//
//  GXModel+GXSecureData.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 14/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

#import <GXObjectsModel/GXModel.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint_least8_t, GXSecureDataSharingType) {
	GXSecureDataSharingTypePrivate,
	GXSecureDataSharingTypeShared,
	GXSecureDataSharingTypeAny
};

@interface GXModel (GXSecureData)

- (nullable NSString *)secureDataForKey:(NSString *)key;
- (nullable NSString *)secureDataForKey:(NSString *)key shared:(GXSecureDataSharingType)shared;
- (nullable NSString *)secureDataForKey:(NSString *)key sharedTypes:(NSArray<NSNumber *> *)sharedTypes; // sharedTypes = @[@(GXSecureDataSharingType)]
- (nullable NSString *)secureDataForKey:(NSString *)key domain:(nullable NSString *)domain;
- (nullable NSString *)secureDataForKey:(NSString *)key domain:(nullable NSString *)domain shared:(GXSecureDataSharingType)shared;
- (nullable NSString *)secureDataForKey:(NSString *)key domain:(nullable NSString *)domain sharedTypes:(NSArray<NSNumber *> *)sharedTypes;
- (nullable NSString *)secureDataForKey:(NSString *)key domain:(nullable NSString *)domain shared:(GXSecureDataSharingType)shared error:(NSError *__autoreleasing*)error;
- (nullable NSString *)secureDataForKey:(NSString *)key domain:(nullable NSString *)domain shared:(GXSecureDataSharingType)shared attributes:(nullable NSDictionary<NSString *, id> *)attributes error:(NSError *__autoreleasing*)error;
- (nullable NSString *)secureDataForKey:(NSString *)key domain:(nullable NSString *)domain sharedTypes:(NSArray<NSNumber *> *)sharedTypes error:(NSError *__autoreleasing*)error;

- (nullable NSError *)setSecureData:(NSString *)data key:(NSString *)key;
- (nullable NSError *)setSecureData:(NSString *)data key:(NSString *)key shared:(GXSecureDataSharingType)shared;
- (nullable NSError *)setSecureData:(NSString *)data key:(NSString *)key domain:(nullable NSString *)domain;
- (nullable NSError *)setSecureData:(NSString *)data key:(NSString *)key domain:(nullable NSString *)domain shared:(GXSecureDataSharingType)shared;
- (nullable NSError *)setSecureData:(NSString *)data key:(NSString *)key domain:(nullable NSString *)domain shared:(GXSecureDataSharingType)shared attributes:(nullable NSDictionary<NSString *, id> *)attributes;

- (nullable NSError *)removeSecureDataForKey:(NSString *)key;
- (nullable NSError *)removeSecureDataForKey:(NSString *)key shared:(GXSecureDataSharingType)shared;
- (nullable NSError *)removeSecureDataForKey:(NSString *)key domain:(nullable NSString *)domain;
- (nullable NSError *)removeSecureDataForKey:(NSString *)key domain:(nullable NSString *)domain shared:(GXSecureDataSharingType)shared;

- (nullable NSError *)removeAllSecureDataForDomain:(NSString *)domain shared:(GXSecureDataSharingType)shared;

@end

NS_ASSUME_NONNULL_END
