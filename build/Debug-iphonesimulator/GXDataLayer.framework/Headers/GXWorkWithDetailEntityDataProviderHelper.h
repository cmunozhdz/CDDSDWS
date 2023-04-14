//
//  GXWorkWithDetailEntityDataProviderHelper.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 09/11/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

#import <GXDataLayer/GXBaseDetailEntityDataProvider.h>
#import <GXDataLayer/GXWorkWithEntityDataProviderHelper.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXWorkWithDetailEntityDataProvider <NSObject>

- (instancetype)initWithWorkWithDetail:(GXWorkWithDetail *)wwDetail;

@end

@protocol GXWorkWithDetailListEntityDataProvider <NSObject>

- (instancetype)initWithWorkWithDetail:(GXWorkWithDetail *)wwDetail
						  workWithData:(GXWorkWithData *)wwData;

@end

@interface GXWorkWithDetailEntityDataProviderHelper : GXWorkWithEntityDataProviderHelper

+ (nullable GXBaseDetailEntityDataProvider *)entityDataDetailProviderForWorkWithComponent:(GXWorkWithDetail *)wwComponent
															   conectivitySupportResolver:(nullable id <GXInheritedConnectivitySupportResolver>)connSupportResolver;
@end

NS_ASSUME_NONNULL_END
