//
//  GXModel+GXModelUpdates.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 21/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

#import <GXObjectsModel/GXModel.h>
#import <GXObjectsModel/GXModelManager.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint_least8_t, GXVersionStateType) {
	GXVersionStateUnknown,
	GXVersionStateUpToDate,
	GXVersionStateNewVersionAvailable,
	GXVersionStateIncompatibleVersion
};

@interface GXModel (GXModelUpdates) <GXModelManagerDelegate>

@property(nonatomic, assign, readonly) GXVersionStateType versionState;
@property(nullable, weak) id <GXModelDelegate> delegate;

- (void)checkForUpdates;
- (void)updateModel;
- (void)openAppStore;

@end

@protocol GXModelDelegate <NSObject>

@optional
- (void)modelVersionStateUpdated:(GXModel *)model;
- (void)modelWillUpdate:(GXModel *)model;
- (void)modelUpdated:(GXModel *)model;
- (void)model:(GXModel *)model didFailUpdatingWithError:(NSError *)error;

@end

extern NSString *const GXModel_ModelObject_GXModelUpdatesVersionState; // Model object key for NSNumber with GXVersionStateType

NS_ASSUME_NONNULL_END
