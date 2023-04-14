//
//  GXScrollManager.h
//  GXFlexibleClient
//
//  Created by willy on 9/26/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import Foundation;
#import <GXCoreUI/GXControlContainer.h>
#import <GXCoreUI/GXScrollableControlProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXScrollManager : NSObject

+ (GXScrollManager *)sharedManager;

- (void)subscribeScrollableControl:(id<GXScrollableControl>)control toContainerId:(NSUInteger)containerId;
- (void)unsubscribeScrollableControl:(id<GXScrollableControl>)control;

- (void)notifyScrollWithContainerId:(NSUInteger)containerId scrollInfo:(id <GXScrollableControlScrollInfo>)scrollInfo;

@end

@interface GXScrollManagerScrollInfo : NSObject <GXScrollableControlScrollInfo>

- (instancetype)initWithScrollInfo:(nullable id <GXScrollableControlScrollInfo>)scrollInfo;

@property CGPoint contentOffset;
@property CGSize contentSize;
@property UIEdgeInsets contentInset;

@end

NS_ASSUME_NONNULL_END
