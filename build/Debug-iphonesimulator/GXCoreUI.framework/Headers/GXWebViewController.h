//
//  GXWebViewController.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 31/08/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import UIKit;
@import SafariServices;
@import GXObjectsModel;
#import <GXCoreUI/GXApplicationBarsAppearance.h>
#import <GXCoreUI/GXWindow.h>
#import <GXCoreUI/UIView+GXWebView.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXWebViewController <NSObject>
@end

UIViewController<GXWebViewController> * _Nullable NewGXWebViewControllerWithURL(NSURL *url);

/**
 * Default GXApplicationBarsAppearance gxApplicationBarsClassName method implementation returns nil
 * This class implements setGxApplicationBarsClassName:, callers can use this method to change the class
 */
@interface GXWebViewController : UIViewController <GXWebViewController, GXWebViewDelegateProtocol, GXApplicationBarsAppearance, GXViewControllerAdaptativePresentation, GXAllowLowContrastTintColor>

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

@property(nullable, nonatomic, strong) NSURLRequest *request;
@property(nonatomic, assign) BOOL preloadData;

@end

/**
 * Default GXApplicationBarsAppearance gxApplicationBarsClassName method implementation returns nil
 * This class implements setGxApplicationBarsClassName:, callers can use this method to change the class
 */
@interface SFSafariViewController (GXWebViewController) <GXWebViewController, GXApplicationBarsAppearance, GXViewControllerAdaptativePresentation>
@end

NS_ASSUME_NONNULL_END
