//
//  GXEntityDataManagerInternalBaseOperation.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 01/11/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import GXObjectsModel;
#import <GXDataLayer/GXEntityDataManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXEntityDataManagerInternalBaseOperation : NSOperation

@property(nullable, weak, readonly) id<GXInternalEntityDataManager> internalEntityDataManager;

- (instancetype)initWithDataSource:(id<GXEntityDataSourceDescriptor>)dataSource
						   manager:(id<GXInternalEntityDataManager>)internalEntityDataManager
NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

// Input Data
@property(nonatomic, strong, readonly) id <GXEntityDataSourceDescriptor> dataSource;

// Helpers for subclasses

@property(nullable, weak, readonly) GXModel *gxModel; // From internalEntityDataManager

- (void)onFinishWithError:(nullable NSError *)error;					// Abtract other onFinishWith... methods calls onFinishWithError:
- (void)onFinishWithSuccess;								// Calls onFinishWithError: with nil
- (void)onFinishWithDefaultErrorIfNil:(nullable NSError *)error;		// Calls onFinishWithError: with error (if error == nil, uses [NSError defaultGXError])
- (void)onFinishWithDefaultError;							// Calls onFinishWithDefaultErrorIfNil: with nil

@end

NS_ASSUME_NONNULL_END
