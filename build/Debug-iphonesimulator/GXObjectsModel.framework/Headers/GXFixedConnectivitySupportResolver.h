//
//  GXFixedConnectivitySupportResolver.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 15/4/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

#import <GXObjectsModel/GXInheritedConnectivitySupportResolver.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXFixedConnectivitySupportResolver : NSObject <GXInheritedConnectivitySupportResolver>

- (instancetype)initWithResolvedConnectivitySupport:(GXConnectivitySupportType)connectivitySupport NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
