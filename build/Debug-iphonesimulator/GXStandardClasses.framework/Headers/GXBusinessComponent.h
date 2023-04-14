//
//  GXBusinessComponent.h
//  GXStd
//
//  Created by Alejandro Panizza on 8/30/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

#import <GXStandardClasses/GXMessageList.h>
#import <GXStandardClasses/GXEmbeddedModelObject.h>

NS_ASSUME_NONNULL_BEGIN

@class GXSdtBusinessComponent;

// Subclasses are generated. Definition must be in ObjC to support XCFrameworks with iOS deployment target lower than 13.0
@interface GXBusinessComponent : GXEmbeddedModelNSObject {
@protected
	NSString *gx_mode;
	GXMessageList *gx_msglist;
}

@property (nonatomic, strong, readonly, nullable) NSNumber *anyerror;
@property (nonatomic, strong) GXMessageList *gx_msglist;
@property (nonatomic, strong, nullable) NSString *mode;

@property (nonatomic, strong, nullable) NSDate *saveTimestamp;

#pragma mark - Abstract methods (implementend by generated BCs)

- (void)setSdt:(GXSdtBusinessComponent *)sdt sdttobc:(NSNumber *)toBc;

- (void)initialize;

- (void)loadKey:(NSArray *)key;

- (void)save;

- (BOOL)insert;

- (BOOL)update;

- (BOOL)insertOrUpdate;

- (void)check;

- (void)delete;

- (void)getInsDefault;

- (void)cleanup;

- (NSString *)gxBCName;

@end

NS_ASSUME_NONNULL_END
