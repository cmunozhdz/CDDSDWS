//
//  GXCommon.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 16/12/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;
@import UIKit;
@import YAJL;
#import <GXFoundation/GXConstants.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_CLOSED_ENUM(uint_least8_t, GXOptionalBoolean) {
	GXOptionalBooleanUnknown,
	GXOptionalBooleanYes,
	GXOptionalBooleanNo
};

typedef NS_ENUM(uint_least8_t, GXDataType) {
	GXDataTypeNumeric,
	GXDataTypeCharacter,
	GXDataTypeDate,
	GXDataTypeDateTime,
	GXDataTypeLongVarchar,
	GXDataTypeVarchar,
	GXDataTypeBoolean,
	GXDataTypeGuid,
	GXDataTypeBlob,
	GXDataTypeBitmap,
	GXDataTypeSDT,
    GXDataTypeExternalObject,
    GXDataTypeAudio,
    GXDataTypeVideo,
    GXDataTypeGeography,
	GXDataTypeBlobFile,
	GXDataTypeHttpClient,
	GXDataTypeFile,
	GXDataTypeDirectory,
	GXDataTypeProperty,
	GXDataTypeProperties,
	GXDataTypeUnknown = UINT_LEAST8_MAX
};

GXDataType GXDataTypeFromString(NSString * stringDataType, NSString * _Nullable typeName);

/// Same as GXDataTypeFromString but also tries to extract length and decimals properties from the given stringDataType
GXDataType GXDataTypeWithInfoFromString(NSString * stringDataType,
										NSString * _Nullable typeName,
										NSNumber * _Nullable __autoreleasing * _Nullable length,
										NSNumber * _Nullable __autoreleasing * _Nullable decimals);

NSString * NSStringFromGXDataType(GXDataType dataType);

BOOL GXDataTypeIsMultimediaType(GXDataType dataType);

typedef NS_ENUM(uint_least8_t, GXBasedOnType) {
    GXBasedOnTypeNone,
    GXBasedOnTypeAttribute,
    GXBasedOnTypeDomain,
    GXBasedOnTypeSDT,
	GXBasedOnTypeBC
};

GXBasedOnType GXBasedOnTypeFromObjectId(NSString * _Nullable basedOnString);

typedef NS_ENUM(uint_least8_t, GXSpecialDomainType) {
	GXSpecialDomainMail,
	GXSpecialDomainPhone,
	GXSpecialDomainLocation,
	GXSpecialDomainAddress,
	GXSpecialDomainWebComponent,
	GXSpecialDomainHtml,
	GXSpecialDomainURL,
	GXSpecialDomainOneTimeCode
};
#define GXSpecialDomainType_UNDEFINED ((GXSpecialDomainType)UINT_LEAST8_MAX)

GXSpecialDomainType GXSpecialDomainTypeFromDomainName(NSString *domainName) NS_REFINED_FOR_SWIFT;

NSString * _Nullable GXSpecialDomainNameFromDomainType(GXSpecialDomainType type);

typedef NS_ENUM(uint_least8_t, GXDataDateFormat) {
	GXDataDateNone,
	GXDataDateYearWithTwoDigits,
	GXDataDateYearWithFourDigits
};
#define GXDataDateFormat_UNDEFINED ((GXDataDateFormat)UINT_LEAST8_MAX)

typedef NS_ENUM(uint_least8_t, GXDataTimeFormat) {
	GXDataTimeHourOnly,
	GXDataTimeHourMinutes,
	GXDataTimeHourMinutesSeconds,
	GXDataTimeHourMinutesSecondsMilliseconds
};
#define GXDataTimeFormat_UNDEFINED ((GXDataTimeFormat)UINT_LEAST8_MAX)

typedef NS_OPTIONS(uint_least8_t, GXModeType) {
	GXModeView = 1,
	GXModeInsert = 1 << 1,
	GXModeUpdate = 1 << 2,
	GXModeDelete = 1 << 3
};

NSString * GXStringFromModeType(GXModeType modeType);

typedef NS_ENUM(uint_least8_t, GXViewVisibleStateType) {
	GXViewVisibleStateAppearing,
	GXViewVisibleStateAppeared,
	GXViewVisibleStateDisappearing,
	GXViewVisibleStateDisappeared,
};

typedef NS_ENUM(uint_least8_t, GXControllerReturnState) {
	/// Explicit return. Continues callers event and controller's gxExecutingActions
	GXControllerReturnStateSuccess,
	/// Explicit Actions.Cancel(). Cancels callers event and controller's gxExecutingActions
	GXControllerReturnStateUserCancelled,
	/// Mix of Success and UserCancelled. Cancels callers event, but does not cancel controller's gxExecutingActions
	GXControllerReturnStateDefault
};

typedef NS_ENUM(uint_least8_t, GXControllerBackEventType) {
	GXControllerBackEventNone,
	GXControllerBackEventEmpty,
	GXControllerBackEventReturn,
	GXControllerBackEventCancel,
	GXControllerBackEventCustom
};

typedef NS_ENUM(uint_least8_t, GXInputViewAppearance)  {
	GXInputViewAppearanceDefault,
	GXInputViewAppearanceLight,
	GXInputViewAppearanceDark
};

#if !TARGET_OS_WATCH
UIKeyboardAppearance UIKeyboardAppearanceFromGXInputViewAppearance(GXInputViewAppearance appearance);
#endif // !TARGET_OS_WATCH

typedef NS_ENUM(uint_least8_t, GXEnterTypeKeyType) {
	GXEnterTypeKeyDefault,
	GXEnterTypeKeyGo,
	GXEnterTypeKeySearch,
	GXEnterTypeKeySend,
	GXEnterTypeKeyDone,
	GXEnterTypeKeyNext,
	GXEnterTypeKeyJoin
};

#if !TARGET_OS_WATCH
UIReturnKeyType UIReturnKeyTypeFromGXEnterTypeKeyType(GXEnterTypeKeyType enterTypeKey);
#endif // !TARGET_OS_WATCH

typedef NS_ENUM(uint_least8_t, GXVerticalAlignType) {
	GXVerticalAlignTypeDefault,
	GXVerticalAlignTypeTop,
	GXVerticalAlignTypeCenter,
	GXVerticalAlignTypeBottom
};

GXVerticalAlignType GXVerticalAlignFromValue(id _Nullable value);

typedef NS_ENUM(uint_least8_t, GXHorizontalAlignType) {
	GXHorizontalAlignTypeDefault,
	GXHorizontalAlignTypeLeft,
	GXHorizontalAlignTypeCenter,
	GXHorizontalAlignTypeRight,
	GXHorizontalAlignTypeJustify
};

GXHorizontalAlignType GXHorizontalAlignFromValue(id _Nullable value);

typedef NS_ENUM(uint_least8_t, GXLayoutUnit) {
    GXLayoutUnitPercent,
    GXLayoutUnitPoint
};

typedef NS_ENUM(uint_least8_t, GXLayoutLabelPositionType) {
	GXLayoutLabelPositionTypeNone,
    GXLayoutLabelPositionTypeLeft,
	GXLayoutLabelPositionTypeTop,
	GXLayoutLabelPositionTypeRight,
	GXLayoutLabelPositionTypeBottom,
	GXLayoutLabelPositionTypeFloat
};

#if !TARGET_OS_WATCH
#define GXLayoutLabelPositionTypePlatformDefault GXLayoutLabelPositionTypeLeft
#else
#define GXLayoutLabelPositionTypePlatformDefault GXLayoutLabelPositionTypeTop
#endif // !TARGET_OS_WATCH

typedef NS_ENUM(uint_least8_t, GXLayoutElementReadonly) {
    GXLayoutElementReadonlyYES,
    GXLayoutElementReadonlyNO,
    GXLayoutElementReadonlyAUTO
};

typedef NS_ENUM(uint_least8_t, GXLayoutInvisibleMode) {
	GXLayoutInvisibleModeKeepSpace,
	GXLayoutInvisibleModeCollapseSpace
};

typedef NS_ENUM(uint_least8_t, GXLayoutExpandableBounds) {
	GXLayoutExpandableBoundsNone,
	GXLayoutExpandableBoundsContent,
	GXLayoutExpandableBoundsBackground
};

typedef NS_ENUM(uint_least8_t, GXLayoutControlTextFormat) {
	GXLayoutControlTextFormatString,
	GXLayoutControlTextFormatHtml
};

typedef NS_OPTIONS(uint_least8_t, GXLayoutExpandDirection) {
	GXLayoutExpandDirectionNone		= 0,
	GXLayoutExpandDirectionUp		= 1 << 0,
	GXLayoutExpandDirectionDown		= 1 << 1,
	GXLayoutExpandDirectionLeft		= 1 << 2,
	GXLayoutExpandDirectionRight	= 1 << 3,
	GXLayoutExpandDirectionAll		= GXLayoutExpandDirectionUp | GXLayoutExpandDirectionDown | GXLayoutExpandDirectionLeft | GXLayoutExpandDirectionRight
};

GXLayoutExpandDirection GXLayoutExpandDirectionMakeWithUIRectEdge(UIRectEdge rectEdge);
UIRectEdge UIRectEdgeMakeWithGXLayoutExpandDirection(GXLayoutExpandDirection expandDirection);

typedef NS_ENUM(uint_least8_t, GXLayoutExpandLimit) {
	GXLayoutExpandLimitApplicationBar,
	GXLayoutExpandLimitSystemBar
};

typedef struct _gxLayoutDimension {
	CGFloat value;
    GXLayoutUnit unit;
} GXLayoutDimension;

#define GXLayoutDimension100Percent ((GXLayoutDimension){ 100.f, GXLayoutUnitPercent })
#define GXLayoutDimensionZeroPoint ((GXLayoutDimension){ 0.f, GXLayoutUnitPoint })

GXLayoutDimension GXLayoutDimensionFromValue(id _Nullable value); // defaultDimmension = GXLayoutDimension100Percent
GXLayoutDimension GXLayoutDimensionFromValueWithDefault(id _Nullable value, GXLayoutDimension defaultDimmension);

GXLayoutDimension GXLayoutDimensionFromString(NSString * _Nullable string); // defaultDimmension = GXLayoutDimension100Percent
GXLayoutDimension GXLayoutDimensionFromStringWithDefault(NSString * _Nullable string, GXLayoutDimension defaultDimmension);

CGFloat GXLayoutDimensionCalculateValueWithBound(GXLayoutDimension dimension, CGFloat bound); // constrainToBound = NO
CGFloat GXLayoutDimensionCalculateValueWithBoundConstranied(GXLayoutDimension dimension, CGFloat bound, BOOL constrainToBound);

typedef struct _gxLayoutQuadDimension{
    CGFloat top;
    CGFloat right;
    CGFloat bottom;
    CGFloat left;
} GXLayoutQuadDimension;

GXLayoutQuadDimension GXLayoutQuadDimensionMake(CGFloat top, CGFloat right, CGFloat bottom, CGFloat left);

#define GXLayoutQuadDimensionZero (GXLayoutQuadDimension){0,0,0,0}

GXLayoutQuadDimension GXLayoutQuadDimensionMakeWithUIEdgeInsets(UIEdgeInsets insets);
UIEdgeInsets UIEdgeInsetsMakeWithGXLayoutQueadDimension(GXLayoutQuadDimension dim);

GXLayoutQuadDimension GXLayoutQuadDimensionAdd(GXLayoutQuadDimension dim1, GXLayoutQuadDimension dim2);
UIEdgeInsets GXUIEdgeInsetsAdd(UIEdgeInsets insets1, UIEdgeInsets insets2);

GXLayoutQuadDimension GXLayoutQuadDimensionAddInset(GXLayoutQuadDimension dim, CGFloat inset);
UIEdgeInsets GXUIEdgeInsetsAddInset(UIEdgeInsets insets1, CGFloat inset);

typedef struct GXVerticalEdgeInsets {
    CGFloat top;
    CGFloat bottom;
} GXVerticalEdgeInsets;

typedef struct GXHorizontalEdgeInsets {
    CGFloat left;
    CGFloat right;
} GXHorizontalEdgeInsets;

GXVerticalEdgeInsets GXVerticalEdgeInsetsMake(CGFloat top, CGFloat bottom);
GXHorizontalEdgeInsets GXHorizontalEdgeInsetsMake(CGFloat left, CGFloat right);

#define GXVerticalEdgeInsetsZero (GXVerticalEdgeInsets){0,0}
#define GXHorizontalEdgeInsetsZero (GXHorizontalEdgeInsets){0,0}

typedef NS_ENUM(uint_least8_t, GXFontCategoryType) {
	GXFontCategoryTypeNone,
	GXFontCategoryTypeHeadline,
	GXFontCategoryTypeSubheadline,
	GXFontCategoryTypeBody,
	GXFontCategoryTypeFootnote,
	GXFontCategoryTypeCaption1,
	GXFontCategoryTypeCaption2
};
#define GXFontCategoryType_UNDEFINED ((GXFontCategoryType)UINT_LEAST8_MAX)

UIFontTextStyle _Nullable UIFontTextStyleFromGXFontCategory(GXFontCategoryType category);

typedef NS_ENUM(uint_least8_t, GXFontWeightType) {
	GXFontWeightTypeThin,
	GXFontWeightTypeExtraLight,
	GXFontWeightTypeLight,
	GXFontWeightTypeNormal,
	GXFontWeightTypeMedium,
	GXFontWeightTypeSemiBold,
	GXFontWeightTypeBold,
	GXFontWeightTypeExtraBold,
	GXFontWeightTypeBlack,
};
#define GXFontWeightType_UNDEFINED ((GXFontWeightType)UINT_LEAST8_MAX)

UIFontWeight UIFontWeightFromGXFontTypeWeight(GXFontWeightType weight);

typedef NS_ENUM(uint_least8_t, GXFontStyleType) {
	GXFontStyleTypeNormal,
	GXFontStyleTypeItalic,
};
#define GXFontStyleType_UNDEFINED ((GXFontStyleType)UINT_LEAST8_MAX)

typedef NS_ENUM(uint_least8_t, GXTextTransformType) {
	GXTextTransformTypeNone,
	GXTextTransformTypeCapitalize,
	GXTextTransformTypeUppercase,
	GXTextTransformTypeLowercase,
};
#define GXTextTransformType_UNDEFINED ((GXTextTransformType)UINT_LEAST8_MAX)

typedef NS_ENUM(uint_least8_t, GXBorderStyleType) {
	GXBorderStyleTypeNone,
	GXBorderStyleTypeDotted,
	GXBorderStyleTypeDashed,
	GXBorderStyleTypeSolid,
	GXBorderStyleTypeDouble,
};
#define GXBorderStyleType_UNDEFINED ((GXBorderStyleType)UINT_LEAST8_MAX)

typedef struct GXBordersRadius {
	CGFloat topLeft;
	CGFloat topRight;
	CGFloat bottomLeft;
	CGFloat bottomRight;
} GXBordersRadius;

NS_INLINE GXBordersRadius GXBordersRadiusMake(CGFloat topLeft, CGFloat topRight, CGFloat bottomLeft, CGFloat bottomRight) {
	return ((GXBordersRadius){topLeft,topRight,bottomLeft,bottomRight});
};
#define GXBordersRadiusZero GXBordersRadiusMake(0,0,0,0)

NS_INLINE BOOL GXBordersRadiusEqualToBordersRadius(GXBordersRadius br1, GXBordersRadius br2) {
	return (br1.topLeft == br2.topLeft && br1.topRight == br2.topRight && br1.bottomLeft == br2.bottomLeft && br1.bottomRight == br2.bottomRight);
};

NS_INLINE BOOL GXBordersRadiusIsSingleRadius(GXBordersRadius br) {
	return (br.topLeft == br.topRight && br.topLeft == br.bottomLeft && br.topLeft == br.bottomRight);
};

NS_INLINE BOOL GXBordersRadiusIsEmpty(GXBordersRadius br) {
	return (br.topLeft == 0 && br.topRight == 0 && br.bottomLeft == 0 && br.bottomRight == 0);
};

typedef NS_ENUM(uint_least8_t, GXListSelectionModeType) {
	GXListSelectionModeTypeNavigate,
	GXListSelectionModeTypePick,
    GXListSelectionModeTypePrompt,
};

typedef NS_ENUM(uint_least8_t, GXListSelectionType) {
	GXListSelectionTypeDefault,
	GXListSelectionTypeNoSelection,
	GXListSelectionTypeKeepSelectionWhileExecuting,
    GXListSelectionTypeKeepUntilNewSelection,
};

typedef NS_ENUM(uint_least8_t, GXHighlightStyleType) {
	GXHighlightStyleNone,
	GXHighlightStyleHighlighted,
	GXHighlightStyleSelected,
};

typedef NS_ENUM(uint_least8_t, GXAdsPositionType) {
	GXAdsPositionBotton,
	GXAdsPositionTop,
	GXAdsPositionNone
};

typedef NS_OPTIONS(uint_least8_t, GXInterfaceOrientation) {
	GXInterfaceOrientationPortrait = 1 << 0,
	GXInterfaceOrientationLandscape = 1 << 1,
	GXInterfaceOrientationAny = GXInterfaceOrientationPortrait | GXInterfaceOrientationLandscape,
};

#define kFloatMaxDigits 6
#define kDoubleMaxDigits 15
#define kInt16MaxDigits 4 // Max int16 = 2 ^ 15 - 1 = 32767
#define kInt32MaxDigits 9 // Max int32 = 2 ^ 31 - 1 = 2147483647
#define kInt64MaxDigits 18 // Max int64 = 2 ^ 63 - 1 = 9.223372e+18

typedef NS_ENUM(uint_least8_t, GXConnectivitySupportType) {
	GXConnectivitySupportOnline,
	GXConnectivitySupportOffline,
	GXConnectivitySupportInherit,
};

typedef NS_ENUM(uint_least8_t, GXSynchronizationReceiveCriteriaType) {
    GXSynchronizationReceiveCriteriaAutomatic,
    GXSynchronizationReceiveCriteriaManual,
    GXSynchronizationReceiveCriteriaTime,
};

typedef NS_ENUM(uint_least8_t, GXSynchronizationSendCriteriaType) {
    GXSynchronizationSendCriteriaWhenConnected,
    GXSynchronizationSendCriteriaManual,
    GXSynchronizationSendCriteriaNever,
};

typedef NS_ENUM(uint_least8_t, GXAuthorizationStatusType) {
	GXAuthorizationStatusNotDetermined = 0,
	GXAuthorizationStatusRestricted = 1,
	GXAuthorizationStatusDenied = 2,
	GXAuthorizationStatusAuthorized = 3, // Always
	GXAuthorizationStatusAuthorizedWhenInUse = 4,
};

typedef NS_ENUM(uint_least8_t, GXApplicationStateType) {
	GXApplicationStateActive = 0,
	GXApplicationStateInactive = 1,
	GXApplicationStateBackground = 2,
	GXApplicationStateNotRunning = 3,
};

typedef NS_ENUM(uint_least8_t, GXParameterKind) {
	GXParameterKindIn,
	GXParameterKindOut,
	GXParameterKindInOut
};

GXParameterKind GXParameterKindFromString(NSString * _Nullable stringParamKind);

NSString * NSStringFromGXParameterKind(GXParameterKind kind);

NS_ASSUME_NONNULL_END
