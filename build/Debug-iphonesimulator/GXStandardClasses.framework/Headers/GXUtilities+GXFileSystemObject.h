//
//  GXUtilities+GXFileSystemObject.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 6/7/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import GXFoundation;

NS_ASSUME_NONNULL_BEGIN

@interface GXUtilities (GXFileSystemObject)

/*!
Creates a unique file path in [GXDirectory temporaryfilespath]

@discussion Similar to createUniqueTemporaryFilePath but returned path is accessible by GXFileSystemObject
*/
+ (NSString *)createUniqueGXDataTemporaryFilePath;

/*!
Creates a unique directory path in [GXDirectory temporaryfilespath]

@discussion Similar to createUniqueTemporaryDirectoryPath but returned path is accessible by GXFileSystemObject. Same as createUniqueGXDataTemporaryFilePath but including the '/' suffix.
*/
+ (NSString *)createUniqueGXDataTemporaryDirectoryPath;

@end

NS_ASSUME_NONNULL_END
