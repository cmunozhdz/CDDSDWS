//
//  GXParseXmlOperation.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 02/12/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@class GXParseXmlOperation;

@protocol GXParseXmlOperationDelegate <NSObject>
@optional
- (void)parseXmlOperationDidFinishParsing:(GXParseXmlOperation *)op;
- (void)parseXmlOperationDidFailParsing:(GXParseXmlOperation *)op;
@end

@interface GXParseXmlOperation : NSOperation <NSXMLParserDelegate> {
	NSData * _Nullable _data;
	NSDictionary * _Nullable _parsedData;
	NSError * _Nullable _error;
	id <GXParseXmlOperationDelegate> __weak _Nullable _delegate;
	
	NSXMLParser * _Nullable _parser;
	NSMutableArray * _Nullable _currentElementStack;
	NSMutableString * _Nullable _currentElementInnerString;
	
	BOOL _executing;
    BOOL _finished;
}

// Input Data
@property(nullable, nonatomic, strong) NSData *data;

// Output Data
@property(nullable, nonatomic, strong, readonly) NSDictionary *parsedData;
@property(nullable, nonatomic, strong, readonly) NSError *error;

// Delegate
@property(nullable, weak) id <GXParseXmlOperationDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
