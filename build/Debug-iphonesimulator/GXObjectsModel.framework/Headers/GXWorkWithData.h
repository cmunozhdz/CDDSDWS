//
//  GXWorkWithData.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 10/12/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXWorkWithDataBase.h>
#import <GXObjectsModel/GXWorkWithOrders.h>
#import <GXObjectsModel/GXWorkWithFilter.h>
#import <GXObjectsModel/GXWorkWithBreakBy.h>
#import <GXObjectsModel/GXWorkWithCacheProperties.h>
#import <GXObjectsModel/GXWorkWithParameters.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXWorkWithData : GXWorkWithDataBase

@property(nonatomic, strong, readonly) NSString *dataProviderName;
@property(nullable, nonatomic, strong, readonly) GXWorkWithParameters *dataProviderParameters;
@property(nullable, nonatomic, strong, readonly) GXWorkWithOrders *orders;
@property(nullable, nonatomic, strong, readonly) GXWorkWithFilter *filter;
@property(nullable, nonatomic, strong, readonly) GXWorkWithBreakBy *breakBy;
@property(nullable, nonatomic, strong, readonly) NSString *bcName;
@property(nonatomic, assign, readonly) UInt32 refreshTimeout;
@property(nullable, nonatomic, strong, readonly) GXWorkWithCacheProperties *cacheProperties;
@property(nonatomic, assign, readonly) BOOL onlyDefinition;
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, __kindof GXWorkWithDataElement *> *ignoreOutputElementsByName;

- (instancetype)initWithElements:(nullable NSArray<__kindof GXWorkWithDataElement *> *)elements
				dataProviderName:(NSString *)dataProviderName
		  dataProviderParameters:(nullable GXWorkWithParameters *)dataProviderParameters
						  orders:(nullable GXWorkWithOrders *)orders
						  filter:(nullable GXWorkWithFilter *)filter
						 breakBy:(nullable GXWorkWithBreakBy *)breakBy
					isCollection:(BOOL)isCollection
						 timeout:(unsigned int)timeout
						  bcName:(nullable NSString *)bcName
						   level:(nullable NSString *)level
				 cacheProperties:(nullable GXWorkWithCacheProperties *)cacheProperties
				  onlyDefinition:(BOOL)onlyDefinition
					   sublevels:(nullable NSArray<GXWorkWithDataSublevel *> *)sublevels
			ignoreOutputElements:(nullable NSArray<__kindof GXWorkWithDataElement *> *)ignoreOutputElements
				  forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithElements:(nullable NSArray<__kindof GXWorkWithDataElement *> *)elements
						   level:(nullable NSString *)level
					   sublevels:(nullable NSArray<GXWorkWithDataSublevel *> *)sublevels
				  forModelObject:(nullable id<GXModelObject>)modelObject NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

#pragma mark - Helper methods

+ (nullable GXWorkWithData *)workWithDataForDataProviderName:(nullable NSString *)dataProviderName
														from:(nullable NSArray<GXWorkWithData *> *)dataArray;

@end

NS_ASSUME_NONNULL_END
