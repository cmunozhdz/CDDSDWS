//
//  GXEntityDataListBreakByProviderProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 16/10/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import GXObjectsModel;
#import <GXDataLayer/GXEntityDataListProviderProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXEntityDataListBreakByProvider <GXEntityDataListProvider>

@property(nullable, nonatomic, strong, readonly) id<GXEntityListBreakBy> breakBy;

@end

NS_ASSUME_NONNULL_END
