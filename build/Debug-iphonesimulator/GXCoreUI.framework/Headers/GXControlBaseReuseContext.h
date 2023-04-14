//
//  GXControlBaseReuseContext.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 7/4/15.
//  Copyright (c) 2015 Artech. All rights reserved.
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@interface GXControlBaseReuseContext : NSObject

@property(nonatomic, assign) BOOL restoreLayoutElementVisible;
@property(nonatomic, assign) BOOL restoreLayoutElementEnabled;
@property(nonatomic, assign) BOOL restoreLayoutElementStyleClass;


@property(nonatomic, assign) BOOL shouldDelayedOnStyleClassChangedFrom;
@property(nonatomic, nullable) GXStyleClass *delayedOnStyleClassChangedFrom;

@property(nonatomic, copy, nullable, readonly) NSSet<NSString *> *restoreStyleClassPropertyOverrides;
- (void)removeRestoreStyleClassPropertyOverride:(NSString *)propertyName;
- (void)addRestoreStyleClassPropertyOverrides:(NSArray<NSString *> *)propertyNames;

@end

NS_ASSUME_NONNULL_END
