//
//  GXImageUploadHelper.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 5/31/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import Foundation;
@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@interface GXImageUploadHelper : NSObject

/// Returns whether the image for the given url should be uploaded. If typeInfo is not an image, returns NO
+ (BOOL)shouldUploadImageFromURL:(NSURL *)url typeInfo:(id<GXEntityDataFieldInfo>)typeInfo;

/**
 * Returns the data for the image resized acording to the corresponding properties
 * Warning: the given URL (file or custom URL Scheme) must be an image & must be called on background thread, if not an image, returns nil
 */
+ (nullable NSData *)imageUploadDataFromURL:(NSURL *)url
								   typeInfo:(id<GXEntityDataFieldInfo>)typeInfo
							 callerTypeInfo:(nullable id<GXEntityDataFieldInfo>)callerTypeInfo
									  error:(out NSError * _Nullable __autoreleasing * _Nullable)error __attribute__((swift_error(nonnull_error)));

/**
 * Returns the data for the image resized acording to the corresponding properties
 * Warning: the given url must be a file URL of an image & must be called on background thread, if not an image, returns nil
 */
+ (nullable NSData *)imageUploadDataFromFileURL:(NSURL *)fileURL
									   typeInfo:(id<GXEntityDataFieldInfo>)typeInfo
								 callerTypeInfo:(nullable id<GXEntityDataFieldInfo>)callerTypeInfo
										  error:(out NSError * _Nullable __autoreleasing * _Nullable)error __attribute__((swift_error(nonnull_error)));

/**
* Returns the data for the image resized acording to the corresponding properties
* Warning: the given data must be an image & must be called on background thread
*/
+ (NSData *)imageUploadDataFromData:(NSData *)imageData
						   typeInfo:(id<GXEntityDataFieldInfo>)typeInfo
					 callerTypeInfo:(nullable id<GXEntityDataFieldInfo>)callerTypeInfo;

+ (GXImageUploadResolutionType)resolvedImageUploadResolutionTypeFromTypeInfo:(id<GXEntityDataFieldInfo>)typeInfo
															  callerTypeInfo:(nullable id<GXEntityDataFieldInfo>)callerTypeInfo;

@end

NS_ASSUME_NONNULL_END
