//
//  GXImageViewActivityIndicator.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 6/9/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import UIKit;

@protocol GXProgressActivityIndicator <NSObject>

- (void)updateProgress:(CGFloat)percent;

@optional
- (void)updateProgress:(CGFloat)percent animated:(BOOL)animated;

@end

NS_ASSUME_NONNULL_BEGIN

@interface GXImageViewActivityIndicator : UIView <GXProgressActivityIndicator>

@end

NS_ASSUME_NONNULL_END
