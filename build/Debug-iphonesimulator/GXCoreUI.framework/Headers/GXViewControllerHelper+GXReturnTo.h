//
//  GXViewControllerHelper+GXReturnTo.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 11/11/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

#import <GXCoreUI/GXViewControllerHelper.h>
#import <GXCoreUI/GXRootControllerProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXViewControllerHelper (GXReturnTo)

+ (BOOL)viewController:(UIViewController *)controller matchesReturnTo:(NSString *)returnTo;

+ (nullable GXReturnToHandlerWithCompletion)returnToHandlerWithComplitionForNavigationController:(UINavigationController *)navController
																						returnTo:(NSString *)returnTo
																				  fromController:(nullable UIViewController *)fromController;

@end

NS_ASSUME_NONNULL_END
