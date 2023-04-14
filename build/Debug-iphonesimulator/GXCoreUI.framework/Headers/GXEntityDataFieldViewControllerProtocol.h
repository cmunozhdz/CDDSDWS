//
//  GXEntityDataFieldViewControllerProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 6/2/15.
//  Copyright (c) 2015 Artech. All rights reserved.
//

@import GXDataLayer;

NS_ASSUME_NONNULL_BEGIN

@protocol GXEntityDataFieldViewControllerDelegate, GXEntityDataFieldEditorViewControllerDelegate;

#pragma mark - Viewer

@protocol GXEntityDataFieldViewController <GXModelObject, NSObject>

- (nullable id<GXEntityData>)entityDataFieldData;
- (id<GXEntityDataFieldDescriptor>)entityDataFieldDescriptor;
- (id<GXEntityDataFieldInfo>)resolvedEntityDataFieldInfo;
- (nullable NSString *)entityDataFieldSpecifier;
- (nullable NSArray<NSNumber *> *)entityDataFieldIndexer;

@property(nullable, weak) id<GXEntityDataFieldViewControllerDelegate> entityDataFieldDelegate;

- (BOOL)dismissEntityDataFieldViewController:(BOOL)animated completion:(void(^ _Nullable)(void))completion;

@end


#pragma mark - Editor


@protocol GXEntityDataFieldEditorViewController <GXEntityDataFieldViewController>

- (nullable id<GXEntityDataWithOverrideValues>)editableEntityDataFieldData; // same as [self entityDataFieldData]
- (BOOL)isEditingEntityData;

@property BOOL shouldDelayEntityDataUpdatesUntilDissmissed;

@property(nullable, weak, readonly) id <GXEntityDataFieldEditorViewControllerDelegate> entityDataFieldEditorDelegate; // same as self.entityDataFieldDelegate

- (BOOL)dismissEntityDataFieldEditorViewController:(BOOL)save animated:(BOOL)animated completion:(void(^ _Nullable)(void))completion;

@end


#pragma mark - Viewer Delegate


@protocol GXEntityDataFieldViewControllerDelegate <NSObject>

- (BOOL)dismissEntityDataFieldViewController:(UIViewController<GXEntityDataFieldViewController> *)controller
									animated:(BOOL)animated
								  completion:(void(^ _Nullable)(void))completion;

@optional
- (void)entityDataFieldViewControllerDismissed:(UIViewController<GXEntityDataFieldViewController> *)controller;

@end


#pragma mark - Editor Delegate


@protocol GXEntityDataFieldEditorViewControllerDelegate <GXEntityDataFieldViewControllerDelegate>

@optional
- (void)entityDataFieldEditorViewControllerDidUpdateFieldValue:(UIViewController<GXEntityDataFieldEditorViewController> *)controller
												 oldFieldValue:(nullable id)oldFieldValue;

- (BOOL)entityDataFieldEditorViewController:(UIViewController<GXEntityDataFieldEditorViewController> *)controller
						   didFinishEditing:(BOOL)success
							dismissAnimated:(BOOL)animated
								 completion:(void(^ _Nullable)(void))completion;

@end

NS_ASSUME_NONNULL_END
