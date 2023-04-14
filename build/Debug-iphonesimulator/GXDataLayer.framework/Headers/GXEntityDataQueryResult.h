//
//  GXEntityDataQueryResult.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 24/11/11.
//  Copyright (c) 2011 Artech. All rights reserved.
//

@import GXObjectsModel;
#import <GXDataLayer/GXEntityDataQueryResultProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXEntityDataQueryResult : NSObject <GXEntityDataQueryResult> // ABASTRACT

- (instancetype)initWithResultData:(nullable id)resultData
						 timeStamp:(nullable NSDate *)timeStamp
							 error:(nullable NSError *)error NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)entityDataQueryResultWithError:(nullable NSError *)error;

@end

@interface GXEntityDataQuerySingleItemResult : GXEntityDataQueryResult <GXEntityDataQuerySingleItemResult>

+ (instancetype)entityDataQueryResultWithResultData:(nullable id<GXEntityData>)resultData
										  timeStamp:(nullable NSDate *)timeStamp;

@end

@interface GXEntityDataQueryCollectionResult : GXEntityDataQueryResult <GXEntityDataQueryCollectionResult>

- (instancetype)initWithResultData:(nullable NSArray<NSArray<id<GXEntityData>> *> *)resultData
						 timeStamp:(nullable NSDate *)timeStamp
							 error:(nullable NSError *)error
							 count:(NSUInteger)count
						  complete:(BOOL)complete
				  alphaIndexTitles:(nullable NSArray<NSString *> *)alphaIndexTitles
		   alphaIndexRangesByTitle:(nullable NSDictionary<NSString *, NSValue *> *)alphaIndexRangesByTitle NS_DESIGNATED_INITIALIZER;

+ (instancetype)entityDataQueryResultWithResultData:(nullable NSArray<NSArray<id<GXEntityData>> *> *)resultData
										  timeStamp:(nullable NSDate *)timeStamp
											  count:(NSUInteger)count
										   complete:(BOOL)complete
								   alphaIndexTitles:(nullable NSArray<NSString *> *)alphaIndexTitles
							alphaIndexRangesByTitle:(nullable NSDictionary<NSString *, NSValue *> *)alphaIndexRangesByTitle;

@end

NS_ASSUME_NONNULL_END
