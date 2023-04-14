//
//  GXEntityListFilterAdvancedViewController.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 31/01/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import GXObjectsModel;
@import GXDataLayer;
#import <GXCoreUI/GXEntityDataFieldViewController.h>
#import <GXCoreUI/GXCallerDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXControlGrid;

@class GXEntityListFilterAdvancedViewController;

#pragma mark -

@protocol GXEntityListFilterAdvancedViewControllerDelegate <GXInheritedConnectivitySupportResolver>

@required

- (void)entityListFilterAdvancedViewController:(GXEntityListFilterAdvancedViewController *)controller
					   didResolveToFieldValues:(nullable NSDictionary<NSString *, id<GXEntityListFilterAdvancedFieldValue>> *)values
									 withOrder:(nullable id<GXEntityListOrder>)order;

@end

#pragma mark -

/**
 * Default GXApplicationBarsAppearance gxApplicationBarsClassName method implementation returns nil
 * This class implements setGxApplicationBarsClassName:, callers can use this method to change the class
 */
@interface GXEntityListFilterAdvancedViewController : UITableViewController <UITextFieldDelegate, GXEntityDataFieldEditorViewControllerDelegate, GXEntityListFilterAdvancedViewControllerDelegate, GXCallerDelegate, GXApplicationBarsAppearance>

@property(nullable, nonatomic, strong, readonly) id <GXEntityListFilterAdvanced> entityListFilterAdvanced;
@property(nullable, nonatomic, strong, readonly) NSArray<id<GXEntityListOrder>> *entityListOrders;
@property(nullable, weak) id <GXEntityListFilterAdvancedViewControllerDelegate> delegate;
@property(nullable, nonatomic, strong) id context;
@property(nullable, nonatomic, strong) NSDictionary<NSString *, GXBusinessComponentRelation *> *relationsByDataElementName;

/**
 * When using the view controller as a "range picker", this is the field info to use to get/set the values
 */
@property(nullable, nonatomic, strong, readonly) id<GXEntityDataFieldInfo> rangePickerFieldInfo;

- (nullable instancetype)initWithGXControlGrid:(id<GXControlGrid>)gridControl;

- (nullable instancetype)initWithGXModel:(GXModel *)gxmodel
								  filter:(nullable id<GXEntityListFilterAdvanced>)filter
							filterValues:(nullable NSArray<id<GXEntityListFilterAdvancedFieldValue>> *)filterValues
								  orders:(nullable NSArray<id<GXEntityListOrder>> *)orders
						   selectedOrder:(NSUInteger)selectedOrder
							   relations:(nullable NSDictionary<NSString *, GXBusinessComponentRelation *> *)relationsByDataElementName;

- (nullable instancetype)initWithGXModel:(GXModel *)gxmodel
								  filter:(nullable id <GXEntityListFilterAdvanced>)filter
					   fieldValuesByName:(nullable NSDictionary<NSString *, id<GXEntityListFilterAdvancedFieldValue>> *)fieldValuesByName
								  orders:(nullable NSArray<id<GXEntityListOrder>> *)orders
						   selectedOrder:(NSUInteger)selectedOrder
							   relations:(nullable NSDictionary<NSString *, GXBusinessComponentRelation *> *)relationsByDataElementName
					rangePickerFieldInfo:(nullable id<GXEntityDataFieldInfo>)rangePickerFieldInfo NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithStyle:(UITableViewStyle)style NS_UNAVAILABLE;
- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
