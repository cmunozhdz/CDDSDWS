//
//  UIKitConstants.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 22/08/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;
@import UIKit;

#define kUIMinimumRecomendedTouchAreaHeight 44.0
#define kUIMinimunRecomendedTouchAreaSize CGSizeMake(44.0, 44.0)

#define kUICollectionViewCellDefaultBound 50.0

#define kUITableViewCellDefaultHeigth 44.0
#define kUITableViewCellDefaultEditHeigth 53.0
#if TARGET_OS_IOS || TARGET_OS_TV
#define kUITableViewCellSeparatorStyleSingleLineHeight ([GXExecutionEnvironmentHelper preferredContentSizeCategoryIsAccessibilityCategory] ? 1.0 : (1.0 / [[UIScreen mainScreen] scale]))
#endif
#define kUITableViewCellContentViewDefaultMarginiPhone 10.0
#define kUITableViewCellContentViewDefaultMarginiPadPortrait 45.0
#define kUITableViewCellContentViewDefaultMarginiPadLandscape 43.0
#define kUITableViewCellTextLabelDefaultMargin 10.0
#define kUITableViewCellTextLabelDefaultWidth 67.0
#define kUITableViewCellSeparatorDefaultWidth 6.0
#define kUITableViewCellAccessoryDefaultWidth 20.0
#define kUITableViewCellDefaultFontSize 17.0
#define kUITableViewCellTextLabelDefaultFontSize 12.0
#define kUITableViewCellDetailTextLabelDefaultFontSize 15.0

#define kUITableViewCellDefaultBackgourndColor UIColor.gxSystemBackgroundColor
#define kUITableViewHeaderFooterViewDefaultBackgourndColor UIColor.gxSystemGray5Color

#define kUITableViewCellDefaultHighlightColor UIColor.gxSystemGray4Color
#define kUITableViewCellDefaultHighlightFromColor kUITableViewCellDefaultHighlightColor
#define kUITableViewCellDefaultHighlightToColor kUITableViewCellDefaultHighlightColor

#define kUITableViewCellDefaultSelectedColor UIColor.gxSystemGray4Color
#define kUITableViewCellDefaultSeparatorColor UIColor.gxSeparatorColor

#define kUIBarAppearanceDefaultShadowColor [UIColor colorWithWhite:0 alpha:0.3]

#define kUIToolbarDefaultHeight 44.0
#define kUIToolbarDefaultHeightiPhoneLandscape 32.0

#define kUITableViewSectionHeaderHeight 28.0
#define kUITableViewIndexWidth 15.0
#define kUITableViewGroupedDefaultSeparator 36.0
#define kUITableViewGroupedDefaultTopInset kUITableViewGroupedDefaultSeparator
#define kUITableViewGroupedDefaultBottomInset 36.0
#define kUITableViewGroupedDefaultVerticalInset 72.0

#define kUIStatusbarDefaultHeigth 20.0

#define kUIKeyboardHeightPortraitiPhone 216.0
#define kUIKeyboardHeightLandscapeiPhone 162.0

#define kUIDatePickerHeigth 216.0

#define kUIPickerViewHeight 216.0
#define kUIPickerViewRowHeight 32
#define kUIPickerViewHorizontalPadding 9
#define kUIPickerViewFontSize 21

#define kUIColorDefaultDetailIndicatorColor UIColor.gxOpaqueSeparatorColor
#define kUIColorDefaultLabelColor UIColor.gxLabelColor
#define kUIColorDefaultTabUnselectedColor [UIColor colorWithWhite:GXExecutionEnvironmentHelper.darkUIStyle ? 0.4784313725 : 0.6 alpha:1.0]
#define kUIColorDefaultInviteMessageColor UIColor.gxPlaceholderTextColor

#define kUIBarButtonItemMaxImageDimension 24.0
#define kUIBarButtonItemMaxImageSize CGSizeMake(kUIBarButtonItemMaxImageDimension, kUIBarButtonItemMaxImageDimension)

#define UIButtonTypeDetailDisclosureDefaultBoundSize 28.0
#define UIButtonRoundedDefaultFontSize 15.0

#define kUIViewAnimationDuration 0.2
#if TARGET_OS_WATCH
#define kUIViewControllerDismissDelayDuration 1.0
#else
#define kUIViewControllerDismissDelayDuration 0.5
#endif

#define kUITextViewDefaultHorizontalEdgeInset 5.0
#define kUITextViewDefaultVerticalEdgeInset 8.0

#define kUIPopoverContentSizeWidth 320.0
#define kUIPopoverDefaultContentSize CGSizeMake(kUIPopoverContentSizeWidth, 1100.0)

#define kUIColorDefaultKeyColor UIColor.gxSystemBlueColor
#define kUIColorPerceivedBrightnessMaximumForLightBackground 0.7
#define kUIColorPerceivedBrightnessMinimumForDarkBackground 0.3

#if TARGET_OS_IOS
#define kUIFontLabelFontSize [UIFont labelFontSize]
#define kUIFontButtonFontSize [UIFont buttonFontSize]
#define kUIFontSmallSystemFontSize [UIFont smallSystemFontSize]
#define kUIFontSystemFontSize [UIFont systemFontSize]
#else // TARGET_OS_IOS
#define kUIFontLabelFontSize 17.0
#define kUIFontButtonFontSize 18.0
#define kUIFontSmallSystemFontSize 12.0
#define kUIFontSystemFontSize 14.0
#endif // TARGET_OS_IOS

#define kTabBarItemSingleImageEdgeInsets UIEdgeInsetsMake(6, 0, -6, 0)

NS_ASSUME_NONNULL_BEGIN

@interface GXUIKitConstants : NSObject

@property(class, readonly) CGFloat UIMinimumRecomendedTouchAreaHeight NS_SWIFT_NAME(UIMinimumRecomendedTouchAreaHeight);

@property(class, readonly) UIColor *UIColorDefaultKeyColor NS_SWIFT_NAME(UIColorDefaultKeyColor);

@property(class, readonly) UIColor *UITableViewCellDefaultBackgourndColor NS_SWIFT_NAME(UITableViewCellDefaultBackgourndColor);
@property(class, readonly) UIColor *UITableViewHeaderFooterViewDefaultBackgourndColor NS_SWIFT_NAME(UITableViewHeaderFooterViewDefaultBackgourndColor);

@property(class, readonly) UIColor *UITableViewCellDefaultHighlightColor NS_SWIFT_NAME(UITableViewCellDefaultHighlightColor);
@property(class, readonly) UIColor *UITableViewCellDefaultHighlightFromColor NS_SWIFT_NAME(UITableViewCellDefaultHighlightFromColor);
@property(class, readonly) UIColor *UITableViewCellDefaultHighlightToColor NS_SWIFT_NAME(UITableViewCellDefaultHighlightToColor);

@property(class, readonly) UIColor *UITableViewCellDefaultSelectedColor NS_SWIFT_NAME(UITableViewCellDefaultSelectedColor);
@property(class, readonly) UIColor *UITableViewCellDefaultSeparatorColor NS_SWIFT_NAME(UITableViewCellDefaultSeparatorColor);

@property(class, readonly) UIColor *UIColorDefaultTabUnselectedColor NS_SWIFT_NAME(UIColorDefaultTabUnselectedColor);

#define kUIBarAppearanceDefaultShadowColor [UIColor colorWithWhite:0 alpha:0.3]

@property(class, readonly) CGFloat UIFontLabelFontSize NS_SWIFT_NAME(UIFontLabelFontSize);
@property(class, readonly) CGFloat UIFontButtonFontSize NS_SWIFT_NAME(UIFontButtonFontSize);
@property(class, readonly) CGFloat UIFontSmallSystemFontSize NS_SWIFT_NAME(UIFontSmallSystemFontSize);
@property(class, readonly) CGFloat UIFontSystemFontSize NS_SWIFT_NAME(UIFontSystemFontSize);

@property(class, readonly) CGFloat UISwitchWidth NS_SWIFT_NAME(UISwitchWidth);
@property(class, readonly) CGFloat UISwitchHeight NS_SWIFT_NAME(UISwitchHeight);

@end

NS_ASSUME_NONNULL_END
