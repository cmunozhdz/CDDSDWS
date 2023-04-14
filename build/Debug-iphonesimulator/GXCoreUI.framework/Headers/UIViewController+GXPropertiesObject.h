//
//  UIViewController+GXPropertiesObject.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 11/11/15.
//  Copyright © 2015 Artech. All rights reserved.
//

@import UIKit;
@import GXFoundation;

@interface UIViewController (GXPropertiesObject)

@property(nonnull, nonatomic, strong, readonly) id <GXMutablePropertiesObject> gxProperties;

@end
