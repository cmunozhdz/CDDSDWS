//
//  GXURLRequestOperationDelegate.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 27/07/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@protocol GXURLRequestOperationDelegate;

@interface GXURLRequestOperation : NSOperation

#pragma mark - Input Data

@property(nullable, nonatomic, strong) NSURLRequest *request;
@property(nonatomic, assign) BOOL followRedirects;

/**
 * The path where the downloaded data will be saved.
 *
 * If set to nil, the downloaded date will only be accessible via the 'data' property.
 */
@property(nullable, nonatomic, strong) NSString *saveToFilePath;

#pragma mark - Output Data

@property(nullable, nonatomic, readonly, strong) NSURLResponse *response;
@property(nullable, nonatomic, readonly, strong) NSData *data;
@property(nullable, nonatomic, readonly, strong) NSError *error;

#pragma mark - Delegate
@property(nullable, weak) id <GXURLRequestOperationDelegate> delegate;

@end

@protocol GXURLRequestOperationDelegate <NSObject>
@optional
- (void)urlRequestOperationDidFinishLoading:(GXURLRequestOperation *)op;
- (void)urlRequestOperationDidFailLoading:(GXURLRequestOperation *)op;
@end

NS_ASSUME_NONNULL_END
