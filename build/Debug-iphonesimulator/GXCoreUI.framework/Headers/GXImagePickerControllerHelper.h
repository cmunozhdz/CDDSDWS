//
//  GXImagePickerControllerHelper.h
//  GXCoreUI-iOS
//
//  Created by Fabian Inthamoussu on 09/07/2019.
//  Copyright © 2019 GeneXus. All rights reserved.
//

@import UIKit;
@import AVFoundation;
@import Photos;
@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@protocol GXUIImagePickerController <NSObject>

@property(weak, nullable, nonatomic) id<UIImagePickerControllerDelegate, UINavigationControllerDelegate> imagePickerDelegate;

@property(nonatomic) UIImagePickerControllerSourceType imagePickerSourceType;
@property(nonatomic, copy) NSArray<NSString *> *imagePickerMediaTypes;
@property(nonatomic) BOOL imagePickerAllowsEditing;
@property(nonatomic) UIImagePickerControllerImageURLExportPreset imagePickerImageExportPreset NS_AVAILABLE_IOS(11_0);

@property(nonatomic) NSTimeInterval imagePickerVideoMaximumDuration;
@property(nonatomic) UIImagePickerControllerQualityType imagePickerVideoQuality;
@property(nonatomic, copy) NSString *imagePickerVideoExportPreset NS_AVAILABLE_IOS(11_0);

@property(nonatomic) BOOL imagePickerShowsCameraControls;
@property(nullable, nonatomic,strong) __kindof UIView *imagePickerCameraOverlayView;
@property(nonatomic) CGAffineTransform imagePickerCameraViewTransform;

- (void)imagePickerTakePicture;

- (BOOL)imagePickerStartVideoCapture;
- (void)imagePickerStopVideoCapture;

@property(nonatomic) UIImagePickerControllerCameraCaptureMode imagePickerCameraCaptureMode;
@property(nonatomic) UIImagePickerControllerCameraDevice imagePickerCameraDevice;
@property(nonatomic) UIImagePickerControllerCameraFlashMode imagePickerCameraFlashMode;

@end

@protocol GXUIImagePickerControllerDelegate <NSObject>

@optional
- (void)gxImagePickerController:(UIViewController<GXUIImagePickerController> *)picker didFinishPickingMediaWithInfo:(NSDictionary<UIImagePickerControllerInfoKey, id> *)info;
- (void)gxImagePickerControllerDidCancel:(UIViewController<GXUIImagePickerController> *)picker;

@end

@protocol GXEntityDataFieldImagePickerProtocol;

@interface GXImagePickerControllerHelper : NSObject

@property(class, nonatomic, readonly, getter=isCameraAvailableForPhoto) BOOL cameraAvailableForPhoto;
@property(class, nonatomic, readonly, getter=isCameraAvailableForMovie) BOOL cameraAvailableForMovie;
@property(class, nonatomic, readonly, getter=isPhotoLibraryAvailableForPhoto) BOOL photoLibraryAvailableForPhoto;
@property(class, nonatomic, readonly, getter=isPhotoLibraryAvailableForMovie) BOOL photoLibraryAvailableForMovie;

+ (NSError *)cameraNotAvailableError;
+ (NSError *)photoLibraryNotAvailableError;

+ (void)executeBlockWithCameraAuthorized:(void(^)(AVAuthorizationStatus authStatus, NSError * _Nullable error))block;
+ (void)executeBlockWithPhotoLibraryAuthorized:(void(^)(PHAuthorizationStatus authStatus, NSError * _Nullable error))block;

/// iOS 11 uses out of process picker, then permission to user's photo library is not needed. No permission check is made if sourceType is PhotoLibrary or SavedPhotosAlbum
+ (void)executeBlockWithAuthorizedStatusForPickerSourceType:(UIImagePickerControllerSourceType)pickerSourceType
													  block:(void(^)(NSError * _Nullable))block; // ignoreDeniedStatusErrorForPhotoLibrary:YES

/// iOS 11 uses out of process picker, then permission to user's photo library is not needed. No permission check is made if sourceType is PhotoLibrary or SavedPhotosAlbum
+ (void)executeBlockWithAuthorizedStatusForPickerSourceType:(UIImagePickerControllerSourceType)pickerSourceType
					 ignoreDeniedStatusErrorForPhotoLibrary:(BOOL)ignoreDeniedStatusErrorForPhotoLibrary
													  block:(void(^)(NSError * _Nullable))block;

+ (void)defaultImagePickerController:(UIViewController<GXUIImagePickerController> *)controller
	   didFinishPickingMediaWithInfo:(NSDictionary<NSString *,id> *)info
					handlerWithBlock:(void(^)(NSURL * _Nullable pickedMediaFileURL, BOOL isTempFileURL))resultBlock;

+ (nullable UIViewController<GXUIImagePickerController> *)newImagePickerControllerWithSourceType:(UIImagePickerControllerSourceType)sourceType
																					   mediaType:(NSString *)mediaType // kUTTypeImage or kUTTypeMovie
																						   error:(out NSError * __autoreleasing _Nullable * _Nullable)error;

+ (nullable UIViewController<GXEntityDataFieldImagePickerProtocol> *)newEntityDataFieldImagePickerWithEntityData:(id<GXEntityDataWithOverrideValues>)entityData
																								 fieldDescriptor:(id<GXEntityDataFieldDescriptor>)fieldDesc
																								  fieldSpecifier:(nullable NSString *)fieldSpecifier
																										 indexer:(nullable NSArray *)indexer
																									  sourceType:(UIImagePickerControllerSourceType)sourceType
																										   error:(out NSError * __autoreleasing _Nullable * _Nullable)error;

+ (nullable id<UIImagePickerControllerDelegate, UINavigationControllerDelegate>)imagePickerDelegateFromGxImagePickerDelegate:(id<GXUIImagePickerControllerDelegate, UINavigationControllerDelegate>)delegate;

/// Creates the picker and sets it up, and then calls the presentingBlock for the caller to present the picker
/// If there is an error creating the picker, it will present an alert message showing the error
+ (void)preparePickerPresentationForCamera:(BOOL)camera
								entityData:(id<GXEntityDataWithOverrideValues>)entityData
						   fieldDescriptor:(id<GXEntityDataFieldDescriptor>)fieldDesc
							fieldSpecifier:(nullable NSString *)fieldSpecifier
								   indexer:(nullable NSArray *)indexer
								allowsNull:(BOOL)allowsNull
						   presentingBlock:(void(^)(UIViewController<GXEntityDataFieldImagePickerProtocol> * _Nullable picker, NSError * _Nullable error))presentingBlock;

@end


@protocol GXImagePickerControllerHelperOptionals <NSObject>

@optional
+ (nullable UIViewController<GXUIImagePickerController> *)optionalNewImagePickerControllerWithSourceType:(UIImagePickerControllerSourceType)sourceType
																							   mediaType:(NSString *)mediaType // kUTTypeImage or kUTTypeMovie
																								   error:(out NSError * __autoreleasing _Nullable * _Nullable)error;

+ (nullable UIViewController<GXEntityDataFieldImagePickerProtocol> *)optionalNewEntityDataFieldImagePickerWithEntityData:(id<GXEntityDataWithOverrideValues>)entityData
																										 fieldDescriptor:(id<GXEntityDataFieldDescriptor>)fieldDesc
																										  fieldSpecifier:(nullable NSString *)fieldSpecifier
																												 indexer:(nullable NSArray *)indexer
																											  sourceType:(UIImagePickerControllerSourceType)sourceType
																												   error:(out NSError * __autoreleasing _Nullable * _Nullable)error;

@end

NS_ASSUME_NONNULL_END
