//
//  GXSynchronizationSendService.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 4/1/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import Foundation;
#import <GXDataLayer/GXSynchronizationSendEventProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXOfflineThreadSynchronizationSendService;

typedef void (^GXSynchronizationSendPendingEventsCompletionBlock)(NSError * _Nullable);

@protocol GXSynchronizationSendService <NSObject>

/// Returns non nil only when caled from a gx offline thread. Must not be shared across threads.
@property(nullable, nonatomic, readonly) id<GXOfflineThreadSynchronizationSendService> offlineThreadSendService;

/*!
 Returns YES if the synchronization is enabled
 
 @discussion It could be disabled for several reasons: the application is online, the user turned off the feature, etc.
 */
- (BOOL)isSynchronizationSendEnabled;

/// Indicates if the synchronization should be performed automatically when there is network connection
- (BOOL)shouldSendAutomaticallyWhenConnected;

/// Returns YES if the minimum time between sends has been elapsed, NO otherwise
- (BOOL)hasMinimumTimeBetweenSendsBeenElapsed;

/*!
 Sends (asynchronically) the events with Status = Pending to the server
 
 Warning: this method does not consider the minimum time between sends. The caller has the responsability to check if
 the time has been elapsed when appropiates (i.e. user started acctions won't check, automatic synchronization will)
 
 @param userStarted Indicates wether the user started the action by calling Synchronization.Send() or it was started automatically
 @param block The block to be executed upon completion
 @discussion The block is executed even if there where not pending events in the table
 */
- (void)sendPendingEventsStartedFromUserCode:(BOOL)userStarted withCompletionBlock:(nullable GXSynchronizationSendPendingEventsCompletionBlock)block;

/// Schedules the Send operation to be performed after the Minimum time between sends has elapsed
- (void)scheduledSendAfterMinimumTime;

@end


/// MUST be called from gx offline thread
@protocol GXOfflineThreadSynchronizationSendService <GXSynchronizationSendService>

/// Creates the database table to be used to store the synchronization events
- (void)createSynchronizationEventsTableIfNeeded;

/// Returns YES if the synchronization event table has any record with Status = Pending
- (BOOL)hasPendingSynchronizationEvents;

/// Returns YES if the synchronization event table has any record with the given status
- (BOOL)hasSynchronizationEventWithStatus:(GXSynchronizationEventStatusType)status;

/// Returns YES if the synchronization event table has any record
- (BOOL)hasAnySynchronizationEvent;

/*!
 Returns the list of the current synchronization events with Status = Pending
 
 @result A NSArray of id<GXSynchronizationSendEvent>
 */
- (nullable NSArray<id<GXSynchronizationSendEvent>> *)getPedingSynchronizationEvents;

/*!
 Returns the list of the current synchronization events, regardless of their status
 
 @result A NSArray of id<GXSynchronizationSendEvent>
 */
- (nullable NSArray<id<GXSynchronizationSendEvent>> *)getAllSynchronizationEvents;

/*!
 Returns the list of the current synchronization events with the given status
 
 @result A NSArray of id<GXSynchronizationSendEvent>
 */
- (nullable NSArray<id<GXSynchronizationSendEvent>> *)getSynchronizationEventsWithStatus:(GXSynchronizationEventStatusType)status;

/*!
 Bulk inserts the received reorganization events into the table
 
 @param pendingEvents Array of id<GXSynchronizationSendEvent> containing the events to be loaded into the table
 */
- (void)loadSynchronizationEvents:(NSArray<id<GXSynchronizationSendEvent>> *)pendingEvents;

/*!
 Sends (synchronically) the events with Status = Pending to the server
 
 Warning: this method does not consider the minimum time between sends. The caller has the responsability to check if
 the time has been elapsed when appropiates (i.e. user started acctions won't check, automatic synchronization will)
 
 @discussion This method executes the synchronization and waits until it finishes. Must be executed off the main thread.
 */
- (void)sendPendingEventsAndWaitForCompletion;

/*!
 Marks the synchronization event identified by the given GUID string as Pending
 
 @param peId The pending event identifier, it must be a string representation of a GUID
 */
- (void)markSynchronizationEventAsPending:(NSString *)peId;

/*!
 Removes the synchronization event identified by the given GUID string
 
 @param peId The pending event identifier, it must be a string representation of a GUID
 */
- (void)removeSynchronizationEvent:(NSString *)peId;

/// Sets a new checkpoint, so that events can later be sent in batches
- (void)createSendCheckpoint;

@end

NS_ASSUME_NONNULL_END
