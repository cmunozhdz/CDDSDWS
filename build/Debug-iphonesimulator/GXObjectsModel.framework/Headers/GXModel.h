//
//  GXModel.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 20/07/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import GXFoundation;
#import <GXObjectsModel/GXApplicationModel.h>
#import <GXObjectsModel/GXModelInfo.h>

NS_ASSUME_NONNULL_BEGIN

// descomentar para probar el mecanismo de actualizacion por minor/major version en kbn debug
//#define TESTMM

@protocol GXModelDelegate;

@interface GXModel : NSObject

- (nullable instancetype)initWithModelInfo:(GXModelInfo *)info
						  applicationModel:(GXApplicationModel *)appModel
							  modelObjects:(NSDictionary<NSString *, id> *)modelObjects NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

+ (nullable GXModel *)currentModel;

@property(nonatomic, strong, readonly) GXModelInfo *info;
@property(nonatomic, strong, readonly) GXApplicationModel *appModel;
@property(atomic, strong, readonly) id <GXMutablePropertiesObject> properties;

@property(null_resettable, nonatomic, strong) GXStyleKBObject *currentStyleObject;
@property(readonly) BOOL currentStyleObjectIsRuntime;

/// This method must NEVER be called from the main thread. Use clearCacheAsync
- (void)clearCache;

/// Calls the method clearCache on a background thread
- (void)clearCacheAsync;

/// Checks if there was a change in user locale or language and calls clearCache when necessary
- (BOOL)clearCacheIfRequired;

@end

extern NSString *const GXModelWillClearCacheNotification;
extern NSString *const GXModelDidClearCacheNotification;

extern NSString *const GXModelWillChangeCurrentModelNotification;
extern NSString *const GXModelDidChangeCurrentModelNotification;
extern NSString *const GXModelDidUpdateCurrentModelNotification;
extern NSString *const GXModelDidLoadCurrentModelRootControllerNotification;
extern NSString *const GXModelDidAuthorizeCurrentModelNotification;

extern NSString *const GXModelModelKey;

extern NSString *const GXModelDidChangeCurrentStyleObjectNotification;

NS_ASSUME_NONNULL_END
