//
//  GXEntityHelper+GXEntityDataDescriptor.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 8/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

#import <GXObjectsModel/GXEntityHelper.h>
#import <GXObjectsModel/GXEntityDataDescriptorProtocol.h>
#import <GXObjectsModel/GXEntityDataFieldDescriptorProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXEntityHelper (GXEntityDataDescriptor)

+ (nullable NSDictionary<NSString *, id <GXEntityDataFieldDescriptor>> *)newDictionaryWithFieldDescriptorsByName:(nullable id <GXEntityDataDescriptor>)descriptor;

+ (nullable id <GXEntityDataFieldDescriptor>)dataFieldDescriptorFromValueExpression:(nonnull NSString *)valueExpression
																 dataElementsByName:(nullable NSDictionary<NSString *, id<GXEntityDataFieldDescriptor>> *)dataElementsByName
																			  error:(out NSError *__autoreleasing __nullable * __nullable)error __attribute__((swift_error(nonnull_error)));

/// Removes '&' character prefix, otherwise retuns the given field name
+ (NSString *)normalizedFieldNameFromFieldName:(NSString *)fieldName;

+ (NSString *)lowercaseNormalizedFieldNameFromFieldName:(NSString *)fieldName;

@end

NS_ASSUME_NONNULL_END
