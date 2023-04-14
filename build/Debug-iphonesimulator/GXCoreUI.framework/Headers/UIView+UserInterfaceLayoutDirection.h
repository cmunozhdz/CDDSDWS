//
//  UIView+UserInterfaceLayoutDirection.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 22/01/2019.
//  Copyright © 2019 GeneXus. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@interface UIView (UserInterfaceLayoutDirection)

@property(nonatomic, readonly) UIUserInterfaceLayoutDirection gxEffectiveUserInterfaceLayoutDirection;

@property(nonatomic, readonly, getter=isLayoutDirectionLeftToRight) BOOL layoutDirectionLeftToRight;
@property(nonatomic, readonly, getter=isLayoutDirectionRightToLeft) BOOL layoutDirectionRightToLeft;

@property(nonatomic, readonly) NSTextAlignment forcedNaturalTextAlignmentIfNeeded;

@end

NS_ASSUME_NONNULL_END
