//
//  GXThemeClass+Protected.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 18/11/15.
//  Copyright © 2015 Artech. All rights reserved.
//

#import <GXObjectsModel/GXThemeClass.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXThemeClass ()

- (instancetype)initWithName:(NSString *)name
	  propertiesValuesByName:(nullable NSDictionary<GXStyleClassPropertyName, id> *)propertiesValuesByName
				  subClasses:(nullable NSArray<__kindof GXThemeClass *> *)subClasses NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

@interface GXThemeClass (Protected)

+ (nullable NSMutableDictionary<GXStyleClassPropertyName, id> *)loadClassSpecificPropertiesValuesByName:(nullable NSMutableDictionary<GXStyleClassPropertyName, id> *)propertyValuesByName
																						   fromMetadata:(NSDictionary<NSString *, id> *)metadata
																					 forStyleObjectType:(GXObjectType)styleObjectType;

+ (Class)themeSubClassClassForFullName:(NSString *)subClassFullName;
+ (NSString *)defautlThemeClassName;

- (nullable NSArray<Class> *)newRequiredSubClassesClassesArray;
- (nullable id)propertyValueForName:(GXStyleClassPropertyName)propertyName recursive:(BOOL)recursive;
- (BOOL)hasAllPropertiesDefault:(BOOL)recursive;

@end

NS_ASSUME_NONNULL_END
