//
//  GXViewControllerHelper+GXViewControllerFactory.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 4/4/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import GXObjectsModel;
@import GXDataLayer;
#import <GXCoreUI/GXEntityModelHelper+GXCoreUI.h>
#import <GXCoreUI/GXEntityViewController.h>
#import <GXCoreUI/GXViewControllerHelper.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXViewControllerHelper (GXViewControllerFactory)

#pragma mark - Panels

+ (nullable GXEntityViewController *)entityViewControllerWithForEntityDataProvider:(id <GXEntityDataProvider>)entityDataProvider
																	   entityModel:(id <GXEntityModel>)entityModel;

+ (nullable GXEntityViewController *)viewControllerForWorkWithComponent:(GXWorkWithDetail *)wwComponent
											 conectivitySupportResolver:(nullable id <GXInheritedConnectivitySupportResolver>)connSupportResolver;

+ (void)reloadEntityViewController:(GXEntityViewController *)viewController;

+ (nullable GXEntityViewController *)viewControllerForWorkWithModel:(GXWorkWithModel *)wwModel
											workWithComponentString:(nullable NSString *)wwComponentString
										 conectivitySupportResolver:(nullable id <GXInheritedConnectivitySupportResolver>)connSupportResolver;
+ (nullable GXEntityViewController *)viewControllerForWorkWithModel:(GXWorkWithModel *)wwModel
										 conectivitySupportResolver:(nullable id <GXInheritedConnectivitySupportResolver>)connSupportResolver;



+ (nullable GXEntityViewController *)foreignKeyPickerViewControllerForRelation:(GXBusinessComponentRelation *)relation
													conectivitySupportResolver:(nullable id <GXInheritedConnectivitySupportResolver>)connSupportResolver;

+ (nullable GXEntityViewController *)promptViewControllerForPromptRule:(id <GXEntityRulePrompt>)promptRule
											conectivitySupportResolver:(nullable id <GXInheritedConnectivitySupportResolver>)connSupportResolver;

#pragma mark - Menu

+ (GXViewController *)menuViewControllerForMenu:(id <GXMenu>)menu;

#pragma mark - Application

+ (nullable GXViewController *)viewControllerForAppEntryPoint:(GXApplicationModel *)appModel;
+ (BOOL)isAppEntryPoint:(GXApplicationModel *)appModel viewController:(UIViewController *)controller;

@end

NS_ASSUME_NONNULL_END
