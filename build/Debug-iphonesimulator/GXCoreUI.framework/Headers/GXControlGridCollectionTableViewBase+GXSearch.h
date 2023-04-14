//
//  GXControlGridCollectionTableViewBase+GXSearch.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 20/6/17.
//  Copyright © 2017 GeneXus. All rights reserved.
//

#import <GXCoreUI/GXControlGridCollectionTableViewBase.h>
#import <GXCoreUI/GXControlWithUserInterfaceController.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXControlGridCollectionTableViewBase (GXSearch) <UISearchControllerDelegate, UISearchResultsUpdating, UISearchBarDelegate, GXControlWithUserInterfaceController>

@property(nonatomic, readonly) BOOL searchSupported; // Defaults to NO
@property(nonatomic, readonly) BOOL canLoadSearchController;

@property(nullable, nonatomic, strong, readonly) UISearchController *searchController;
@property(nullable, nonatomic, strong, readonly) UIViewController *searchContentsController;
@property(nullable, nonatomic, strong, readonly) UIScrollView<GXControlGridCollectionTableView> *activeSearchGridView; // self.gridView if [self.searchController isActive]
@property(assign, readonly) BOOL searchInProcess;

/// Initialize search controllers after gridView has been loaded (called on viewDidLoad)
- (void)initializeSearchControllers;
- (void)unloadSearchControllers:(BOOL)dealloc;

#if TARGET_OS_IOS
@property(nonatomic, readonly) BOOL canAddSearchControllerToNavigationBar API_AVAILABLE(ios(11.0));
@property(nonatomic, readonly) BOOL shouldAddSearchControllerToNavigationBar API_AVAILABLE(ios(11.0)); // ABSTRACT
@property(nonatomic, readonly, getter=isSearchControllerInNavigationBar) BOOL searchControllerInNavigationBar API_AVAILABLE(ios(11.0));
#endif // TARGET_OS_IOS
- (void)addSearchBar:(UISearchBar *)searchBar toGridView:(UIScrollView<GXControlGridCollectionTableView> *)gridView; // ABSTRACT

- (BOOL)isSearchGridView:(UIScrollView<GXControlGridCollectionTableView> *)gridView;

- (BOOL)updateGridViewSearchHeaderViewFrameIfNeeded:(BOOL)allowFromTransitionCoordinator;
- (BOOL)shouldScrollToInitialGridScrollViewPositionOnSearchControllerDismiss;

@end

NS_ASSUME_NONNULL_END
