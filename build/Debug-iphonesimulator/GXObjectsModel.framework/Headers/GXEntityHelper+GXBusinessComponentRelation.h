//
//  GXEntityHelper+GXBusinessComponentRelation.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 5/4/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

#import <GXObjectsModel/GXEntityHelper.h>
#import <GXObjectsModel/GXBusinessComponentRelation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXEntityHelper (GXBusinessComponentRelation)

+ (nullable NSDictionary<NSString *, NSString *> *)subTypesFieldNamesMappingForRelation:(GXBusinessComponentRelation *)relation;
+ (nullable NSDictionary<NSString *, NSString *> *)subTypesFieldNamesMappingForRelation:(GXBusinessComponentRelation *)relation
																			 reverseMap:(BOOL)reverseMap;
@end

NS_ASSUME_NONNULL_END
