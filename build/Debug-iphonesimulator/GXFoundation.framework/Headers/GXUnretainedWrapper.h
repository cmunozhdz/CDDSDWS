//
//  GXUnretainedWrapper.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 22/10/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface GXUnretainedWrapper : NSObject

@property(nonatomic, unsafe_unretained, readonly) id unretainedObject;
@property(nullable, nonatomic, weak, readonly) id weakObject;

- (instancetype)initWithObject:(id)object NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END