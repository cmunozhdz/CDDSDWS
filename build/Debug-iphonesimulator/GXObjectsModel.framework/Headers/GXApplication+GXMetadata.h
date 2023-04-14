//
//  GXApplication+GXMetadata.h
//  GXObjectsModel
//
//  Created by Fabian Inthamoussu on 19/05/2020.
//  Copyright © 2020 GeneXus. All rights reserved.
//

#import <GXObjectsModel/GXApplication.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXApplicationModelLoaderExtension <NSObject>

- (nullable NSDictionary<NSString *, id> *)applicationEntryPointPropertiesFromMetadataLoaderBlock:(NS_NOESCAPE id __nullable (^)(NSString *))metadataLoaderBlock
																							error:(out NSError * __autoreleasing __nullable * __nullable)error;

@end

@interface GXApplication (GXMetadata)

+ (void)registerApplicationModelLoaderExtension:(id <GXApplicationModelLoaderExtension>)loaderExtension;

@end

NS_ASSUME_NONNULL_END
