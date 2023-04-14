//
//  GXEntityDataListOrderProviderProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 16/10/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import GXObjectsModel;
#import <GXDataLayer/GXEntityDataListProviderProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXEntityDataListOrderProvider <GXEntityDataListProvider>

@property(nonatomic, assign, readonly) NSUInteger orderIndex;
@property(nullable, nonatomic, strong, readonly) id <GXEntityListOrder> order;
- (void)applyOrderAtIndex:(NSUInteger)orderIndex;
@property(nullable, nonatomic, strong, readonly) NSArray<NSString *> *orderAlphaIndexTitles; // Collection of NSString with first character title of loaded sections
- (NSRange)orderSectionsRangeForAlphaIndexTitle:(NSString *)title;

@end

#pragma mark - GXEntityDataListOrderProviderDelegate

@protocol GXEntityDataListOrderProviderDelegate <GXEntityDataListProviderDelegate>

@optional
- (void)entityDataListProvider:(id <GXEntityDataListOrderProvider>)provider orderDidChange:(nullable id <GXEntityListOrder>)order;

@end

NS_ASSUME_NONNULL_END
