//
//  GXEntityHelper+GXDataLayer_EntityDataDescriptor.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 18/1/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@interface GXEntityHelper (GXDataLayer_EntityDataDescriptor)

+ (id <GXEntityDataDescriptor>)onlyInOrInoutParamersDataDescriptorFromParametersDescriptor:(id <GXParametersDescriptor>)paramsDescriptor;

@end

NS_ASSUME_NONNULL_END
