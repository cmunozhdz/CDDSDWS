//
//  GXThemeClassWithTransformation.h
//  GXFlexibleClient
//
//  Created by willy on 11/7/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXTransformation.h>

NS_ASSUME_NONNULL_BEGIN

@class GXTransformation;

@protocol GXStyleClassWithTransformation <NSObject>

@property(nullable, nonatomic, strong, readonly) GXTransformation *transformation;
@property(nonatomic, assign, readonly) BOOL animated;
@property(nullable, nonatomic, strong, readonly) NSNumber *animationDuration;

@end

@protocol GXThemeClassWithTransformation <GXStyleClassWithTransformation>
@end

NS_ASSUME_NONNULL_END
