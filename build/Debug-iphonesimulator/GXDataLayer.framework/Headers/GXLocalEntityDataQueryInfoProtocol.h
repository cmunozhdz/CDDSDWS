//
//  GXLocalEntityDataQueryInfoProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 17/9/14.
//  Copyright (c) 2014 Artech. All rights reserved.
//

@import GXObjectsModel;
#import <GXDataLayer/GXEntityDataQueryInfoProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXLocalEntityDataQueryInfo <GXEntityDataQueryInfo>
@end

@protocol GXLocalEntityDataQuerySingleItemInfo <GXEntityDataQuerySingleItemInfo, GXLocalEntityDataQueryInfo>
@end

@protocol GXLocalEntityDataQueryCollectionInfo <GXEntityDataQueryCollectionInfo, GXLocalEntityDataQueryInfo>

/*!
 Number of already loaded entities
 
 @discussion Valid only if pageSize > 0 and (allLoadedData = YES or type = GXEntityDataQueryTypeMore), otherwise may return 0.
 */
@property(nonatomic, assign, readonly) NSUInteger loadedEntitiesCount;

/*!
 Already loaded entities
 
 @discussion Valid only if pageSize > 0 and allLoadedData = NO and type = GXEntityDataQueryTypeMore, otherwise may return nil.
 If not nil, [loadedEntities count] must be equals to loadedEntitiesCount.
 */
@property(nullable, nonatomic, strong, readonly) NSArray<id<GXEntityData>> *loadedEntities;

@end

NS_ASSUME_NONNULL_END
