//
//  GXMessageViewController.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 02/08/10.
//  Copyright 2010 Artech. All rights reserved.
//

#import <GXCoreUI/GXApplicationBarsAppearance.h>
#import <GXCoreUI/GXMessageView.h>
#import <GXCoreUI/GXWindow.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXMessageViewController : UIViewController <GXApplicationBarsAppearance, GXAllowLowContrastTintColor>

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

@property(nullable, nonatomic, strong, readonly) GXMessageView *messageView;
@property(nullable, nonatomic, strong, readonly) NSString *message;
@property(nonatomic, assign, readonly) BOOL animating;

- (void)setMessage:(nullable NSString *)message animating:(BOOL)animating;

@end

NS_ASSUME_NONNULL_END
