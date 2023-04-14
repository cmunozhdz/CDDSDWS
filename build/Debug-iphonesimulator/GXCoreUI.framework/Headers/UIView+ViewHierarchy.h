//
//  UIView+ViewHierarchy.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 28/12/11.
//  Copyright (c) 2011 Artech. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@interface UIView (ViewHierarchy)

- (nullable __kindof UIView *)superviewOfClass:(Class)c upToView:(nullable UIView *)upToView;
- (BOOL)hasSuperviewOfClass:(Class)c upToView:(nullable UIView *)upToView;

- (nullable __kindof UIView *)subviewOfClass:(Class)c recursive:(BOOL)recursive;
- (nullable __kindof UIView *)subviewOfClass:(Class)c;
- (BOOL)hasSubviewOfClass:(Class)c;

- (nullable __kindof UIView *)subviewOfClass:(Class)c withTag:(NSUInteger)tag;
- (BOOL)hasSubviewOfClass:(Class)c withTag:(NSUInteger)tag;

- (void)gxEnumerateSubviewsOfClass:(Class)c recursive:(BOOL)recursive block:(void(^)(__kindof UIView *view, BOOL *stop))block;

@end

NS_ASSUME_NONNULL_END
