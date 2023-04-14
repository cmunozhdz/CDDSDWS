//
//  GXEOProgressIndicator.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 22/3/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import GXCoreBL;
@import GXStandardClasses;

NS_ASSUME_NONNULL_BEGIN

@interface GXEOProgressIndicator : GXExternalObjectBase
@end

@interface GXEOProgressIndicator (OfflineGenerator)

@property (nonatomic, strong) NSString *progressIndicatorClass GX_WARN_GXOFFLINETHREAD_ONLY_METHOD;
@property (nonatomic, assign) NSInteger progressIndicatorType GX_WARN_GXOFFLINETHREAD_ONLY_METHOD;
@property (nonatomic, strong) NSString *progressIndicatorTitle GX_WARN_GXOFFLINETHREAD_ONLY_METHOD;
@property (nonatomic, strong) NSString *progressIndicatorDescription GX_WARN_GXOFFLINETHREAD_ONLY_METHOD;
@property (nonatomic, assign) NSInteger progressIndicatorMaxValue GX_WARN_GXOFFLINETHREAD_ONLY_METHOD;
@property (nonatomic, assign) NSInteger progressIndicatorValue GX_WARN_GXOFFLINETHREAD_ONLY_METHOD;

- (void)show GX_WARN_GXOFFLINETHREAD_ONLY_METHOD;

- (void)showWithTitle:(NSString *)title NS_SWIFT_NAME(showWithTitle(_:)) GX_WARN_GXOFFLINETHREAD_ONLY_METHOD;

- (void)showWithTitleAndDescription:(NSString *)title :(NSString *)desc NS_SWIFT_NAME(showWithTitleAndDescription(_:_:)) GX_WARN_GXOFFLINETHREAD_ONLY_METHOD;

- (void)hide GX_WARN_GXOFFLINETHREAD_ONLY_METHOD;

@end

NS_ASSUME_NONNULL_END
