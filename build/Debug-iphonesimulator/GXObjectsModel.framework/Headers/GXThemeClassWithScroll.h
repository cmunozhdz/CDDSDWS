//
//  GXThemeClassWithScroll.h
//  GXObjectsModel
//
//  Created by Fabian Inthamoussu on 4/7/18.
//  Copyright © 2018 GeneXus. All rights reserved.
//

@import Foundation;

typedef NS_ENUM(uint_least8_t, GXScrollIndicatorsStyle)  {
	GXScrollIndicatorsStyleDefault,
	GXScrollIndicatorsStyleDark,
	GXScrollIndicatorsStyleLight
};

typedef NS_ENUM(uint_least8_t, GXScrollIndicatorsVisibility)  {
	GXScrollIndicatorsVisibilityDefault,
	GXScrollIndicatorsVisibilityBoth,
	GXScrollIndicatorsVisibilityHorizontal,
	GXScrollIndicatorsVisibilityVertical,
	GXScrollIndicatorsVisibilityNone
};

typedef NS_ENUM(uint_least8_t, GXScrollBouncingStyle)  {
	GXScrollBouncingStyleDefault,
	GXScrollBouncingStyleWhenContentAllowsScrolling,
	GXScrollBouncingStyleAlwaysHorizontally,
	GXScrollBouncingStyleAlwaysVertically,
	GXScrollBouncingStyleAlways,
	GXScrollBouncingStyleNever
};

NS_ASSUME_NONNULL_BEGIN

@protocol GXStyleClassWithScroll <NSObject>

@property(nonatomic, assign, readonly) GXScrollIndicatorsStyle scrollIndicatorsStyle;
@property(nonatomic, assign, readonly) GXScrollIndicatorsVisibility scrollIndicatorsVisibility;
@property(nonatomic, assign, readonly) GXScrollBouncingStyle scrollBouncingStyle;

@end

@protocol GXThemeClassWithScroll <GXStyleClassWithScroll>
@end

NS_ASSUME_NONNULL_END
