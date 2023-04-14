//
//  GXTimerProxy.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 24/06/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface GXTimerProxy : NSProxy {
@private
    id _target;
    NSTimeInterval _timeInterval;
    BOOL _repeats;
	
    NSTimer *_timer;
}

+ (instancetype)scheduledTimerProxyWithTarget:(id)target timeInterval:(NSTimeInterval)ti repeats:(BOOL)repeats;
- (void)invalidate;

@end

NS_ASSUME_NONNULL_END
