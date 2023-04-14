//
//  GXEventDescriptorProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 20/11/15.
//  Copyright © 2015 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXActionParametersDescriptorProtocol.h>
#import <GXObjectsModel/GXModelObjectProtocol.h>

@protocol GXEventActionDescriptor;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint_least8_t, GXEventType) {
	GXEventTypeAction = 0,
	GXEventTypeExternalObject,
	GXEventTypeSubroutine
};

GXEventType GXEventTypeFromString(NSString * __nullable eventTypeStr);
GXEventType GXEventTypeFromStringWithDefault(NSString * __nullable eventTypeStr, GXEventType defaultEventType);

typedef NS_ENUM(uint_least8_t, GXActionErrorHandlingMode) {
	GXActionErrorHandlingModeComposite,
	GXActionErrorHandlingModeNormal
};

@protocol GXEventDescriptor <GXModelObject, NSObject>

@property(nonatomic, strong, readonly) NSString *eventName;
@property(nonatomic, assign, readonly) GXEventType eventType;
@property(nullable, nonatomic, strong, readonly) id <GXEventActionDescriptor> eventRootActionDescriptor;
@property(nonatomic, assign, readonly) GXActionErrorHandlingMode eventActionErrorHandlingMode;

@optional
@property(nullable, nonatomic, strong, readonly) id <GXActionParametersDescriptor> eventActionParametersDescriptor;

@end

NS_ASSUME_NONNULL_END
