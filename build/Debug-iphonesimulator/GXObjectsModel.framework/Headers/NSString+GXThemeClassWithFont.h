//
//  NSString+GXThemeClassWithFont.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 15/4/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXThemeClassWithFont.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (GXThemeClassWithFont)

- (NSAttributedString *)attributedStringWithThemeClass:(nullable id<GXStyleClassWithFont>)classWithFont; // defaultFontResolver:NULL
- (CGSize)gxMultilineSizeWithThemeClass:(nullable id<GXStyleClassWithFont>)classWithFont forWidth:(CGFloat)width; // defaultFontResolver:NULL

- (NSAttributedString *)attributedStringWithThemeClass:(nullable id<GXStyleClassWithFont>)classWithFont
								   defaultFontResolver:(UIFont * _Nullable (^ _Nullable)(void))defaultFontResolver; // alignmentResolver:NULL
- (CGSize)gxMultilineSizeWithThemeClass:(nullable id<GXStyleClassWithFont>)classWithFont
							   forWidth:(CGFloat)width
					defaultFontResolver:(UIFont * _Nullable (^ _Nullable)(void))defaultFontResolver; // alignmentResolver:NULL

- (NSAttributedString *)attributedStringWithThemeClass:(nullable id<GXStyleClassWithFont>)classWithFont
								   defaultFontResolver:(UIFont * _Nullable (^ _Nullable)(void))defaultFontResolver
									 alignmentResolver:(NSTextAlignment (^ _Nullable)(void))alignmentResolver;
- (CGSize)gxMultilineSizeWithThemeClass:(nullable id<GXStyleClassWithFont>)classWithFont
							   forWidth:(CGFloat)width
					defaultFontResolver:(UIFont * _Nullable (^ _Nullable)(void))defaultFontResolver
					  alignmentResolver:(NSTextAlignment (^ _Nullable)(void))alignmentResolver;


@end

NS_ASSUME_NONNULL_END
