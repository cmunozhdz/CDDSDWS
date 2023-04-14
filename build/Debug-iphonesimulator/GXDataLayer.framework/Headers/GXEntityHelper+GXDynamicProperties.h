//
//  GXEntityHelper+GXDynamicProperties.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 20/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

@import GXObjectsModel;
#import <GXDataLayer/GXDynamicPropertiesCollection.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXEntityHelper (GXDynamicProperties)

+ (nullable GXDynamicPropertiesCollection *)parseDynamicPropertiesCollectionFromValue:(nullable id)value;
+ (nullable GXDynamicPropertiesCollection *)parseDynamicPropertiesCollectionFromEntityData:(nullable id<GXEntityData>)entityData;

@end

NS_ASSUME_NONNULL_END
