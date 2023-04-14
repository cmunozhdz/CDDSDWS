//
//  GXEntityHelper+GXDomainInfo.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 12/11/15.
//  Copyright © 2015 Artech. All rights reserved.
//

#import <GXObjectsModel/GXEntityHelper.h>
#import <GXObjectsModel/GXEntityDataFieldInfoProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@class GXDomainInfo;

@interface GXEntityHelper (GXDomainInfo)

+ (nullable GXDomainInfo *)domainInfoFromFieldInfo:(nullable id<GXEntityDataFieldInfo>)fieldInfo;

@end

NS_ASSUME_NONNULL_END
