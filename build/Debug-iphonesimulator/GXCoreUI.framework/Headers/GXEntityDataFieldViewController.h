//
//  GXEntityDataFieldViewController.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 13/02/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import GXObjectsModel;
#import <GXCoreUI/GXEntityDataFieldViewControllerHelper.h>
#import <GXCoreUI/GXApplicationBarsAppearance.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Viewer

/**
 * Default GXApplicationBarsAppearance gxApplicationBarsClassName method implementation returns nil
 * This class implements setGxApplicationBarsClassName:, callers can use this method to change the class
 */
@interface GXEntityDataFieldViewerViewController : UIViewController <GXEntityDataFieldViewController, GXApplicationBarsAppearance, GXViewControllerAdaptativePresentation, GXEntityDataFieldViewControllerHelperDelegate>

@property(nonatomic, strong, readonly) GXEntityDataFieldViewControllerHelper *helper;

- (instancetype)initWithReadOnlyEntityData:(nullable id<GXEntityData>)entityData
						   fieldDescriptor:(id<GXEntityDataFieldDescriptor>)fieldDesc
							fieldSpecifier:(nullable NSString *)fieldSpecifier
								   indexer:(nullable NSArray<NSNumber *> *)indexer NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (nullable UIColor *)applyBackgroundColorOnViewDidLoadIfNeeded;

#pragma mark - Action Handlers

/*!
 Returns if default buttons must be used
 
 @result Restuns YES if default buttons must be used, NO otherwise
 @discussion Subclases may override this methods to avoid using default buttons.
 */
@property(assign, readonly) BOOL useDefaultActionHandlersBarButtons;

@property(assign, readonly) BOOL doneButtonEnabled;

- (void)invalidateDoneButtonEnabled;

/// Helper method for default done bar button, calls [self.helper handleDone]
- (void)handleDone;

#pragma mark - Override Points

/// Class for self.helper. Must be subclass of GXEntityDataFieldViewControllerHelper and subclass of GXEntityDataFieldEditorViewControllerHelper for subclasses of GXEntityDataFieldViewController.
+ (Class)editorHelperClass;

@end


#pragma mark - Editor


@interface GXEntityDataFieldViewController : GXEntityDataFieldViewerViewController <GXEntityDataFieldEditorViewController, GXEntityDataFieldEditorViewControllerHelperDelegate>

@property(nonatomic, strong, readonly) GXEntityDataFieldEditorViewControllerHelper *editorHelper; // same as self.helper

- (instancetype)initWithEntityData:(nullable id<GXEntityDataWithOverrideValues>)entityData
				   fieldDescriptor:(id<GXEntityDataFieldDescriptor>)fieldDesc
					fieldSpecifier:(nullable NSString *)fieldSpecifier
						   indexer:(nullable NSArray<NSNumber *> *)indexer NS_DESIGNATED_INITIALIZER;


#pragma mark - GXEntityDataFieldEditorViewControllerHelperDelegate Override Points

/*!
 Updates entity data from editor
 
 @discussion entityDataFieldEditorViewControllerHelperCommitChanges: calls this method. Default implementation does nothing. Subclasses must override this method to commit changes. See editorHelper updateEntityDataResolvedFieldWithValue:.
 */
- (void)commitChanges;

/*!
 Discard changes
 
 @discussion entityDataFieldEditorViewControllerHelperDiscardChanges: calls this method. Default implementation does nothing. Subclasses may override this method to revert changes when user cancels.
 */
- (void)discardChanges;

#pragma mark - Action Handlers

/// Helper method for default save bar button, calls [self.editorHelper handleSave]
- (void)handleSave;

/// Helper method for default cancel bar button, calls [self.editorHelper handleCancel]
- (void)handleCancel;

@end

NS_ASSUME_NONNULL_END
