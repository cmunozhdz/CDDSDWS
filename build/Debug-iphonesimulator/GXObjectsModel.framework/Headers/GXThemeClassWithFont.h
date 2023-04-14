//
//  GXThemeClassWithFont.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 05/01/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;
@import UIKit;
@import GXFoundation;

NS_ASSUME_NONNULL_BEGIN

@protocol GXStyleClassWithFont <NSObject>

/*!
 Theme class font calculated with properties: fontSize, fontWeight, fontStyle, fontCategory & fontFamily
 
 @result The calculated font
 @discussion Same as calling fontResolvingToDefaultValue:YES
 */
@property(nullable, nonatomic, strong, readonly) UIFont *font;
@property(nullable, nonatomic, strong, readonly) UIColor *foreColor;
@property(nullable, nonatomic, strong, readonly) UIColor *highlightedForeColor;
@property(nullable, nonatomic, strong, readonly) UIColor *inviteMessageColor;

@property(nonatomic, assign, readonly) CGFloat fontSize;
@property(nonatomic, assign, readonly) GXFontWeightType fontWeight NS_REFINED_FOR_SWIFT;
@property(nonatomic, assign, readonly) BOOL fontStrikeThrough;
@property(nonatomic, assign, readonly) GXFontStyleType fontStyle NS_REFINED_FOR_SWIFT;
@property(nonatomic, assign, readonly) GXFontCategoryType fontCategory NS_REFINED_FOR_SWIFT;
@property(nullable, nonatomic, strong, readonly) NSString *fontFamily;
@property(nonatomic, assign, readonly) GXTextTransformType textTransform NS_REFINED_FOR_SWIFT;

/*!
 Theme class font calculated with properties: fontSize, fontWeight, fontStyle, fontCategory & fontFamily
 
 @param resolveToDefault NO if result font should be nil when all properties have default values
 @result The calculated font
 @discussion The result font is calculated with properties resolved to default (even if resolveToDefault = NO), but if resolveToDefault = YES and all properties are default, the result font is nil.
 */
- (nullable UIFont *)fontResolvingToDefaultValue:(BOOL)resolveToDefault;
- (nullable UIColor *)foreColorResolvingToDefaultValue:(BOOL)resolveToDefault;
- (nullable UIColor *)highlightedForeColorResolvingToDefaultValue:(BOOL)resolveToDefault;
- (nullable UIColor *)inviteMessageColorResolvingToDefaultValue:(BOOL)resolveToDefault;

- (CGFloat)fontSizeResolvingToDefaultValue:(BOOL)resolveToDefault;
- (GXFontWeightType)fontWeightResolvingToDefaultValue:(BOOL)resolveToDefault NS_REFINED_FOR_SWIFT;
- (GXFontStyleType)fontStyleResolvingToDefaultValue:(BOOL)resolveToDefault NS_REFINED_FOR_SWIFT;
- (GXFontCategoryType)fontCategoryResolvingToDefaultValue:(BOOL)resolveToDefault NS_REFINED_FOR_SWIFT;
- (nullable NSString *)fontFamilyResolvingToDefaultValue:(BOOL)resolveToDefault;
- (GXTextTransformType)textTransformResolvingToDefaultValue:(BOOL)resolveToDefault NS_REFINED_FOR_SWIFT;

@end

@protocol GXThemeClassWithFont <GXStyleClassWithFont>
@end

NS_ASSUME_NONNULL_END
