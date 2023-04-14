//
//  GXWorkWithLayoutElement.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 23/12/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXLayoutProtocol.h>
#import <GXObjectsModel/GXActionUIDescriptorProtocol.h>

NS_ASSUME_NONNULL_BEGIN

#define kGXHorizontalAlignPropertyKey @"halign"
#define kGXVerticalAlignPropertyKey @"valign"
#define kGXWidthPropertyKey @"w"
#define kGXHeightPropertyKey @"h"
#define kGXFixedHeightSum @"FHS"
#define kGXFixedWidthSum @"FWS"
#define kGXThemeClassPropertyKey @"class"
#define kGXBackgroundKey @"bg"
#define kGXAutoGrowPropertyKey @"ag"
#define kGXVisiblePropertyKey @"visible"
#define kGXEnabledPropertyKey @"enabled"
#define kGXInvisibleModePropertyKey @"invisibleMode"


#pragma mark - GXWorkWithLayoutElement

@interface GXWorkWithLayoutElement : GXModelObjectChild <GXLayoutElement> // Abstract

#pragma mark - GXLayoutElement abstract methods

// - (GXLayoutElementType)layoutElementType;

#pragma mark - Constructor methods

/**
 * Initialization method, subclasses should override this methods for loading from metadata (or methods called by this)
 * Default implementation:
 *	- generates a new unique layoutElementId
 *	- calls initalizeWithMetadataDictionary:context:error: if metadata is kind of class NSDictionary
 *	- calls workWithLayoutElementPropertiesFromMetadata:context:error:
 *	- if error is instantiated, sets self to nil
 */
- (nullable instancetype)initWithMetadata:(nullable id)metadata
								  context:(nullable id)context
						   forModelObject:(nullable id<GXModelObject>)modelObject
									error:(out NSError * __autoreleasing __nullable * __nullable)error NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithModelObject:(nullable id<GXModelObject>)modelObject NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

/**
 * Convinience constructor method
 * Default implementation:
 *	- Calls workWithLayoutElementInstanceClassFromMentadata:context:error:
 *	- Allocates an instance of the returned class and calls initWithMetadata:context:error:
 */
+ (nullable instancetype)workWithLayoutElementFromMentadata:(nullable id)metadata
													context:(nullable id)context
											 forModelObject:(nullable id<GXModelObject>)modelObject
													  error:(out NSError * __autoreleasing __nullable * __nullable)error;

#pragma mark - Constructor override points

/**
 * Initialization method
 * Called by initWithMetadata:context:error: if metadata is kind of class NSDictionary
 * Subclasses can override this method instead of initWithMetadata:context:error: if only needs to load from NSDicationary metadata
 * Default implementation does nothing
 */
- (nullable NSError *)initalizeWithMetadataDictionary:(nullable NSDictionary<NSString *, id> *)metadata
											  context:(nullable id)context;

/**
 * Creates workWithLayoutElementProperties from given metadata
 * Useful for optional properties which does not require instance variables and for converting properties from metadata
 * Called by initWithMetadata:context:error:
 * Default implementation stores @visible and @invisibleMode from metadata if there values are not default, returns nil otherwise
 */
+ (nullable NSMutableDictionary<NSString *, id> *)workWithLayoutElementPropertiesFromMetadata:(nullable NSDictionary<NSString *, id> *)metadata
																					  context:(nullable id)context
																						error:(out NSError * __autoreleasing __nullable * __nullable)error;

/**
 * Subclasses can override this method to create different classes than self in workWithLayoutElementFromMentadata:context:error:
 * Default implementation returns [self class]
 */
+ (nullable Class)workWithLayoutElementInstanceClassFromMentadata:(nullable id)metadata
														  context:(nullable id)context
															error:(out NSError * __autoreleasing __nullable * __nullable)error;

@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, id> *workWithLayoutElementProperties;

@end

NS_ASSUME_NONNULL_END
