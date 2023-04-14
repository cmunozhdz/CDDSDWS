//
//  GXEntityViewController.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 03/02/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import GXObjectsModel;
@import GXDataLayer;
#import <GXCoreUI/GXActionControllerDelegateProtocol.h>
#import <GXCoreUI/GXViewController.h>
#import <GXCoreUI/GXEntityActionBarItemReference.h>
#import <GXCoreUI/GXEntityControllerProtocol.h>
#import <GXCoreUI/GXEntityListFilterAdvancedViewController.h>
#import <GXCoreUI/GXEntityModelProtocol.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint_least8_t, GXEntityStandardActionType) {
	GXEntityStandardActionNone,
	GXEntityStandardActionUpdate,
	GXEntityStandardActionDelete,
	GXEntityStandardActionSave,
	GXEntityStandardActionCancel
};

#pragma mark -

@interface GXEntityViewController : GXViewController <GXEntityControllerProtocol, GXEntityListFilterAdvancedViewControllerDelegate, GXActionControllerDelegate> {
	
@protected
	GXListSelectionModeType _selectionMode;
}

@property(nonatomic, strong, readonly) id <GXEntityDataProvider> entityDataProvider;
@property(nonatomic, strong, readonly) id <GXEntityModel> entityModel;
@property(nonatomic, setter=setMode:) GXModeType mode;
@property(nonatomic, assign) BOOL updateModeAllowsDelete;
@property(nonatomic, assign) GXListSelectionModeType selectionMode;

- (void)setupWithEntityDataProvider:(id <GXEntityDataProvider>)entityDataProvider
						entityModel:(id <GXEntityModel>)entityModel;

- (void)setMode:(GXModeType)mode;
- (void)setMode:(GXModeType)mode animated:(BOOL)animated;

- (BOOL)navigateToRelatedEntityWithContextEntityData:(id<GXEntityData>)contextEntityData
											relation:(GXBusinessComponentRelation *)relation
											 context:(nullable GXPresentationContext *)context;

#pragma mark - Layout Helpers

@property(nonatomic, strong, readonly) id <GXLayout> currentLayout;

#pragma mark - Data by data provider

- (nullable id)valueForKey:(id <NSCopying>)key dataProviderName:(NSString *)dpName;
- (void)setValue:(nullable id)value forKey:(id <NSCopying>)key dataProviderName:(NSString *)dpName;
- (void)removeValueForKey:(id <NSCopying>)key dataProviderName:(NSString *)dpName; // same as setValue:forKey:dataProviderName: with nil value

- (nullable NSDictionary<NSString *, id> *)valuesByDataProviderNameForKey:(id <NSCopying>)key;
- (void)setValuesByDataProviderName:(nullable NSDictionary<NSString *, id> *)valuesByDpName forKey:(id <NSCopying>)key;
- (void)removeValuesForDataProviderNames:(nullable NSArray<NSString *> *)dpNames forKey:(id <NSCopying>)key;
- (void)removeValuesForAllDataProviderNamesForKey:(id <NSCopying>)key; // same as removeValuesForDataProviderNames:forKey: with nil dpNames

#pragma mark - Control Properties

- (nullable id)valueForFormPropertyName:(NSString *)lowercaseName;
- (BOOL)applyFormPropertyName:(NSString *)lowercaseName value:(nullable id)value;
- (BOOL)executeFormMethodName:(NSString *)lowercaseName withParameters:(NSArray *)parameters;

- (nullable id)valueForApplicationBarPropertyName:(NSString *)lowercaseName;
- (BOOL)applyApplicationBarPropertyName:(NSString *)lowercaseName value:(nullable id)value;
- (BOOL)executeApplicationBarMethodName:(NSString *)lowercaseName withParameters:(NSArray *)parameters;

#pragma mark - Actions Methods

/// Clears caches of actions
- (void)invalidateLoadedActions;

/// Clears caches of actions and asynchonically refreshes action bar
- (void)needsReloadActions;
/// Same as needsReloadActions but also marks animation needed or not with the given parameter
- (void)needsReloadActionsAnimated:(BOOL)animated;

/**
 * Calls continueExecutingActionWithEntities: with the corresponding entities
 * Returns NO if the action is not executing or the corresponding grid is not found or
 * there is another multiline action waiting for selection, YES otherwise.
 * If the action iteration type is Selection, it continues action execution asynchronous, synchronous otherwise.
 */
- (BOOL)entitiesForExecuteMultilineAction:(id <GXMultilineActionHandler, GXActionUIHandler>)actionHandler;

/**
 * Clears the selection of the corresponding grid for the given action handler if is executing
 */
- (void)clearSelectionForExecutingMultilineAction:(id <GXMultilineActionHandler, GXActionUIHandler>)actionHandler;

#pragma mark Standard Actions

- (nullable GXEntityActionBarItemActionReference *)standardUpdateActionReference;
- (nullable GXEntityActionBarItemActionReference *)standardDeleteActionReference;
- (nullable GXEntityActionBarItemActionReference *)standardSaveActionReference;
- (nullable GXEntityActionBarItemActionReference *)standardCancelActionReference;

- (void)setNeedsToReloadStandardActionsForMode:(GXModeType)mode;
- (void)setNeedsToReloadStandardActionsForCurrentMode;

- (GXEntityStandardActionType)isStandardAction:(id <GXActionDescriptor>)actionDesc mode:(GXModeType)mode;

- (BOOL)loadStandardUpdateActionReference:(out GXEntityActionBarItemActionReference * __nullable * __nullable)updateRef
			standardDeleteActionReference:(out GXEntityActionBarItemActionReference * __nullable * __nullable)deleteRef
			  standardSaveActionReference:(out GXEntityActionBarItemActionReference * __nullable * __nullable)saveRef
			standardCancelActionReference:(out GXEntityActionBarItemActionReference * __nullable * __nullable)cancelRef
									model:(id <GXEntityModel>)model
									 mode:(GXModeType)mode;
- (void)loadStandardUpdateActionReference:(out GXEntityActionBarItemActionReference * __nullable * __nullable)updateRef
			standardDeleteActionReference:(out GXEntityActionBarItemActionReference * __nullable * __nullable)deleteRef
			  standardSaveActionReference:(out GXEntityActionBarItemActionReference * __nullable * __nullable)saveRef
			standardCancelActionReference:(out GXEntityActionBarItemActionReference * __nullable * __nullable)cancelRef
									 mode:(GXModeType)mode;

#pragma mark Actions UI Items

- (UIBarButtonItem *)refreshButtonItem;
- (BOOL)hasMoreActions;
- (nullable UIBarButtonItem *)moreActionsButton;
- (nullable UIBarButtonItem *)filtersButtonItem;

- (nullable NSMutableArray<UIBarButtonItem *> *)navigationBarLeftActionButtonItems; // Left to right
- (nullable NSMutableArray<UIBarButtonItem *> *)navigationBarRightActionButtonItems; // Right To left
- (nullable NSMutableArray<UIBarButtonItem *> *)toolbarActionButtonItems;

- (void)refreshNavigationItem:(BOOL)animated;
- (void)refreshNavigationItemAnimatedIfNeeded;

- (void)refreshToolbarItems:(BOOL)animated;
- (void)refreshToolbarItemsAnimatedIfNeeded;

- (void)refreshToolbarItemsAndVisibility:(BOOL)animated; // Calls refreshToolbarItems: & refreshToolbarVisibility:
- (void)refreshToolbarItemsAndVisibilityAnimatedIfNeeded;

- (void)refreshActionBarActionsAnimated:(BOOL)animated; // Calls refreshNavigationItem:animated & refreshToolbarItemsAndVisibility:animated
- (void)refreshActionBarActionsAnimatedIfNeeded;

- (UIBarButtonItem *)newStandardCancelButtonItemWithTarget:(id)target
													action:(SEL)action;
- (UIBarButtonItem *)newStandardDoneButtonItemWithTarget:(id)target
												  action:(SEL)action;

#pragma mark Standard Actions UI Items

- (BOOL)hasStandardEditSave;
- (nullable UIBarButtonItem *)standardEditSaveButtonItem;
- (BOOL)hasStandardCancel;
- (nullable UIBarButtonItem *)standardCancelButtonItem;

#pragma mark Actions Handlers

- (BOOL)handleBarButtonMoreActions:(nullable id)sender;

- (void)handleMultilineActionHandlerDidFinishSelecting:(UIBarButtonItem *)sender;

#pragma mark Standard Actions Handlers

- (void)handleStandardEdit:(nullable id)sender;
- (void)handleStandardSave:(nullable id)sender;
- (void)handleStandardCancel:(nullable id)sender;

#pragma mark Actions Override entry points

// Priority Masks to load action bar actions
- (GXActionBarUIPriorityType)moreItemsActionsPriorityMask;
- (GXActionBarUIPriorityType)navigationBarActionsPriorityMask;
- (GXActionBarUIPriorityType)toolbarActionsPriorityMask;

- (BOOL)isActionBarAction:(id <GXActionDescriptor>)actionDesc validForMode:(GXModeType)mode;
- (BOOL)shouldDisplayActionBarActionsForModel:(id <GXEntityModel>)model mode:(GXModeType)mode;

#pragma mark - Dynamic data

- (BOOL)shouldApplyDynamicDataFromProvider:(id <GXEntityDataProvider>)provider withError:(nullable NSError *)error;

#pragma mark - Abstract methods

- (nullable NSString *)editableBCName;

- (void)handleRefresh:(nullable id)sender; // Calls [self handleRefresh:sender keep:YES];
- (void)handleRefresh:(nullable id)sender keep:(BOOL)keep;

#pragma mark - Helper methods

- (nullable id <GXEntityDataWithOverrideValues>)providerLoadedEntityDataForCurrentMode:(id <GXEntityDataDetailProvider>)provider;
- (BOOL)canDisplayDataFromDetailProviderForCurrentMode:(id <GXEntityDataDetailProvider>)provider;
- (BOOL)allowReloadProviderIfNeededOnViewDidAppear:(id <GXEntityDataProvider>)provider;

- (void)applyShowGxApplicationBars:(BOOL)animated;

#pragma  mark - client refresh

- (void)executeClientRefreshEvenWithEntityData:(id<GXEntityDataWithOverrideValues>)entityData;

@end

NS_ASSUME_NONNULL_END
