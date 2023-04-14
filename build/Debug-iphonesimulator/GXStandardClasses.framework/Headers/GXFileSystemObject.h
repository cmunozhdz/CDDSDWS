//
//  GXFileSystemObject.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 6/20/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import Foundation;
@import GXObjectsModel;
#import <GXStandardClasses/GXEmbeddedModelObject.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXFileSystemObject : GXEmbeddedModelNSObject <GXDataTypeWithProperties>

/**
 * Selects the file in the specified path
 * The path may be relative, absolute, a file URL absolute string or a prefixed path like gxblobdata://somefile
 */
@property (nonatomic, strong, readwrite) NSString *source;

/**
 * Returns the result of the last operation
 */
@property (nonatomic, readonly) NSInteger errCode;

/**
 * Returns the result description of the last operation
 */
@property (nonatomic, strong, readonly) NSString *errDescription;

/**
 * Checks whether the file specified in source exists
 */
- (BOOL)exists;

/**
 * Renames the file specified in source. It can be also used to move the file changing its current path.
 */
- (void)renameTo:(nullable NSString *)path  NS_SWIFT_NAME(renameTo(_:));

/**
 * Return the name of the file specified in source.
 */
- (NSString *)getName;

/**
 * Return the absolute name of the file specified in source.
 */
- (NSString *)getAbsoluteName;

@end

NS_ASSUME_NONNULL_END
