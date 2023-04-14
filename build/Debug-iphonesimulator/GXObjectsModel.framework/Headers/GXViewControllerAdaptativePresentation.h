//
//  GXViewControllerAdaptativePresentation.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 10/2/15.
//  Copyright (c) 2015 Artech. All rights reserved.
//

@import Foundation;
@import UIKit;

@protocol GXViewControllerAdaptativePresentation <NSObject>

@optional
- (UIViewController *)gxViewControllerForModalPresentation; // Not implemented or returning nil means not changing the controller to present
#if TARGET_OS_IOS
- (UIViewController *)gxViewControllerForPopupPresentation; // Not implemented or returning nil means not changing the controller to present
#endif // TARGET_OS_IOS

- (BOOL)gxUseNavigationControllerContainerForModalPresentation; // Not implemented means NO
#if TARGET_OS_IOS
- (BOOL)gxUseNavigationControllerContainerForPopupPresentation; // Not implemented means NO
#endif // TARGET_OS_IOS

- (BOOL)gxUseThemeApplicationBackgroundForModalPresentation; // Not implemented means gxViewControllerForModalPresentation is implemented and returned controller is kind of GXNavigationController or gxUseNavigationControllerContainerForModalPresentation implemented and returns YES, NO otherwise
#if TARGET_OS_IOS
- (BOOL)gxUseThemeApplicationBackgroundForPopupPresentation; // Not implemented means gxViewControllerForPopupPresentation is implemented and returned controller is kind of GXNavigationController or gxUseNavigationControllerContainerForPopupPresentation implemented and returns YES, NO otherwise
#endif // TARGET_OS_IOS

- (BOOL)gxUseThemeApplicationBarsClass; // Not implemented means YES if conforms to GXApplicationBarsAppearance, NO otherwise

- (BOOL)gxAllowsModalPresentation; // Not implemented means YES
#if TARGET_OS_IOS
- (BOOL)gxAllowsPopupPresentation; // Not implemented means YES
#endif // TARGET_OS_IOS
- (BOOL)gxAllowsNavigationControllerPresentation; // Not implemented means YES
- (BOOL)gxDismissObservingSupportsDealloc; // Not implemented means YES

@end
