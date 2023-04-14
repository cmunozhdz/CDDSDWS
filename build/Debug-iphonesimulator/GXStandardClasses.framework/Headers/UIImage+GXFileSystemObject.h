//
//  UIImage+GXFileSystemObject.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 6/7/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import UIKit;

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (GXFileSystemObject)

/*!
 Saves the image to file to a temporary file in [GXDirectory temporaryfilespath]
 
 @param pathExtension Suggested file extension
 @result The file URL where image was saved, nil on error
 @discussion Similar to saveToTemporaryFileWithPathExtension but returned path is accessible by GXFileSystemObject (using [GXUtilities createUniqueGXDataTemporaryFilePath])
 */
- (nullable NSURL *)saveToGXDataTemporaryFileWithPathExtension:(nullable NSString *)pathExtension;

@end

NS_ASSUME_NONNULL_END