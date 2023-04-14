//
//  GXStyleClass+Protected.h
//  GXObjectsModel
//
//  Created by Fabian Inthamoussu on 11/3/21.
//  Copyright © 2021 GeneXus. All rights reserved.
//

#import <GXObjectsModel/GXObjectsModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXStyleClass ()

- (instancetype)initWithName:(NSString *)name
	  propertiesValuesByName:(nullable NSDictionary<GXStyleClassPropertyName, id> *)propertiesValuesByName NS_DESIGNATED_INITIALIZER;

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

@interface GXStyleClass (Protected)

+ (NSMutableDictionary<GXStyleClassPropertyName, id> *)loadPropertiesValuesByName:(NSMutableDictionary<GXStyleClassPropertyName, id> *)propertyValuesByName
																	 fromMetadata:(nullable NSDictionary<NSString *, id> *)metadata;

- (void)replaceDefinitionWithMetadata:(nullable NSDictionary<NSString *, id> *)metadata;

@end

NS_ASSUME_NONNULL_END
