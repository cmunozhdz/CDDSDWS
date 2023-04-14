//
//  GXWorkWithActions.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 10/12/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXEventDescriptor.h>
#import <GXObjectsModel/GXModelObjectChild.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXWorkWithActions : GXModelObjectChild

@property(nonatomic, strong, readonly) NSArray<GXEventDescriptor *> *events;

- (instancetype)initWithEvents:(nullable NSArray<GXEventDescriptor *> *)events
				forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
