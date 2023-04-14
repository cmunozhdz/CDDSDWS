//
//  GXThemeClassWithBackground.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 05/01/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;
@import UIKit;

typedef NS_ENUM(uint_least8_t, GXBackgroundImageMode)  {
	GXBackgroundImageModeStrech,
	GXBackgroundImageModeTile,
};
#define GXBackgroundImageMode_UNDEFINED ((GXBackgroundImageMode)UINT_LEAST8_MAX)

NS_ASSUME_NONNULL_BEGIN

@protocol GXStyleClassWithBackground <NSObject>

@property(nullable, nonatomic, strong, readonly) UIColor *backgroundColor;
@property(nullable, nonatomic, strong, readonly) UIColor *highlightedBackgroundColor;
@property(nullable, nonatomic, strong, readonly) NSString *backgroundImage;
@property(nullable, nonatomic, strong, readonly) NSString *highlightedBackgroundImage;
@property(nonatomic, assign, readonly) GXBackgroundImageMode backgroundImageMode NS_REFINED_FOR_SWIFT;

- (nullable UIColor *)backgroundColorResolvingToDefaultValue:(BOOL)resolveToDefault;
- (nullable UIColor *)highlightedBackgroundColorResolvingToDefaultValue:(BOOL)resolveToDefault;
- (nullable NSString *)backgroundImageResolvingToDefaultValue:(BOOL)resolveToDefault;
- (nullable NSString *)highlightedBackgroundImageResolvingToDefaultValue:(BOOL)resolveToDefault;
- (GXBackgroundImageMode)backgroundImageModeResolvingToDefaultValue:(BOOL)resolveToDefault NS_REFINED_FOR_SWIFT;

@end

@protocol GXThemeClassWithBackground <GXStyleClassWithBackground>
@end

NS_ASSUME_NONNULL_END
