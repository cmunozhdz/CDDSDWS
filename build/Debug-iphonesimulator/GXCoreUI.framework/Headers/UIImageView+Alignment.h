//
//  UIImageView+Alignment.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 24/11/11.
//  Copyright (c) 2011 Artech. All rights reserved.
//

@import UIKit;
@import GXFoundation;

@interface UIImageView (GXAlignment)

- (void)alignAndResizeWithContentMode:(UIViewContentMode)contentMode
							   inRect:(CGRect)frame
					  horizontalAlign:(GXHorizontalAlignType)hAlign
						verticalAlign:(GXVerticalAlignType)vAlign
                    resizeImageToSize:(CGSize)targetImageSize;

+ (CGFloat)requiredHeightForViewWidth:(CGFloat)viewWidth
						  contentMode:(UIViewContentMode)contentMode
							imageSize:(CGSize)imageSize;

@end
