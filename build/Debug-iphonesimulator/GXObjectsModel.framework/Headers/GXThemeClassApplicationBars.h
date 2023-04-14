//
//  GXThemeClassApplicationBars.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 20/01/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

#import <GXObjectsModel/GXThemeClass.h>
#import <GXObjectsModel/GXThemeClassWithBackground.h>
#import <GXObjectsModel/GXThemeClassWithFont.h>
#import <GXObjectsModel/GXThemeClassWithShadow.h>

NS_ASSUME_NONNULL_BEGIN

#if TARGET_OS_IOS
typedef NS_ENUM(uint_least8_t, GXApplicationBarsLargeTitleMode)  {
	GXApplicationBarsLargeTitleModeAutomatic,
	GXApplicationBarsLargeTitleModeInherit,
	GXApplicationBarsLargeTitleModeAlways,
	GXApplicationBarsLargeTitleModeNever
};
#endif // TARGET_OS_IOS

@interface GXThemeClassApplicationBars : GXThemeClass
@end

NS_ASSUME_NONNULL_END
