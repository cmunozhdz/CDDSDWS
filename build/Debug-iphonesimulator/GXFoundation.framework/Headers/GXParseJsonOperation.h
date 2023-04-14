//
//  GXParseJsonOperation.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 22/07/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@protocol GXParseJsonOperationDelegate;

@interface GXParseJsonOperation : NSOperation {
	NSData *_data;
	id _parsedData;
	NSError *_error;
	id <GXParseJsonOperationDelegate> __weak _delegate;
}

// Input Data
@property(nullable, nonatomic, strong) NSData *data;

// Output Data
@property(nullable, nonatomic, strong, readonly) id parsedData; // NSArray or NSDictionary
@property(nullable, nonatomic, strong, readonly) NSError *error;

// Delegate
@property(nullable, weak) id <GXParseJsonOperationDelegate> delegate;

@end

@protocol GXParseJsonOperationDelegate <NSObject>
@optional
- (void)parseJsonOperationDidFinishParsing:(GXParseJsonOperation *)op;
- (void)parseJsonOperationDidFailParsing:(GXParseJsonOperation *)op;
@end

NS_ASSUME_NONNULL_END
