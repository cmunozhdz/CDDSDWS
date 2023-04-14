//
//  GXThemeClassWithMargin.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 13/12/11.
//  Copyright (c) 2011 Artech. All rights reserved.
//

@import Foundation;
@import GXFoundation;

NS_ASSUME_NONNULL_BEGIN

@protocol GXStyleClassWithMargin <NSObject>

@property(nonatomic, assign, readonly) GXLayoutQuadDimension margin;

@end

@protocol GXThemeClassWithMargin <GXStyleClassWithMargin>
@end

NS_ASSUME_NONNULL_END
