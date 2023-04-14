//
//  GXControlGridHeightCalculationHelper.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 06/09/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

#import <GXCoreUI/GXControlGridBase.h>
#import <GXCoreUI/GXControlGridBase+GXHeightCalculationHelper.h>
#import <GXCoreUI/GXControlGridItemHeightCalculationHelper.h>

@class GXControlGridItemHeightCalculationHelper;

NS_ASSUME_NONNULL_BEGIN

@interface GXControlGridHeightCalculationHelper : NSObject

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithGridControl:(GXControlGridBase *)gridControl NS_DESIGNATED_INITIALIZER;

@property(nullable, nonatomic, weak, readonly) GXControlGridBase *gridControl;

@property(nonatomic, assign, readonly) GXControlGridItemHeightCalculationHelper *defaultLayoutItemHelper;
@property(nonatomic, strong, readonly) NSDictionary<NSString *, GXControlGridItemHeightCalculationHelper *> *itemsHelpersByLayoutName;

- (GXControlGridItemHeightCalculationHelper *)itemHelperForLayoutName:(nullable NSString *)layoutName;
- (void)enumerateItemsHelpersUsingBlock:(void(^)(NSString *layoutName, GXControlGridItemHeightCalculationHelper *itemHelper, BOOL *stop))block;

- (BOOL)hasMultipleItemsLayouts;
- (BOOL)hasItemWithPercentWidth;
- (BOOL)hasItemWithPercentHeight;
- (BOOL)hasItemWithPointWidth;
- (BOOL)hasItemWithPointHeight;

- (BOOL)isRowWidthDynamic;
- (BOOL)isRowHeightDynamic;

- (void)invalidateRowHeightCalculationDataIfHasThemeClassDependency;

@end

NS_ASSUME_NONNULL_END
