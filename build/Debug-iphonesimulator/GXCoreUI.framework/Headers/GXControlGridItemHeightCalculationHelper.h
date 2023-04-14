//
//  GXControlGridItemHeightCalculationHelper.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 06/09/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

#import <GXCoreUI/GXControlGridHeightCalculationHelper.h>
#import <GXCoreUI/GXControlTableForHeightCalculation.h>

@class GXControlGridHeightCalculationHelper;

NS_ASSUME_NONNULL_BEGIN

@interface GXControlGridItemHeightCalculationHelper : NSObject

- (instancetype)initWithGridHeightCalculationHelper:(GXControlGridHeightCalculationHelper *)helper
								  rootLayoutElemnet:(id <GXLayoutElementTable>)rootLayoutElement
										 layoutName:(NSString *)layoutName NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

@property(nullable, nonatomic, weak, readonly) GXControlGridHeightCalculationHelper *helper;
@property(nonatomic, strong, readonly) id <GXLayoutElementTable> rootLayoutElement;
@property(nonatomic, strong, readonly) NSString *layoutName;

@property(nonatomic, strong, readonly) GXControlTableForHeightCalculation *tableControl;
@property(nonatomic, assign, readonly) GXControlAutoHeightDependencyFlags rowHeightDependencyFlags;
@property(nonatomic, assign, readonly) CGFloat evenRowHeight;
@property(nonatomic, assign, readonly) CGFloat oddRowHeight;
@property(nonatomic, assign) BOOL forceRowHeightDynamic;

- (BOOL)isTableControlLoaded;
- (void)unloadTableControl;

- (BOOL)isRowHeightDynamic;
- (BOOL)isRowHeightDynamic:(BOOL * _Nullable)dueToEvenAndOddItemThemeClass;

- (void)invalidateRowHeightCalculationDataIfHasThemeClassDependency;

@end

NS_ASSUME_NONNULL_END
