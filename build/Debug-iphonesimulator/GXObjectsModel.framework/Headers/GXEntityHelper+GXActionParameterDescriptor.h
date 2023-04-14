//
//  GXEntityHelper+GXActionParameterDescriptor.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 12/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

@import GXFoundation;
#import <GXObjectsModel/GXActionParametersDescriptorProtocol.h>
#import <GXObjectsModel/GXEntityHelper.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXEntityHelper (GXActionParameterDescriptor)

+ (nullable NSString *)entityDataFieldNameFromActionParameterDescriptor:(id <GXActionParameterDescriptor>)actionParamDesc;

@end

NS_ASSUME_NONNULL_END
