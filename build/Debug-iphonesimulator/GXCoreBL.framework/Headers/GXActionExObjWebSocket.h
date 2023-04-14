//
//  GXActionExObjWebSocket.h
//  GXCoreBL
//
//  Created by Marcos Crispino on 9/4/19.
//  Copyright © 2019 GeneXus. All rights reserved.
//

@import Foundation;
#import <GXCoreBL/SRWebSocket.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXWebSocketHandlerDelegate <NSObject>
- (void)success;
- (void)failed;
@end

@interface GXActionExObjWebSocket : NSObject <SRWebSocketDelegate>

@property(nonatomic, readonly, assign) SRReadyState status;

+ (GXActionExObjWebSocket *)sharedInstance;

- (void)sendMessage:(NSString *)message;
- (void)close;

@end

NS_ASSUME_NONNULL_END
