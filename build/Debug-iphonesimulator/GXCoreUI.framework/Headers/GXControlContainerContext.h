//
//  GXControlContainerContext.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 31/08/11.
//  Copyright (c) 2011 Artech. All rights reserved.
//

@import GXObjectsModel;
#if !TARGET_OS_WATCH
#import <GXCoreUI/GXControlWithActionBarItems.h>
#endif // !TARGET_OS_WATCH
#import <GXCoreUI/GXEntityModelProtocol.h>
#import <GXCoreUI/GXEntityControllerProtocol.h>
#if !TARGET_OS_WATCH
#import <GXCoreUI/GXEntityViewController.h>
#endif // !TARGET_OS_WATCH

NS_ASSUME_NONNULL_BEGIN

@interface GXControlContainerContext : NSObject

@property(nonatomic, strong, readonly) id<GXEntityModel> entityModel;
@property(nullable, nonatomic, weak, readonly) id<GXEntityControllerProtocol> entityController;
@property(nullable, nonatomic, weak, readonly) GXControlContainerContext* parentContainerContext;
@property(nonatomic, strong, readonly) NSMutableDictionary *properties;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithEntityModel:(id<GXEntityModel>)entityModel
					  parentContext:(GXControlContainerContext *)parentContainerContext;
- (instancetype)initWithEntityModel:(id<GXEntityModel>)entityModel
						 controller:(id<GXEntityControllerProtocol>)entityController
					  parentContext:(nullable GXControlContainerContext *)parentContainerContext NS_DESIGNATED_INITIALIZER;

- (nullable id<GXEventDescriptor>)eventDescriptorWithName:(NSString *)name;

#if !TARGET_OS_WATCH
@property(nonatomic, assign, readonly, getter=isInsideGXControlTableForHeightCalculation) BOOL insideGXControlTableForHeightCalculation;
#endif

#pragma mark - Controls' state

/**
 * Saves state for the given control
 */
- (void)setState:(nullable id)state forKey:(NSString *)key controlName:(NSString *)controlName;

/**
 * Gets the state as a dictinary for the given control
 */
- (nullable id)stateForKey:(NSString *)key controlName:(NSString *)controlName;

@end

NS_ASSUME_NONNULL_END
