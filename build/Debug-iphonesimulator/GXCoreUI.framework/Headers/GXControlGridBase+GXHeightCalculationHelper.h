//
//  GXControlGridBase+GXHeightCalculationHelper.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 5/5/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

#import <GXCoreUI/GXControlGridBase.h>
#import <GXCoreUI/GXControlGridHeightCalculationHelper.h>
#import <GXCoreUI/GXControlTableForHeightCalculation.h>

@class GXControlGridHeightCalculationHelper;
@class GXControlGridItemHeightCalculationHelper;

NS_ASSUME_NONNULL_BEGIN

@interface GXControlGridBase (GXHeightCalculationHelper)

@property(nonatomic, strong, readonly) GXControlGridHeightCalculationHelper *heightCalculationHelper;
@property(nullable, nonatomic, strong, readonly) GXControlGridHeightCalculationHelper *heightCalculationHelperIfLoaded;
- (BOOL)isHeightCalculationHelperLoaded;
/// GXControlTableForHeightCalculation to be used for height calculation. Called from GXControlGridItemHeightCalculationHelper.tableControl
- (GXControlTableForHeightCalculation *)newTableControlForHeightCalculation:(NSString *)layoutName;
- (Class)gxControlTableGridItemClassForHeightCalculation;

@property(nonatomic, assign, readonly) GXLayoutQuadDimension gridItemOddListItemThemeClassInsets;
@property(nonatomic, assign, readonly) GXLayoutQuadDimension gridItemEvenListItemThemeClassInsets;

- (GXLayoutQuadDimension)gridItemListItemThemeClassInsets:(BOOL)even;
- (CGFloat)gridItemListItemThemeClassHorizontalInsets:(BOOL)even;
- (CGFloat)gridItemListItemThemeClassVerticalInsets:(BOOL)even;


@property(nonatomic, assign, readonly) CGFloat relativeHeightForItemWithPercentHeight;
- (CGFloat)calculateRelativeHeightForItemWithPercentHeight:(CGRect)gridViewFrame;
- (void)onRelativeHeightForItemWithPercentHeightChanged:(CGFloat)oldRelativeHeightForItemWithPercentHeight;

@property(nonatomic, assign, readonly) CGFloat defaultGridItemHeight;

- (CGFloat)gridItemHeightForEntityDataAtIndex:(NSUInteger)index
									  section:(NSUInteger)section
									 filtered:(BOOL)filtered
									  context:(nullable id)context;
- (BOOL)shouldCalculateDynamicHeightForEntityData:(id <GXEntityDataWithOverrideValues>)entityData
										   helper:(GXControlGridItemHeightCalculationHelper *)itemHelper
										 atIndex:(NSUInteger)index
										 section:(NSUInteger)section
										filtered:(BOOL)filtered
										 context:(nullable id)context;
- (CGFloat)gridItemHeightForHeightCalculation:(BOOL)calculateDynamicHeight
								 ofEntityData:(id <GXEntityDataWithOverrideValues>)entityData
									   helper:(GXControlGridItemHeightCalculationHelper *)itemHelper
									  atIndex:(NSUInteger)index
									  section:(NSUInteger)section
									 filtered:(BOOL)filtered
									  context:(nullable id)context;
- (CGFloat)gridItemWidthForHeightCalculationOfEntityData:(id <GXEntityDataWithOverrideValues>)entityData
												 atIndex:(NSUInteger)index
												 section:(NSUInteger)section
												filtered:(BOOL)filtered
											  layoutName:(nullable NSString *)layoutName
												 context:(nullable id)context;
- (CGSize)gridItemSizeForHeightCalculation:(BOOL)calculateDynamicHeight
							  ofEntityData:(id <GXEntityDataWithOverrideValues>)entityData
									helper:(GXControlGridItemHeightCalculationHelper *)itemHelper
								   atIndex:(NSUInteger)index
								   section:(NSUInteger)section
								  filtered:(BOOL)filtered
								   context:(nullable id)context;
- (nullable NSDictionary<NSString *,id> *)gridItemTableAdditionalHeightContextOptionsForHelper:(GXControlGridItemHeightCalculationHelper *)itemHelper
																					tableFrame:(inout CGRect * _Nonnull)tableFrame
																					   atIndex:(NSUInteger)index
																					   section:(NSUInteger)section
																					  filtered:(BOOL)filtered
																					   context:(nullable id)context;
- (CGFloat)gridItemExtraHeightForEntityData:(id <GXEntityDataWithOverrideValues>)entityData
									atIndex:(NSUInteger)index
									section:(NSUInteger)section
								   filtered:(BOOL)filtered
								 layoutName:(nullable NSString *)layoutName
									context:(nullable id)context;
@property(nonatomic, assign, readonly) BOOL updateLoadedInfoItemHeights;

@end

@interface GXControlGridBase (GXSizeCalculationHelper)

@property(nonatomic, assign, readonly) CGSize relativeSizeForItemWithPercentDimension;
- (CGSize)calculateRelativeSizeForItemWithPercentDimension:(CGRect)gridViewFrame;
- (void)onRelativeSizeForItemWithPercentDimensionChanged:(CGSize)oldRelativeSizeForItemWithPercentDimension;

@property(nonatomic, assign, readonly) CGSize defaultGridItemSize;

@property(nonatomic, assign, readonly) CGFloat relativeWidthForItemWithPercentWidth;
- (CGFloat)calculateRelativeWidthForItemWithPercentWidth:(CGRect)gridViewFrame;
- (void)onRelativeWidthForItemWithPercentWidthChanged:(CGFloat)oldRelativeWidthForItemWithPercentWidth;

- (CGSize)gridItemSizeForEntityDataAtIndex:(NSUInteger)index
								   section:(NSUInteger)section
								  filtered:(BOOL)filtered
								   context:(nullable id)context;

- (CGSize)gridItemSizeForEntityDataAtIndex:(NSUInteger)index
								   section:(NSUInteger)section
								  filtered:(BOOL)filtered
								   context:(nullable id)context
							canIgnoreWidth:(BOOL)canIgnoreWidth;

- (void)updateRelativeSizeForItemWithPercentDimensionIfNeeded;

@end

NS_ASSUME_NONNULL_END
