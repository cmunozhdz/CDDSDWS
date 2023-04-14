//
//  GXAudioManagerService.h
//  GXCoreBL
//
//  Created by Marcos Crispino on 3/1/17.
//  Copyright © 2017 GeneXus. All rights reserved.
//

@protocol GXAudioManagerService <NSObject>

#if !TARGET_OS_WATCH
- (BOOL)remoteControlReceivedWithEvent:(UIEvent *)receivedEvent;
#endif // !TARGET_OS_WATCH

@end
