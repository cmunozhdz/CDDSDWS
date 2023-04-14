//
//  GXScrollableControlProtocol.h
//  GXFlexibleClient
//
//  Created by willy on 9/26/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@protocol GXScrollableControlScrollInfo <NSObject>

- (CGPoint)gxScrollInfoContentOffset;
- (CGSize)gxScrollInfoContentSize;
- (UIEdgeInsets)gxScrollInfoContentInset;

@end

@protocol GXScrollableControl <NSObject>

- (void)scrollableControlContainerId:(NSUInteger)containerId didScrollWithInfo:(id<GXScrollableControlScrollInfo>)scrollInfo;

@end

@interface UIScrollView (GXScrollableControlScrollInfo) <GXScrollableControlScrollInfo>
@end

NS_ASSUME_NONNULL_END
