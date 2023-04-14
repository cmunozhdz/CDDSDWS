//
//  GXEntityDataFieldDynamicComboProvider.h
//  GXFlexibleClient
//
//  Created by Panizza Alejandro on 12/2/11.
//  Copyright (c) 2011 None. All rights reserved.
//

@import Foundation;
@import GXFoundation;
@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@class GXEntityDataFieldDynamicComboData;
@class GXEntityDataFieldDynamicComboProvider;

@protocol GXEntityDataFieldDynamicComboProviderDelegate <NSObject>

@optional
- (BOOL)entityDataFieldComboProviderCanLoad:(GXEntityDataFieldDynamicComboProvider *)provider;

- (void)entityDataFieldComboProvider:(GXEntityDataFieldDynamicComboProvider *)provider
				   didLoadEntityData:(GXEntityDataFieldDynamicComboData *)values;

- (void)entityDataFieldComboProvider:(GXEntityDataFieldDynamicComboProvider *)provider
			 didFailLoadingWithError:(NSError *)error;

@end

@interface GXEntityDataFieldDynamicComboProvider : NSObject

@property (nullable, nonatomic, weak) id<GXEntityDataFieldDynamicComboProviderDelegate> delegate;
@property (nonatomic, strong, readonly) id<GXDynamicDataService> service;
@property (nullable, nonatomic, strong) id<GXEntityData> entityData;
@property (nonatomic, strong, readonly) id<GXEntityDataFieldDescriptor> fieldDescriptor;
@property (nullable, nonatomic, strong, readonly) NSString *fieldSpecifier;
@property (nonatomic, strong, readonly) id<GXEntityDataFieldInfo> resolvedFieldInfo;
@property (nonatomic, assign, readonly) GXConnectivitySupportType connectivitySupport;

+ (GXEntityDataFieldDynamicComboProvider *)dynamicComboProviderWithEntityData:(nullable id <GXEntityData>)entityData
															  fieldDescriptor:(id <GXEntityDataFieldDescriptor>)fieldDescriptor
															   fieldSpecifier:(nullable NSString *)fieldSpecifier
																	  service:(id<GXDynamicDataService>)service
														  connectivitySupport:(GXConnectivitySupportType)connSupport;

- (BOOL)canLoad;

/**
 * Abstract: must implement in subclasses
 * Performs the provider's load operation
 * Returns false if the operation could not be started (canLoad == NO)
 */
- (BOOL)load;

/**
 * Abstract: must implement in subclasses
 * Cancels the provider's load operation (if any)
 */
- (void)cancel;

@end

NS_ASSUME_NONNULL_END
