//
//  GXControlTextViewProtocol.h
//  GXFlexibleClient
//
//  Created by willy on 11/9/15.
//  Copyright © 2015 Artech. All rights reserved.
//

@import UIKit;
#if TARGET_OS_WATCH
@import WatchKit;
#endif
@import GXFoundation;

NS_ASSUME_NONNULL_BEGIN

@protocol GXControlTextView <NSObject>

#if !TARGET_OS_WATCH
@property(nullable, nonatomic, copy) NSString *gxText;
@property(nullable, nonatomic, strong) UIFont *gxFont;
@property(nullable, nonatomic, strong) UIColor *gxTextColor;
@property(nonatomic) NSTextAlignment gxTextAlignment;
#else
- (void)setGxText:(nullable NSString *)gxText;
- (void)setGxTextColor:(nullable UIColor *)gxTextColor;
#endif // !TARGET_OS_WATCH

#if !TARGET_OS_WATCH
@property(nullable, nonatomic, copy) NSAttributedString *gxAttributedText;
#else
- (void)setGxAttributedText:(nullable NSAttributedString *)gxAttributedText;
#endif // !TARGET_OS_WATCH

@optional
- (void)setGxPlaceholderTextColor:(nullable UIColor *)placeholderTextColor;
@property(null_resettable, nonatomic, strong) UIColor *gxPlaceholderTextColor;
@property(nullable, nonatomic, copy) NSString *gxPlaceholderText;

#if !TARGET_OS_WATCH
@property(nonatomic, copy) NSDictionary<NSAttributedStringKey, id> *gxTypingAttributes;
@property(nullable, nonatomic) UIView *gxInputView;
#endif // !TARGET_OS_WATCH

@end

#if !TARGET_OS_WATCH
@interface UILabel (GXControlTextView) <GXControlTextView>
@end

@interface UITextField (GXControlTextView) <GXControlTextView>
@end

@interface UITextView (GXControlTextView) <GXControlTextView>
@end

@interface UIView (GXControlTextView)

+ (NSTextAlignment)gxTextAlignmentFromHorizontalAlignment:(GXHorizontalAlignType)hAlign forView:(UIView *)view;

+ (void)setGxTextAlignmentFromHorizontalAlignment:(GXHorizontalAlignType)hAlign toControlTextView:(UIView<GXControlTextView> *)view;

@end

#else

@interface WKInterfaceLabel (GXControlTextView) <GXControlTextView>
@end
#endif // !TARGET_OS_WATCH

NS_ASSUME_NONNULL_END
