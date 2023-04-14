//
//  GXSynchronizationReceiveService.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 4/1/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint_least8_t, GXSynchronizationReceiveStatusType) {
	// As documented in http://wiki.genexus.com/commwiki/servlet/hwikibypageid?23603
	GXSynchronizationReceiveStatusOk = 0,
	GXSynchronizationReceiveStatusSyncNotNeeded = 1,
	GXSynchronizationReceiveStatusAppNotOffline = 2,
	GXSynchronizationReceiveStatusErrorHasPendingEvents = 3,
	GXSynchronizationReceiveStatusAlreadyRunning = 8,
	GXSynchronizationReceiveStatusMetadataErrorCode1 = 51,
	GXSynchronizationReceiveStatusMetadataErrorCode2 = 52,
	GXSynchronizationReceiveStatusMetadataErrorCode3 = 53,
	GXSynchronizationReceiveStatusErrorUnknown = 99
};

typedef NS_ENUM(uint_least8_t, GXSynchronizationServerStatusType) {
	GXSynchronizationServerStatusOk = 0,
	GXSynchronizationServerStatusSyncNeeded = 1,
	GXSynchronizationServerStatusAppNotOffline = 2,
};

typedef NS_ENUM(uint_least8_t, GXSynchronizationReceiveSettings) {
	GXSynchronizationReceiveSettingNone = 0,
	GXSynchronizationReceiveSettingWaitIfRunning = 1 << 0,
	GXSynchronizationReceiveSettingUserStarted = 1 << 1
};

typedef void (^GXSynchronizationReceiveCompletionBlock)(GXSynchronizationReceiveStatusType, NSError * _Nullable);

typedef void (^GXSynchronizationServerStatusCompletionBlock)(GXSynchronizationServerStatusType, NSError * _Nullable);



@protocol GXSynchronizationReceiveService <NSObject>

/**
 * Loads the synchronization hashes from the main bundle, so that the next synchronization will start from the preloaded database state.
 *
 * Warning! Use this method wisely, it cannot be undone, and it will probably break the synchronization process.
 */
- (void)loadSynchronizationHashesFromBundleResources;

/**
* Loads the synchronization hashes from the specified file, so that the next synchronization will start from the given hashes.
*
* Warning! Use this method wisely, it cannot be undone, and it will probably break the synchronization process.
*/
- (BOOL)loadSynchronizationHashesFromFilePath:(NSString *)filePath;

/**
 * Removes the synchronization hashes, so that the next synchronization will perform a full synchronization
 *
 * Warning! Use this method wisely, it cannot be undone, and it will probably break the synchronization process.
 */
- (void)removeSynchronizationHashes;

/// Executes the synchronization, but only if needed.
- (void)synchronizeIfNeeded;

/// Same as  synchronizeWithSettings:completionBlock: with GXSinchronizationReceiveSettingNone
- (void)synchronizeWithCompletionBlock:(nullable GXSynchronizationReceiveCompletionBlock)block;

/// Executes the reorganization. The block is executed regardless of the result.
- (void)synchronizeWithSettings:(GXSynchronizationReceiveSettings)settings completionBlock:(nullable GXSynchronizationReceiveCompletionBlock)block;

- (void)checkServerSynchronizationStatusWithCompletionBlock:(nullable GXSynchronizationServerStatusCompletionBlock)block;

/**
 * Indicates that a synchronization is needed
 */
- (void)setNeedsSynchronization;

@end

NS_ASSUME_NONNULL_END
