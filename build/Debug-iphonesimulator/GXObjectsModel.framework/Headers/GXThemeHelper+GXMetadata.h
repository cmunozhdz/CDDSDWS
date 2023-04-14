//
//  GXThemeHelper+GXMetadata.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 17/11/15.
//  Copyright © 2015 Artech. All rights reserved.
//

@import Foundation;
@import GXFoundation;
#import <GXObjectsModel/GXThemeHelper.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXStyleHelper (GXMetadata)

+ (nullable NSNumber *)floatNumberFromValue:(nullable id)value;
+ (nullable NSNumber *)floatNumberRoundedToScreenScaleFromValue:(nullable id)value;
+ (nullable NSNumber *)borderStyleFromValue:(nullable id)value;
+ (nullable NSNumber *)numberFromMeasuredValue:(nullable id)value;
+ (nullable NSNumber *)fontWeightFromValue:(nullable id)value;
+ (nullable NSNumber *)fontStyleFromValue:(nullable id)value;
+ (nullable NSNumber *)fontCategoryFromValue:(nullable id)value;
+ (nullable UIFontDescriptor *)fontDescriptorForCategory:(GXFontCategoryType)category
											  familyName:(nullable NSString *)family
												  weight:(GXFontWeightType)weight
												   style:(GXFontStyleType)style NS_REFINED_FOR_SWIFT;
+ (nullable NSString *)fontNameForFamilyName:(nullable NSString *)family
									  weight:(GXFontWeightType)weight
									   style:(GXFontStyleType)style NS_REFINED_FOR_SWIFT;
+ (nullable NSNumber *)horizontalAlignmentFromValue:(nullable id)value;
+ (nullable NSNumber *)verticalAlignmentFromValue:(nullable id)value;

@end

NS_ASSUME_NONNULL_END
