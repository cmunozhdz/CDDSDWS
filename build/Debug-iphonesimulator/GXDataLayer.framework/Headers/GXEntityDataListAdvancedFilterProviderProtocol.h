//
//  GXEntityDataListAdvancedFilterProviderProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 16/10/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

#import <GXDataLayer/GXEntityDataListProviderProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXEntityDataListAdvancedFilterProvider <GXEntityDataListProvider>

@property(nullable, nonatomic, strong, readonly) NSArray<id<GXEntityListFilterAdvancedFieldValue>> *advancedFilterValues;
- (BOOL)applyAdvancedFilterValues:(nullable NSArray<id<GXEntityListFilterAdvancedFieldValue>> *)filterValues;

@end

NS_ASSUME_NONNULL_END
