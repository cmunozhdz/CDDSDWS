//
//  GXObjectCollection.h
//  GXStd
//
//  Created by Alejandro Panizza on 8/15/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import GXObjectsModel;
#import <GXStandardClasses/GXEmbeddedModelObject.h>

NS_ASSUME_NONNULL_BEGIN

@class GXFile;

@interface GXObjectCollection : GXEmbeddedModelNSObject <GXSDTDataCollection>

@property (nonatomic, strong) NSMutableArray *items;
@property (nullable, nonatomic, strong) NSString * itemsTypeName;

- (instancetype)initWithArray:(NSArray *)initialArray
		  embeddedModelObject:(id<GXEmbeddedModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithTypeName:(nullable NSString *)typeName
			 embeddedModelObject:(id<GXEmbeddedModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

/**
 * Adds the item to the collection
 * The item gets added to the end of the collection
 */
- (void)addItem:(id)item;

/**
 * Adds the item to the collection
 * Same as addItem:
 */
- (void)add:(id)item;

/**
 * Adds the item to the collection at the given position
 * The 'index' parameter is 1-based, where the zero means "insert at the end"
 */
- (void)addItem:(id)item atIndex:(NSInteger)index;

- (void)clear;

- (void)removeAllItems;

/**
 * Removes the element at the location given by index
 * The 'index' parameter is 1-based
 * Returns 1 if success, 0 otherwise
 */
- (NSInteger)removeElement:(NSInteger)index;

- (NSString *)stringAtIndex:(NSInteger)index;

- (id)objectAtIndex:(NSInteger)index;
- (NSInteger)indexOf:(id)item NS_SWIFT_NAME(indexOf(_:));

- (NSUInteger)count;

- (NSInteger)size;

- (id)gxSerialize;
- (id)gxJSONSerialize;

- (NSString *)toJSONString;
- (NSString *)toJSONString:(BOOL)includeState;
- (NSString *)toJSONString:(BOOL)includeState includeNonInitialized:(BOOL)includeNonInitialized NS_SWIFT_NAME(toJSONString(_:_:));

/**
 * Loads the collection content from the given JSON
 *
 * @param json The JSON string with the content
 *
 * @return true if success, false if JSON string could not be parsed
 */
- (BOOL)fromJSONString:(nullable NSString *)json;

/**
 * Loads the collection content from the given JSON
 *
 * @param json The JSON string with the content
 * @param messages Messages SDT where resulting error messages are returned
 *
 * @return true if success, false if JSON string could not be parsed
 */
- (BOOL)fromJSONString:(nullable NSString *)json messages:(nullable GXObjectCollection *)messages;

/**
 * Loads the collection content from the given JSON File
 *
 * @param json The GXFile where the JSON data is stored
 * @param messages Messages SDT where resulting error messages are returned
 *
 * @return true if success, false if JSON string could not be parsed
 */
- (BOOL)fromJSONFile:(GXFile *)json messages:(nullable GXObjectCollection *)messages;

/**
 * Returns the XML representation of this collection object
 */
- (NSString *)toxml;

/**
 * Returns the XML representation of this collection object
 * Parameters:
 *   - includeHeader: if YES, the XML header is included in the resulting string
 *   - inclideState: It only applies to Business Components. If YES, then the returned string contains the auxiliar variables (old values, mode, initialized flag).
 *   - header: [Ignored parameter]
 *   - nameSpace: [Ignored parameter]
 */
- (NSString *)toxmlIncludeHeader:(BOOL)inclHeader includeState:(BOOL)inclState header:(nullable NSString *)header nameSpace:(nullable NSString *)ns;

/**
 * Initializes the collection with the contents of the given XML string
 *
 * @param xml The XML string
 *
 * @return true if success, false if the XML string could not be parsed
 */
- (BOOL)fromxml:(nullable NSString *)xml;

/**
 * Initializes the collection with the contents of the given XML string
 *
 * @param xml The XML string
 * @param messages Messages SDT where resulting error messages are returned
 *
 * @return true if success, false if the XML string could not be parsed
 */
- (BOOL)fromxml:(nullable NSString *)xml messages:(nullable GXObjectCollection *)messages;

/**
 * Initializes the collection with the contents of the given XML file
 *
 * @param file The XML file
 * @param messages Messages SDT where resulting error messages are returned
 *
 * @return true if success, false if the XML string could not be parsed
 */
- (BOOL)fromxmlfile:(GXFile *)file messages:(nullable GXObjectCollection *)messages;

- (void)sort:(NSString *)membersList;

/**
 * Loads items from the array, modifying the current object
 *
 * @discussion If the collection already has items, new items are appended
 * @discussion Conversions ara applied to items in the array to convert them to the supported offline types
 */
- (void)loadFromArray:(NSArray *)array;

@end

@interface GXObjectCollection (SwiftGenerator)

@property (nullable, nonatomic, strong) id currentItem;

- (instancetype)initWithCollection:(GXObjectCollection *)col;

- (nullable id)createItemInstance;

- (instancetype)clone;

@end

NS_ASSUME_NONNULL_END
