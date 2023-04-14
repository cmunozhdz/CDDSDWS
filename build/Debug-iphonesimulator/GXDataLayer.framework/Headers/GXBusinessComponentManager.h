//
//  GXBusinessComponentManager.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 02/02/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@class GXBusinessComponentManager;

@protocol GXBusinessComponentManagerDelegate <NSObject>

- (id)contextForBusinessComponentManagerNotification:(GXBusinessComponentManager *)manager;

@optional

- (void)businessComponentManager:(GXBusinessComponentManager *)manager
						 didLoad:(id <GXBusinessComponentLevelEntityData, GXEntityDataWithOverrideValues>)loadedEntityData
			   businessComponent:(GXBusinessComponentModel *)bcModel;

- (BOOL)businessComponentManager:(GXBusinessComponentManager *)manager
 didFailLoadingBusinessComponent:(GXBusinessComponentModel *)bcModel
							 key:(id <GXEntityDataKey>)key
					   withError:(NSError *)error;

- (void)businessComponentManager:(GXBusinessComponentManager *)manager
					   didInsert:(id <GXBusinessComponentLevelEntityData, GXEntityDataWithOverrideValues>)insertedEntityData
			   businessComponent:(GXBusinessComponentModel *)bcModel;

- (BOOL)businessComponentManager:(GXBusinessComponentManager *)manager
didFailInsertingBusinessComponent:(GXBusinessComponentModel *)bcModel
                       withError:(NSError *)error;
 
- (void)businessComponentManager:(GXBusinessComponentManager *)manager
					   didUpdate:(id <GXBusinessComponentLevelEntityData, GXEntityDataWithOverrideValues>)updatedEntityData
		  businessComponentLevel:(GXBusinessComponentLevel *)level
							 key:(id <GXEntityDataKey>)key;

- (BOOL)businessComponentManager:(GXBusinessComponentManager *)manager
didFailUpdatingBusinessComponentLevel:(GXBusinessComponentLevel *)level
							 key:(id <GXEntityDataKey>)key
                       withError:(NSError *)error;

- (void)businessComponentManager:(GXBusinessComponentManager *)manager
 didDeleteBusinessComponentLevel:(GXBusinessComponentLevel *)level
							 key:(id <GXEntityDataKey>)key;

- (BOOL)businessComponentManager:(GXBusinessComponentManager *)manager
didFailDeletingBusinessComponentLevel:(GXBusinessComponentLevel *)level
							 key:(id <GXEntityDataKey>)key
					   withError:(NSError *)error;

- (void)businessComponentManager:(GXBusinessComponentManager *)manager
				 didLoadDefaults:(id <GXBusinessComponentLevelEntityData, GXEntityDataWithOverrideValues>)loadedEntityData
			   businessComponent:(GXBusinessComponentModel *)bcModel
		   instanceSharingObject:(NSObject<NSCopying> *)sharingObject;

- (BOOL)businessComponentManager:(GXBusinessComponentManager *)manager
didFailLoadingBusinessComponentDefaults:(GXBusinessComponentModel *)bcModel
		   instanceSharingObject:(NSObject<NSCopying> *)sharingObject
					   withError:(NSError *)error;

@end

#pragma mark -

@interface GXBusinessComponentManager : NSObject <GXModelObject>

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (void)loadBusinessComponentModel:(GXBusinessComponentModel *)bcModel
							   key:(id <GXEntityDataKey>)key
						  delegate:(id <GXBusinessComponentManagerDelegate>)delegate
			   connectivitySupport:(GXConnectivitySupportType)connSupport;

- (void)insertBusinessComponentModel:(GXBusinessComponentModel *)bcModel
						  entityData:(id <GXBusinessComponentLevelEntityData>)entityData
							delegate:(id <GXBusinessComponentManagerDelegate>)delegate
				 connectivitySupport:(GXConnectivitySupportType)connSupport;

- (void)updateBusinessComponentLevel:(GXBusinessComponentLevel *)level
						  entityData:(id <GXBusinessComponentLevelEntityData>)entityData
							delegate:(id <GXBusinessComponentManagerDelegate>)delegate
				 connectivitySupport:(GXConnectivitySupportType)connSupport;

- (void)insertOrUpdateBusinessComponentModel:(GXBusinessComponentModel *)bcModel
								  entityData:(id <GXBusinessComponentLevelEntityData>)entityData
									delegate:(id <GXBusinessComponentManagerDelegate>)delegate
						 connectivitySupport:(GXConnectivitySupportType)connSupport;

- (void)deleteBusinessComponentLevel:(GXBusinessComponentLevel *)level
								 key:(id <GXEntityDataKey>)key
							delegate:(id <GXBusinessComponentManagerDelegate>)delegate
				 connectivitySupport:(GXConnectivitySupportType)connSupport;

- (void)cancelLoadingBusinessComponentModel:(GXBusinessComponentModel *)bcModel
										key:(id <GXEntityDataKey>)key
								   delegate:(id <GXBusinessComponentManagerDelegate>)delegate
						connectivitySupport:(GXConnectivitySupportType)connSupport;

- (nullable id<GXBusinessComponentLevelEntityData>)obtainNewBusinessComponentModel:(GXBusinessComponentModel *)bcModel
															 instanceSharingObject:(NSObject<NSCopying> *)sharingObject
														 inferredFieldValuesByName:(nullable NSDictionary<NSString *, id> *)inferredFieldValuesByName
																		  delegate:(id<GXBusinessComponentManagerDelegate>)delegate
															   connectivitySupport:(GXConnectivitySupportType)connSupport;
- (void)releaseBusinessComponentModel:(GXBusinessComponentModel *)bcModel
				instanceSharingObject:(NSObject<NSCopying> *)sharingObject
							 delegate:(id<GXBusinessComponentManagerDelegate>)delegate
				  connectivitySupport:(GXConnectivitySupportType)connSupport;

- (BOOL)isDelegateLoading:(id <GXBusinessComponentManagerDelegate>)delegate;
- (BOOL)isDelegateInserting:(id <GXBusinessComponentManagerDelegate>)delegate;
- (BOOL)isDelegateUpdating:(id <GXBusinessComponentManagerDelegate>)delegate;
- (BOOL)isDelegateDeleting:(id <GXBusinessComponentManagerDelegate>)delegate;
- (BOOL)isLoadingDefaultsForBusinessComponentModel:(GXBusinessComponentModel *)bcModel
							 instanceSharingObject:(NSObject<NSCopying> *)sharingObject
							   connectivitySupport:(GXConnectivitySupportType)connSupport;

@end

extern NSString *const GXBusinessComponentLoadNotification;
extern NSString *const GXBusinessComponentInsertNotification;
extern NSString *const GXBusinessComponentUpdateNotification;
extern NSString *const GXBusinessComponentDeleteNotification;

extern NSString *const GXBusinessComponentModelKey;
extern NSString *const GXBusinessComponentLevelKey;
extern NSString *const GXBusinessComponentErrorKey;
extern NSString *const GXBusinessComponentEntityDataKey;
extern NSString *const GXBusinessComponentEntityDataKeyKey;
extern NSString *const GXBusinessComponentContextKey;

NS_ASSUME_NONNULL_END
