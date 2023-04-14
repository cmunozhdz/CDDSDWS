//
//  GXBusinessComponentHandler.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 19/05/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@interface GXBusinessComponentHandler : NSObject

@property(nonatomic, strong, readonly) GXBusinessComponentModel *businessComponentModel;
@property(nonatomic, strong, readonly) GXBusinessComponentLevel *businessComponentLevel;
@property(nonatomic, assign, readonly) GXConnectivitySupportType connectivitySupport;

- (instancetype)initWithBusinessComponentLevel:(GXBusinessComponentLevel *)bcLevel NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

- (void)start;
- (void)cancel;

#pragma mark - Internal

@property(nonatomic, strong, readonly) NSOperationQueue *operationQueue;

@end

NS_ASSUME_NONNULL_END
