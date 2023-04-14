//
//  GXViewControllerHelper+GXInterfaceOriantation.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 10/2/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

#import <GXCoreUI/GXViewControllerHelper.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXViewControllerHelper (GXInterfaceOriantation)

+ (UIInterfaceOrientationMask)resolvedSupportedInterfaceOrientationsForViewController:(nullable UIViewController *)viewController;
+ (UIInterfaceOrientationMask)resolvedSupportedInterfaceOrientationsForViewControllers:(nullable NSArray<UIViewController *> *)viewControllers;

+ (UIInterfaceOrientationMask)defaultSupportedInterfaceOrientations;

+ (UIInterfaceOrientation)gxInterfaceOrientationFrom:(UIInterfaceOrientation)interfaceOrientation targetTransfrom:(CGAffineTransform)transform;

@end

NS_ASSUME_NONNULL_END
