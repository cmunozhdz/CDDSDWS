//
//  GXEntityDataEmpty.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 19/05/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

/**
 * Empty entity data
 * Returns nil when asked for field values
 * Returns YES to hasValueForEntityDataFieldName: if descriptor has field for the given name, NO otherwise
 */
@interface GXEntityDataEmpty : NSObject <GXEntityData>

- (instancetype)init NS_UNAVAILABLE;

+ (id <GXEntityData>)entityDataEmptyWithRequiredProtocols:(GXEntityDataProtocolsFlags)requiredProtocols
											   descriptor:(nullable id<GXEntityDataDescriptor>)descriptor;

@property(nullable, nonatomic, strong, readonly) id <GXEntityDataDescriptor> entityDataDescriptor;

@end

/**
 * In this subclass, when a mutable entity is created in class constructor methods,
 * it returns YES to entityDataNew.
 */
@interface GXNewEntityDataEmpty : GXEntityDataEmpty
@end


#pragma mark -

/**
 * Empty entity data
 * Returns NO to entityDataNew & entityDataUpdated
 */
@interface GXMutableEntityDataEmpty : GXEntityDataEmpty <GXMutableEntityData>
@end


/**
 * Empty entity data
 * Returns nil to entityMD5Hash & entityChildLevelEntitiesForLevelName:
 */
@interface GXBusinessComponentLevelEntityDataEmpty : GXMutableEntityDataEmpty <GXBusinessComponentLevelEntityData>
@end


#pragma mark -

/**
 * New variants returns YES to entityDataNew
 */

@interface GXNewMutableEntityDataEmpty : GXMutableEntityDataEmpty
@end

@interface GXNewBusinessComponentLevelEntityDataEmpty : GXBusinessComponentLevelEntityDataEmpty
@end

NS_ASSUME_NONNULL_END
