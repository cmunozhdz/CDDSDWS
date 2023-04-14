//
//  GXFile.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 6/18/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

#import <GXStandardClasses/GXFileSystemObject.h>
#import <GXStandardClasses/GXStringCollection.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXFile : GXFileSystemObject

/**
 * Returns the name separator character dependant of the OS
 */
@property (nonatomic, strong, readonly) NSString *separator;

/**
 * True if the end of the file has been reached. The file must be opened for reading before using this property.
 */
@property (nonatomic, assign, readonly) BOOL eof;

/**
 * Copies the file specified in source to a new location.
 */
- (void)copyToPath:(nullable NSString *)path NS_SWIFT_NAME(copyToPath(_:));

/**
 * Deletes the file specified in source.
 */
- (void)deleteFile;

/**
 * Returns the path of the parent directory.
 */
- (NSString *)getPath;

/**
 * Returns the date and time the file specified in source was last modified.
 */
- (NSDate *)getLastModified;

/**
 * Returns the size (in bytes) of the file specified in source
 */
- (NSInteger)getLength;

/**
 * Returns the file's absolute path.
 */
- (NSString *)getURI;

/**
 * Returns the name of the file for the given file path
 */
+ (NSString *)gxFileName:(NSString *)path;

/**
 * Returns the extension for the given file path
 */
+ (NSString *)gxFileExt:(NSString *)path;

/**
 * Opens a file for read/write access, using the optionally specified encoding (UTF-8 if not specified).
 * If the file exists the content to write is appended to the file. Otherwise, a new file is created.
 *
 * @param encoding The encoding to use for opening the file
 */
- (void)open:(nullable NSString *)encoding;

/**
 * Opens a file for read/write access, using the default encoding (UTF-8).
 * If the file exists the content to write is appended to the file. Otherwise, a new file is created.
 */
- (void)openWithDefaultEncoding;

/**
 * Opens a file for write access in order to append content, or creates a new file if one does not exist, using the optionally specified encoding (UTF-8 if not specified).
 *
 * @param encoding The encoding to use for opening the file
 */
- (void)openwrite:(nullable NSString *)encoding NS_SWIFT_NAME(openWrite(_:));

/**
 * Opens a file for write access in order to append content, or creates a new file if one does not exist, using the default encoding (UTF-8).
 */
- (void)openWriteWithDefaultEncoding;

/**
 * Opens a file for read access, using the optionally specified encoding (UTF-8 if not specified).
 *
 * @param encoding The encoding to use for opening the file
 */
- (void)openread:(nullable NSString *)encoding NS_SWIFT_NAME(openRead(_:));

/**
 * Opens a file for read access, using the default encoding (UTF-8).
 */
- (void)openReadWithDefaultEncoding;

/**
 * Closes the file.
 */
- (void)close;

/**
 * Reads a line of characters from the file. The string that is returned does not contain the terminating carriage return or line feed. The file must be opened before using this method.
 *
 * @return The line read
 */
- (NSString *)readline NS_SWIFT_NAME(readLine());

/**
 * Opens a text file, reads all lines of the file, and then closes the file, using the optionally specified encoding (UTF-8 if not specified).
 *
 * @param encoding The encoding to use for opening the file
 */
- (NSString *)readalltext:(nullable NSString *)encoding NS_SWIFT_NAME(readAllText(_:));

/**
 * Opens a text file, reads all lines of the file, and then closes the file, using the default encoding (UTF-8).
 */
- (NSString *)readAllTextWithDefaultEncoding;

/**
 * Opens a text file, reads all lines of the file, and then closes the file. Each item of the collection is a line from the file, using the optionally specified encoding (UTF-8 if not specified).
 *
 * @param encoding The encoding to use for opening the file
 */
- (GXStringCollection *)readalllines:(nullable NSString *)encoding NS_SWIFT_NAME(readAllLines(_:));

/**
 * Opens a text file, reads all lines of the file, and then closes the file. Each item of the collection is a line from the file, using UTF-8 encoding.
 */
- (GXStringCollection *)readalllines NS_SWIFT_NAME(readAllLines());

/**
 * Writes the specified string followed by a line terminator. The file must be opened before using this method.
 *
 * @param text The line of text to be added to the file
 */
- (void)writeline:(NSString *)text  NS_SWIFT_NAME(writeLine(_:));

/**
 * Writes the specified string to the file, and then closes the file. If the file has content, it is overwritten, using the optionally specified encoding (UTF-8 if not specified).
 *
 * @param text The line of text to be added to the file
 * @param encoding The encoding to use for opening the file
 */
- (void)writealltext:(NSString *)text encoding:(nullable NSString *)encoding NS_SWIFT_NAME(writeAllText(_:_:));

/**
 * Writes the specified string to the file, and then closes the file. If the file has content, it is overwritten, using the default encoding (UTF-8).
 *
 * @param text The line of text to be added to the file
 */
- (void)writeAllTextWithDefaultEncoding:(NSString *)text;

/**
 * Writes the specified string collection to the file, each string followed by a line terminator, and then closes the file. If the file has content, it is overwritten, using the optionally specified encoding (UTF-8 if not specified).
 *
 * @param lines The collection of text lines to be added to the file
 */
- (void)writealllines:(id<GXSDTDataCollection>)lines encoding:(nullable NSString *)encoding NS_SWIFT_NAME(writeAllLines(_:_:));

/**
 * Writes the specified string collection to the file, each string followed by a line terminator, and then closes the file. If the file has content, it is overwritten, using the default encoding (UTF-8).
 *
 * @param lines The collection of text lines to be added to the file
 */
- (void)writeAllLinesWithDefaultEncoding:(id<GXSDTDataCollection>)lines;

/**
 * Opens a file, appends the specified string to the file, and then closes the file, using the optionally specified encoding (UTF-8 if not specified).
 *
 * @param text The line of text to be added to the file
 * @param encoding The encoding to use for opening the file
 */
- (void)appendalltext:(NSString *)text encoding:(nullable NSString *)encoding NS_SWIFT_NAME(appendAllText(_:_:));

/**
 * Opens a file, appends the specified string to the file, and then closes the file, using the default encoding (UTF-8 if not specified).
 *
 * @param text The line of text to be added to the file
 */
- (void)appendAllTextWithDefaultEncoding:(NSString *)text;

/**
 * Opens a file, appends the specified string collection to the file, each string followed by a line terminator, and then closes the file, using the optionally specified encoding (UTF-8 if not specified).
 *
 * @param lines The collection of text lines to be added to the file
 * @param encoding The encoding to use for opening the file
 */
- (void)appendalllines:(id<GXSDTDataCollection>)lines encoding:(nullable NSString *)encoding  NS_SWIFT_NAME(appendAllLines(_:_:));

/**
 * Opens a file, appends the specified string collection to the file, each string followed by a line terminator, and then closes the file, using the default encoding (UTF-8).
 *
 * @param lines The collection of text lines to be added to the file
 */
- (void)appendAllLinesWithDefaultEncoding:(id<GXSDTDataCollection>)lines;

/**
 * Creates a text file in the path specified in the Source property.
 */
- (void)create;

/**
 * Creates a file by converting the base-64 string to its binary representation
 *
 * @param base64Str The base-64 string containing the file content
 *
 * @return YES on success, NO otherwise
 */
- (BOOL)frombase64string:(NSString *)base64Str;

@end


@interface GXObjectCollection (GXFile)

/**
 * Loads the collection content from the given JSON file
 */
- (void)fromJSONFile:(GXFile *)file;

/**
 * Initializes the collection with the contents of the given XML file
 *
 * @param file The file to read
 */
- (void)fromxmlfile:(GXFile *)file;

@end

NS_ASSUME_NONNULL_END
