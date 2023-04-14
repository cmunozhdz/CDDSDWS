//
//  GXActionControllerDelegateProtocol.h
//  GXFlexibleClient
//
//  Created by willy on 5/11/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import Foundation;
@import GXObjectsModel;
@import GXDataLayer;
#import <GXCoreUI/GXEntityModelProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXActionControllerDelegate <NSObject>

- (nullable id <GXActionHandler>)handleAction:(id<GXActionDescriptor>)action
									fromModel:(id<GXEntityModel>)entityModel
							   withEntityData:(nullable id <GXEntityDataWithOverrideValues>)entityData
								 indexerStack:(nullable NSArray<NSNumber *> *)indexer
									   sender:(nullable id)sender
						 userInterfaceContext:(nullable GXUserInterfaceContext *)uiContext
							  concurrencyMode:(GXActionHandlerConcurrencyMode)concurrencyMode;

@optional

/**
 * Control objects call this method when the avilable actions need to change, for example when
 * the sections are displayed as tabs and the selected tab changes
 * The method needsReloadActions is animated if needed (visible state is Appeared or Appearing)
 */
- (void)needsReloadActions;
- (void)needsReloadActionsAnimated:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END
