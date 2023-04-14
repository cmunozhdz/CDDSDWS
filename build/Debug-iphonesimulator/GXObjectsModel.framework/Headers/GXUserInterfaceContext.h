//
//  GXUserInterfaceContext.h
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
#import <GXObjectsModel/GXUserInterfaceContextProtocol.h>
#import <GXObjectsModel/GXCommonTypes.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXUserInterfaceContext : NSObject

@property(nonatomic, strong, readonly) NSArray<id<GXUserInterfaceContext>> *userInterfaceContextItems;

- (void)addUserInterfaceContext:(nullable id <GXUserInterfaceContext>)uiContext NS_SWIFT_NAME(add(uiContext:));

#if !TARGET_OS_WATCH
- (void)addUserInterfaceContextWithView:(UIView *)view NS_SWIFT_NAME(add(view:));
- (void)addUserInterfaceContextWithBarItem:(UIBarItem *)barItem
							viewController:(nullable UIViewController *)controller NS_SWIFT_NAME(add(barItem:viewController:));
- (void)addUserInterfaceContextWithGestureRecognizer:(UIGestureRecognizer *)gestureRecognizer NS_SWIFT_NAME(add(gestureRecognizer:));
#else
- (void)addUserInterfaceContextWithInterfaceObject:(WKInterfaceObject *)interfaceObject NS_SWIFT_NAME(add(interfaceObject:));
#endif // !TARGET_OS_WATCH

- (void)addUserInterfaceContextWithController:(GXUserInterfaceController *)controller NS_SWIFT_NAME(add(controller:));

- (void)addEdittingUserInterfaceContext:(id<GXEditingUserInterfaceContext>)context NS_SWIFT_NAME(add(editingUIContext:));

@end

NS_ASSUME_NONNULL_END
