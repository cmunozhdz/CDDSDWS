//
//  GXWorkWithSectionEntityDataProviderHelper.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 09/11/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import GXObjectsModel;
#import <GXDataLayer/GXWorkWithEntityDataProviderHelper.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXWorkWithSectionListEntityDataProvider <NSObject>

- (instancetype)initWithWorkWithSection:(GXWorkWithSection *)wwSection
						   workWithData:(GXWorkWithData *)wwData;

@end

@interface GXWorkWithSectionEntityDataProviderHelper : GXWorkWithEntityDataProviderHelper

@property(nonatomic, strong, readonly) GXWorkWithSection *workWithSection;

- (instancetype)initWithBaseEntityDataProvider:(GXBaseEntityDataProvider *)provider
							   workWithSection:(GXWorkWithSection *)wwSection NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithBaseEntityDataProvider:(GXBaseEntityDataProvider *)provider
								workWithDetail:(GXWorkWithDetail *)wwDetail NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
