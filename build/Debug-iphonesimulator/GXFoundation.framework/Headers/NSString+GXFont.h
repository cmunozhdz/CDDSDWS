//
//  NSString+GXFont.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 15/4/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import UIKit;

@interface NSString (GXFont)

- (CGSize)gxSizeWithFont:(UIFont *)font;
- (CGSize)gxMultilineSizeWithFont:(UIFont *)font forWidth:(CGFloat)width;
- (CGSize)gxMultilineSizeWithFont:(UIFont *)font forWidth:(CGFloat)width alignedBaseLine:(BOOL)aligned;
- (CGSize)gxMultilineSizeWithFont:(UIFont *)font constrainedToSize:(CGSize)size truncatingLastVisibleLine:(BOOL)truncating;
- (CGSize)gxMultilineSizeWithFont:(UIFont *)font
				constrainedToSize:(CGSize)size
		truncatingLastVisibleLine:(BOOL)truncating
				  alignedBaseLine:(BOOL)aligned;

- (void)gxDrawInRect:(CGRect)rect withFont:(UIFont *)font;
- (void)gxDrawAtPoint:(CGPoint)point withFont:(UIFont *)font;

@end
