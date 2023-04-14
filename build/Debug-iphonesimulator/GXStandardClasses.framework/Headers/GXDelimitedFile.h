//
//  GXDelimitedFile.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 15/01/14.
//  Copyright (c) 2014 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface GXDelimitedFile : NSObject

/**
 * To open a text file for its processing.  It is the first function to be called to begin reading a text file.
 *
 * @param fileName The name of the file to be processed.
 * @param len Indicates the maximum size, in number of characters, of the record to be read
 * @param fDel Indicates the delimiting character among fields
 * @param sDel Indicates the delimiting character of the string fields
 * @param enc The encoding to be used to read the file
 * @return error code (0 == no error)
 */
+ (NSNumber *)dfropen:(NSString *)fileName length:(NSNumber *)len filedDelimiter:(NSString *)fDel stringDelimiter:(NSString *)sDel encoding:(NSString *)enc;

/**
 * To read the following record (line) of the delimited text file.
 *
 * @return error code (0 == no error)
 */
+ (NSNumber *)dfrnext;

/**
 * To close the file opened by dfropen. This function must be called after a sucessful call (without error) to dfropen.
 *
 * @return error code (0 == no error)
 */
+ (NSNumber *)dfrclose;

/**
 * To open a text file for processing.  It is the first function to call to begin writing a text file.
 *
 * @param fileName The name of the file to be processed.
 * @param fDel Indicates the delimiting character among fields
 * @param sDel Indicates the delimiting character of the string fields
 * @param append Indicates what to do if the file exists
 * @param enc The encoding to be used to read the file
 * @return error code (0 == no error)
 */
+ (NSNumber *)dfwopen:(NSString *)fileName filedDelimiter:(NSString *)fDel stringDelimiter:(NSString *)sDel append:(NSNumber *)append encoding:(NSString *)enc;

/**
 * To save the record with the values specified by the previous calls to DFWPTxt, DFWPNum, etc., in the delimited text file.
 *
 * @return error code (0 == no error)
 */
+ (NSNumber *)dfwnext;

/**
 * To close the file opened by dfwopen. This function should be called after a successful call (without error) to DFWOpen.
 *
 * @return error code (0 == no error)
 */
+ (NSNumber *)dfwclose;

/**
 * To save a character type field in the current record of the delimited ASCII file.
 *
 * @param text Its value will be that saved in the corresponding field.
 * @param len Indicates the number of characters to be saved.  In case they are omitted, it is assumed as the size defined for the <text> parameter.
 * @return error code (0 == no error)
 */
+ (NSNumber *)dfwptxt:(NSString *)text length:(NSNumber *)len;

/**
 * To save a numeric type field in the current record of the delimited ASCII file.
 *
 * @param num Its value will be the one saved in the corresponding field.
 * @param dec Indicates the decimal quantity to be specified in the field.
 * @return error code (0 == no error)
 */
+ (NSNumber *)dfwpnum:(NSNumber *)num decimals:(NSNumber *)dec;

/**
 * To save a date type field in the current record of the delimited ASCII file. If it has GeneXus null value, the date "00/00/0000" will be saved.
 *
 * @param date Date value to save to the file
 * @param fmt It indicates the format of the date in the field to be saved. Each character of the field may have a “y”, “m” or “d” value. Its combination generates the format. For example, if the string contains the “ymd” character, the field date to be saved is assumed in Year, Month, Day format. If, on the contrary, the string contains the “dmy” characters, the field date to be read is assumed in Day, Month, Year format. It is important to note that the characters should be in small letters. The default value is “ymd”.
 * @param sep Indicates the separator element of a date.  Commonly used values are “/”, “-“ and “.”. The default value is “-”.
 * @return error code (0 == no error)
 */
+ (NSNumber *)dfwpdate:(NSDate *)date format:(NSString *)fmt separator:(NSString *)sep;

/**
 * To read a character type field of the current line (read by dfrnext).
 *
 * @param text The read value will be stored here.
 * @param len Indicates the maximum number of characters to be read.  Their value, if specified, may not exceed the size defined for <txt>. In case it is omitted, it is assumed as the size defined for the attribute or variable  <txt>. If this parameter exceeds the <txt> size, results become unpredictable.
 * @return error code (0 == no error)
 */
+ (NSNumber *)dfrgtxt:(NSString * _Nonnull __strong * _Nonnull)text length:(NSNumber *)len;

/**
 * To read a numeric type field of the current line (read by dfrnext).
 *
 * @param num The read value will be stored here.
 * @return error code (0 == no error)
 */
+ (NSNumber *)dfrgdecimal:(NSDecimalNumber * _Nonnull __strong * _Nonnull)num;

/**
 * To read a numeric type field of the current line (read by dfrnext).
 *
 * @param num The read value will be stored here.
 * @return error code (0 == no error)
 */
+ (NSNumber *)dfrgnum:(NSNumber * _Nonnull __strong * _Nonnull)num;

/**
 * To read a date type field of the current line (read by dfrnext). The date value is not adjusted according to the "First  Year of 20th Century" (generator property).
 *
 * @param date The read value is stored here.
 * @param fmt Indicates the format that the date has in the field to be read. Each field character may have the “y”, “m” or “d” values.  Their combination generates the format.  For example, if the string contains the “ymd” characters the field date to be read is assumed (and validated) in Year, Month Day format. If, on the contrary, the string contains the “dmy” characters, the field date to be read is assumed in Day, Month, and Year format. It is important to note that the characters must be in lowercase letters. The default value is “ymd”.
 * @param sep Indicates which the element separator of a date is.  The values commonly used are “/”, “-“and “.”. The default value is “-”.
 * @return error code (0 == no error)
 */
+ (NSNumber *)dfrgdate:(NSDate * _Nonnull __strong * _Nonnull)date format:(NSString *)fmt separator:(NSString *)sep;

@end

NS_ASSUME_NONNULL_END
