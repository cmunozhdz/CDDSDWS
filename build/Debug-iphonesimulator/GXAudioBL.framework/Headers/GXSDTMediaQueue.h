//
//  GXSDTMediaQueue.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 6/11/15.
//  Copyright © 2015 Artech. All rights reserved.
//

@import GXObjectsModel;
#import <GXAudioBL/GXSDTMediaItem.h>

@interface GXSDTMediaQueue : NSObject

@property (nonatomic, strong, readonly) NSString *mediaQueueTitle;
@property (nonatomic, strong, readonly) NSArray<GXSDTMediaItem *> *mediaQueueItems;
@property (nonatomic, assign, readonly) NSUInteger mediaQueueItemsCount;
@property (nonatomic, assign) BOOL mediaQueueShuffle;

- (instancetype)initWithSDTData:(id<GXSDTData>)sdtData;

- (NSDictionary *)dictionaryRepresentation;

/**
 * Returns the 1-based position for the media item with the given Id
 *
 * @param mediaItemId The media item identificator to search for
 * @return The 1-based position of the media item if found, 0 otherwise
 */
- (NSUInteger)positionForMediaItemWithId:(NSString *)mediaItemId;

/**
 * Returns the sorted media items array, taking into account the mediaQueueShuffle property
 *
 * @discussion If mediaQueueShuffle is set to false, the original mediaQueueItems array is returned; if set to true, then the order of the list is shuffled
 * Consecutive calls to this method (without changing the value of mediaQueueShuffle) return the list in the same order.
 */
- (NSArray<GXSDTMediaItem *> *)shuffledMediaQueueItems;

/**
 * Toggles the mediaQueueShuffle property, and if the resulting list is shuffled, moves the item with mediaItemId to the first position
 *
 * @param mediaItemId The id of the first item in the list after the shuffle operation
 */
- (void)toggleMediaQueueShuffledWithCurrentItemId:(NSString *)mediaItemId;

@end
