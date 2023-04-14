//
//  GXDynamicDataServiceProtocol.h
//  GXFlexibleClient
//
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXActionParametersDescriptorProtocol.h>
#import <GXObjectsModel/GXModelObjectProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXDynamicDataService <GXModelObject, NSObject>

@property(nonatomic, strong, readonly) NSString *dynamicDataServiceName;
@property(nonatomic, strong, readonly) NSArray<id<GXActionParameterDescriptor>> *dynamicDataServiceParameters;

@end

#pragma mark -

@protocol GXRemoteDynamicDataService <GXDynamicDataService>

@property(nonatomic, strong, readonly) NSString *dynamicDataServiceUrlString;

@end

#pragma mark -

@protocol GXLocalDynamicDataService <GXDynamicDataService>

@property(nonatomic, strong, readonly) NSString *dynamicDataServiceOfflineClassName;
@property(nullable, nonatomic, assign, readonly) SEL dynamicDataServiceSelector;

@end

NS_ASSUME_NONNULL_END
