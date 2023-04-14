//
//  GXApplicationModel.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 05/08/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import GXFoundation;
#import <GXObjectsModel/GXApplication.h>
#import <GXObjectsModel/GXApplicationProtocol.h>
#import <GXObjectsModel/GXKBObjectsModel.h>

NS_ASSUME_NONNULL_BEGIN

@class GXApplicationSettings;

@interface GXApplicationModel : GXKBObjectsModel

@property(nonatomic, strong, readonly) NSURL *serverBaseUrl;
@property(nonatomic, assign, readonly) GXApplicationServerType serverType;
@property(nonatomic, strong, readonly) GXApplicationEntryPoint *mainEntryPoint;
@property(nonatomic, strong, readonly) NSString *uuid;
@property(nonatomic, assign, readonly) UInt32 version;
@property(nonatomic, assign, readonly) UInt32 minorVersion;
@property(nonatomic, assign, readonly) UInt32 majorVersion;
@property(nullable, nonatomic, strong, readonly) GXReachability *hostReachability;
@property(nonatomic, strong, readonly) GXApplicationSettings *settings;
@property (nonatomic, assign, readonly) BOOL enableTestMode;

- (instancetype)initWithObjectModelsById:(nullable NSDictionary <NSString *, NSDictionary<NSString *, __kindof GXNamedElement<GXModelObject> *> *> *)objectModels
							   resources:(GXResources *)resources
						  forModelObject:(nullable id<GXModelObject>)modelObject NS_UNAVAILABLE;

- (instancetype)initWithAppServerBaseUrl:(NSURL *)serverBaseUrl
							  serverType:(GXApplicationServerType)serverType
								 appUUID:(nullable NSString *)appUUID
								 version:(UInt32)version
							minorVersion:(UInt32)minorVersion
							majorVersion:(UInt32)majorVersion
							  entryPoint:(GXApplicationEntryPoint *)entryPoint
						objectModelsById:(nullable NSDictionary <NSString *, NSDictionary<NSString *, __kindof GXNamedElement<GXModelObject> *> *> *)objectModels
							   resources:(GXResources *)resources
								settings:(GXApplicationSettings *)settings
						  forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;


- (nullable GXSDObjectModel *)mainEntryPointObjectModel;

@end

@interface GXApplicationModel (GXApplication) <GXApplication>

#pragma mark Nonnull GXApplication overrides

@property(nonatomic, strong, readonly) NSURL *appServerBaseUrl;
@property(nonatomic, strong, readonly) NSString *appName;
@property(nonatomic, strong, readonly) id <GXApplicationEntryPoint> appEntryPoint;
@property(nonatomic, strong, readonly) NSString *appUUID;

@end

@interface GXApplicationModel (GXModel)

/// #deprecated: 2022-01-27: trunk; #to-remove: ??
+ (nullable GXApplicationModel *)currentModel __attribute__((deprecated("Use GXModel appModel instead")));

@end

NS_ASSUME_NONNULL_END
