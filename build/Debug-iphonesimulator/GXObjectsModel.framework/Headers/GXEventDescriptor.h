//
//  GXEventDescriptor.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 23/11/15.
//  Copyright © 2015 Artech. All rights reserved.
//

#import <GXObjectsModel/GXNamedModelObjectChild.h>
#import <GXObjectsModel/GXEventDescriptorProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXEventDescriptor : GXNamedModelObjectChild <GXEventDescriptor>

@property(nonatomic, strong, readonly) NSString *name;

- (instancetype)initWithName:(NSString *)name
				   eventType:(GXEventType)type
		 eventParametersDesc:(nullable id <GXActionParametersDescriptor>)eventParametersDesc
			  rootActionDesc:(nullable id <GXEventActionDescriptor>)rootActionDesc
		   errorHandlingMode:(GXActionErrorHandlingMode)errorHandlingMode
			  forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithName:(nullable NSString *)name forModelObject:(nullable id<GXModelObject>)modelObject NS_UNAVAILABLE;

#pragma mark - Convenience Initializers

- (instancetype)initWithName:(NSString *)name
				   eventType:(GXEventType)type
		 eventParametersDesc:(nullable id <GXActionParametersDescriptor>)eventParametersDesc
			  rootActionDesc:(nullable id <GXEventActionDescriptor>)rootActionDesc
			  forModelObject:(nullable id<GXModelObject>)modelObject; // GXActionErrorHandlingModeComposite

@end

NS_ASSUME_NONNULL_END
