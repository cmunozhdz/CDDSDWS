//
//  GXViewLayoutDelegationProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 16/03/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@protocol GXViewTouchResponderDelegate <NSObject>

- (void)layoutViewTouchBegan;
- (void)layoutViewTouchEnded;
- (void)layoutViewTouchCancelled;

@end

@protocol GXViewLayoutDelegate <GXViewTouchResponderDelegate>

- (void)layoutView:(UIView *)view;

@end

@protocol GXViewWithLayoutDelegation <NSObject>

@property(nullable, nonatomic, weak) id <GXViewLayoutDelegate> layoutDelegate;

@end

NS_ASSUME_NONNULL_END