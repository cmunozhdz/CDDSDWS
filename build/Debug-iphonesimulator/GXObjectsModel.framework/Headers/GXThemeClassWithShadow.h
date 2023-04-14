//
//  GXThemeClassWithShadow.h
//  GXObjectsModel
//
//  Created by willy on 6/7/18.
//  Copyright © 2018 GeneXus. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@protocol GXStyleClassWithShadow <NSObject>

@property(nonatomic, assign, readonly) CGSize shadowOffset;
@property(nullable, nonatomic, strong, readonly) UIColor *shadowColor;
@property(nonatomic, assign, readonly) CGFloat shadowOpacity;
@property(nonatomic, assign, readonly) CGFloat shadowRadius;

@end

@protocol GXThemeClassWithShadow <GXStyleClassWithShadow>
@end

NS_ASSUME_NONNULL_END
