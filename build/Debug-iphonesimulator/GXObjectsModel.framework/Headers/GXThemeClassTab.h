//
//  GXThemeClassTab.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 12/08/11.
//  Copyright (c) 2011 Artech. All rights reserved.
//

#import <GXObjectsModel/GXThemeClassContainerBase.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint_least8_t, GXThemeClassTabPosition) {
	GXThemeClassTabPositionTop,
	GXThemeClassTabPositionBottom
};

@interface GXThemeClassTab : GXThemeClassContainerBase
@end

NS_ASSUME_NONNULL_END
