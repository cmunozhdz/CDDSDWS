//
//  GXControlTableBase+ChildControls.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 28/7/15.
//  Copyright (c) 2015 Artech. All rights reserved.
//

#import <GXCoreUI/GXControlTable.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXControlTableBase (ChildControls)

- (void)initializeGridControlsAndLabelAligner;

- (void)enumerateGridControlsWithBlock:(void(^)(id <GXControl> control, NSUInteger rowIndex, NSUInteger cellIndex, BOOL *stop))block;

/**
 Enumerates the controls at the given row index.
 @discussion The row index MUST BE in the range 0..<self.tableLayout.layoutElementTableRows.count, or the method will crash.
 @par rowIndex The index of the row for which the controls will be enumerated
 @par block The code block to execute for each control in the row
 */
- (void)enumerateGridControlsAtRow:(NSUInteger)rowIndex block:(void(^)(id <GXControl> control, id <GXLayoutElementRow> row, NSUInteger cellIndex, id <GXLayoutElementCell> cell))block;

- (id <GXControl>)controlAtRow:(NSUInteger)rowIndex controlIndexInRow:(NSUInteger)cellIndex;

#if !TARGET_OS_WATCH
@property(nullable, nonatomic, strong, readonly) NSArray<UIView *> *horizontalRowSeparatorViews;
#endif // !TARGET_OS_WATCH
- (CGFloat)horizontalRulesHeight;

#if !TARGET_OS_WATCH
- (void)updateHorizontalRowSeparatorViewsFromCurrentStyleClass;
#endif // !TARGET_OS_WATCH

- (nullable GXStyleClass *)controlLayoutElementStyleClass:(id <GXControl>)control styleObject:(nullable GXStyleKBObject *)styleObject;

@end

NS_ASSUME_NONNULL_END
