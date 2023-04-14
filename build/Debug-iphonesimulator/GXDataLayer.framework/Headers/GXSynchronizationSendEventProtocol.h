//
//  GXSynchronizationSendEventProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 27/4/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import Foundation;
@import YAJL;
@import GXObjectsModel;

typedef NS_ENUM(uint_least8_t, GXSynchronizationEventActionType) {
	GXSynchronizationEventActionInsert = 1,
	GXSynchronizationEventActionUpdate = 2,
	GXSynchronizationEventActionDelete = 3,
};
#define GXSynchronizationEventActionType_UNDEFINED ((GXSynchronizationEventActionType)UINT_LEAST8_MAX)

typedef NS_ENUM(uint_least8_t, GXSynchronizationEventStatusType) {
	GXSynchronizationEventStatusPending = 1,
	GXSynchronizationEventStatusServerProcessing = 2,
	GXSynchronizationEventStatusServerConfirmed = 3,
	GXSynchronizationEventStatusServerRejected = 4,
	GXSynchronizationEventStatusUserCanceled = 5,
	GXSynchronizationEventStatusSendCheckpoint = 51,
};

NS_ASSUME_NONNULL_BEGIN

@protocol GXSynchronizationSendEvent <YAJLCoding, GXSDTData>

@property(nonatomic, strong, readonly) NSString *syncEventId;
@property(nonatomic, strong, readonly) NSDate *syncEventTimeStamp;
@property(nonatomic, strong, readonly) NSString *syncEventBC;
@property(nonatomic, assign, readonly) GXSynchronizationEventActionType syncEventActionType;
@property(nonatomic, strong, readonly) NSString *syncEventData;
@property(nonatomic, strong, readonly) NSArray *syncEventFiles;
@property(nonatomic, assign, readonly) GXSynchronizationEventStatusType syncEventStatusType;
@property(nonatomic, strong, readonly) NSString *syncEventErrors;

@end

NS_ASSUME_NONNULL_END
