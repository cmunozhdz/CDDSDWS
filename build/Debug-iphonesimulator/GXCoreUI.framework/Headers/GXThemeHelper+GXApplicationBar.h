//
//  GXThemeHelper+GXApplicationBar.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 11/2/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import GXObjectsModel;
#import <GXCoreUI/GXApplicationBarsAppearance.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXStyleHelper (GXApplicationBar)

#pragma mark UISearchBar

+ (void)applyApplicationBarTheme:(nullable NSString *)className toSearchBar:(UISearchBar *)searchBar;
+ (void)applyApplicationBarTheme:(nullable NSString *)className toSearchBar:(UISearchBar *)searchBar atTopWithFullWidth:(BOOL)atTopWithFullWidth;

#pragma mark UINavigationController

+ (void)applyApplicationBarTheme:(nullable NSString *)className
			navigationController:(UINavigationController *)navigationController
				  viewController:(nullable UIViewController *)viewController;
+ (void)applyApplicationBarTheme:(nullable NSString *)className
			  navigationBarTheme:(nullable NSString *)navBarClassName
						animated:(BOOL)animated
			navigationController:(UINavigationController *)navController
				  viewController:(nullable UIViewController *)viewController;

#if TARGET_OS_IOS
+ (UINavigationItemLargeTitleDisplayMode)largeTitleDisplayModeFor:(GXApplicationBarsLargeTitleMode)largeTitleMode
												   viewController:(UIViewController *)viewController
										   inNavigationController:(UINavigationController *)navController API_AVAILABLE(ios(11.0));
#endif // TARGET_OS_IOS


#pragma mark UIBarButtonItem

+ (void)applyStyleClass:(nullable GXStyleClass *)styleClass
propertyDefaultResolver:(nullable id<GXStyleClassPropertyDefaultResolver>)resolver
	   toBarButtonItems:(NSArray<UIBarButtonItem *> *)items;
+ (void)applyStyleClass:(nullable GXStyleClass *)styleClass
propertyDefaultResolver:(nullable id<GXStyleClassPropertyDefaultResolver>)resolver
		toBarButtonItem:(UIBarButtonItem *)item;
+ (nullable GXStyleClass *)applicationBarDefaultButtonClass:(nullable NSString *)appBarClassName;
+ (void)applyApplicationBarDefaultButtonClass:(nullable NSString *)appBarClassName
							 toBarButtonItems:(NSArray<UIBarButtonItem *> *)items;
+ (void)applyApplicationBarDefaultButtonClass:(nullable NSString *)appBarClassName
							  toBarButtonItem:(UIBarButtonItem *)item;
+ (void)applyDefaultApplicationBarDefaultButtonClassToBarButtonItems:(NSArray<UIBarButtonItem *> *)items; // Same as calling applyApplicationBarDefaultButtonClass:toBarButtonItems: with nil class name
+ (void)applyDefaultApplicationBarDefaultButtonClassToBarButtonItem:(UIBarButtonItem *)item; // Same as calling applyApplicationBarDefaultButtonClass:toBarButtonItem: with nil class name
+ (void)applyApplicationBarDefaultButtonClassFromAppBarsAppearance:(id<GXApplicationBarsAppearance>)appBarsAppearance
												  toBarButtonItems:(NSArray<UIBarButtonItem *> *)items
												  forNavigationBar:(BOOL)navBar;
+ (void)applyApplicationBarDefaultButtonClassFromAppBarsAppearance:(id<GXApplicationBarsAppearance>)appBarsAppearance
												   toBarButtonItem:(UIBarButtonItem *)item
												  forNavigationBar:(BOOL)navBar;


@end

NS_ASSUME_NONNULL_END
