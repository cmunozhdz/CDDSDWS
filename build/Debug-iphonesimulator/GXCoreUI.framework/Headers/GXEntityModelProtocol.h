//
//  GXEntityModelProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 27/07/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import GXObjectsModel;
@import GXDataLayer;

@protocol GXActionHandler, GXEntityComponentModel;

NS_ASSUME_NONNULL_BEGIN

@protocol GXEntityModel <GXModelObject, GXSDObjectLocator>

#if TARGET_OS_IOS
- (nullable id<GXLayout>)entityLayoutForOrientation:(UIInterfaceOrientation)orientation mode:(GXModeType)mode;
- (BOOL)hasLayoutForOrientation:(UIInterfaceOrientation)orientation mode:(GXModeType)mode;
- (BOOL)hasDifferenteLayoutsByOrientationForMode:(GXModeType)mode;
#else
- (nullable id<GXLayout>)entityLayoutForMode:(GXModeType)mode;
#endif // TARGET_OS_IOS
- (BOOL)hasLayoutInAnyOrientationForMode:(GXModeType)mode;

- (nullable GXBusinessComponentLevel *)entityBusinessComponentLevel;

@property(nonatomic, strong, readonly) id<GXEntityDataProvider> entityDataProvider;

@property(nullable, nonatomic, weak, readonly) id<GXEntityModel> entityParentModel;

/**
 * Collection of id<GXEntityComponentModel>
 * if the entity model does not support components, returns nil (sections)
 * if the entity model supports components, but it doesn't have any, returns an empty array (detail)
 */
@property(nullable, nonatomic, strong, readonly) NSArray<id <GXEntityComponentModel>> *entityComponentModels;

@property(nullable, nonatomic, strong, readonly) NSString *entityCaption;
@property(nonatomic, strong, readonly) NSArray<id<GXEventDescriptor>> *entityEvents;
- (nullable id <GXActionHandler>)entityActionHandlerForEntityActionDescriptor:(id <GXActionDescriptor>)entityActionDesc;

@property(nullable, nonatomic, strong, readonly) id <GXParametersDescriptor> entityGXObjectParametersDescriptor;

/// Returns an array with all the prompt rules for the model
- (NSArray<id<GXEntityRulePrompt>> *)entityRulesPrompt;

@end

#pragma mark -

@protocol GXEntityComponentModel <GXEntityModel>

@property(nonatomic, strong, readonly) NSString *entityDetailComponentCode;

@end

NS_ASSUME_NONNULL_END
