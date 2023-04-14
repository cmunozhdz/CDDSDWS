//
//  GXWindow.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 2/2/15.
//  Copyright (c) 2015 Artech. All rights reserved.
//

@import UIKit;

@protocol GXAllowLightTintColor <NSObject> // Use GXAllowLowContrastTintColor instead
@end

@protocol GXAllowLowContrastTintColor <GXAllowLightTintColor>
@end
