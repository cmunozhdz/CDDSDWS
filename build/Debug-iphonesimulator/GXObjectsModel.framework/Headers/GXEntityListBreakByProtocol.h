//
//  GXEntityListBreakByProtocol.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 27/01/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXEntityDataFieldDescriptorProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXEntityListBreakByField <GXEntityDataFieldDescriptor>
@end

@protocol GXEntityListBreakBy <NSObject>

@property(nonatomic, strong, readonly) NSArray<id<GXEntityListBreakByField>> *entityListBreakByFields;
@property(nullable, nonatomic, strong, readonly) id <GXEntityListBreakByField> entityListBreakByDescriptionField;

@end

NS_ASSUME_NONNULL_END
