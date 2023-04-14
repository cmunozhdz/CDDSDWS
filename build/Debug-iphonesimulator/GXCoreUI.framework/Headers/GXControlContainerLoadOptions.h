//
//  GXControlContainerLoadOptions.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 30/01/14.
//  Copyright (c) 2014 Artech. All rights reserved.
//

@import GXDataLayer;

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(uint_least8_t, GXControlContainerLoadOptionsFlags) {
	GXControlContainerLoadOptionsFlagDynProperties = 1 << 0
};

@interface GXControlContainerLoadOptions : NSObject <NSCopying, NSMutableCopying>

- (instancetype)initWithFlags:(GXControlContainerLoadOptionsFlags)flags
dynamicPropertiesCollection:(nullable GXDynamicPropertiesCollection *)dynProps NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

@property(assign, readonly) GXControlContainerLoadOptionsFlags flags;
@property(nullable, nonatomic, strong, readonly) GXDynamicPropertiesCollection *dynamicPropertiesCollection;

@end

@interface GXControlContainerMutableLoadOptions : GXControlContainerLoadOptions

@property(assign, readwrite) GXControlContainerLoadOptionsFlags flags;
@property(nullable, nonatomic, strong, readwrite) GXDynamicPropertiesCollection *dynamicPropertiesCollection;

@end

NS_ASSUME_NONNULL_END
