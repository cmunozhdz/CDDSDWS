//
//  GXThemeClassWithLabel.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 23/01/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;
@import UIKit;
@import GXFoundation;

@class GXThemeClass;

NS_ASSUME_NONNULL_BEGIN

@protocol GXStyleClassWithLabel <NSObject>

@property(nullable, nonatomic, strong, readonly) GXStyleClass *labelThemeClass;
@property(nonatomic, assign, readonly) CGFloat labelWidth;
@property(nonatomic, assign, readonly) GXHorizontalAlignType labelHorizontalAlignment;
@property(nonatomic, assign, readonly) GXVerticalAlignType labelVerticalAlignment;

@end

@protocol GXThemeClassWithLabel <GXStyleClassWithLabel>
@end

NS_ASSUME_NONNULL_END
