//
//  GXXMLWriter.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 7/4/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

#import <GXStandardClasses/GXHttpClient.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXXMLWriter : NSObject <GXHTTPClientDelegate>

@property (nonatomic, strong, readonly) NSNumber *errCode;
@property (nonatomic, strong, readonly) NSString *errDescription;
@property (nonatomic, strong) NSNumber *indentation;
@property (nonatomic, strong) NSString *indentChar;
@property (nonatomic, strong, readonly) NSString *resultingString;

- (void)openURL:(NSString *)fileUrl;

- (void)openToString;

- (void)openRequest:(GXHttpClient *)http;

- (void)close;

- (void)writeStartDocument:(NSString *)encoding standalone:(NSNumber *)standalone;

- (void)writeStartElement:(NSString *)element;

- (void)writeEndElement;

- (void)writeElement:(NSString *)name value:(NSString *)value;

- (void)writeComment:(NSString *)comment;

- (void)writeCData:(NSString *)cdata;

- (void)writeAttribute:(NSString *)name value:(NSString *)value;

- (void)writeElement:(NSString *)name value:(NSString *)value attributes:(NSDictionary<NSString *, NSString *> *)attributes;

- (void)writeText:(NSString *)text;

- (void)writeRawText:(NSString *)text;

- (void)writeDocType:(NSString *)docType subset:(NSString *)subset;

- (void)writeDocTypeSystem:(NSString *)docType uri:(NSString *)uri subset:(NSString *)subset;

- (void)writeDocTypePublic:(NSString *)docType uri:(NSString *)uri subset:(NSString *)subset;

- (void)writeNSStartElement:(NSString *)localName prefix:(NSString *)prefix namespaceURI:(NSString *)uri;

- (void)writeNSElement:(NSString *)localName namespaceURI:(NSString *)uri value:(NSString *)value;

- (void)writeProcessingInstruction:(NSString *)instruction value:(NSString *)value;

@end

/*
 Missing methods
 
 OpenRequest,                $openrequest($,				[], 		[[obj(httpclient),0,0,0]]):- !.
 OpenResponse,               $openresponse($,				[], 		[[obj(httpresponse),0,0,0]]):- !.
 WriteEntityReference,       $writeentityreference($, 		[], 		[[char,1024,0,0]]):- !.
 */

NS_ASSUME_NONNULL_END
