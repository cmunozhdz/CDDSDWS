//
//  GXControlActionBarItemHelper.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 4/8/17.
//  Copyright © 2017 GeneXus. All rights reserved.
//

#import <GXCoreUI/GXControlActionBarItem.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXControlActionBarItemHelper : NSObject

+ (BOOL)controlActionBarItem:(id<GXControlActionBarItem>)control supportsViewType:(GXControlActionBarViewType)viewType;

+ (nullable id<GXControlActionBarButtonItem>)controlActionBarButtonItemFromControl:(id<GXControlActionBarItem>)control;
+ (nullable id<GXControlActionBarAlertActionItem>)controlActionBarAlertActionItemFromControl:(id<GXControlActionBarItem>)control;
+ (nullable id<GXControlActionBarSegmentedControlItem>)controlActionBarSegmentedControlItemFromControl:(id<GXControlActionBarItem>)control;

+ (nullable UISegmentedControl *)segmentedControlWithControlActionBarSegmentedControlItems:(NSArray<id<GXControlActionBarSegmentedControlItem>> *)items;

+ (nullable NSString *)controlActionBarItemCaption:(id<GXControlActionBarItem>)control;
+ (NSString *)controlActionBarItemCaption:(id<GXControlActionBarItem>)control withDefaultValue:(NSString *)defaultValue;


#pragma mark - GXControlCustomActionBarItem Builders

+ (id<GXControlCustomActionBarItem>)customActionBarItemControlWithParentControl:(id<GXControlWithActionBarItems>)parentControl
																	controlName:(NSString *)controlName
															 positionDescriptor:(nullable id<GXActionBarUIPositionDescriptor>)positionDesc
														   barButtonItemBuilder:(UIBarButtonItem<GXControlActionBarItemView> * _Nonnull(^_Nullable)(void))barButtonItemBuilder
															 alertActionBuilder:(UIAlertAction<GXControlActionBarItemView> * _Nonnull(^_Nullable)(BOOL destructiveStyleAllowed))alertActionBuilder
													segmentedControlItemBuilder:(GXSegmentedControlItem<GXControlActionBarItemView> * _Nonnull(^_Nullable)(void))segmentedControlItemBuilder;

+ (id<GXControlCustomActionBarItem>)customActionBarItemControlWithParentControl:(id<GXControlWithActionBarItems>)parentControl
																	controlName:(NSString *)controlName
															 positionDescriptor:(nullable id<GXActionBarUIPositionDescriptor>)positionDesc
														   barButtonItemBuilder:(UIBarButtonItem<GXControlActionBarItemView> * _Nonnull(^_Nonnull)(void))barButtonItemBuilder;
+ (id<GXControlCustomActionBarItem>)customActionBarItemControlWithParentControl:(id<GXControlWithActionBarItems>)parentControl
																	controlName:(NSString *)controlName
															 positionDescriptor:(nullable id<GXActionBarUIPositionDescriptor>)positionDesc
															 alertActionBuilder:(UIAlertAction<GXControlActionBarItemView> * _Nonnull(^_Nonnull)(BOOL destructiveStyleAllowed))alertActionBuilder;
+ (id<GXControlCustomActionBarItem>)customActionBarItemControlWithParentControl:(id<GXControlWithActionBarItems>)parentControl
																	controlName:(NSString *)controlName
															 positionDescriptor:(nullable id<GXActionBarUIPositionDescriptor>)positionDesc
													segmentedControlItemBuilder:(GXSegmentedControlItem<GXControlActionBarItemView> * _Nonnull(^_Nonnull)(void))segmentedControlItemBuilder;

#pragma mark - GXActionBarUIPositionDescriptor Builders

+ (id<GXActionBarUIPositionPriorityBasedDescriptor>)actionBarUIPositionDescriptorWithPriority:(GXActionBarUIPriorityType)priority;

+ (id<GXActionBarUIPositionCustomDescriptor>)actionBarUIPositionDescriptorWithHorizontalAlign:(GXHorizontalAlignType)hAlign
																				verticalAlign:(GXVerticalAlignType)vAlign;

@end

NS_ASSUME_NONNULL_END
