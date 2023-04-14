//
//  GXXMLReader.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 7/5/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

#import <GXStandardClasses/GXHttpClient.h>

NS_ASSUME_NONNULL_BEGIN

#define GXXMLReaderNodeTypeNone 0

typedef NS_OPTIONS(uint_least8_t, GXXMLReaderNoteType) {
    GXXMLReaderNoteTypeElement = 1,
    GXXMLReaderNoteTypeEndTag = 1 << 1,
    GXXMLReaderNoteTypeText = 1 << 2,
    GXXMLReaderNoteTypeComment = 1 << 3,
    GXXMLReaderNoteTypeWhiteSpace = 1 << 4,
    GXXMLReaderNoteTypeCData = 1 << 5,
    GXXMLReaderNoteTypeProcessingInstruction = 1 << 6,
    GXXMLReaderNoteTypeDocumentType = 1 << 7
};

@interface GXXMLReader : GXEmbeddedModelNSObject

@property (nonatomic, assign, readonly) NSInteger attributeCount;
@property (nonatomic, assign, readonly) BOOL eof;
@property (nonatomic, assign, readonly) NSInteger errCode;
@property (nonatomic, strong, readonly) NSString *errDescription;
@property (nonatomic, strong, readonly) NSString *localName;
@property (nonatomic, strong, readonly) NSString *name;
@property (nonatomic, strong, readonly) NSString *namespaceURI;
@property (nonatomic, assign, readonly) NSInteger nodeType;
@property (nonatomic, assign, readonly) NSInteger isSimple;
@property (nonatomic, strong, readonly) NSString *value;

@property (nonatomic, assign) BOOL removeWhiteNodes;
@property (nonatomic, assign) BOOL removeWhiteSpaces;
@property (nonatomic, assign) BOOL simpleElements;

- (NSInteger)open:(NSString *)fileUrl;

- (NSInteger)openFromString:(NSString *)xmlString;

- (NSInteger)openResponse:(GXHttpClient *)httpClient;

/**
 * Tries to open the embedded resource with the specified path, and if it fails it tries to load the resource from the static content in the web server.
 * If neither resource can be located, then an error is stored in the errorCode & errorDescription properties
 */
- (void)openResource:(NSString *)resourcePath;

- (NSInteger)close;

- (NSInteger)read;

- (NSInteger)readType:(NSNumber *)nodeType name:(nullable NSString *)nodeName;

- (NSString *)readRawXML;

- (NSString *)getAttributeByIndex:(NSNumber *)index;

- (NSString *)getAttributeByName:(NSString *)attName;

- (NSInteger)existsAttribute:(NSString *)attName;

- (NSInteger)skip;

@end

NS_ASSUME_NONNULL_END


/*

Missing Properties
==================
 @property (nonatomic, strong, readonly) NSNumber *errLineNumber;
 @property (nonatomic, strong, readonly) NSNumber *errLinePos;
 @property (nonatomic, strong, readonly) NSNumber *isSimple;
 @property (nonatomic, strong, readonly) NSString *prefix;

 @property (nonatomic, strong) NSNumber *readExternalEntities;
 @property (nonatomic, strong) NSNumber *simpleElements;
 @property (nonatomic, strong) NSNumber *validationType;

Missing Methods
===============
 AddSchema,                     [char,10240,0,0],	[[char,1024,0,0], [char,1024,0,0]]):- !.

 SetDocEncoding,                [int, 4, 0, 0],		[[char,1024,0,0]]):- !.
 SetNodeEncoding,               [int, 4, 0, 0],		[[char,1024,0,0]]):- !.
 
 GetAttributeName, 				[char,1024,0,0],	[[int,4,0,0]]):- !.
 GetAttributePrefix,            [char,1024,0,0],	[[int,4,0,0]]):- !.
 GetAttributeLocalName,			[char,1024,0,0],	[[int,4,0,0]]):- !.
 GetAttributeURI,				[char,1024,0,0],	[[int,4,0,0]]):- !.

 GetAttEntityValueByIndex,		[char,1024,0,0],	[[int,4,0,0]]):- !.
 GetAttEntityValueByName,		[char,1024,0,0],	[[char,1024,0,0]]):- !.
 GetAttEntityNotationByIndex, 	[char,1024,0,0],	[[int,4,0,0]]):- !.
 GetAttEntityNotationByName,    [char,1024,0,0],	[[char,1024,0,0]]):- !.
 */
