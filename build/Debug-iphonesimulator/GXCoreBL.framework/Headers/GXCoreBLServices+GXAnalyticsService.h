//
//  GXCoreBLServices+GXAnalyticsService.h
//  GXCoreBL
//
//  Created by Marcos Crispino on 29/1/18.
//  Copyright © 2018 GeneXus. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@interface GXCoreBLServices (GXAnalyticsService)

+ (void)registerAnalyticsService:(id<GXAnalyticsService>)analyticsService;

@end

NS_ASSUME_NONNULL_END
