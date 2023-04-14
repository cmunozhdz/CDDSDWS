//
//  GXModelManager+GXModelManagerExtension.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 26/1/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

#import <GXObjectsModel/GXModelManager.h>

NS_ASSUME_NONNULL_BEGIN

@class GXModelLoadOperation;
@class GXModelLoadOperationContext;

@protocol GXModelManagerExtension <NSObject>

- (nullable NSArray<__kindof GXModelLoadOperation *> *)extensionModelLoadOperationsForContext:(GXModelLoadOperationContext *)context;
- (nullable NSDictionary<NSString *, id> *)loadExtensionModelObjectsFromCacheForApplication:(id <GXApplication>)application
																					  error:(out NSError * __autoreleasing __nullable * __nullable)error;
- (nullable NSDictionary<NSString *, id> *)onModelLoadOperationsDidFinishForContext:(GXModelLoadOperationContext *)context
																			  error:(out NSError * __autoreleasing __nullable * __nullable)error;
- (void)clearCachedExtensionModelObjectsForApplication:(id <GXApplication>)application;

@end

@interface GXModelManager (GXModelManagerExtension)

- (void)registerModelManagerExtension:(id <GXModelManagerExtension>)modelManagerExtension;

@end

NS_ASSUME_NONNULL_END
