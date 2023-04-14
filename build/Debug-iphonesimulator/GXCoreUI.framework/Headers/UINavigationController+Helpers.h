//
//  UINavigationController+Helpers.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 30/1/15.
//  Copyright (c) 2015 Artech. All rights reserved.
//

@import UIKit;

@interface UINavigationController (Helpers)

- (void)gxPushViewController:(UIViewController *)viewController
					animated:(BOOL)animated
				  completion:(void (^)(void))completion;

- (UIViewController *)gxPopViewControllerAnimated:(BOOL)animated
									   completion:(void (^)(void))completion;
- (NSArray *)gxPopToViewController:(UIViewController *)viewController
						  animated:(BOOL)animated
						completion:(void (^)(void))completion;
- (NSArray *)gxPopToRootViewControllerAnimated:(BOOL)animated
									completion:(void (^)(void))completion;

@end
