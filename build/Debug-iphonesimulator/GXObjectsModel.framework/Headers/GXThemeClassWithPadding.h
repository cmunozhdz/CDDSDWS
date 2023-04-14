//
//  GXThemeClassWithPadding.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 13/12/11.
//  Copyright (c) 2011 Artech. All rights reserved.
//

@import Foundation;
@import GXFoundation;

NS_ASSUME_NONNULL_BEGIN

@protocol GXStyleClassWithPadding <NSObject>

@property(nonatomic, assign, readonly) GXLayoutQuadDimension padding;

@end

@protocol GXThemeClassWithPadding <GXStyleClassWithPadding>
@end

NS_ASSUME_NONNULL_END
