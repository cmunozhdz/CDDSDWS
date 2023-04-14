//
//  GXControlGridBaseWithSelection.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 19/07/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

#import <GXCoreUI/GXControlGridBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXControlGridBaseWithSelection : GXControlGridBase

- (void)clearEntityDataSelectionModifiedIndexPaths;
- (void)clearFilteredEntityDataSelectionModifiedIndexPaths;

- (nullable NSArray<NSIndexPath *> *)selectedEntitiesIndexPaths;
- (nullable NSArray<NSIndexPath *> *)selectedFilteredEntitiesIndexPaths;

- (nullable NSArray<id<GXEntityData>> *)selectedEntitiesData;
- (nullable NSArray<id<GXEntityData>> *)selectedFilteredEntitiesData;


// Helper methods

//! Same as layoutGridItemNameForEntityData:atIndex:section: but also loads selected if not NULL
- (nullable NSString *)layoutGridItemNameForEntityData:(id<GXEntityData>)entityData atIndex:(NSUInteger)index section:(NSUInteger)section selected:(BOOL * _Nullable)selected; // filtered:NO
//! Same as layoutGridItemNameForEntityData:atIndex:section:filtered: but also loads selected if not NULL
- (nullable NSString *)layoutGridItemNameForEntityData:(id<GXEntityData>)entityData atIndex:(NSUInteger)index section:(NSUInteger)section filtered:(BOOL)filtered selected:(BOOL * _Nullable)selected;

- (void)fireSelectionChangedEventWithIndexPath:(NSIndexPath *)pIndexPath
									completion:(void (^ _Nullable)(void))block;

/*!
 Current resolved list selection style
 
 @result Current resolved list selection style, never equals GXListSelectionTypeDefault
 */
@property(nonatomic, assign, readonly) GXListSelectionType validResolvedSelectionType;

//! Invalidates validResolvedSelectionType, it will be reloaded on next call
- (void)invalidateValidResolvedSelectionType;



/*!
 Checks if the grid item is selected
 
 @param index The grid item index in section to check selection
 @param section The grid section index
 @result YES if the entity data at given index path is selected, NO otherwise
 */
- (BOOL)isEntityDataSelectedAtIndex:(NSUInteger)index section:(NSUInteger)section; // filtered:NO
/*!
 Checks if the grid item is selected
 
 @param index The grid item index in section to check selection
 @param section The grid section index
 @param filtered YES if the entity data is filtered, NO otherwise
 @result YES if the entity data at given index path is selected, NO otherwise
 */
- (BOOL)isEntityDataSelectedAtIndex:(NSUInteger)index section:(NSUInteger)section filtered:(BOOL)filtered;

/*!
 Selects/Deselects entity data at given index path
 
 @param index The grid item index in section to select/deselect
 @param section The grid section index
 @result YES if the entity data at given index path is selected, NO otherwise
 */
- (BOOL)selectEntityDataAtIndex:(NSUInteger)index section:(NSUInteger)section; // filtered:NO
/*!
 Selects/Deselects entity data at given index path
 
 @param index The grid item index in section to select/deselect
 @param section The grid section index
 @param filtered YES if the entity data is filtered, NO otherwise
 @result YES if the entity data at given index path is selected, NO otherwise
 */
- (BOOL)selectEntityDataAtIndex:(NSUInteger)index section:(NSUInteger)section filtered:(BOOL)filtered;

/*!
 Sets the selection for the entity data at given index path
 
 @param index The grid item index in section to apply selection
 @param section The grid section index
 @param selected The new value for the selection
 @result YES if the selection changed, NO otherwise
 */
- (BOOL)setEntityDataAtIndex:(NSUInteger)index section:(NSUInteger)section selected:(BOOL)selected; // filtered:NO
/*!
 Sets the selection for the entity data at given index path
 
 @param index The grid item index in section to apply selection
 @param section The grid section index
 @param filtered YES if the entity data is filtered, NO otherwise
 @param selected The new value for the selection
 @result YES if the selection changed, NO otherwise
 */
- (BOOL)setEntityDataAtIndex:(NSUInteger)index section:(NSUInteger)section filtered:(BOOL)filtered selected:(BOOL)selected;

/*!
 Checks if the default selection can be executed for the given index and section
 
 @param index The grid item index in section to evaluate
 @param section The grid section index
 @result YES if executeDefaultSelectionForEntityAtIndex:section: can be executed, NO otherwise
 */
- (BOOL)canExecuteDefaultSelectionForEntityAtIndex:(NSUInteger)index section:(NSUInteger)section; // filtered:NO
/*!
 Checks if the default selection can be executed for the given index and section
 
 @param index The grid item index in section to evaluate
 @param section The grid section index
 @param filtered YES if the entity data is filtered, NO otherwise
 @result YES if executeDefaultSelectionForEntityAtIndex:section: can be executed, NO otherwise
 */
- (BOOL)canExecuteDefaultSelectionForEntityAtIndex:(NSUInteger)index section:(NSUInteger)section filtered:(BOOL)filtered;

/*!
 Executes the default selection/deselection for the given index and section
 
 @param index The grid item index in section to execute default selection
 @param section The grid section index
 @result A set of NSIndexPath for the rows which selection changed
 */
- (nullable NSSet<NSIndexPath *> *)executeDefaultSelectionForEntityAtIndex:(NSUInteger)index section:(NSUInteger)section; // filtered:NO
/*!
 Executes the default selection/deselection for the given index and section
 
 @param index The grid item index in section to execute default selection
 @param section The grid section index
 @param filtered YES if the entity data is filtered, NO otherwise
 @result A set of NSIndexPath for the rows which selection changed
 */
- (nullable NSSet<NSIndexPath *> *)executeDefaultSelectionForEntityAtIndex:(NSUInteger)index section:(NSUInteger)section filtered:(BOOL)filtered;

/*!
 Checks if selected highlight style should be applied while grid item is selected
 
 @result YES if GXHighlightStyleSelected should be applied while grid item is selected, NO otherwise
 @discussion Selected highlight style should be applied when resolved list selection style is keep while executing or until new selection and there is no default selected layout
 */
- (BOOL)shouldApplyHighlightStyleSelectedOnSelection;

#pragma mark - GXListSelectionTypeKeepUntilNewSelection Helpers

/*!
 Keeps track of action handler execution
 
 @param actionHandler The action handler to keep track execution
 @param index The grid item index in section of action handler execution
 @param section The grid section index
 @result YES if the action execution is being tracked, NO otherwise
 @discussion When the action finishes executing keepSelectionWhileExecutingActionHandler:forEntityAtIndex:section: is called.
 */
- (BOOL)keepSelectionWhileExecutingActionHandler:(id <GXActionHandler>)actionHandler
								forEntityAtIndex:(NSUInteger)index
										 section:(NSUInteger)section; // filtered:NO
/*!
 Keeps track of action handler execution
 
 @param actionHandler The action handler to keep track execution
 @param index The grid item index in section of action handler execution
 @param section The grid section index
 @param filtered YES if the entity data is filtered, NO otherwise
 @result YES if the action execution is being tracked, NO otherwise
 @discussion When the action finishes executing keepSelectionWhileExecutingActionHandler:forEntityAtIndex:section: is called.
 */
- (BOOL)keepSelectionWhileExecutingActionHandler:(id <GXActionHandler>)actionHandler
								forEntityAtIndex:(NSUInteger)index
										 section:(NSUInteger)section
										filtered:(BOOL)filtered;

/*!
 Called when the SelectionChanged Grid event is triggered to allow performing some additional actions to keep the selection while the event is running
 
 @param pIndexPath The index path of the selected item
 @param actionHandler The action handler executing the SelectionChanged event
 @discusion Default implementation does nothing
 */
- (void)keepSelectionWhileExecutingIfNeededForIndexPath:(NSIndexPath *)pIndexPath actionHandler:(id<GXActionHandler>)actionHandler;

/*!
 Call back for tracked action handler execution end, see keepSelectionWhileExecutingActionHandler:forEntityAtIndex:section:
 
 @param actionHandler The action handler that finished executing
 @param index The grid item index in section of action handler execution
 @param section The grid section index
 @param filtered YES if the entity data is filtered, NO otherwise
 @discussion Abstract, subclasses must override this method
 */
- (void)selectionWhileExecutingActionHandlerEnded:(id<GXActionHandler>)actionHandler
								 forEntityAtIndex:(NSUInteger)index
										  section:(NSInteger)section
										 filtered:(BOOL)filtered;

//! Stops tracking action execution, see keepSelectionWhileExecutingActionHandler:forEntityAtIndex:section:filtered:
- (void)stopKeepingSelectionWhileExecuting; // filtered and non filtered
- (void)stopKeepingSelectionWhileExecuting:(BOOL)filtered;

@end

NS_ASSUME_NONNULL_END
