//
//  GXStyleClassHelper.h
//  GXObjectsModel
//
//  Created by Fabian Inthamoussu on 15/4/21.
//  Copyright © 2021 GeneXus. All rights reserved.
//

@import GXFoundation;
#import <GXObjectsModel/GXStyleClass.h>
#import <GXObjectsModel/GXStyleClassPropertyName.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXStyleClassHelper : NSObject

+ (nullable NSMutableDictionary<GXStyleClassPropertyName, id> *)loadPropertiesValuesByName:(nullable NSMutableDictionary<GXStyleClassPropertyName, id> *)propertyValuesByName
																			  fromMetadata:(NSDictionary<NSString *, id> *)metadata
																		forStyleObjectType:(GXObjectType)styleObjectType; // Abstract

@end

@protocol GXStyleClassProvider <NSObject>

@property(nonnull, nonatomic, readonly) GXStyleClass *styleClass;

@end

NS_ASSUME_NONNULL_END
