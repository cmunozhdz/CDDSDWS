//
//  GXSegmentedControlItem.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 7/8/17.
//  Copyright © 2017 GeneXus. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@interface GXSegmentedControlItem : NSObject

- (instancetype)initWithHandler:(void (^ __nullable)(GXSegmentedControlItem *item))handler NS_DESIGNATED_INITIALIZER;

/// Referenced segmented control
@property(nullable, nonatomic, weak) UISegmentedControl *segmentedControl;

/// Index of the item in the referenced segmented control (or NSNotFound)
@property(nonatomic, assign) NSUInteger segmentedControlItemIndex;

- (void)handleItemSelected;

- (void)insertIntoSegmentedControl:(UISegmentedControl *)segmentedControl atIndex:(NSUInteger)segment animated:(BOOL)animated;
- (void)removeFromSegmentedControl:(BOOL)animated;

@property(nonatomic, assign) BOOL enabled;
@property(nullable, nonatomic, strong) NSString *title;
@property(nullable, nonatomic, strong) UIImage *image;

@end

NS_ASSUME_NONNULL_END
