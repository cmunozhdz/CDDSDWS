//
//  GXReadWriteLock.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 8/9/15.
//  Copyright (c) 2015 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

/**
 * Objective-C wrapper for read-write locks
 *
 * @discussion This lock allows multiple concurrent reads, but blocks any write if there are other threads reading
 * It also blocks any read or write while there is a writer holding the lock.
 *
 * Avoid aquiring the lock multiple times in the same thread, for it may lead to deadlocks.
 */
@interface GXReadWriteLock : NSObject

- (void)acquireReadLock;

- (void)acquireWriteLock;

- (void)unlock;

@end

NS_ASSUME_NONNULL_END
