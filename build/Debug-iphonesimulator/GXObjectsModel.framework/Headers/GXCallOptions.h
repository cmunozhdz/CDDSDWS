//
//  GXCallOptions.h
//  GXFlexibleClient
//
//  Created by willy on 10/12/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

#define kCALL_OPTIONS_CURRENT_TARGET_NAME @"CurrentTarget"

@import Foundation;
@import GXFoundation;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint_least8_t, GXCallOptionEffect) {
	GXCallOptionEffectDefault,
	GXCallOptionEffectCurlUp,
	GXCallOptionEffectCurlDown,
	GXCallOptionEffectFlipFromLeft,
	GXCallOptionEffectFlipFromRight,
	GXCallOptionEffectSlideDown,
	GXCallOptionEffectSlideTop,
	GXCallOptionEffectSlideLeft,
	GXCallOptionEffectSlideRight,
	GXCallOptionEffectPushDown,
	GXCallOptionEffectPushTop,
	GXCallOptionEffectPushLeft,
	GXCallOptionEffectPushRight,
	GXCallOptionEffectFade,
	GXCallOptionEffectNone,
	GXCallOptionEffectUnspecified,
	GXCallOptionEffectUserDefined
};

GXCallOptionEffect GXCallOptionEffectFromName(NSString *effectName);
GXCallOptionEffect GXCallOptionEffectOposite(GXCallOptionEffect effect) __attribute__((const));

typedef NS_ENUM(uint_least8_t, GXCallOptionType) {
	GXCallOptionTypePush,
	GXCallOptionTypeReplace,
	GXCallOptionTypePopup,
	GXCallOptionTypeCallout,
	GXCallOptionTypeUnspecified,
	GXCallOptionTypeReplaceAll
};

GXCallOptionType GXCallOptionTypeFromName(NSString *typeName);

typedef NS_ENUM(uint_least8_t, GXCallOptionTargetSize) {
	GXCallOptionTargetSizeUnspecified,
	GXCallOptionTargetSizeSmall,
	GXCallOptionTargetSizeMedium,
	GXCallOptionTargetSizeLarge,
	GXCallOptionTargetSizeCustom
};

GXCallOptionTargetSize GXCallOptionTargetSizeFromName(NSString *targetSizeName);

#define GXCallOptionTargetCustomDimensionFromValue(value) GXLayoutDimensionFromValueWithDefault(value, GXLayoutDimensionZeroPoint)

@interface GXCallOptions : NSObject <NSCoding, NSMutableCopying>

@property(nonatomic, assign, readonly) GXCallOptionEffect enterEffect;
@property(nonatomic, assign, readonly) GXCallOptionEffect closeEffect;
@property(nonatomic, assign, readonly) GXCallOptionEffect closeEffectResolvedDefault;
@property(nonatomic, assign, readonly) GXCallOptionType type;
@property(nullable, nonatomic, strong, readonly) NSString *targetName;
@property(nonatomic, assign, readonly) GXCallOptionTargetSize targetSize;
@property(nonatomic, assign, readonly) GXLayoutDimension targetSizeCustomWidth;
@property(nonatomic, assign, readonly) GXLayoutDimension targetSizeCustomHeight;
@property(nonatomic, assign, readonly) BOOL hideTabs;

@property(nonatomic, assign, readonly, getter=isEmpty) BOOL empty;

- (instancetype)initWithEnterEffect:(GXCallOptionEffect)enterEffect
						closeEffect:(GXCallOptionEffect)closeEffect
							   type:(GXCallOptionType)type
						 targetName:(nullable NSString *)targetName
						 targetSize:(GXCallOptionTargetSize)targetSize
			  targetSizeCustomWidth:(GXLayoutDimension)targetSizeCustomWidth
			 targetSizeCustomHeight:(GXLayoutDimension)targetSizeCustomHeight
						   hideTabs:(BOOL)hideTabs NS_DESIGNATED_INITIALIZER;

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

@interface GXMutableCallOptions : GXCallOptions

@property(nonatomic, assign, readwrite) GXCallOptionEffect enterEffect;
@property(nonatomic, assign, readwrite) GXCallOptionEffect closeEffect;
@property(nonatomic, assign, readwrite) GXCallOptionType type;
@property(nullable, nonatomic, strong, readwrite) NSString *targetName;
@property(nonatomic, assign, readwrite) GXCallOptionTargetSize targetSize;
@property(nonatomic, assign, readwrite) GXLayoutDimension targetSizeCustomWidth;
@property(nonatomic, assign, readwrite) GXLayoutDimension targetSizeCustomHeight;
@property(nonatomic, assign, readwrite) BOOL hideTabs;

- (void)mergeWithOptions:(GXCallOptions *)options;

@end

NS_ASSUME_NONNULL_END
