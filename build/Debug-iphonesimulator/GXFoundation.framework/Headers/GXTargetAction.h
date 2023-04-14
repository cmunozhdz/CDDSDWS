//
//  GXTargetAction.h
//  GXFlexibleClient
//
//  Created by willy on 11/29/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface GXTargetAction : NSObject {
@private
    id __weak _target;
    SEL _selector;
}

- (instancetype)initWithTarget:(id)target selector:(SEL)action NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

- (void)onTick;
- (void)invalidate;

@end

NS_ASSUME_NONNULL_END