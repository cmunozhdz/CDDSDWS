//
//  GXEntityListOrderProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 23/12/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXEntityDataFieldDescriptorProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXEntityListOrderField;

@protocol GXEntityListOrder <NSObject>

@property(nonatomic, strong, readonly) NSArray<id<GXEntityListOrderField>> *entityListOrderFields;
@property(nonatomic, assign, readonly) BOOL entityListOrderGroupBy;
@property(nonatomic, assign, readonly) NSUInteger entityListOrderGroupByUpToFieldIndex;
@property(nullable, nonatomic, strong, readonly) id <GXEntityDataFieldDescriptor> entityListOrderGroupByDescriptionField;
@property(nonatomic, assign, readonly) BOOL entityListOrderAlphaIndexerEnabled;

@optional

@property(nonatomic, strong, readonly) NSString *entityListOrderName;

@end

@protocol GXEntityListOrderField <GXEntityDataFieldDescriptor>

@property(nullable, nonatomic, strong, readonly) NSString *entityListOrderFieldDescription;
@property(nonatomic, assign, readonly) BOOL entityListOrderAscending;

@end

NS_ASSUME_NONNULL_END
