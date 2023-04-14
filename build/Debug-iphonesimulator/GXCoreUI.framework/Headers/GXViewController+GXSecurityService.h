//
//  GXViewController+GXSecurityService.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 11/2/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

#import <GXCoreUI/GXViewController.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXViewController (GXSecurityService)

@property(nonatomic, assign, readwrite) BOOL showLogoutButton;

- (nullable UIBarButtonItem *)logoutButtonItem;

- (void)reloadLogoutButtonItem;

@end

NS_ASSUME_NONNULL_END
