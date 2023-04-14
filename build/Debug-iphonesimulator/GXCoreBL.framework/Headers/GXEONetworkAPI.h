//
//  GXEONetworkAPI.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 5/9/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import GXFoundation;
@import GXStandardClasses;

NS_ASSUME_NONNULL_BEGIN

@interface GXEONetworkAPI : GXExternalObjectBase

+ (nullable NSString *)applicationServerURLForModelObject:(id<GXModelObject>)modelObject;

+ (void)setApplicationServerURL:(NSString *)urlString modelObject:(id<GXModelObject>)modelObject NS_SWIFT_NAME(setApplicationServerURL(_:for:));

+ (void)isServerAvailableForModelObject:(id<GXModelObject>)modelObject completionBlock:(void(^)(BOOL serverAvailable))block;
+ (void)isServerAvailable:(NSString *)urlString modelObject:(id<GXModelObject>)modelObject completionBlock:(void(^)(BOOL serverAvailable))block;

+ (void)connectionTypeForModelObject:(id<GXModelObject>)modelObject completionBlock:(void(^)(GXNetworkStatusType connectionType))block;
+ (void)connectionType:(NSString *)urlString modelObject:(id<GXModelObject>)modelObject completionBlock:(void(^)(GXNetworkStatusType connectionType))block;

+ (void)isTrafficBasedCostForModelObject:(id<GXModelObject>)modelObject completionBlock:(void(^)(BOOL trafficBasedCost))block;
+ (void)isTrafficBasedCost:(NSString *)urlString modelObject:(id<GXModelObject>)modelObject completionBlock:(void(^)(BOOL trafficBasedCost))block;

@end


@interface GXEONetworkAPI (OfflineGenerator)

@property(nonatomic, readonly) NSString *applicationserverurl;

+ (NSString *)applicationServerURL GX_WARN_GXOFFLINETHREAD_ONLY_METHOD;
+ (void)setApplicationServerURL:(NSString *)urlString GX_WARN_GXOFFLINETHREAD_ONLY_METHOD NS_SWIFT_NAME(setApplicationServerURL(_:));

+ (BOOL)isserveravailable GX_WARN_GXOFFLINETHREAD_ONLY_METHOD;
+ (BOOL)isserveravailable:(NSString *)urlString NS_SWIFT_NAME(isserveravailable(_:)) GX_WARN_GXOFFLINETHREAD_ONLY_METHOD;

+ (NSInteger)connectiontype GX_WARN_GXOFFLINETHREAD_ONLY_METHOD;
+ (NSInteger)connectiontype:(NSString *)urlString NS_SWIFT_NAME(connectiontype(_:)) GX_WARN_GXOFFLINETHREAD_ONLY_METHOD;

+ (BOOL)trafficbasedcost GX_WARN_GXOFFLINETHREAD_ONLY_METHOD;
+ (BOOL)trafficbasedcost:(NSString *)urlString NS_SWIFT_NAME(trafficbasedcost(_:)) GX_WARN_GXOFFLINETHREAD_ONLY_METHOD;

@end

NS_ASSUME_NONNULL_END
