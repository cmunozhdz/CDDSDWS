//
//  GXControlGridCollectionTableViewBase+GXPullToRefresh.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 21/6/17.
//  Copyright © 2017 GeneXus. All rights reserved.
//

#import <GXCoreUI/GXControlGridCollectionTableViewBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXControlGridCollectionTableViewBase (GXPullToRefresh)

@property(nonatomic, assign, readonly, getter=isPullToRefreshEnabled) BOOL pullToRefreshEnabled;
@property(nullable, nonatomic, strong, readonly) UIRefreshControl *loadedRefreshControl;

/// Initialize refresh control after gridView has been loaded (called on viewDidLoad)
- (void)initializeRefreshControl;
- (void)unloadRefreshControl:(BOOL)dealloc;

- (void)handlePullToRefresh:(UIRefreshControl *)refreshControl;

- (void)endRefreshingRefreshControlIfNeeded;

@end

NS_ASSUME_NONNULL_END
