//
//  GXExternalObjectBase.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 1/3/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import Foundation;
#import <GXStandardClasses/GXEmbeddedModelObject.h>

NS_ASSUME_NONNULL_BEGIN

// Subclasses are generated. Definition must be in ObjC to support XCFrameworks with iOS deployment target lower than 13.0
@interface GXExternalObjectBase : GXEmbeddedModelNSObject

@property(nonatomic, strong, readonly) NSString *externalObjectName; // Abstract

@property(nullable, nonatomic, strong) NSError *error;

/**
 * Will be called if the execution of an asynchronic operation must be suspended.
 *
 * Default implementation has no effect, must be overriden if the execution is asynchonic.
 */
- (void)cancelExecution;

/*!
 Dispatches an event with the given name for the reciver with the given paramenters.
 
 @param eventName Name of the event.
 @param parameters Parameters for the event execution.
 @discussion [NSString stringWithFormat:@"%@.%@", self.externalObjectName, eventName] is the full name of the event to be dispatched.
 */
- (void)dispatchExteralObjectEvent:(NSString *)eventName withParameters:(nullable NSArray *)parameters;

@end

NS_ASSUME_NONNULL_END
