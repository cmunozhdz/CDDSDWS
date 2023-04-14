//
//  GXEntityDataQueryResultProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 29/10/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@protocol GXEntityDataQueryResult <NSObject>

@property(nullable, nonatomic, strong, readonly) id resultData; // id<GXEntityData> or NSArray<NSArray<id<GXEntityData>> *> if entityDataSourceIsCollection
@property(nullable, nonatomic, strong, readonly) NSError *error;
@property(nullable, nonatomic, strong, readonly) NSDate *timeStamp;

- (BOOL)isSuccessful;

@end

@protocol GXEntityDataQuerySingleItemResult <GXEntityDataQueryResult>

@property(nullable, nonatomic, strong, readonly) id <GXEntityData> dataItem;

@end

@protocol GXEntityDataQueryCollectionResult <GXEntityDataQueryResult>

@property(assign, readonly)	NSUInteger count;
@property(assign, readonly, getter=isComplete) BOOL complete;
@property(nullable, nonatomic, strong, readonly) NSArray<NSArray<id<GXEntityData>> *> *dataItems; // @[section[row]]
@property(nullable, nonatomic, strong, readonly) NSArray<NSString *> *alphaIndexTitles;
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, NSValue *> *alphaIndexRangesByTitle;

@end

NS_ASSUME_NONNULL_END
