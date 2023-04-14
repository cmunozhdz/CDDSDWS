//
//  UIView+GXSnapshotting.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 21/11/14.
//  Copyright (c) 2014 Artech. All rights reserved.
//

@import UIKit;

@interface UIView (GXSnapshotting)

- (UIImage *)gxSnapshotIntoImage:(BOOL)opaque afterScreenUpdates:(BOOL)afterUpdates;

- (UIImage *)gxSnapshotIntoImage:(BOOL)opaque afterScreenUpdates:(BOOL)afterUpdates rect:(CGRect)rect;

@end
