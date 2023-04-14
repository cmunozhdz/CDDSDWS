//
//  GXBusinessComponentHandlerBuilderProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 18/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

#import <GXDataLayer/GXBusinessComponentDefaultLoadHandler.h>
#import <GXDataLayer/GXBusinessComponentDeleteHandler.h>
#import <GXDataLayer/GXBusinessComponentInsertHandlerProtocol.h>
#import <GXDataLayer/GXBusinessComponentLoadHandler.h>
#import <GXDataLayer/GXBusinessComponentSaveHandler.h>
#import <GXDataLayer/GXBusinessComponentUpdateHandlerProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXBusinessComponentHandlerBuilder <NSObject>

- (instancetype)init;

- (GXBusinessComponentLoadHandler *)newBusinessComponentLoadHandlerForModel:(GXBusinessComponentModel *)bcModel
																		key:(id <GXEntityDataKey>)key;

- (GXBusinessComponentSaveHandler<GXBusinessComponentInsertHandler> *)newBusinessComponentInsertHandlerForModel:(GXBusinessComponentModel *)bcModel
																									 entityData:(id <GXBusinessComponentLevelEntityData>)entityData;

- (GXBusinessComponentSaveHandler<GXBusinessComponentInsertHandler, GXBusinessComponentUpdateHandler> *)newBusinessComponentInsertOrUpdateHandlerForModel:(GXBusinessComponentModel *)bcModel
																																			   entityData:(id <GXBusinessComponentLevelEntityData>)entityData;

- (GXBusinessComponentDefaultLoadHandler *)newBusinessComponentDefaultLoadHandlerForModel:(GXBusinessComponentModel *)bcModel
																inferredFieldValuesByName:(nullable NSDictionary<NSString *, id> *)inferredFieldValuesByName;

- (GXBusinessComponentSaveHandler<GXBusinessComponentUpdateHandler> *)newBusinessComponentUpdateHandlerForLevel:(GXBusinessComponentLevel *)level
																									 entityData:(id <GXBusinessComponentLevelEntityData>)entityData;

- (GXBusinessComponentDeleteHandler *)newBusinessComponentDeleteHandlerForLevel:(GXBusinessComponentLevel *)level
																			key:(id <GXEntityDataKey>)key;


@optional
- (void)releaseBusinessComponentEntityDataWithDefaults:(id <GXBusinessComponentLevelEntityData>)entityData
											   ofModel:(GXBusinessComponentModel *)bcModel;

@end

NS_ASSUME_NONNULL_END
