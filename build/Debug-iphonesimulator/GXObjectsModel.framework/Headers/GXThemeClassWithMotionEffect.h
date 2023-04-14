//
//  GXThemeClassWithMotionEffect.h
//  GXFlexibleClient
//
//  Created by willy on 10/7/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@protocol GXStyleClassWithMotionEffect <NSObject>

@property(nonatomic, assign, readonly) CGFloat motionEffectMaxVerticalOffset;
@property(nonatomic, assign, readonly) CGFloat motionEffectMaxHorizontalOffset;

@end

@protocol GXThemeClassWithMotionEffect <GXStyleClassWithMotionEffect>
@end

NS_ASSUME_NONNULL_END
