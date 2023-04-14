//
//  GXEntityHelper+GXFieldSpecifier.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 20/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

@import GXObjectsModel;

@interface GXEntityHelper (GXFieldSpecifier)

/**
 * Convert fieldSpecifier format from design time to runtime
 */
+ (NSString *)runtimeFieldSpecifierFromDesignTime:(NSString *)designTimeFieldSpecifier;

/**
 * Converts the fieldSpecifier to the indexed field specifier
 * Example: converts "CurrentItem.SomeField" to "Item(2).SomeField
 */
+ (NSString *)fieldSpecifierForIndexer:(NSArray *)indexer fieldSpecifier:(NSString *)fieldSpecifier;

/// Joins the given variable components with '.'
+ (NSString *)fieldSpecifierFromComponents:(NSString *)componenets, ...;

/**
 * Extracts the index value from a field specifier. For example, for the field specifier "item(2).SomeItemId" it would yield the value 2
 * If the filed specifier does not contain an index, then NSNotFound is returned.
 */
+ (NSUInteger)indexFromFieldSpecifier:(NSString *)fieldSpecifier;

@end
