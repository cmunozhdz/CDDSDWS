//
//  GXEntityDetailViewController+GXActionBar.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 9/8/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

#import <GXCoreUI/GXEntityDetailViewController.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXEntityDetailViewController (GXActionBar)

@property(nonatomic, strong, readonly) NSArray<id<GXControlActionBarItem>> *rootControlActionBarItems;

- (void)updateRootControlActionBarItemsDefaultAppBarThemeClass;

@end

NS_ASSUME_NONNULL_END
