//
//  GXEntityHelper+GXAttributeInfo.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 21/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

#import <GXObjectsModel/GXEntityHelper.h>
#import <GXObjectsModel/GXEntityDataFieldInfoProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@class GXAttributeInfo;

@interface GXEntityHelper (GXAttributeInfo)

+ (nullable GXAttributeInfo *)attributeInfoFromFieldInfo:(id <GXEntityDataFieldInfo>)fieldInfo;

@end

NS_ASSUME_NONNULL_END
