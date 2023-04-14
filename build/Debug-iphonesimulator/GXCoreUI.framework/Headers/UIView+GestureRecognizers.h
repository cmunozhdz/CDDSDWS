//
//  UIView+GestureRecognizers.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 3/13/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@interface UIView (GestureRecognizers)

- (nullable UITapGestureRecognizer *)gxSingleTapGestureRecognizer;

- (nullable UITapGestureRecognizer *)gxDoubleTapGestureRecognizer;

- (UITapGestureRecognizer *)gxAddTapGestureRecognizerWithTarget:(nullable id)target
													   selector:(nullable SEL)selector
													   delegate:(nullable id<UIGestureRecognizerDelegate>)delegate
												   numberOfTaps:(NSUInteger)taps
#if TARGET_OS_IOS
												numberOfTouches:(NSUInteger)touches
#endif // TARGET_OS_IOS
										 requiredGesturesToFail:(nullable NSArray<UIGestureRecognizer *> *)reqToFail;

- (BOOL)gxViewDisablesTapGestures;

@end

NS_ASSUME_NONNULL_END