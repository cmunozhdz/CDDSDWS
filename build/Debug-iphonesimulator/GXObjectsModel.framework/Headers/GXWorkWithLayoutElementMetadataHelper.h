//
//  GXWorkWithLayoutElementMetadataHelper.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 27/03/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXWorkWithLayoutElementAlignmentHelper.h>
#import <GXObjectsModel/GXWorkWithLayoutElementContainerLayoutHelper.h>
#import <GXObjectsModel/GXWorkWithLayoutElementExpandableBoundsHelper.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXWorkWithLayoutElementMetadataHelper : NSObject

/// Creates a new error with the given developer description.
/// @param desc The message to set as the developer description for the resulting error.
/// @discussion Same as calling `defaultModelErrorWithDeveloperDescription:controlName:` passing nil to the `controlName`.
+ (NSError *)defaultModelErrorWithDeveloperDescription:(NSString *)desc;

/// Creates a new error with the given developer description, appending the control name to it if provided.
/// @param desc The message to set as the developer description for the resulting error.
/// @param controlName The name of the control. If it is not `nil`, the message "for control <controlName>" is added to the end of the `desc` parameter.
+ (NSError *)defaultModelErrorWithDeveloperDescription:(NSString *)desc controlName:(nullable NSString *)controlName;

+ (nullable GXWorkWithLayoutElementAlignmentHelper *)workWithLayoutElementAlignmentHelperFromMetadata:(nullable NSDictionary<NSString *, id> *)metadata;
+ (BOOL)workWithLayoutElementAutoGrowFromMetadata:(nullable NSDictionary<NSString *, id> *)metadata defaultValue:(BOOL)defaultValue;
+ (BOOL)workWithLayoutElementPullToRefreshFromMetadata:(nullable NSDictionary<NSString *, id> *)metadata;
+ (BOOL)workWithLayoutElementInverseLoadingFromMetadata:(nullable NSDictionary<NSString *, id> *)metadata;
+ (BOOL)workWithLayoutElementEnableMultipleSelectionFromMetadata:(nullable NSDictionary<NSString *, id> *)metadata;
+ (nullable GXWorkWithLayoutElementContainerLayoutHelper *)workWithLayoutElementContainerLayoutHelperFromMetadata:(nullable NSDictionary<NSString *, id> *)metadata;
+ (nullable GXWorkWithLayoutElementExpandableBoundsHelper *)workWithLayoutElementExpandableBoundsHelperFromMetadata:(nullable NSDictionary<NSString *, id> *)metadata;
+ (nullable GXWorkWithLayoutElementExpandableBoundsHelper *)workWithLayoutElementExpandableBoundsHelperFromMetadata:(nullable NSDictionary<NSString *, id> *)metadata
																						withDefaultExpandableBounds:(GXLayoutExpandableBounds)expandableBounds
																									expandDirection:(GXLayoutExpandDirection)expandDirection
																										expandLimit:(GXLayoutExpandLimit)expandLimit;

@end

NS_ASSUME_NONNULL_END
