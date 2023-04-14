//
//  GXAudioManager.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 01/08/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;
@import AVFoundation;
@import GXCoreBL;
#import <GXAudioBL/GXSDTAudioPlayerSettings.h>
#import <GXAudioBL/GXSDTMediaQueue.h>
#import <GXAudioBL/GXSDTMediaQueueState.h>

typedef NS_ENUM(uint_least8_t, GXAudioManagerCategoryType) {
	GXAudioManagerCategoryBackground = 1,
	GXAudioManagerCategoryMix = 2,
	GXAudioManagerCategorySolo = 3,
};

extern NSString *const GXAudioManagerMediaItemDictionaryKey;

extern NSString *const GXAudioManagerDidLoadMediaQueueNotification;
extern NSString *const GXAudioManagerDidStartPlayingMediaItemNotification;
extern NSString *const GXAudioManagerDidPauseNotification;
extern NSString *const GXAudioManagerDidResumeNotification;
extern NSString *const GXAudioManagerDidStopNotification;
extern NSString *const GXAudioManagerDidSelectMediaItemNotification;

/*
 * When the previous button is pressed, if the song has advanced past this threshold, the song is restarted.
 * If the threshold was not yet reached, then the previous song is played.
 * It is expressed in seconds.
 */
extern NSTimeInterval const GXAudioManagerSongRestartThreshold;

@interface GXAudioManager : NSObject <GXAudioManagerService, AVAudioPlayerDelegate>

#pragma mark -

+ (GXAudioManager *)sharedInstance;

#pragma mark -

- (void)playWithURL:(NSURL *)url category:(GXAudioManagerCategoryType)category description:(NSString *)descr;

- (void)stop;
- (void)stopCategory:(GXAudioManagerCategoryType)category;

- (void)pauseCategory:(GXAudioManagerCategoryType)category;
- (void)resumeCategory:(GXAudioManagerCategoryType)category;

- (BOOL)isPlaying;
- (BOOL)isPlayingCategory:(GXAudioManagerCategoryType)category;

#pragma mark -

@property (nonatomic, strong) GXSDTMediaQueue *mediaQueue;

@property (nonatomic, strong, readonly) GXSDTMediaItem *firstMediaItem;
@property (nonatomic, strong, readonly) GXSDTMediaItem *currentMediaItem;

@property (nonatomic) BOOL showsMiniPlayer;

@property (nonatomic, strong) GXSDTAudioPlayerSettings *audioPlayerSettings;

@property (nonatomic, assign, readonly) BOOL mediaQueueRepeatOne;
@property (nonatomic, assign, readonly) BOOL mediaQueueRepeatAll;

- (GXSDTMediaQueueState *)queueState;

- (void)playQueue;

- (void)pauseQueue;

- (void)tooglePause;

- (void)toogleFavorite;

- (void)nextQueueTrack;

- (void)previousQueueTrack;

- (void)shuffleQueue;

/*
 * Changes the current index in the play queue
 *
 * @param index The 1-based index of the media item to set as current
 *
 * @return true if success, false if the index is not valid.
 */
- (BOOL)setQueueCurrentIndex:(NSInteger)index;

/*
 * Changes the current item in the play queue
 *
 * @param mediaId The Id of the media item to be placed as the current item
 *
 * @return true if success, false if the Id is not valid.
 */
- (BOOL)setQueueCurrentItem:(NSString *)mediaId;

#pragma mark - 

- (void)onQueueItemCustomEvent:(NSString *)customActionId;


@end
