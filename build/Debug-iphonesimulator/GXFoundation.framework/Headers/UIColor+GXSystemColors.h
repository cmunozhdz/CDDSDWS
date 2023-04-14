//
//  UIColor+GXSystemColors.h
//  GXFoundation
//
//  Created by Fabian Inthamoussu on 06/08/2019.
//  Copyright © 2019 GeneXus. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

// See UIColorSystemColors category
@interface UIColor (GXSystemColors)

#pragma mark System colors

/* Some colors that are used by system elements and applications.
 * These return named colors whose values may vary between different contexts and releases.
 * Do not make assumptions about the color spaces or actual colors used.
 */
@property(class, nonatomic, readonly) UIColor *gxSystemRedColor;
@property(class, nonatomic, readonly) UIColor *gxSystemGreenColor;
@property(class, nonatomic, readonly) UIColor *gxSystemBlueColor;
@property(class, nonatomic, readonly) UIColor *gxSystemOrangeColor;
@property(class, nonatomic, readonly) UIColor *gxSystemYellowColor;
@property(class, nonatomic, readonly) UIColor *gxSystemPinkColor;
@property(class, nonatomic, readonly) UIColor *gxSystemPurpleColor;
@property(class, nonatomic, readonly) UIColor *gxSystemTealColor;
@property(class, nonatomic, readonly) UIColor *gxSystemIndigoColor;

/* Shades of gray. systemGray is the base gray color.
 */
@property(class, nonatomic, readonly) UIColor *gxSystemGrayColor;

/* The numbered variations, systemGray2 through systemGray6, are grays which increasingly
 * trend away from systemGray and in the direction of systemBackgroundColor.
 *
 * In UIUserInterfaceStyleLight: systemGray1 is slightly lighter than systemGray.
 *                               systemGray2 is lighter than that, and so on.
 * In UIUserInterfaceStyleDark:  systemGray1 is slightly darker than systemGray.
 *                               systemGray2 is darker than that, and so on.
 */
@property(class, nonatomic, readonly) UIColor *gxSystemGray2Color;
@property(class, nonatomic, readonly) UIColor *gxSystemGray3Color;
@property(class, nonatomic, readonly) UIColor *gxSystemGray4Color;
@property(class, nonatomic, readonly) UIColor *gxSystemGray5Color;
@property(class, nonatomic, readonly) UIColor *gxSystemGray6Color;

#pragma mark Foreground colors

/* Foreground colors for static text and related elements.
*/
@property(class, nonatomic, readonly) UIColor *gxLabelColor;
@property(class, nonatomic, readonly) UIColor *gxSecondaryLabelColor;
@property(class, nonatomic, readonly) UIColor *gxTertiaryLabelColor;
@property(class, nonatomic, readonly) UIColor *gxQuaternaryLabelColor;

/* Foreground color for standard system links.
 */
@property(class, nonatomic, readonly) UIColor *gxLinkColor;

/* Foreground color for placeholder text in controls or text fields or text views.
 */
@property(class, nonatomic, readonly) UIColor *gxPlaceholderTextColor;

/* Foreground colors for separators (thin border or divider lines).
 * `separatorColor` may be partially transparent, so it can go on top of any content.
 * `opaqueSeparatorColor` is intended to look similar, but is guaranteed to be opaque, so it will
 * completely cover anything behind it. Depending on the situation, you may need one or the other.
 */
@property(class, nonatomic, readonly) UIColor *gxSeparatorColor;
@property(class, nonatomic, readonly) UIColor *gxOpaqueSeparatorColor;

#pragma mark Background colors

/* We provide two design systems (also known as "stacks") for structuring an iOS app's backgrounds.
 *
 * Each stack has three "levels" of background colors. The first color is intended to be the
 * main background, farthest back. Secondary and tertiary colors are layered on top
 * of the main background, when appropriate.
 *
 * Inside of a discrete piece of UI, choose a stack, then use colors from that stack.
 * We do not recommend mixing and matching background colors between stacks.
 * The foreground colors above are designed to work in both stacks.
 *
 * 1. systemBackground
 *    Use this stack for views with standard table views, and designs which have a white
 *    primary background in light mode.
 */
@property(class, nonatomic, readonly) UIColor *gxSystemBackgroundColor;
@property(class, nonatomic, readonly) UIColor *gxSecondarySystemBackgroundColor;
@property(class, nonatomic, readonly) UIColor *gxTertiarySystemBackgroundColor;

/* 2. systemGroupedBackground
 *    Use this stack for views with grouped content, such as grouped tables and
 *    platter-based designs. These are like grouped table views, but you may use these
 *    colors in places where a table view wouldn't make sense.
 */
@property(class, nonatomic, readonly) UIColor *gxSystemGroupedBackgroundColor;
@property(class, nonatomic, readonly) UIColor *gxSecondarySystemGroupedBackgroundColor;
@property(class, nonatomic, readonly) UIColor *gxTertiarySystemGroupedBackgroundColor;

#pragma mark Fill colors

/* Fill colors for UI elements.
 * These are meant to be used over the background colors, since their alpha component is less than 1.
 *
 * systemFillColor is appropriate for filling thin and small shapes.
 * Example: The track of a slider.
 */
@property(class, nonatomic, readonly) UIColor *gxSystemFillColor;

/* secondarySystemFillColor is appropriate for filling medium-size shapes.
 * Example: The background of a switch.
 */
@property(class, nonatomic, readonly) UIColor *gxSecondarySystemFillColor;

/* tertiarySystemFillColor is appropriate for filling large shapes.
 * Examples: Input fields, search bars, buttons.
 */
@property(class, nonatomic, readonly) UIColor *gxTertiarySystemFillColor;

/* quaternarySystemFillColor is appropriate for filling large areas containing complex content.
 * Example: Expanded table cells.
 */
@property(class, nonatomic, readonly) UIColor *gxQuaternarySystemFillColor;

@end

NS_ASSUME_NONNULL_END
