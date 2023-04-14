//
//  GXControlActionBarButtonItem.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 10/8/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import UIKit;
#import <GXCoreUI/GXControlActionBarItem.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXControlActionBarButtonItem : UIBarButtonItem <GXControlActionBarItemView, UIAccessibilityIdentification>

- (instancetype)initWithTitle:(nullable NSString *)title
						style:(UIBarButtonItemStyle)style
					   target:(nullable id)target
					   action:(nullable SEL)action
				  controlName:(nullable NSString *)controlName;

- (instancetype)initWithGXImageName:(NSString *)imageName
						modelObject:(nullable id<GXModelObject>)modelObject
							  style:(UIBarButtonItemStyle)style
							 target:(nullable id)target
							 action:(nullable SEL)action
						controlName:(nullable NSString *)controlName;

/// #deprecated: 2022-01-26: trunk; #to-remove: ??
- (instancetype)initWithGXImageName:(NSString *)imageName
							  style:(UIBarButtonItemStyle)style
							 target:(nullable id)target
							 action:(nullable SEL)action
						controlName:(nullable NSString *)controlName  __attribute__((deprecated("Use initWithGXImageName:modelObject:style:target:action:controlName: instead")));

@end

NS_ASSUME_NONNULL_END
