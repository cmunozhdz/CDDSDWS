//
//  UIView+GXTheme.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 12/04/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(uint_least8_t, UIViewThemeFlags) {
	UIViewThemeFlagsBorder		= 1 << 0,
	UIViewThemeFlagsMargin		= 1 << 1,
	UIViewThemeFlagsBackground	= 1 << 2,
	UIViewThemeFlagsColor		= 1 << 3,
	UIViewThemeFlagsFont		= 1 << 4,
	UIViewThemeFlagsPadding		= 1 << 5,
	UIViewThemeFlagsAll			= UIViewThemeFlagsBorder | UIViewThemeFlagsMargin | UIViewThemeFlagsBackground | UIViewThemeFlagsColor | UIViewThemeFlagsFont | UIViewThemeFlagsPadding,
};

NS_ASSUME_NONNULL_END
