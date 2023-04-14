//
//  GXDBCommand.h
//  GXStd
//
//  Created by Marcos Crispino on 28/06/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;
@import GXFoundation;
#import <GXStandardClasses/GXDBConnection.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(unsigned int, GXDBCursorStatusType) {
	GXDBCursorStatusOk = 0,
	GXDBCursorStatusDuplicate = 1,
	GXDBCursorStatusDataTruncation = 2,
	GXDBCursorStatusEOF = 101,
	GXDBCursorStatusLocked = 103,
	GXDBCursorStatusObjectNotFound = 105,
	GXDBCursorStatusDBAlreadyExists = 106,
	GXDBCursorStatusParentPrimaryKeyNotFound = 500,
	GXDBCursorStatusReferential = 600,
	GXDBCursorStatusUnexpectedDBMSError = 999,
};

@interface GXDBCommand : NSObject

#pragma mark - Properties

@property (nonatomic, retain, readonly) NSString *statement;
@property (nonatomic, nullable, retain) NSArray *parameters;
@property (nonatomic, nullable, retain) NSArray *nullParameters;

#pragma mark - Init

- (id)initWithStatement:(NSString *)stm;

#pragma mark - Public methods

/**
 * Indicates wheather the statement is a query (returns a set of rows) or an update (insert, update, delete, etc.)
 */
- (BOOL)isQuery;

/**
 * Returns the query parameters with nulls where specified by the nullParameters property
 */
- (NSArray *)resolvedCommandParameters;

#pragma mark - Command execution

/**
 * Abstract method
 * Executes the command
 */
- (GXDBExecuteResult)execute;

/**
 * Abstract method
 * Executes the command and returns the value
 */
- (NSNumber *)executeScalar;

/**
 * Executes the command and fetches the first row
 */
- (void)fetchFirst;

#pragma mark - Managing cursor

/**
 * Abstract method
 * Fetches the next row
 */
- (void)fetch;

/**
 * Abstract method
 * Indicates if there are more rows available
 */
- (BOOL)eof;

/**
 * Abstract method
 * Returns the status of the command after execution
 */
- (GXDBCursorStatusType)status;

/**
 * Abstract method
 * Finihes the command executions. Cleans up the parameters and results
 */
- (void)close;

#pragma mark - Reading columns from result

/**
 * Abstract method
 * Returns the string value of the column given by name
 */
- (NSString *)stringValueForColumn:(NSString *)columnName;

/**
 * Abstract method
 * Returns the string value of the column given by index
 */
- (NSString *)stringValueForColumnAtIndex:(NSUInteger)index;

/**
 * Abstract method
 * Returns the date value of the column given by name
 */
- (NSDate *)dateValueForColumn:(NSString *)columnName;

/**
 * Abstract method
 * Returns the date value of the column given by index
 */
- (NSDate *)dateValueForColumnAtIndex:(NSUInteger)index;

/**
 * Abstract method
 * Returns the numeric value of the column given by name
 */
- (NSNumber *)numberValueForColumn:(NSString *)columnName;

/**
 * Abstract method
 * Returns the numeric value of the column given by index
 */
- (NSNumber *)numberValueForColumnAtIndex:(NSUInteger)index;

/**
 * Abstract method
 * Returns the integer value of the column given by index
 */
- (NSInteger)intValueForColumn:(NSString *)columnName;

/**
 * Abstract method
 * Returns the Int64 value of the column given by index
 */
- (long long)int64ValueForColumn:(NSString *)columnName;

/**
 * Abstract method
 * Returns the Double value of the column given by index
 */
- (double)doubleValueForColumn:(NSString *)columnName;

/**
 * Abstract method
 * Returns the boolean value of the column given by name
 */
- (BOOL)booleanValueForColumn:(NSString *)columnName;

/**
 * Abstract method
 * Returns the boolean value of the column given by index
 */
- (BOOL)booleanValueForColumnAtIndex:(NSUInteger)index;

/**
 * Abstract method
 * Returns the decimal value of the column given by name
 */
- (NSDecimal)decimalValueForColumn:(NSString *)columnName;

/**
 * Abstract method
 * Returns the decimal value of the column given by index
 */
- (NSDecimal)decimalValueForColumnAtIndex:(NSUInteger)index;

/**
 * Abstract method
 * Returns the data value of the column given by name
 * This method is used for blobs. It gets the blob from the database, saves it locally to a temporary file and returns the file url absolute string
 */
- (NSString *)dataValueForColumn:(NSString *)columnName;

/**
 * Abstract method
 * Returns the data value of the column given by index
 * This method is used for blobs. It gets the blob from the database, saves it locally to a temporary file and returns the file url absolute string
 */
- (NSString *)dataValueForColumnAtIndex:(NSUInteger)index;

/**
 * Abstract method
 * Returns the UUID value of the column given by name
 */
- (GXUUID *)uuidValueForColumn:(NSString *)columnName;

/**
 * Abstract method
 * Returns the UUID value of the column given by index
 */
- (GXUUID *)uuidValueForColumnAtIndex:(NSUInteger)index;

/**
 * Abstract method
 * Returns the URI value of the column given by name
 * @discussion This method is valid for multimedia fields, it converts the URI value stored in the database to an http: or file: URI.
 */
- (NSString *)uriValueForColumn:(NSString *)columnName;

/**
 * Abstract method
 * Returns the URI value of the column given by index
 * @discussion This method is valid for multimedia fields, it converts the URI value stored in the database to an http: or file: URI.
 */
- (NSString *)uriValueForColumnAtIndex:(NSUInteger)index;

/**
 * Abstract method
 * Returns true if the value of the column given by name is null
 */
- (BOOL)valueIsNullForColumn:(NSString *)columnName;

/**
 * Abstract method
 * Returns true if the value of the column given by index is null
 */
- (BOOL)valueIsNullForColumnAtIndex:(NSUInteger)index;

@end

NS_ASSUME_NONNULL_END
