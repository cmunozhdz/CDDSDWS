//
//  GXReorganization.h
//  GXStd
//
//  Created by Marcos Crispino on 21/08/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface GXReorganization : NSObject

#pragma mark - Class methods used by the reorg

+ (void)addMsg:(NSString *)msg;

+ (void)addMsgWithId:(int)mdgId message:(NSString *)msg;

+ (void)replaceMsgWithId:(int)mdgId message:(NSString *)msg;

+ (BOOL)getRecordCount;

#pragma mark - Empty methods, required to compile the project...

- (void)executeReorg:(NSString *)args createDatabase:(BOOL)createDB;

- (int)getHandle;

@end

NS_ASSUME_NONNULL_END
