//
//  GXObjectsModelObjcConstants.h
//  GXObjectsModel
//
//  Created by Fabian Inthamoussu on 26/11/20.
//  Copyright © 2020 GeneXus. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - GXSecurityService

typedef void (^GXSecurityServiceAuthorizationCompletionBlock)(BOOL success, NSError * _Nullable error);

#pragma mark - GXApplicationImageUploadSettings

typedef NS_ENUM(uint_least8_t, GXImageUploadResolutionType) {
	GXImageUploadResolutionActualSize,
	GXImageUploadResolutionLarge,
	GXImageUploadResolutionMedium,
	GXImageUploadResolutionSmall
};

extern GXImageUploadResolutionType const kGXImageDefaultUploadResolution; // GXImageUploadResolutionType

GXImageUploadResolutionType GXImageUploadResolutionTypeSmallestResolution(GXImageUploadResolutionType first, GXImageUploadResolutionType second);

#define GXImageRenderingMode_UNDEFINED (UINT_LEAST8_MAX)

NS_ASSUME_NONNULL_END
