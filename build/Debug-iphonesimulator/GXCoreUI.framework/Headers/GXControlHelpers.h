//
//  GXControlHelpers.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 10/01/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import GXFoundation;
@import GXObjectsModel;
#import <GXCoreUI/GXControl.h>
#if !TARGET_OS_WATCH
#import <GXCoreUI/GXControlBase+GXDragDrop.h>
#endif // !TARGET_OS_WATCH
#import <GXCoreUI/GXControlComponentProtocol.h>
#import <GXCoreUI/GXControlContainer.h>
#if !TARGET_OS_WATCH
#import <GXCoreUI/GXControlWithDataEditable.h>
#import <GXCoreUI/GXControlWithExpandableBounds.h>
#import <GXCoreUI/GXControlWithUserInterfaceController.h>
#import <GXCoreUI/GXEntityDataFieldBarCodeScannerProtocol.h>
#endif // !TARGET_OS_WATCH

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, GXControlHelpersLookupDirection) {
	GXControlHelpersLookupDirectionSelf = 1 << 0,
	GXControlHelpersLookupDirectionDescenders = 1 << 1,
	GXControlHelpersLookupDirectionAscenders = 1 << 2,
	GXControlHelpersLookupDirectionAny = GXControlHelpersLookupDirectionSelf | GXControlHelpersLookupDirectionDescenders | GXControlHelpersLookupDirectionAscenders,
};

#if !TARGET_OS_WATCH
typedef void(^GXControlExpandedFrameAndAdditionalHeightToFrameContextOptionsLoader)(id<GXControl> _Nonnull, CGRect * _Nonnull, NSDictionary<NSString *, id> * __strong _Nullable * _Nonnull);
typedef void(^GXChildControlExpandableBoundsValuesLoader)(id<GXControlWithExpandableBounds> _Nullable, CGRect * _Nonnull, GXLayoutExpandableBounds * _Nonnull, UIEdgeInsets * _Nonnull, NSDictionary<NSString *, id> * __strong _Nullable * _Nonnull);
#endif // !TARGET_OS_WATCH

@interface GXControlHelpers : NSObject

#if !TARGET_OS_WATCH
+ (CGRect)frameByApplyingMargin:(GXLayoutQuadDimension)margin
						toFrame:(CGRect)frame;

+ (CGRect)frameByApplyingBorder:(CGFloat)borderWidth
					 andPadding:(GXLayoutQuadDimension)padding
						toFrame:(CGRect)frame;

+ (void)setFrame:(CGRect)frame toView:(UIView *)view;
#endif // !TARGET_OS_WATCH

+ (id <GXControlContainerWithDataProvider>)controlWithDataProviderForControl:(id <GXControlBaseProperties>)control NS_SWIFT_NAME(controlWithDataProvider(for:));
+ (id <GXControlComponent>)componentControlForControl:(id <GXControlBaseProperties>)control NS_SWIFT_NAME(componentControl(for:));

+ (nullable id <GXControlComponent>)findComponentControlWithEntityModel:(id <GXEntityModel>)model fromControl:(id <GXControlComponent>)control;

+ (nullable id <GXControl>)findControlWithControlName:(NSString *)controlName fromControl:(id <GXControl>)control;
+ (nullable id <GXControl>)findControlWithControlName:(NSString *)controlName
										  fromControl:(id<GXControl>)control
										  inComponent:(nullable id <GXControlComponent>)controlComponent;
+ (nullable id <GXControl>)findControlWithControlName:(NSString *)controlName
										  fromControl:(id<GXControl>)control
										  inComponent:(nullable id <GXControlComponent>)controlComponent
									  lookupDirection:(GXControlHelpersLookupDirection)lookupDirection;

+ (void)applyRecursiveBlockWithControl:(id<GXControl>)control
				  enumeratationOptions:(GXControlContainerChildControlsEnumerationOptions)options
								 block:(void (^)(id <GXControl> control, BOOL *stop))block;

#if !TARGET_OS_WATCH
+ (id <GXControlWithUserInterfaceController>)controlWithUserInterfaceControllerForControl:(id <GXControl>)control;
/// Same as controlWithUserInterfaceControllerForControl:, but keeps looking from parentControl if userInterfaceController == nil
+ (nullable id <GXControlWithUserInterfaceController>)controlWithNonNilUserInterfaceControllerForControl:(id <GXControl>)control;
#endif // !TARGET_OS_WATCH

#if !TARGET_OS_WATCH
+ (CGSize)formSizeFromControl:(id <GXControl>)control;

+ (UIUserInterfaceLayoutDirection)layoutDirectionFromControl:(id <GXControl>)control;
#endif // !TARGET_OS_WATCH

+ (GXConnectivitySupportType)connectivitySupportForControl:(id<GXControl>)control;

#if !TARGET_OS_WATCH
+ (nullable id<GXControl>)findControlFromView:(UIView *)view;

+ (nullable id<GXControl>)findControlFromView:(UIView *)view withBlock:(BOOL(^)(id<GXControl>))block;

+ (nullable id<GXControlWithDataEditable>)nextFocusableControlAfterControl:(id<GXControl>)control;

+ (CGFloat)frameWithAdditionalHeightToFrame:(inout CGRect *)frame forControlWithAutoHeight:(id <GXControlAutoHeight>)control;
+ (CGFloat)frameWithAdditionalHeightToFrame:(inout CGRect *)frame
							 contextOptions:(nullable NSDictionary<NSString *,id> *)contextOptions
   forControlAutoHeightWithExpandableBounds:(id <GXControlAutoHeight, GXControlWithExpandableBounds>)control
				 contentExpEdgeInsetsBottom:(out nullable CGFloat *)contentExpEdgeInsetsBottom;

+ (CGFloat)setFrameWithAdditionalHeightToFrame:(CGRect)frame toControlWithAutoHeight:(id <GXControlAutoHeight>)control;
+ (CGFloat)setFrameWithAdditionalHeightToFrame:(CGRect)frame
								contextOptions:(nullable NSDictionary<NSString *,id> *)contextOptions
	  forControlAutoHeightWithExpandableBounds:(id <GXControlAutoHeight, GXControlWithExpandableBounds>)control
					contentExpEdgeInsetsBottom:(out nullable CGFloat *)contentExpEdgeInsetsBottom;

+ (GXControlExpandedFrameAndAdditionalHeightToFrameContextOptionsLoader)childControlExpandedFrameAndContextOptionsBlockWithExpandableEdgeInsetsForChildControls:(UIEdgeInsets)expEdgeInsetsBase
																																				   contentFrame:(CGRect)contentFrame;
+ (GXChildControlExpandableBoundsValuesLoader)childControlExpandableValuesLoaderWithExpandableEdgeInsetsForChildControls:(UIEdgeInsets)expEdgeInsetsBase
																											contentFrame:(CGRect)contentFrame; // hasControlWithAutoHeightDependencyFlags == YES
+ (GXChildControlExpandableBoundsValuesLoader)childControlExpandableValuesLoaderWithExpandableEdgeInsetsForChildControls:(UIEdgeInsets)expEdgeInsetsBase
																											contentFrame:(CGRect)contentFrame
																				 hasControlWithAutoHeightDependencyFlags:(BOOL)hasControlWithAutoHeightDependencyFlags;

+ (nullable UIViewController<GXEntityDataFieldBarCodeScanner> *)barcodeScannerViewControllerWithScannerDelegate:(nullable id <GXEntityDataFieldBarCodeScannerDelegate>)scannerDelegate
																									 scanInLoop:(BOOL)loop
																								 beepOnEachRead:(BOOL)beepOnRead
																						   forGXControlWithData:(id<GXControlWithData>)control
																										  error:(NSError * __autoreleasing _Nullable * _Nullable)error;

+ (nullable UIViewController<GXEntityDataFieldBarCodeScanner> *)barcodeScannerViewControllerWithScannerDelegate:(nullable id <GXEntityDataFieldBarCodeScannerDelegate>)scannerDelegate
																									 scanInLoop:(BOOL)loop
																								 beepOnEachRead:(BOOL)beepOnRead
																								 forModelObject:(id<GXModelObject>)modelObject
																										  error:(NSError * __autoreleasing _Nullable * _Nullable)error;
#endif // !TARGET_OS_WATCH

+ (nullable NSString *)actionNameForControl:(id<GXNamedControlElement>)control eventName:(NSString *)eventName;
+ (nullable NSString *)actionNameForControlName:(NSString *)controlName eventName:(NSString *)eventName;

+ (void)updateControlDelegates:(id <GXControl>)control
  withControlDelegatesProvider:(id <GXControlDelegatesProvider>)provider;
+ (void)updateControlDelegates:(id <GXControl>)control
  withControlDelegatesProvider:(id <GXControlDelegatesProvider>)provider
					   options:(GXControlDelegatesProviderInvalidateOptions)options;

@end

NS_ASSUME_NONNULL_END
