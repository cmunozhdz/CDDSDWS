//
//  GXEmbeddedModelObject.h
//  GXStandardClasses
//
//  Created by Fabian Inthamoussu on 15/2/22.
//  Copyright © 2022 GeneXus. All rights reserved.
//

@import GXObjectsModel;

#if GX_WARN_GXOFFLINETHREAD_ONLY_METHODS
#define GX_WARN_GXOFFLINETHREAD_ONLY_METHOD __deprecated_msg("To be called from generated code. Must be called from a GXOfflineThread.")
#else
#define GX_WARN_GXOFFLINETHREAD_ONLY_METHOD
#endif

NS_ASSUME_NONNULL_BEGIN

/// Model Object that only applies to embedded models.
@protocol GXEmbeddedModelObject <GXModelObject>

/// Returned model must satisfy appModel.isEmbeddedApplication == true. Return value must be the same as self.gxModel or nil.
@property(nonatomic, nullable, readonly) GXModel* gxEmbeddedModel;

@end


@interface GXEmbeddedModelNSObject: NSObject<GXEmbeddedModelObject>

- (instancetype)initWithEmbeddedModelObject:(id<GXEmbeddedModelObject>)modelObject;
- (nullable instancetype)initWithModelObject:(id<GXModelObject>)modelObject;
- (instancetype)init NS_DESIGNATED_INITIALIZER;

- (void)assignEmbeddedModel:(GXModel *)embeddedModel;

@end

NS_ASSUME_NONNULL_END
