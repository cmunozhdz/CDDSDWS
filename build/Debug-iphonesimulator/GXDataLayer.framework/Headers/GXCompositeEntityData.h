//
//  GXCompositeEntityData.h
//  GXFlexibleClient
//
//  Created by willy on 2/3/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@interface GXCompositeEntityData : NSObject <GXEntityData>

@property(nonatomic, strong, readonly) id <GXEntityData> parentEntityData;
@property(nonatomic, strong, readonly) id <GXEntityData> entityData;

+ (nullable id<GXEntityData>)entityDataWithEntity:(nullable id<GXEntityData>)entityData
									 parentEntity:(nullable id<GXEntityData>)parent; // excludedComposeFieldNames = nil

@end

@interface GXCompositeEntityDataWithOverrideValues : GXCompositeEntityData <GXEntityDataWithOverrideValues>
@end

@interface GXCompositeMutableEntityData : GXCompositeEntityData <GXMutableEntityData>
@end

@interface GXCompositeMutableEntityDataWithOverrideValues : GXCompositeEntityDataWithOverrideValues <GXMutableEntityData>
@end

@interface GXCompositeBusinessComponentLevelEntityData : GXCompositeMutableEntityData <GXBusinessComponentLevelEntityData>
@end

@interface GXCompositeBusinessComponentLevelEntityDataWithOverrideValues : GXCompositeMutableEntityDataWithOverrideValues <GXBusinessComponentLevelEntityData>
@end



@interface GXCompositeEntityData (ExcludedComposeFieldNames)

@property(nullable, nonatomic, strong, readonly) NSSet<NSString *> *excludedComposeFieldNames; // Lowercase

+ (nullable id<GXEntityData>)entityDataWithEntity:(nullable id<GXEntityData>)entityData
									 parentEntity:(nullable id<GXEntityData>)parent
						excludedComposeFieldNames:(nullable NSSet<NSString *> *)excludedComposeLowercaseFieldNames;

@end

NS_ASSUME_NONNULL_END
