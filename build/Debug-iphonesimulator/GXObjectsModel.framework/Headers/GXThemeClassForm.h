//
//  GXThemeClassForm.h
//  GXFlexibleClient
//
//  Created by willy on 10/24/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

#import <GXObjectsModel/GXThemeClassBase.h>
#import <GXObjectsModel/GXCallOptions.h>
#import <GXObjectsModel/GXThemeClassWithLoadingAnimation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint_least8_t, GXFormContentSizeChangeType)  {
	GXFormContentSizeChangeDefault,
	GXFormContentSizeChangeResize,
	GXFormContentSizeChangeScroll
};

@interface GXThemeClassForm : GXThemeClassBase
@end

NS_ASSUME_NONNULL_END
