//
//  GXNavigationBar.h
//  GXFlexibleClient
//
//  Created by willy on 11/24/15.
//  Copyright © 2015 Artech. All rights reserved.
//

@import UIKit;

@interface GXNavigationBar : UINavigationBar

@property(nonatomic, assign) BOOL sizeToFitTitleView;

#if TARGET_OS_IOS
@property(nonatomic, assign) BOOL enableLargeTitleBackgroundViewLayoutCorrection API_AVAILABLE(ios(11.0));
#endif // TARGET_OS_IOS

@end
