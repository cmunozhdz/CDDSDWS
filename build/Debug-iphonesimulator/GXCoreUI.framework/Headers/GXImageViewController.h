//
//  GXImageViewController.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 15/06/10.
//  Copyright 2010 Artech. All rights reserved.
//

#import <GXCoreUI/GXApplicationBarsAppearance.h>
#import <GXCoreUI/GXWindow.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Default GXApplicationBarsAppearance gxApplicationBarsClassName method implementation returns nil
 * This class implements setGxApplicationBarsClassName:, callers can use this method to change the class
 */
@interface GXImageViewController : UIViewController <GXApplicationBarsAppearance, GXAllowLowContrastTintColor>

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
