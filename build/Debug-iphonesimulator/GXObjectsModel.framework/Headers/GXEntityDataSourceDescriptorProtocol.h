//
//  GXEntityDataSourceDescriptorProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 23/11/11.
//  Copyright (c) 2011 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXEntityDataDescriptorProtocol.h>
#import <GXObjectsModel/GXEntityDataKeyDescriptorProtocol.h>
#import <GXObjectsModel/GXEntityListBreakByProtocol.h>
#import <GXObjectsModel/GXEntityListFilterAdvancedProtocol.h>
#import <GXObjectsModel/GXEntityListFilterSearchProtocol.h>
#import <GXObjectsModel/GXEntityListOrderProtocol.h>
#import <GXObjectsModel/GXParametersDescriptorProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXEntityDataSourceSublevelDescriptor;

@protocol GXEntityDataSourceLevelDescriptor <NSObject>

@property(nullable, nonatomic, strong, readonly) id <GXEntityDataDescriptor> entityDataSourceDataDescriptor;
@property(nullable, nonatomic, strong, readonly) id <GXEntityDataKeyDescriptor> entityDataSourceKeyDescriptor;
@property(nullable, nonatomic, strong, readonly) id <GXEntityDataKeyDescriptor> entityDataSourceStorageKeyDescriptor;
@property(nonatomic, assign, readonly) BOOL entityDataSourceIsCollection;
@property(nullable, nonatomic, strong, readonly) NSArray<GXEntityDataSourceSublevelDescriptor> *entityDataSourceSublevels;

@property(nullable, nonatomic, strong, readonly) NSString *entityDataSourceLevelName;

@end

@protocol GXEntityDataSourceSublevelDescriptor <GXEntityDataSourceLevelDescriptor>

@property(nullable, nonatomic, weak, readonly) id<GXEntityDataSourceLevelDescriptor> entityDataSourceParentLevel;
@property(nonnull, nonatomic, strong, readonly) NSString *entityDataSourceLevelName;

@end

@protocol GXEntityDataSourceDescriptor <GXEntityDataSourceLevelDescriptor>

@property(nullable, nonatomic, strong, readonly) NSString *entityDataSourceDataProviderName;
@property(nonatomic, assign, readonly) BOOL entityDataSourceOnlyDefinition;
@property(nullable, nonatomic, strong, readonly) id <GXParametersDescriptor> entityDataSourceParametersDescriptor;

- (nullable id <GXEntityDataFieldDescriptor>)entityDataSourceIgnoreOutputFieldDescriptorForName:(NSString *)fieldName;

// Auto-Refresh
@property(nonatomic, assign, readonly) unsigned int entityDataSourceRefreshTimeoutLapse;

// Business Component
@property(nullable, nonatomic, strong, readonly) NSString *entityDataSourceBusinessComponentName;

@end

@protocol GXCollectionEntityDataSourceDescriptor <GXEntityDataSourceDescriptor>

@property(nullable, nonatomic, strong, readonly) id <GXEntityListFilterSearch> entityDataSourceFilterSearch;
@property(nullable, nonatomic, strong, readonly) id <GXEntityListFilterAdvanced> entityDataSourceFilterAdvanced;
@property(nullable, nonatomic, strong, readonly) NSArray<id<GXEntityListOrder>> *entityDataSourceOrders;
@property(nullable, nonatomic, strong, readonly) id<GXEntityListBreakBy> entityDataSourceBreakBy;

@end

@protocol GXSingleItemEntityDataSourceDescriptor <GXEntityDataSourceDescriptor>

@end

NS_ASSUME_NONNULL_END
