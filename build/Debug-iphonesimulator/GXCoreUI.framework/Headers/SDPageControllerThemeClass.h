//
//  SDPageControllerThemeClass.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 18/02/14.
//  Copyright (c) 2014 Artech. All rights reserved.
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

extern GXStyleClassPropertyName GXStyleClassPropertyNameSDPageControllerBackgroundColor;
extern GXStyleClassPropertyName GXStyleClassPropertyNameSDPageIndicatorSelectedColor;
extern GXStyleClassPropertyName GXStyleClassPropertyNameSDPageIndicatorUnselectedColor;

@interface SDPageControllerThemeClass : GXThemeClass

+ (nullable UIColor *)backgroundColorFromStyleClass:(nullable GXStyleClass *)styleClass
			 resolvingToDefaultWithPropertyResolver:(nullable id<GXStyleClassPropertyDefaultResolver>)resolver;

+ (nullable UIColor *)indicatorSelectedColorFromStyleClass:(nullable GXStyleClass *)styleClass
					resolvingToDefaultWithPropertyResolver:(nullable id<GXStyleClassPropertyDefaultResolver>)resolver;

+ (nullable UIColor *)indicatorUnselectedColorFromStyleClass:(nullable GXStyleClass *)styleClass
					  resolvingToDefaultWithPropertyResolver:(nullable id<GXStyleClassPropertyDefaultResolver>)resolver;

@property (nonatomic, strong, readonly) UIColor *backgroundColor;
@property (nullable, nonatomic, strong, readonly) UIColor *indicatorSelectedColor;
@property (nullable, nonatomic, strong, readonly) UIColor *indicatorUnselectedColor;

@end

NS_ASSUME_NONNULL_END
