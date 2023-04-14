//
//  GXKeyboardStateListener.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 23/02/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import UIKit;

typedef NS_ENUM(uint_least8_t, GXKeyboardStateType) {
	GXKeyboardStateHidden,
	GXKeyboardStateShowing,
	GXKeyboardStateVisible,
	GXKeyboardStateHidding
};

@interface GXKeyboardStateListener : NSObject {

@private
    GXKeyboardStateType _state;
}

+ (GXKeyboardStateListener *)sharedInstance;

@property(readonly) GXKeyboardStateType state;

@end
