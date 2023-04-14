//
//  GXThemeClassWithDimensions.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 5/3/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@protocol GXStyleClassWithDimensions <NSObject>

@property (nonatomic, assign, readonly) NSUInteger width;
@property (nonatomic, assign, readonly) NSUInteger height;

@end

@protocol GXThemeClassWithDimensions <GXStyleClassWithDimensions>
@end

NS_ASSUME_NONNULL_END
