//
//  GXImageScaleType.h
//  GXObjectsModel
//
//  Created by Marcos Crispino on 8/17/20.
//  Copyright © 2020 GeneXus. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint_least8_t, GXImageScaleType) {
	GXImageScaleTypeFit,
	GXImageScaleTypeNoScale,
	GXImageScaleTypeFill,
	GXImageScaleTypeFillKeepingAspect,
	GXImageScaleTypeTile,
};
#define GXImageScaleType_UNDEFINED ((GXImageScaleType)UINT_LEAST8_MAX)

/**
 Convenience method, calls GXImageScaleTypeFromStringWithDefault(str, GXImageScaleTypeFit)
 */
GXImageScaleType GXImageScaleTypeFromString(NSString *str);

GXImageScaleType GXImageScaleTypeFromStringWithDefault(NSString *str, GXImageScaleType defaultValue);

NS_ASSUME_NONNULL_END
