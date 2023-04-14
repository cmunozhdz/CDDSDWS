//
//  GXControlWithUserInterfaceController.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 26/7/18.
//  Copyright © 2018 GeneXus. All rights reserved.
//

#import <GXCoreUI/GXControl.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXControlWithUserInterfaceController <GXControl>

@property(nullable, nonatomic, strong, readonly) UIViewController *userInterfaceController;

@end

NS_ASSUME_NONNULL_END
