//
//  GXDBConnection.h
//  GXStd
//
//  Created by Marcos Crispino on 28/06/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;
#import <GXStandardClasses/GXEmbeddedModelObject.h>
@class GXDBCommand;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint_least8_t, GXDBConnectionType) {
	GXDBConnectionSQLite,
};

typedef NS_ENUM(unsigned int, GXDBExecuteResult) {
	GXDBExecuteScalarOk,
	GXDBExecuteUpdateOpenedTransaction,
	GXDBExecuteUpdateExistingTransaction,
	GXDBExecuteResultError,
	GXDBExecuteResultUnknown,
};

@interface GXDBConnection : GXEmbeddedModelNSObject

#pragma mark - Creating connections

/**
 * Creates a new connection object of the given type
 */
+ (GXDBConnection *)createConnectionOfType:(GXDBConnectionType)type withIdentifier:(id)connId connectionString:(NSString *)connStr;

#pragma mark - Abstract properties

@property (nonatomic, readonly) GXDBConnectionType connectionType;

@property (nonatomic, retain, readonly) id connectionIdentifier;

@property (nonatomic, retain, readonly) NSString *connectionString;

#pragma mark - Abstract methods

- (BOOL)isDatabaseCreated;

- (void)connect;

- (void)disconnect;

- (void)commit;

- (void)rollback;

- (void)beginTransaction;

- (void)endTransaction;

- (BOOL)hasAnyOpenTransaction;

#pragma mark - Public methods

- (GXDBCommand *)commandWithSQLStatement:(NSString *)stm;

- (void)addInsertedBlobURLAbsoluteString:(NSString *)urlAbsoluteStr;

- (void)addDeletedBlobURLAbsoluteString:(NSString *)urlAbsoluteStr;

@end

NS_ASSUME_NONNULL_END
