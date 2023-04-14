//
//  GXModel+GXCoreDataCache.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 21/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

@import CoreData;
@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@interface GXModel (GXCoreDataCache)

@property(nonatomic, strong, readonly) NSManagedObjectModel *managedObjectModel;
@property(nonatomic, strong, readonly) NSManagedObjectContext *managedObjectContext;
@property(nonatomic, strong, readonly) NSPersistentStoreCoordinator *persistentStoreCoordinator;

@end

extern NSString *const GXModel_ModelObject_GXCoreDataCacheManagedObjectModel; // Model object key for NSManagedObjectModel

extern NSString *const GXModelSQLStoreConfiguration;
extern NSString *const GXModelMemoryStoreConfiguration;

NS_ASSUME_NONNULL_END
