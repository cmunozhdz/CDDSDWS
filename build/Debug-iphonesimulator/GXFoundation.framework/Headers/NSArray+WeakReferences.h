//
//  NSArray+WeakReferences.h
//  GXFlexibleClient
//
//  Created by willy on 3/14/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import Foundation;

@interface NSMutableArray (WeakReferences)

+ (id)mutableArrayUsingWeakReferences;
+ (id)mutableArrayUsingWeakReferencesWithCapacity:(NSUInteger)capacity;

@end
