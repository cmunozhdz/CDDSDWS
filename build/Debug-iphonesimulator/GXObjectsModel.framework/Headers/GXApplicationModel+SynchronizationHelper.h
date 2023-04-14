//
//  GXApplicationModel+SynchronizationHelper.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 22/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

#import <GXObjectsModel/GXApplicationModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXApplicationModel (SynchronizationHelper)

@property(nonatomic, assign, readonly) GXSynchronizationReceiveCriteriaType syncReceiveCriteria;
@property(nonatomic, assign, readonly) NSUInteger minTimeBetweenSyncs;
@property(nonatomic, assign, readonly) GXSynchronizationSendCriteriaType syncSendCriteria;
@property(nonatomic, assign, readonly) NSUInteger minTimeBetweenSends;
@property(nullable , nonatomic, strong, readonly) NSString *synchronizerObjectName;
@property(nonatomic, assign, readonly) BOOL encryptOfflineDatabase;
@property(nonatomic, assign, readonly) NSTimeInterval syncReceiveTimeout;
@property(nonatomic, assign, readonly) NSTimeInterval syncSendTimeout;

@end

NS_ASSUME_NONNULL_END
