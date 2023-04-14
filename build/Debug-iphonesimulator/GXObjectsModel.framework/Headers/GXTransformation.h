//
//  GXTransformation.h
//  GXFlexibleClient
//
//  Created by willy on 11/7/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint_least8_t, GXTransformUnit) {
	GXTransformUnitAbsolute,
	GXTransformUnitPercent,
};
#define GXTransformUnit_UNDEFINED ((GXTransformUnit)UINT_LEAST8_MAX)

typedef NS_ENUM(uint_least8_t, GXTransformRelativeTo) {
	GXTransformRelativeToParent,
	GXTransformRelativeToCurrentControl,
	GXTransformRelativeToForm,
	GXTransformRelativeToCustom
};

GXTransformRelativeTo GXTransformRelativeToFromString(NSString * _Nullable string); // defaultValue == GXTransformRelativeToCurrentControl
GXTransformRelativeTo GXTransformRelativeToFromStringWithDefault(NSString * _Nullable string, GXTransformRelativeTo defaultValue);

typedef struct _gxTransformValue {
	float value;
	GXTransformUnit unit;
} GXTransformValue;

#define GXTransformValueUndefined ((GXTransformValue){ 0.f, GXTransformUnit_UNDEFINED })

BOOL GXTransformValueIsUndefined(GXTransformValue value);

GXTransformValue GXTransformValueMake(float value, GXTransformUnit unit);

GXTransformValue GXTransformValueFromString(NSString * _Nullable string) NS_REFINED_FOR_SWIFT; // defaultValue == GXTransformValueUndefined
GXTransformValue GXTransformValueFromStringWithDefault(NSString * _Nullable string, GXTransformValue defaultValue) NS_REFINED_FOR_SWIFT;

NS_ASSUME_NONNULL_END
