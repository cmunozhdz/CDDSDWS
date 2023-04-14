//
//  GXSDTMediaItemFinishedInfo.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 31/3/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import Foundation;

typedef NS_ENUM(uint_least8_t, GXMediaFinishReasonType) {
	GXMediaFinishReasonUnknown = 0,
	GXMediaFinishReasonPlaybackCompleted = 1,
	GXMediaFinishReasonStopped = 2,
	GXMediaFinishReasonSkipped = 3,
	GXMediaFinishReasonQueueReplaced = 4,
};

@interface GXSDTMediaItemFinishedInfo : NSObject

@property (nonatomic, strong) NSString *itemId;
@property (nonatomic) NSInteger queuePosition;
@property (nonatomic) NSInteger trackPosition;
@property (nonatomic) GXMediaFinishReasonType reason;

- (instancetype)initWithItemId:(NSString *)itemId
				 queuePosition:(NSInteger)queuePosition
				 trackPosition:(NSInteger)trackPosition
						reason:(GXMediaFinishReasonType)reason NS_DESIGNATED_INITIALIZER;

- (NSDictionary *)dictionaryRepresentation;

@end
