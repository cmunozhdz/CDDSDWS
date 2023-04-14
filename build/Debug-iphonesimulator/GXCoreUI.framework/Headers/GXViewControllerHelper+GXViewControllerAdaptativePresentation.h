//
//  GXViewControllerHelper+GXViewControllerAdaptativePresentation.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 12/2/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import GXObjectsModel;
#import <GXCoreUI/GXViewControllerHelper.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXViewControllerHelper (GXViewControllerAdaptativePresentation)

+ (UIViewController *)viewControllerToPresentControllerModal:(UIViewController *)controller
													 context:(nullable GXPresentationContext *)context;

#if TARGET_OS_IOS
+ (UIViewController *)viewControllerToPresentControllerPopover:(UIViewController *)controller
													   context:(nullable GXPresentationContext *)context;
#endif // TARGET_OS_IOS

@end

NS_ASSUME_NONNULL_END
