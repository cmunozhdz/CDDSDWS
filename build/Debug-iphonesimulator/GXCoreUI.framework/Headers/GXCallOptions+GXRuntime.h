//
//  GXCallOptions+GXRuntime.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 17/11/15.
//  Copyright © 2015 Artech. All rights reserved.
//

@import UIKit;
@import GXObjectsModel;

@class GXInterfaceControllerContext;

NS_ASSUME_NONNULL_BEGIN

@interface GXCallOptions (GXRuntime)

/*!
 Returns the current runtime call options for the given objectName
 
 @param objectName The object name to get call options
 @param modelObject The model object where the given object name belongs
 @result The current runtime call options for the given objectName
 */
+ (GXMutableCallOptions *)currentRuntimeCallOptionsForObjectName:(NSString *)objectName
													 modelObject:(id<GXModelObject>)modelObject;

/// #deprecated: 2022-01-20: trunk; #to-remove: ??
+ (GXMutableCallOptions *)currentRuntimeCallOptionsForObjectName:(NSString *)objectName __attribute__((deprecated("Use currentRuntimeCallOptionsForObjectName:modelObject: instead")));



#if !TARGET_OS_WATCH
/*!
 Returns the call options to be used when presenting the given view controller
 
 @param viewController The view controller to build call options for presenting it
 @result Returns the call options to be used when calling the given view controller (may be nil)
 @discussion It mergers the current runtime call options with the design call options and asociates the result instance to the view controller. See gxCalledOptions method in UIViewController's GXCallOptions category. Should be called before presenting the controller.
 */
+ (nullable GXMutableCallOptions *)callOptionsForViewController:(UIViewController *)viewController;
#else
/*!
 Returns the call options to be used when presenting the given interface controller context
 
 @param interfaceControllerContext The interface controller context to build call options for presenting with it
 @result Returns the call options to be used (may be nil)
 @discussion It mergers the current runtime call options with the design call options and asociates the result instance to the interface controller. See gxCalledOptions method in WKInterfaceController's GXCallOptions category. Should be called before presenting the controller.
 */
+ (nullable GXMutableCallOptions *)callOptionsForInterfaceControllerContext:(nullable id)interfaceControllerContext;
#endif // !TARGET_OS_WATCH

/*!
 Clears the current runtime call options for the given objectName
 
 @param objectName The object name to clear call options
 @param modelObject The model object where the given object name belongs
 */
+ (void)clearCurrentRuntimeCallOptionsForObjectName:(NSString *)objectName
										modelObject:(id<GXModelObject>)modelObject;

// #deprecated: 2022-01-20: trunk; #to-remove: ??
+ (void)clearCurrentRuntimeCallOptionsForObjectName:(NSString *)objectName __attribute__((deprecated("Use clearCurrentRuntimeCallOptionsForObjectName:modelObject: instead")));


#if !TARGET_OS_WATCH
/*!
 Clears the current runtime call options for the object name obtained from the given view controller
 
 @param viewController The view controller from where obtain object name to clear call options
 @discussion Should be called after presenting the controller. See callOptionsForViewController: method.
 */
+ (void)clearCurrentRuntimeCallOptionsForViewController:(UIViewController *)viewController;
#else
/*!
 Clears the current runtime call options for the object name obtained from the given interface controller context
 
 @param interfaceControllerContext The interface controller context from where obtain object name to clear call options
 @discussion Should be called after presenting the controller. See callOptionsForInterfaceControllerContext: method.
 */
+ (void)clearCurrentRuntimeCallOptionsForInterfaceControllerContext:(nullable id)interfaceControllerContext;
#endif // !TARGET_OS_WATCH

@end

NS_ASSUME_NONNULL_END
