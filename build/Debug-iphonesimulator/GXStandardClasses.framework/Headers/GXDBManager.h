//
//  GXDBManager.h
//  GXStd
//
//  Created by Marcos Crispino on 28/06/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

#import <GXStandardClasses/GXDBConnection.h>
#import <GXStandardClasses/GXEmbeddedModelObject.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint_least8_t, GXDBManagerDatabaseCreationResultType) {
    GXDBManagerDatabaseCreationNotNeeded,
    GXDBManagerDatabaseCreationCopiedFromBundle,
    GXDBManagerDatabaseCreationReorgExecuted,
    GXDBManagerDatabaseCreationError
};

typedef void (^GXDBManagerDatabaseCreationCompletionBlock)(GXDBManagerDatabaseCreationResultType, NSError * _Nullable);

@interface GXDBManager: GXEmbeddedModelNSObject

+ (GXDBManager *)sharedInstance GX_WARN_GXOFFLINETHREAD_ONLY_METHOD;

- (instancetype)initWithEmbeddedModelObject:(id<GXEmbeddedModelObject>)modelObject NS_UNAVAILABLE;
- (nullable instancetype)initWithModelObject:(id<GXModelObject>)modelObject NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

#pragma mark - Class methods

/**
 * Empty. Used to compile the reorganization, it gets called before executing the DB creation
 */
+ (void)startCreateDataBase;

/**
 * Execute the statement in the given datastore
 *
 * This method shoud be only used in reorganizations and database creations, since it is not blocked by
 * database creation process
 */
+ (GXDBExecuteResult)executeInDatastore:(NSString *)dsName commandString:(NSString *)cmdStr;

#pragma mark - Database creation methods

/**
 * Returns YES if the database file exists, NO otherwise
 */
- (BOOL)isDatabaseCreated;

/**
 * If there has been a database creation in the current application execution, the time interval since reference date
 * is returned by this method.
 * It may return 0 at any time, used only to know if any database connection is older than the last database creation.
 */
- (NSTimeInterval)timeIntervalSinceReferenceDateForLastKnownDatabaseCreation;

/*!
 Indicates if the database needs creation
 */
- (BOOL)needsCreateDatabase;

- (void)setNeedsCreateDatabase;

/*!
 Executes database creation
 
 @param block The block to be executed after finish
 @discussion When finished executes the block received as parameter, passing the result of the creation and the error if any (or nil otherwise)
 */
- (void)createDatabaseIfNeededWithCompletionBlock:(nullable GXDBManagerDatabaseCreationCompletionBlock)block;

#pragma mark - Public methods

/**
 * Commits all existing connections
 */
- (void)commit;

/**
 * Commits in the given datastore
 */
- (void)commitDatastore:(NSString *)dsName;

/**
 * Rolls back all existing connections
 */
- (void)rollback;

/**
 * Rolls back the given datastore
 */
- (void)rollbackDatastore:(NSString *)dsName;

/**
 * Disconnects all existing connections
 */
- (void)disconnect;

/**
 * Returns the connection objects for the given datastore
 */
- (nullable GXDBConnection *)connectionForDatastore:(NSString *)dsName;

/**
 * Returns the database path for the DEFAULT datastore
 */
- (NSString *)databasePath;

/**
 * Starts a transaction in all existing connections
 */
- (void)beginTransaction;

/**
 * Ends the transaction for all existing connections
 */
- (void)endTransaction;

/**
 * Closes all database connection objects and creates new ones
 */
- (void)resetDatabaseConnections;

@end

NS_ASSUME_NONNULL_END
