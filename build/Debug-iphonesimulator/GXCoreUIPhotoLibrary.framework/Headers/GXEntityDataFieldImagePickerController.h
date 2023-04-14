//
//  GXEntityDataFieldImagePickerController.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 22/03/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import GXCoreUI;

NS_ASSUME_NONNULL_BEGIN

@interface GXEntityDataFieldImagePickerController : UIImagePickerController <GXEntityDataFieldImagePickerProtocol,
																				GXEntityDataFieldEditorViewControllerHelperDelegate,
																				UINavigationControllerDelegate,
																				UIImagePickerControllerDelegate>

@property(nonatomic, strong, readonly) GXEntityDataFieldEditorViewControllerHelper *editorHelper;

- (nullable instancetype)initWithEntityData:(id<GXEntityDataWithOverrideValues>)entityData
							fieldDescriptor:(id<GXEntityDataFieldDescriptor>)fieldDesc
							 fieldSpecifier:(nullable NSString *)fieldSpecifier
									indexer:(nullable NSArray *)indexer
								 sourceType:(UIImagePickerControllerSourceType)sourceType
									  error:(out NSError * __autoreleasing _Nullable * _Nullable)error NS_DESIGNATED_INITIALIZER;

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;
- (instancetype)initWithNavigationBarClass:(nullable Class)navigationBarClass toolbarClass:(nullable Class)toolbarClass NS_UNAVAILABLE;
- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;
- (instancetype)initWithRootViewController:(UIViewController *)rootViewController NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
