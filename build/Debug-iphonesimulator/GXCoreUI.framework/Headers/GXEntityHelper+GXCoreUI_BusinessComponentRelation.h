//
//  GXEntityHelper+GXCoreUI_BusinessComponentRelation.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 5/4/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import GXObjectsModel;
#import <GXCoreUI/GXEntityModelProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXEntityHelper (GXCoreUI_BusinessComponentRelation)

+ (nullable NSDictionary<NSString *, GXBusinessComponentRelation *> *)relationsByDataElementNameForModel:(id<GXEntityModel>)componentModel
																						   layoutElement:(id<GXLayoutElement>)layoutElement
																						fieldDescriptors:(nullable NSArray<id<GXEntityDataFieldDescriptor>> *)fieldDescriptors
																			 useBestDataElementForPicker:(BOOL)useBestDataElementForPicker
																									mode:(GXModeType)mode;

@end

NS_ASSUME_NONNULL_END
