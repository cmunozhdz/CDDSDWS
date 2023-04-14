//
//  GXSDTMediaQueueState.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 6/11/15.
//  Copyright © 2015 Artech. All rights reserved.
//

@import Foundation;

typedef NS_ENUM(uint_least8_t, GXMediaPlaybackStateType) {
	GXMediaPlaybackStateNone = 0,
	GXMediaPlaybackStateStopped = 1,
	GXMediaPlaybackStatePaused = 2,
	GXMediaPlaybackStatePlaying = 3,
	GXMediaPlaybackStateError = 4,
	GXMediaPlaybackStateTransitional = 5
};

@interface GXSDTMediaQueueState : NSObject

@property (nonatomic) GXMediaPlaybackStateType playbackState;
@property (nonatomic) NSInteger queuePosition;
@property (nonatomic) NSInteger trackPosition;
@property (nonatomic) NSInteger trackDuration;
@property (nonatomic, nonnull) NSString *mediaItemId;

- (nonnull NSDictionary *)dictionaryRepresentation;

@end
