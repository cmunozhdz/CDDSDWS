//
//  UIFont+Helpers.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 30/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

@import UIKit;
@import CoreGraphics;

NS_ASSUME_NONNULL_BEGIN

@interface UIFont (Helpers)

/*!
 Adjust the given size to be base line aligned with the receiver font
 
 @param size Size required by the multiline text
 @result The vertical aligned size aligned to base line, using self.ascender and self.descender properties
 @discussion The result size.height is always integer and grater or equal than the given size.
 */
- (CGSize)gxBaseLineAlignedMultilineSize:(CGSize)size;

@end

NS_ASSUME_NONNULL_END