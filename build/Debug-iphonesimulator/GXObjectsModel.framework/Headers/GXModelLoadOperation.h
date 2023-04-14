//
//  GXModelLoadOperation.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 01/11/10.
//  Copyright 2010 Artech. All rights reserved.
//

#import <GXObjectsModel/GXApplicationProtocol.h>
#import <GXObjectsModel/GXApplicationModel.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const GXModelLoadOperation_GXMetadataPathComponent; // "gxmetadata"

@interface GXModelLoadOperationContext : NSObject

- (instancetype)initWithApplicationToLoad:(id <GXApplication>)applicationToLoad NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

// Input Data
@property(nonatomic, strong) id <GXApplication> applicationToLoad;

// Output Data
@property(nullable, nonatomic, strong, readonly) GXApplicationModel *applicationModel;
@property(nullable, nonatomic, strong, readonly) NSError *error;

@end

@interface GXModelLoadOperationContext (GXModelManagerExtension)

@property(nullable, nonatomic, strong, readwrite) NSError *error;

- (void)setModelObject:(id)modelObject forKey:(NSString *)key;
- (nullable id)modelObjectForKey:(NSString *)key;

@end

@interface GXModelLoadOperation : NSOperation // Abstract

- (instancetype)initWithContext:(GXModelLoadOperationContext *)context NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

@property(nonatomic, strong, readonly) GXModelLoadOperationContext *modelLoadContext;

@end

NS_ASSUME_NONNULL_END
