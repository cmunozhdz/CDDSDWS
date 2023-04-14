//
//  GXUserInterfaceContextProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 16/11/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;
#if TARGET_OS_IOS || TARGET_OS_TV
@import UIKit;
#elif TARGET_OS_WATCH
@import WatchKit;
#endif

NS_ASSUME_NONNULL_BEGIN

@protocol GXUserInterfaceContext <NSObject>

@property(nonatomic, assign, readonly, getter=isUserInterfaceContextValid) BOOL userInterfaceContextValid;

@end

@protocol GXEditingUserInterfaceContext <GXUserInterfaceContext>

- (void)userInterfaceContextCommitChanges;

@end

@protocol GXControlUserInterfaceContext <GXUserInterfaceContext>

@property(nullable, nonatomic, strong, readonly) NSString *userInterfaceContextControlName;

@end

@protocol GXViewUserInterfaceContext <GXUserInterfaceContext>

#if TARGET_OS_WATCH
@property(nullable, nonatomic, strong, readonly) WKInterfaceObject *userInterfaceContextInterfaceObject;
#else
@property(nullable, nonatomic, strong, readonly) UIView *userInterfaceContextView;
#endif // TARGET_OS_WATCH

@end

#if TARGET_OS_WATCH
@protocol GXControllerUserInterfaceContext <GXUserInterfaceContext>

@property(nullable, nonatomic, strong, readonly) WKInterfaceController *userInterfaceContextController;

@end

#else

@protocol GXBarItemUserInterfaceContext <GXUserInterfaceContext>

@property(nullable, nonatomic, strong, readonly) UIBarItem *userInterfaceContextBarItem;

@end


@protocol GXGestureRecognizerUserInterfaceContext <GXViewUserInterfaceContext>

@property(nullable, nonatomic, strong, readonly) UIGestureRecognizer *userInterfaceGestureRecognizer;

@end


@protocol GXControllerUserInterfaceContext <GXViewUserInterfaceContext>

@property(nullable, nonatomic, strong, readonly) UIViewController *userInterfaceContextController;

@end

@protocol GXViewControllerUserInterfaceContext <GXControllerUserInterfaceContext>

@property(nullable, nonatomic, strong, readonly) UIViewController *userInterfaceContextViewController;

@end
#endif // TARGET_OS_WATCH

@protocol GXDynamicPropertyOverrideUserInterfaceContext <GXUserInterfaceContext>

@property(nonatomic, readonly) NSString *userInterfaceContextDynamicPropertyName; // Lowercase
@property(nonatomic, readonly) NSString *userInterfaceContextDynamicPropertyControlName; // Lowercase

@property(nonatomic, readonly) BOOL userInterfaceContextDynamicPropertyOverrideHandled;
- (void)userInterfaceContextDidHandleDynamicPropertyOverride;

- (void)userInterfaceContextInvalidate;

@end

NS_ASSUME_NONNULL_END
