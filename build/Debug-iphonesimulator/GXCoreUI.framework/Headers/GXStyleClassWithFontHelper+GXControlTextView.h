//
//  GXStyleClassWithFontHelper+GXControlTextView.h
//  GXCoreUI
//
//  Created by José Echagüe on 12/9/21.
//  Copyright © 2021 GeneXus. All rights reserved.
//

@import Foundation;
@import GXObjectsModel;

#import <GXCoreUI/GXControl.h>
#import <GXCoreUI/GXControlTextViewProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXStyleClassWithFontHelper (GXControlTextView)

/// Apply text or attributedText with style class and format.
/// @Note textTransform should already be applied to the given text.
+ (void)setText:(nullable NSString *)text
 withStyleClass:(nullable GXStyleClass *)styleClass
propertyDefaultResolver:(nullable id<GXStyleClassPropertyDefaultResolver>)resolver
	 textFormat:(GXLayoutControlTextFormat)textFormat
		 toView:(id<GXControlTextView>)view;

/// Apply text or attributedText with style class and format.
/// @Note textTransform should already be applied to the given text.
+ (void)setText:(nullable NSString *)text
withStyleClassWithFont:(id <GXStyleClassWithFont>)classWithFont
	 textFormat:(GXLayoutControlTextFormat)textFormat
		 toView:(id<GXControlTextView>)view;

#if !TARGET_OS_WATCH

+ (void)setTextColorWithStyleClass:(nullable GXStyleClass *)styleClass
		   propertyDefaultResolver:(nullable id<GXStyleClassPropertyDefaultResolver>)resolver
					highlightStyle:(GXHighlightStyleType)highlightStyle
					 fallbackColor:(UIColor * _Nullable(^_Nullable)(void))fallbackColorResolver
					  onlyIfNonNil:(BOOL)onlyIfNonNil
							toView:(id<GXControlTextView>)view;

+ (void)setTextColorWithControlDefaultFallbackColor:(id<GXControl>)control
									   onlyIfNonNil:(BOOL)onlyIfNonNil
											 toView:(id<GXControlTextView>)view;

#endif // !TARGET_OS_WATCH

@end

NS_ASSUME_NONNULL_END
