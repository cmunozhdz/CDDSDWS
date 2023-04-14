//
//  GXEntityDataProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 16/12/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXEntityDataFieldDescriptorProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXEntityDataOverrideValueChangedDelegate

- (void)entityDataOverrideValuesChanged;

@end

@protocol GXEntityData <NSObject>

- (nullable id)valueForEntityDataFieldName:(NSString *)name;
- (nullable id)valueForEntityDataFieldName:(NSString *)name
							fieldSpecifier:(nullable NSString *)fieldSpecifier
						   fieldDescriptor:(nullable id <GXEntityDataFieldDescriptor>)fieldDesc;

- (BOOL)hasValueForEntityDataFieldName:(NSString *)name;

- (nullable NSDictionary<NSString *, id> *)relatedValuesByFieldNameForFieldName:(NSString *)name value:(id)value;

@end

@protocol GXMutableEntityData <GXEntityData>

/**
 * Returns YES if the entity data object is being inserted, NO if it already exists in the database
 */
@property (nonatomic, assign, readonly) BOOL entityDataNew;

/**
 * Returns YES if the entity data object exists in the database and has local changes
 */
@property (nonatomic, assign, readonly) BOOL entityDataUpdated;

@end

@protocol GXBusinessComponentLevelEntityData <GXMutableEntityData>

/**
 * Returns a MD5 hash for the entity (used in REST services)
 */
- (nullable NSString *)entityMD5Hash;

/**
 * Returns set of GXBusinessComponentLevelEntityData for the given level
 */
- (nullable NSSet<id<GXBusinessComponentLevelEntityData>> *)entityChildLevelEntitiesForLevelName:(NSString *)levelName;

@end


extern NSString * const GXEntityDataOverrideValueChangedNotification;

@protocol GXEntityDataWithOverrideValues <GXEntityData>

- (void)addOverrideValuesByFieldName:(NSDictionary<NSString *, id> *)overrideValuesByFieldName;
- (void)setOverrideValueForFieldName:(NSString *)fieldName
                     fieldDescriptor:(nullable id<GXEntityDataFieldDescriptor>)fieldDescriptor
                      fieldSpecifier:(nullable NSString *)fieldSpecifier
                          fieldValue:(nullable id)fieldValue;

- (void)addOverrideValueChangedObserver:(id<GXEntityDataOverrideValueChangedDelegate>)delegate;
- (void)removeOverrideValueChangedObserver:(id<GXEntityDataOverrideValueChangedDelegate>)delegate;

- (nullable NSDictionary<NSString *, id> *)overrideValuesByFieldName;
- (BOOL)hasOverrideValues;

/*!
 Returns a dictionary with the override values, but only for those values\
 that did not change in the parameter entity data.
 
 @param loadedEntityData The loaded entity data to compare override values to detect changes
 @result A dictionary with the override values, but only for those values that did not change in the parameter entity data.
 @discussion
	This method is useful for example after a refresh that brought new data from the server, \
 to keep the values that changed locally, but only if they were not updeted in the Refresh
 */
- (nullable NSDictionary<NSString *, id> *)overrideValuesForValuesUnchangedInEntityData:(id<GXEntityData>)loadedEntityData;

- (BOOL)replaceOverrideValues:(NSDictionary<NSString *, id> *)overrideValuesByFieldName
				forEntityData:(id<GXEntityData>)entityData;

@end

typedef NS_OPTIONS(uint_least8_t, GXEntityDataProtocolsFlags) {
	GXEntityDataProtocolsNone = 0,
	GXEntityDataProtocolEntityData = 1 << 0,
	GXEntityDataProtocolOverrideValues = 1 << 1 | GXEntityDataProtocolEntityData,
	GXEntityDataProtocolMutable = 1 << 2 | GXEntityDataProtocolEntityData,
	GXEntityDataProtocolBusinessComponent = 1 << 3 | GXEntityDataProtocolMutable,
};

GXEntityDataProtocolsFlags GXEntityDataProtocolsFromEntityData(id<GXEntityData> _Nullable entityData);

NS_ASSUME_NONNULL_END
