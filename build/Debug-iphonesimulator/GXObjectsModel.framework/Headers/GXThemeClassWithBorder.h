//
//  GXThemeClassWithBorder.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 13/12/11.
//  Copyright (c) 2011 Artech. All rights reserved.
//

@import Foundation;
@import UIKit;
@import GXFoundation;

NS_ASSUME_NONNULL_BEGIN

@protocol GXStyleClassWithBorder <NSObject>

@property(nonatomic, assign, readonly) GXBordersRadius bordersRadius;
@property(nonatomic, assign, readonly) CGFloat borderRadius; // Preffer bordersRadius
@property(nonatomic, assign, readonly) GXBorderStyleType borderStyle NS_REFINED_FOR_SWIFT;
@property(nonatomic, assign, readonly) CGFloat borderWidth;
@property(nullable, nonatomic, strong, readonly) UIColor *borderColor;

- (GXBordersRadius)bordersRadiusResolvingToDefaultValue:(BOOL)resolveToDefault;
- (CGFloat)borderRadiusResolvingToDefaultValue:(BOOL)resolveToDefault; // Preffer bordersRadiusResolvingToDefaultValue:
- (GXBorderStyleType)borderStyleResolvingToDefaultValue:(BOOL)resolveToDefault NS_REFINED_FOR_SWIFT;
- (CGFloat)borderWidthResolvingToDefaultValue:(BOOL)resolveToDefault;
- (nullable UIColor *)borderColorResolvingToDefaultValue:(BOOL)resolveToDefault;

@end

@protocol GXThemeClassWithBorder <GXStyleClassWithBorder>
@end

NS_ASSUME_NONNULL_END
