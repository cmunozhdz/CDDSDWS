//
//  GXControlActionBarItem.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 3/8/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import UIKit;
#import <GXCoreUI/GXControlContainer.h>
#import <GXCoreUI/GXControlWithActionBarItems.h>
#import <GXCoreUI/GXSegmentedControlItem.h>

@protocol GXControlActionBarItem;
@protocol GXControlActionBarItemDelegate;
@protocol GXControlContainer;
@protocol GXControlWithActionBarItems;

typedef NS_ENUM(uint_least8_t, GXControlActionBarItemType) {
	GXControlActionBarItemTypeLayout,
	GXControlActionBarItemTypeCustom,
};

NS_ASSUME_NONNULL_BEGIN

@protocol GXControlActionBarItemView <NSObject>

@property(nullable, nonatomic, weak) id<GXControlActionBarItem> gxControlActionBarItem;

@end

typedef NS_ENUM(uint_least8_t, GXControlActionBarViewType) {
	GXControlActionBarViewTypeBarButtonItem,
	GXControlActionBarViewTypeAlertAction,
	GXControlActionBarViewTypeSegmentedControlItem,
};

@protocol GXControlActionBarItemViewReference;

@protocol GXControlActionBarItem <GXControlBaseProperties, GXActionBarUIDescriptor>

@property(assign, readonly) GXControlActionBarItemType controlActionBarItemType;
@property(nullable, nonatomic, weak, readonly) id <GXControlWithActionBarItems> controlActionBarItemParentControl;
@property(nullable, nonatomic, weak) id <GXControlActionBarItemDelegate> controlActionBarItemDelegate;
@property(nullable, nonatomic, readonly) id<GXModelObject> controlActionBarItemModelObject;

@property(nonatomic, strong, readonly) id<GXControlActionBarItemViewReference> viewReference; // lazy loaded
@property(nonatomic, readonly, getter = isViewLoaded) BOOL viewLoaded;

/* Defines the type of the view
 
 viewType = BarButtonItem => [self.viewReference conformsToProtocol:@protocol(GXControlActionBarButtonItem)]
 viewType = AlertAction => [self.viewReference conformsToProtocol:@protocol(GXControlActionBarAlertActionItem)]
 viewType = SegmentedControlItem => [self.viewReference conformsToProtocol:@protocol(GXControlActionBarSegmentedControlItem)]
 */
@property(nonatomic, assign, readonly) GXControlActionBarViewType viewType;

/// YES if the current styleClass is action bar default items class. NO if a custom style class has been set.
@property(nonatomic, readonly, getter = isStyleClassControlActionBarItemDefault) BOOL styleClassControlActionBarItemDefault;
/// Sets themeClass and styleClassControlActionBarItemDefault = YES
- (void)setActionBarDefaultStyleClass:(nullable GXStyleClass *)styleClass;

@optional

/* Returns YES if the given view type is supported
 
 If not implemented, only current viewType value is supported.
 Note: Returned value must match setViewType: result. If returns YES for a view type different than current viewType value, setViewType: must be implemented.
 */
- (BOOL)isViewTypeSupported:(GXControlActionBarViewType)viewType;

/* Allows changing the control view type
 
 If not implemented, only current viewType value is supported.
 Note: Returned value must match isViewTypeSupported: result. If returns YES for a view type different than current viewType value, isViewTypeSupported: must be implemented.
 */
- (BOOL)setViewType:(GXControlActionBarViewType)viewType;

@end


@protocol GXControlActionBarItemDelegate <NSObject>

- (void)controlActionBarItemVisibleChanged:(id <GXControlActionBarItem>)controlActionBarItem;
- (void)controlActionBarItemViewInvalidated:(id <GXControlActionBarItem>)controlActionBarItem;

@end

@protocol GXControlActionBarItemViewProxy <NSObject>

@property(nonatomic, assign) BOOL enabled;

- (void)applyStyleClass:(nullable GXStyleClass *)themeClass propertyDefaultResolver:(nullable id<GXStyleClassPropertyDefaultResolver>)resolver;

@optional
@property(nonatomic, assign) BOOL visible;
@property(nullable, nonatomic, copy) NSString *caption;
@property(nullable, nonatomic, copy) NSString *badgeText;

@end

@protocol GXControlActionBarItemViewReference <NSObject>

@property(nullable, nonatomic, weak) id<GXControlActionBarItem> controlActionBarItem; // owner GXControlActionBarItem
@property(nonatomic, strong, readonly) id<GXControlActionBarItemView> view;
@property(nonatomic, strong, readonly) id<GXControlActionBarItemViewProxy> viewProxy;
@property(nonatomic, assign, readonly) GXControlActionBarViewType viewType;

@end

@protocol GXControlActionBarButtonItem <GXControlActionBarItemViewReference> // self.viewType == BarButtonItem

@property(nonatomic, strong, readonly) UIBarButtonItem<GXControlActionBarItemView> *barButtonItem; // same as self.view

@end

@protocol GXControlActionBarAlertActionItem <GXControlActionBarItemViewReference> // self.viewType == AlertAction

@property(nonatomic, strong, readonly) UIAlertAction<GXControlActionBarItemView> *alertActionView; // same as self.view

@property(nonatomic, assign) BOOL destructiveStyleAllowed;

@property(nonatomic, assign) id<GXEntityDataWithOverrideValues> entityData;

- (void)invalidateAlertActionView;

@end

@protocol GXControlActionBarSegmentedControlItem <GXControlActionBarItemViewReference> // self.viewType == SegmentedControlItem

@property(nonatomic, strong, readonly) GXSegmentedControlItem<GXControlActionBarItemView> *segmentedControlItem; // same as self.view

@end


@protocol GXControlLayoutActionBarItem <GXControlActionBarItem, GXControlBaseRuntimeProperties, GXNamedControlElement> // controlActionBarItemType == GXControlActionBarItemTypeLayout

@property(nonatomic, strong, readonly) id<GXLayoutActionBarItem> layoutActionBarItem;

@optional
@property(nullable, nonatomic, strong) NSString *caption;
@property(nullable, nonatomic, strong) NSString *badgeText;

@end


@protocol GXControlLayoutActionBarGroup <GXControlBaseProperties, GXControlBaseRuntimeProperties, GXNamedControlElement>

@property(nonatomic, strong, readonly) id<GXLayoutActionBar> layoutActionBarGroup;
@property(nullable, nonatomic, weak, readonly) id <GXControlWithActionBarItems> groupControlParentControl;
@property(nullable, nonatomic, weak) id <GXControlActionBarItemDelegate> controlActionBarGourpItemsDelegate;

@property(nonatomic, strong, readonly) NSArray<id<GXControlLayoutActionBarItem>> *groupControlLayoutActionBarItems;

@end


@protocol GXControlLayoutActionBarGroupItem <GXControlLayoutActionBarItem, GXControlLayoutActionBarGroup>

@property(nonatomic, strong, readonly) id<GXLayoutActionBarGroupItem> layoutActionBarGroupItem;

@end



@protocol GXControlCustomActionBarItem <GXControlActionBarItem> // controlActionBarItemType == GXControlActionBarItemTypeCustom

@end

NS_ASSUME_NONNULL_END
