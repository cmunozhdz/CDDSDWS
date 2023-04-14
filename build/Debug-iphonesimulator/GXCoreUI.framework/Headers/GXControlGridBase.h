//
//  GXControlGridBase.h
//  GXFlexibleClient
//
//  Created by Guillermo Pasquero on 10/4/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import GXObjectsModel;
@import GXDataLayer;
#import <GXCoreUI/GXControlContainerBase.h>
#import <GXCoreUI/GXControlTableGridItem.h>
#if !TARGET_OS_WATCH
#import <GXCoreUI/GXViewLayoutDelegationProtocol.h>
#endif // !TARGET_OS_WATCH

NS_ASSUME_NONNULL_BEGIN

#if !TARGET_OS_WATCH
@interface GXControlGridBase : GXControlContainerBase <GXControlGrid, GXEntityDataListProviderDelegate, GXEntityDataListSearchProviderDelegate, GXViewLayoutDelegate, GXActionControllerDelegate>
#else
@interface GXControlGridBase : GXControlContainerBase <GXControlGrid, GXEntityDataListProviderDelegate, GXEntityDataListSearchProviderDelegate, GXActionControllerDelegate>
#endif // !TARGET_OS_WATCH
{
@protected
	BOOL							_autoLoad;
}

extern NSString *const GXControlGridEventNameSelectionChanged;

@property(nullable, nonatomic, strong, readonly) id <GXEntityDataListSearchProvider> entityDataListSearchProvider;
@property(nullable, nonatomic, strong, readonly) id <GXEntityDataListOrderProvider> entityDataListOrderProvider;
@property(nullable, nonatomic, strong, readonly) id <GXEntityDataListBreakByProvider> entityDataListBreakByProvider;
@property(nullable, nonatomic, strong, readonly) id <GXEntityDataListAdvancedFilterProvider> entityDataListAdvancedFilterProvider;
@property(nullable, nonatomic, strong, readonly) id <GXEntityDataListFieldBasedProvider> entityDatataListFieldBasedProvider;
@property(nullable, nonatomic, strong, readonly) id <GXEntityDataListSDTProvider> entityDatataListSDTProvider;
@property(nonatomic, strong, readonly) id <GXLayoutElementGrid> gridElement;
#if !TARGET_OS_WATCH
@property(nullable, nonatomic, strong, readonly) UIView *gridView;
#endif // !TARGET_OS_WATCH
@property(nullable, nonatomic, strong, readonly) GXStyleClass *listItemEvenItemClass;
@property(nullable, nonatomic, strong, readonly) GXStyleClass *listItemOddItemClass;
@property(nonatomic, assign, readonly) BOOL sameOddAndEvenListItemStyleClass;
@property(nonatomic, strong, readonly) id <GXCodingPropertiesObject> properties;
@property(nonatomic, assign, readonly) BOOL autoLoad;
@property(nullable, nonatomic, strong, readonly) id <GXEventDescriptor> defaultActionEventDescriptor;

@property(nullable, nonatomic, strong, readonly) id <GXEntityListFilterSearch> filterSearch;
@property(nullable, nonatomic, strong, readonly) id <GXEntityListFilterAdvanced> filterAdvanced;
@property(nullable, nonatomic, strong, readonly) NSArray<id<GXEntityListOrder>> *orders;

@property(nonatomic, readonly) BOOL currentOrderHasGroupBy;
- (BOOL)currentOrderHasGroupBy:(BOOL)filtered;

#if !TARGET_OS_WATCH
/**
 * Indicates whether the item's tables should handle the highlighting
 * Default implementation returns NO
 */
@property(nonatomic, assign, readonly) BOOL tableControlHandlesHighlighting;
#endif // !TARGET_OS_WATCH

- (BOOL)canExecuteDefaultActionForEntityAtIndex:(NSUInteger)index section:(NSUInteger)section; // filtered:NO
- (BOOL)canExecuteDefaultActionForEntityAtIndex:(NSUInteger)index section:(NSUInteger)section filtered:(BOOL)filtered;

- (nullable id <GXActionHandler>)executeDefaultActionForEntityAtIndex:(NSUInteger)index section:(NSUInteger)section fromGxControlTable:(nullable GXControlTable *)table; // filtered:NO
- (nullable id <GXActionHandler>)executeDefaultActionForEntityAtIndex:(NSUInteger)index section:(NSUInteger)section filtered:(BOOL)filtered fromGxControlTable:(nullable GXControlTable *)table;

- (nullable id <GXActionHandler>)executeDefaultActionForEntityAtIndex:(NSUInteger)index section:(NSUInteger)section userInterfaceContext:(nullable GXUserInterfaceContext *)uiContext; // filtered:NO
- (nullable id <GXActionHandler>)executeDefaultActionForEntityAtIndex:(NSUInteger)index section:(NSUInteger)section filtered:(BOOL)filtered userInterfaceContext:(nullable GXUserInterfaceContext *)uiContext;

+ (Class)gxControlTableGridItemClass;
#if !TARGET_OS_WATCH
@property(nonatomic, readonly) BOOL gxControlTableGridItemAutoGrow; // Default to YES
@property(nonatomic, readonly) BOOL gxControlTableGridItemPercentDimensionAs100; // Default to NO
- (GXControlTableGridItem *)gxControlTableForEntityAtIndex:(NSUInteger)index section:(NSUInteger)section; // withStyleClass:nil
- (GXControlTableGridItem *)gxControlTableForEntityAtIndex:(NSUInteger)index section:(NSUInteger)section withStyleClass:(nullable GXStyleClass *)styleClass; // filtered:NO
- (GXControlTableGridItem *)gxControlTableForEntityAtIndex:(NSUInteger)index section:(NSUInteger)section filtered:(BOOL)filtered; // withStyleClass:nil
- (GXControlTableGridItem *)gxControlTableForEntityAtIndex:(NSUInteger)index section:(NSUInteger)section filtered:(BOOL)filtered withStyleClass:(nullable GXStyleClass *)styleClass;
- (GXControlTableGridItem *)gxControlTableForEntityAtIndex:(NSUInteger)index
												   section:(NSUInteger)section
												layoutName:(nullable NSString *)lowercaseLayoutName
												styleClass:(nullable GXStyleClass *)styleClass
												entityData:(nullable id <GXEntityDataWithOverrideValues>)entityData; // filtered:NO
- (GXControlTableGridItem *)gxControlTableForEntityAtIndex:(NSUInteger)index
												   section:(NSUInteger)section
												  filtered:(BOOL)filtered
												layoutName:(nullable NSString *)lowercaseLayoutName
												styleClass:(nullable GXStyleClass *)styleClass
												entityData:(nullable id <GXEntityDataWithOverrideValues>)entityData;
#else
- (GXControlTableGridItem *)gxControlTableForEntityAtIndex:(NSUInteger)index
												   section:(NSUInteger)section
												  filtered:(BOOL)filtered
							  withInterfaceObjectsProvider:(id<GXControlInterfaceObjectsProvider>)interfaceObjectsProvider
												styleClass:(nullable GXStyleClass *)styleClass;
- (GXControlTableGridItem *)gxControlTableForEntityAtIndex:(NSUInteger)index
												   section:(NSUInteger)section
												  filtered:(BOOL)filtered
												layoutName:(nullable NSString *)lowercaseLayoutName
							  withInterfaceObjectsProvider:(id<GXControlInterfaceObjectsProvider>)interfaceObjectsProvider
												styleClass:(nullable GXStyleClass *)styleClass
												entityData:(nullable id <GXEntityDataWithOverrideValues>)entityData;
#endif // !TARGET_OS_WATCH


- (nullable NSArray<NSNumber *> *)controlIndexerForEntityAtIndex:(NSUInteger)index section:(NSUInteger)section; // filtered:NO
- (nullable NSArray<NSNumber *> *)controlIndexerForEntityAtIndex:(NSUInteger)index section:(NSUInteger)section filtered:(BOOL)filtered;
- (NSArray<NSNumber *> *)indexerByAddingIndex:(NSUInteger)index;


- (nullable id)valueForEntityDataFieldName:(NSString *)fieldName
							fieldSpecifier:(nullable NSString *)fieldSpecifier
						  forEntityAtIndex:(NSUInteger)index
								   section:(NSUInteger)section
							   enitityData:(inout id<GXEntityDataWithOverrideValues> __strong _Nullable * _Nullable)entityData
						   fieldDescriptor:(inout id<GXEntityDataFieldDescriptor> __strong _Nullable * _Nullable)fieldDesc
								   indexer:(inout NSArray * __strong _Nullable * _Nullable)indexer
					 indexedFieldSpecifier:(inout NSString * __strong _Nullable * _Nullable)indexedFieldSpecifier; // filtered:NO

- (nullable id)valueForEntityDataFieldName:(NSString *)fieldName
							fieldSpecifier:(nullable NSString *)fieldSpecifier
						  forEntityAtIndex:(NSUInteger)index
								   section:(NSUInteger)section
								  filtered:(BOOL)filtered
							   enitityData:(inout id<GXEntityDataWithOverrideValues> __strong _Nullable * _Nullable)entityData
						   fieldDescriptor:(inout id<GXEntityDataFieldDescriptor> __strong _Nullable * _Nullable)fieldDesc
								   indexer:(inout NSArray * __strong _Nullable * _Nullable)indexer
					 indexedFieldSpecifier:(inout NSString * __strong _Nullable * _Nullable)indexedFieldSpecifier;

- (void)showError:(NSError *)error;


/*!
 Retruns entity data from provider at given index and section, applying the corresponding indexer to obtain only the data for that row

 @param index The grid item index in section
 @param section The grid section index
 @result Entity data from provider applying the corresponding indexer
 */
- (nullable id<GXEntityDataWithOverrideValues>)entityDataApplyingIndexerForEntityAtIndex:(NSUInteger)index section:(NSUInteger)section; // filtered:NO
/*!
 Retruns entity data from provider at given index and section, applying the corresponding indexer to obtain only the data for that row
 
 @param index The grid item index in section
 @param section The grid section index
 @param filtered YES for filtered entity data, NO otherwise
 @result Entity data from provider applying the corresponding indexer
 */
- (nullable id<GXEntityDataWithOverrideValues>)entityDataApplyingIndexerForEntityAtIndex:(NSUInteger)index section:(NSUInteger)section filtered:(BOOL)filtered;

/**
 * Retruns the item layout lowercase name for the given entityData and indexPath.
 * If the gridElement doesn't have multiple item layouts this methods returns nil.
 */
- (nullable NSString *)layoutGridItemNameForEntityData:(nullable id<GXEntityData>)entityData atIndex:(NSUInteger)index section:(NSUInteger)section; // filtered:NO
- (nullable NSString *)layoutGridItemNameForEntityData:(nullable id<GXEntityData>)entityData atIndex:(NSUInteger)index section:(NSUInteger)section filtered:(BOOL)filtered;

#if !TARGET_OS_WATCH
/*
 * Called on [_mainView layoutSubviews]
 * Default implementation sets grid view frame with contentFrame
 */
- (void)layoutControls;

/// Sets the given frame to gridView. Called on layoutControls.
- (void)setGridViewFrame:(CGRect)gridViewFrame;

/**
 * Indicates whether the grid's view handles the content insets from it's frame
 * Default implementation returns NO
 */
@property(nonatomic, assign, readonly) BOOL gridViewHandlesContentInsets;

/*!
 Returns the grid's view frame given the control's view frame
 
 @param viewFrame Control's view frame.
 @result The frame for self.gridView.
 @discussion Default implementations retuns, if self.gridViewHandlesContentInsets, the given viewFrame with the origin at CGPointZero, otherwise [self contentFrameForViewFrame:viewFrame].
 */
- (CGRect)gridViewFrameForViewFrame:(CGRect)viewFrame;

/// Returns YES if the gridView width matches the panel full width and it's position is at top, NO otherwise.
@property(nonatomic, assign, readonly) BOOL gridViewIsAtTopWithFullWidth;
/// Returns YES if the gridView size matches the panel full size, NO otherwise. Note gridViewFillsFullPanel => gridViewIsAtTopWithFullWidth
@property(nonatomic, assign, readonly) BOOL gridViewFillsFullPanel;
/// Invalidate cached values of gridViewIsAtTopWithFullWidth and gridViewFillsFullPanel
- (void)invalidateIsAtTopWithFullWidthAndFillsFullPanel;

#endif // !TARGET_OS_WATCH

/**
 * Grid should reload it's UI with the providers data
 * loadInfo may contain information of changes and previous provider state, see GXEntityDataListProvider* keys in GXEntityDataListProvider protocol definition
 * Default implementation calls [self reloadData]
 * Override this method use loadInfo when reloading (ie. for animations), and also implement reloadData with: { [self reloadData:nil]; }
 */
- (void)reloadData:(nullable NSDictionary<NSString *, id> *)loadInfo;

/**
 * Grid view was removed from view hierancy and empty data set views were added.
 * Override this method to clean grid view loaded items.
 */
- (void)reloadOnEmptyDataSet;

/*!
 Show or hide grid view to allow empty data set views to be displayed
 
 @param emtyDataSetViewsVisible Empty data set views visibility.
 @result NO if empty data set views could not be displayed.
 @discussion Default implementations set [[self gridView] setHidden:emtyDataSetViewsVisible] and returns YES.
 */
- (BOOL)updateGridViewOnEmtyDataSetViewsVisible:(BOOL)emtyDataSetViewsVisible;

#pragma mark - Delayed loading helpers
/**
 * These methos are usefull for making the provider load after an event plus a delay
 * Sample: used to delay first remote load when searching
 */

/*!
 Checks if there is a delayed load scheduled
 
 @result YES if there is a delayed load shceduled, NO otherwise
 */
- (BOOL)isProviderDelayedLoadScheduled;

/// Performs a load if there is a delayed load scheduled
- (void)loadProviderDelayed;

/*!
 Schedules a delayed load
 
 @param delay The time in seconds to perform a delayed load
 @discussion Calling this method cancels any previous shceduled load
 */
- (void)scheduleProviderDelayedLoad:(NSTimeInterval)delay;

/// Cancels previous shceduled load (if shceduled)
- (void)cancelProviderDelayedLoadIfNeeded;

#pragma mark - Abstract
/**
 * Grid should reload it's UI with the providers data
 * Abstract (must override and do not call super)
 */
- (void)reloadData;
#if !TARGET_OS_WATCH
/**
 * Retruns a new UIView for the grid. Could be called multiple times (after unloadView is called)
 * Abstract (must override and do not call super)
 */
- (UIView *)newGridViewWithFrame:(CGRect)frame;
#endif // !TARGET_OS_WATCH

@end


#pragma mark - Reuse

#if !TARGET_OS_WATCH
@interface GXControlGridBaseReuseContext : GXControlContainerBaseReuseContext

@property(nonatomic, assign) BOOL reloadGridItems;

@end

@interface GXControlGridBase (Reuse)

@property(nullable, nonatomic, strong, readonly) GXControlGridBaseReuseContext *gridReuseContext;

@end
#endif // !TARGET_OS_WATCH

NS_ASSUME_NONNULL_END
