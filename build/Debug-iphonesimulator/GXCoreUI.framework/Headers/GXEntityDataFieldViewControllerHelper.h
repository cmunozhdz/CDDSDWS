//
//  GXEntityDataFieldViewControllerHelper.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 6/2/15.
//  Copyright (c) 2015 Artech. All rights reserved.
//

#import <GXCoreUI/GXEntityDataFieldViewControllerProtocol.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Viewer

@protocol GXEntityDataFieldViewControllerHelperDelegate;

@interface GXEntityDataFieldViewControllerHelper : NSObject <GXEntityDataFieldViewController>

@property(nullable, weak, readonly) UIViewController<GXEntityDataFieldViewController> *viewController;
@property(nullable, weak) id <GXEntityDataFieldViewControllerHelperDelegate> delegate; // Initialized with viewController if conforms to protocol

@property(nullable, nonatomic, strong, readonly) id <GXEntityData> readOnlyEntityData;
@property(nonatomic, strong, readonly) id<GXEntityDataFieldDescriptor> entityFieldDescriptor;
@property(nonatomic, strong, readonly) id<GXEntityDataFieldInfo> resolvedFieldInfo;
@property(nullable, nonatomic, strong, readonly) NSString *fieldSpecifier;
@property(nullable, nonatomic, strong, readonly) NSArray<NSNumber *> *indexer;

@property(nonatomic, strong, readonly) id<GXModelObject> modelObject;

- (instancetype)initWithViewController:(UIViewController<GXEntityDataFieldViewController> *)controller
					readOnlyEntityData:(nullable id<GXEntityData>)entityData
					   fieldDescriptor:(id<GXEntityDataFieldDescriptor>)fieldDesc
						fieldSpecifier:(nullable NSString *)fieldSpecifier
							   indexer:(nullable NSArray<NSNumber *> *)indexer NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

#pragma mark - Loading Helpers

- (nullable id)fieldValueFromReadOnlyEntityData;

#pragma mark - ViewController hooks

// These methods have to be called viewController's counterparts

/// Call on viewController's viewDidAppear:
- (void)onViewControllerViewDidAppear;
/// Call on viewController's didMoveToParentViewController:
- (void)onViewControllerDidMoveToParentViewController;
/// Call on viewController's dealloc with self as parameter
- (void)onViewControllerDealloc:(UIViewController<GXEntityDataFieldViewController> *)viewController;

#pragma mark - Action Handlers

/// Calls handleDone:completion:
- (void)handleDone;
/*!
 Dismisses view controller
 
 @discussion Calls dismissEntityDataFieldViewController:completion:
 */
- (BOOL)handleDone:(BOOL)animated completion:(void(^ _Nullable)(void))completion;

/*!
 Dismisses view controller
 
 @param animated YES if dismiss should be animated, NO otherwise.
 @param completion The block to execute after the view controller is dismissed. You may specify nil for this parameter.
 @result YES if dismiss was handled, NO otherwise. Completion will be called only it result is YES.
 @discussion Calls dismissEntityDataFieldViewController:animated:completion:. After view controller is dismissed calls completion block (if not nil) and finally calls entityDataFieldDelegate entityDataFieldViewControllerDismissed: if implemented.
 */
- (BOOL)dismissEntityDataFieldViewController:(BOOL)animated completion:(void(^ _Nullable)(void))completion;

@end

#pragma mark - Viewer Delegate

@protocol GXEntityDataFieldViewControllerHelperDelegate <NSObject>

@optional
- (void)entityDataFieldViewControllerHelper:(GXEntityDataFieldViewControllerHelper *)helper willDismissViewController:(BOOL)animated;

@end




#pragma mark - Editor

@protocol GXEntityDataFieldEditorViewControllerHelperDelegate;

@interface GXEntityDataFieldEditorViewControllerHelper : GXEntityDataFieldViewControllerHelper <GXEntityDataFieldEditorViewController>

@property(nullable, weak, readonly) UIViewController<GXEntityDataFieldEditorViewController> *editorViewController;
@property(nullable, weak, readonly) id <GXEntityDataFieldEditorViewControllerHelperDelegate> editorDelegate; // Sane as self.delegate. Initialized with editorViewController if conforms to protocol

@property(nullable, nonatomic, strong, readonly) id <GXEntityDataWithOverrideValues> entityData;
@property(nonatomic, assign) BOOL allowsNull;

- (instancetype)initWithEditorViewController:(UIViewController<GXEntityDataFieldEditorViewController> *)controller
								  entityData:(nullable id<GXEntityDataWithOverrideValues>)entityData
							 fieldDescriptor:(id<GXEntityDataFieldDescriptor>)fieldDesc
							  fieldSpecifier:(nullable NSString *)fieldSpecifier
									 indexer:(nullable NSArray<NSNumber *> *)indexer NS_DESIGNATED_INITIALIZER;

/*!
 Helper for editorDelegate entityDataFieldEditorViewControllerHelperCommitChanges: method
 
 @param newValue new value (before convertion if needed) to update entity data.
 @result The given newValue or converted value if needed is returned.
 @discussion Updates entity data with the given newValue (newValue or converted value if needed is returned) and calls entityDataFieldEditorDelegate entityDataFieldViewControllerDidUpdateFieldValue:.
 */
- (nullable id)updateEntityDataResolvedFieldWithValue:(nullable id)newValue;

/*!
 Dismisses view controller with the given success value
 
 @param success NO if edit was cancelled, YES otherwise.
 @param animated YES if dismiss should be animated, NO otherwise.
 @param completion The block to execute after the view controller is dismissed. You may specify nil for this parameter.
 @result YES if dismiss was handled, NO otherwise. Completion will be called only it result is YES.
 @discussion Calls entityDataFieldEditorDelegate entityDataFieldViewController:didFinishEditing: (with success) if implemented and isEditingEntityData = YES, otherwise calls dismissEntityDataFieldViewController:completion:. Commit changes after view controller is dismissed if shouldDelayEntityDataUpdatesUntilDissmissed, then calls completion block (if not nil) and finally calls entityDataFieldDelegate entityDataFieldViewControllerDismissed: if implemented.
 */
- (BOOL)dismissEntityDataFieldEditorViewControllerWithSuccess:(BOOL)success animated:(BOOL)animated completion:(void(^ _Nullable)(void))completion;

#pragma mark - Action Handlers

/// Calls handleSave:completion:
- (void)handleSave;
/*!
 Commit changes (delayed if needed) and dismisses view controller
 
 @discussion Default implementation calls editorDelegate entityDataFieldEditorViewControllerHelperCommitChanges: if updates should not be delayed (shouldDelayEntityDataUpdatesUntilDissmissed) and then calls dismissEntityDataFieldEditorViewControllerWithSuccess:YES animated:completion:
 */
- (BOOL)handleSave:(BOOL)animated completion:(void(^ _Nullable)(void))completion;

/// Calls handleCancel:completion:
- (void)handleCancel;
/*!
 Discards changes and dismisses view controller
 
 @discussion Default implementation calls editorDelegate entityDataFieldEditorViewControllerHelperIsEditingEntityData: (if implemented) and then calls dismissEntityDataFieldEditorViewControllerWithSuccess:NO animated:completion:
 */
- (BOOL)handleCancel:(BOOL)animated completion:(void(^ _Nullable)(void))completion;

@end


#pragma mark - Editor Delegate


@protocol GXEntityDataFieldEditorViewControllerHelperDelegate <GXEntityDataFieldViewControllerHelperDelegate>

- (void)entityDataFieldEditorViewControllerHelperCommitChanges:(GXEntityDataFieldEditorViewControllerHelper *)helper;

@optional
- (BOOL)entityDataFieldEditorViewControllerHelperIsEditingEntityData:(GXEntityDataFieldEditorViewControllerHelper *)helper;
- (void)entityDataFieldEditorViewControllerHelperDiscardChanges:(GXEntityDataFieldEditorViewControllerHelper *)helper;

@end

NS_ASSUME_NONNULL_END
