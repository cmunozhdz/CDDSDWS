//
//  GXPreferencesViewController.h
//  GXFlexibleClient
//
//  Created by Alejandro Panizza on 6/1/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@class GXPreferencesViewController;

@protocol GXPreferenceViewControllerDelegate <NSObject>

- (void)preferenceViewController:(GXPreferencesViewController *)controller didValidateModelForUrl:(NSString *)url;

@end

@interface GXPreferencesViewController : UITableViewController

- (instancetype)initWithUrlString:(nullable NSString *)urlString NS_DESIGNATED_INITIALIZER;

@property(weak) id <GXPreferenceViewControllerDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
