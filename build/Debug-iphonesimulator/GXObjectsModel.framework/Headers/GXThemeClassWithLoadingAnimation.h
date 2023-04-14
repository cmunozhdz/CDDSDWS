//
//  GXThemeClassWithLoadingAnimation.h
//  GXObjectsModel
//
//  Created by Fabian Inthamoussu on 8/8/17.
//  Copyright © 2017 GeneXus. All rights reserved.
//

@import Foundation;
@import UIKit;
@import GXFoundation;

@class GXThemeClass;

NS_ASSUME_NONNULL_BEGIN

@protocol GXStyleClassWithLoadingAnimation <NSObject>

@property(nullable, nonatomic, strong, readonly) GXStyleClass *loadingAnimationThemeClass;

@end

@protocol GXThemeClassWithLoadingAnimation <GXStyleClassWithLoadingAnimation>
@end

NS_ASSUME_NONNULL_END
