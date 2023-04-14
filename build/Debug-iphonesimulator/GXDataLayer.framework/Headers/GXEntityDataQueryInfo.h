//
//  GXEntityDataQueryData.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 23/11/11.
//  Copyright (c) 2011 Artech. All rights reserved.
//

#import <GXDataLayer/GXEntityDataQueryInfoProtocol.h>

NS_ASSUME_NONNULL_BEGIN

// ABSTRACT Classes, use Local or Remote subclasses

@interface GXEntityDataQueryInfo : NSObject <GXEntityDataQueryInfo> {
@private
	id <GXEntityDataSourceDescriptor> _dataSource;
	GXEntityDataQueryType _type;
	NSArray *_parameters;
	NSUInteger _gxid;
}

- (instancetype)initWithDataSource:(id <GXEntityDataSourceDescriptor>)dataSource
							  type:(GXEntityDataQueryType)type
						parameters:(nullable NSArray *)parameters
							  gxid:(NSUInteger)gxid NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

@end


@interface GXEntityDataQuerySingleItemInfo : GXEntityDataQueryInfo <GXEntityDataQuerySingleItemInfo>

- (instancetype)initWithSingleItemDataSource:(id <GXSingleItemEntityDataSourceDescriptor>)dataSource
										type:(GXEntityDataQueryType)type
								  parameters:(nullable NSArray *)parameters
										gxid:(NSUInteger)gxid NS_DESIGNATED_INITIALIZER;;
@end


@interface GXEntityDataQueryCollectionInfo : GXEntityDataQueryInfo <GXEntityDataQueryCollectionInfo>

- (instancetype)initWithCollectionDataSource:(id <GXCollectionEntityDataSourceDescriptor>)dataSource
										type:(GXEntityDataQueryType)type
								  parameters:(nullable NSArray *)parameters
										gxid:(NSUInteger)gxid
							   allLoadedData:(BOOL)allLoadedData
									pageSize:(NSUInteger)pageSize
								  orderIndex:(NSUInteger)orderIndex
								  searchText:(nullable NSString *)searchText
							searchFieldIndex:(NSUInteger)searchFieldIndex
						advancedFilterValues:(nullable NSArray<id<GXEntityListFilterAdvancedFieldValue>> *)advancedFilterValues NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
