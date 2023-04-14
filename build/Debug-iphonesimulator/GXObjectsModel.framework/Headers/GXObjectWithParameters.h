//
//  GXObjectWithParameters.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 1/6/15.
//  Copyright (c) 2015 Artech. All rights reserved.
//


@import Foundation;
#import <GXObjectsModel/GXEntityDataProtocol.h>
#import <GXObjectsModel/GXParametersDescriptorProtocol.h>

@protocol GXObjectWithParameters <NSObject>

@property(nullable, nonatomic, strong, readonly) id <GXParametersDescriptor> parametersDescriptor;
@property(nullable, nonatomic, strong) id <GXEntityData> inputParametersEntityData;

@optional
@property(nullable, nonatomic, strong, readonly) id <GXEntityData> outputParametersEntityData;

@end
