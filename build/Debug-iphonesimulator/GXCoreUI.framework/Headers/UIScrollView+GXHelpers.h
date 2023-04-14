//
//  UIScrollView+GXHelpers.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 16/11/17.
//  Copyright © 2017 GeneXus. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@interface UIScrollView (GXHelpers)

/// Returns adjustedContentInset in iOS >= 11, contentInsets otherwise
@property(nonatomic, readonly) UIEdgeInsets gxAdjustedContentInset;


@end

NS_ASSUME_NONNULL_END
