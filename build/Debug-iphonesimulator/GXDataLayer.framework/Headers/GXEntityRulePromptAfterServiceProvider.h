//
//  GXEntityRulePromptAfterServiceProvider.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 3/12/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import Foundation;
@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@class GXEntityRulePromptAfterServiceProvider;

@protocol GXEntityRulePromptAfterServiceProviderDelegate <NSObject>

@optional
- (void)entityRulePromptAfterServiceProvider:(GXEntityRulePromptAfterServiceProvider *)provider
                               didLoadValues:(NSDictionary<NSString *, id> *)entityData;

- (void)entityRulePromptAfterServiceProvider:(GXEntityRulePromptAfterServiceProvider *)provider
                     didFailLoadingWithError:(NSError *)error;

@end

#pragma mark -

@interface GXEntityRulePromptAfterServiceProvider : NSObject

@property(nullable, nonatomic, weak) id<GXEntityRulePromptAfterServiceProviderDelegate> delegate;
@property(nullable, nonatomic, strong, readonly) id<GXEntityData> entityData;
@property(nonatomic, strong, readonly) id<GXEntityRulePrompt> promptRule;
@property(nullable, nonatomic, strong, readonly) NSDictionary *userInfo;

- (instancetype)init NS_UNAVAILABLE;

+ (nullable __kindof GXEntityRulePromptAfterServiceProvider *)entityRulePromptAfterServiceProviderWithEntityData:(nullable id<GXEntityData>)entityData
																									  promptRule:(id<GXEntityRulePrompt>)promptRule
																							 connectivitySupport:(GXConnectivitySupportType)connSupport
																										userInfo:(nullable NSDictionary *)userInfo;

/**
 * Abstract: must implement in subclasses
 * Performs the provider's load operation
 * Returns false if the operation could not be started
 */
- (BOOL)load;

/**
 * Abstract: must implement in subclasses
 * Cancels the provider's load operation (if any)
 */
- (void)cancel;

@end

NS_ASSUME_NONNULL_END
