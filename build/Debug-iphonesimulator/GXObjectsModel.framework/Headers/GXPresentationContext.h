//
//  GXPresentationContext.h
//  GXFlexibleClient
//
//  Created by willy on 12/7/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXCallOptions.h>
#import <GXObjectsModel/GXUserInterfaceContext.h>
#if TARGET_OS_IOS || TARGET_OS_TV
#import <GXObjectsModel/GXViewControllerAdaptativePresentation.h>
#endif // TARGET_OS_IOS || TARGET_OS_TV
#import <GXObjectsModel/GXCommonTypes.h>

NS_ASSUME_NONNULL_BEGIN

@class GXUserInterfaceContext, GXPresentationContext;

@protocol GXPresentationContextDelegate <NSObject>

@optional
#if TARGET_OS_IOS || TARGET_OS_TV
- (nullable id <GXViewControllerAdaptativePresentation>)presentationContext:(GXPresentationContext *)context
						  adaptativePresentationForPresentingViewController:(UIViewController *)controllerToPresent;
#endif // TARGET_OS_IOS || TARGET_OS_TV

@end

@interface GXPresentationContext : NSObject

+ (instancetype)presentationContextWithUserInterfaceContext:(nullable GXUserInterfaceContext *)uiContext;
- (instancetype)initWithUIContext:(nullable GXUserInterfaceContext *)uiContext NS_DESIGNATED_INITIALIZER;

- (void)setupWithUserInterfaceController:(GXUserInterfaceController *)presentingController;

- (void)setCallOptionsCopy:(nullable GXCallOptions *)callOptions;
#if !TARGET_OS_WATCH
- (void)validateForPresentingViewController:(UIViewController *)controllerToPresent;
#else
- (void)validateForPresentingControllerWithName:(NSString *)controllerName
					 interfaceControllerContext:(nullable id)interfaceControllerContext;
- (void)validateForPresentingControllerWithNames:(NSArray<NSString *> *)controllerNames
					 interfaceControllerContexts:(nullable NSArray *)interfaceControllerContexts;
#endif // !TARGET_OS_WATCH

- (NSArray<GXUserInterfaceController *> *)validUserInterfaceContextControllers;

@property(nullable, weak) id <GXPresentationContextDelegate> delegate;

@property(nullable, nonatomic, weak, readonly) GXUserInterfaceController *presentingController;
@property(nonatomic, strong, readonly) GXUserInterfaceContext *uiContext;
@property(nullable, nonatomic, strong, readonly) GXMutableCallOptions *callOptions;
@property(nonatomic, assign, readwrite) BOOL animated; // default value = YES
@property(nonatomic, assign, readwrite) BOOL modal;
#if TARGET_OS_IOS
@property(nonatomic, assign, readwrite) BOOL popover;
#endif // TARGET_OS_IOS
@property(nonatomic, assign, readwrite) BOOL presentedInDifferentTarget;

@end

NS_ASSUME_NONNULL_END
