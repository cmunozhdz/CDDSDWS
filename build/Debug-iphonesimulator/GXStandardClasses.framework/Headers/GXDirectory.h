//
//  GXDirectory.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 6/20/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

#import <GXStandardClasses/GXFileSystemObject.h>
#import <GXStandardClasses/GXObjectCollection.h>

NS_ASSUME_NONNULL_BEGIN

@class GXFileCollection;
@class GXDirectoryCollection;

@interface GXDirectory : GXFileSystemObject

/**
 * Creates a new directory in the specified source
 */
- (void)create;

/**
 * Deletes the specified directory
 */
- (void)deleteDirectory;

/**
 * Returns all files in the specified directory
 */
- (GXFileCollection *)getFiles;

/**
 * Returns the files in the specified directory
 */
- (GXFileCollection *)getFiles:(nullable NSString *)extension;

/**
 * Returns the directories in the specified directory
 */
- (GXDirectoryCollection *)getDirectories;

+ (NSString *)applicationdatapath;

+ (NSString *)externalfilespath;

+ (NSString *)temporaryfilespath;

+ (NSString *)cachefilespath;

@end

NS_ASSUME_NONNULL_END
