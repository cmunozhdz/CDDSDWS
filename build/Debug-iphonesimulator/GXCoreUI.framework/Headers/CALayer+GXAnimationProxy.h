//
//  CALayer+GXAnimationProxy.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 31/7/18.
//  Copyright © 2018 GeneXus. All rights reserved.
//

@import QuartzCore;
@import UIKit;

NS_ASSUME_NONNULL_BEGIN

typedef id _Nullable (^GXLayerAnimationProxyFromValueProviderBlock)(NSString *keyPath);

@protocol GXLayerAnimationProxyOptions <NSObject>

@property(nonatomic, assign) BOOL ignoreAnimationIfNilFromValue; // Default NO
@property(nullable, nonatomic, copy) GXLayerAnimationProxyFromValueProviderBlock fromValueProvider;

@end

extern NSString *const GXModelModelKey;

@interface CALayer (GXAnimationProxy)

- (void)gxAnimateWithDuration:(NSTimeInterval)duration
				   animations:(__attribute__((noescape)) void (^)(__kindof CALayer *layer, id<GXLayerAnimationProxyOptions> options))animations;

- (void)gxAnimateIfInInheritedAnimation:(__attribute__((noescape)) void (^)(__kindof CALayer *layer, BOOL animated, id<GXLayerAnimationProxyOptions> _Nullable options))animations;

@end

@interface UIView (GXAnimationProxy)

@property(class, nonatomic, readonly) NSTimeInterval gxEnabledInheritedAnimationDuration;

- (void)gxAnimateLayerWithDuration:(NSTimeInterval)duration
				   layerAnimations:(__attribute__((noescape)) void (^)(__kindof UIView *view, id<GXLayerAnimationProxyOptions> options))layerAnimations;

- (void)gxAnimateLayerIfInInheritedAnimation:(__attribute__((noescape)) void (^)(__kindof UIView *view, BOOL animated, id<GXLayerAnimationProxyOptions> _Nullable options))layerAnimations;

@end

NS_ASSUME_NONNULL_END
