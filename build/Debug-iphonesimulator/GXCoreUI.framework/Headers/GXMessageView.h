//
//  GXMessageView.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 02/08/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@interface GXMessageView : UIView

@property(nonatomic, readonly) UIActivityIndicatorView *activityIndicatorView;
@property(nonatomic, readonly) UILabel *titleView;

@end

NS_ASSUME_NONNULL_END