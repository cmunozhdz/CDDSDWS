//
//  GXBusinessComponentLevel.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 16/12/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXBusinessComponentAttribute.h>
#import <GXObjectsModel/GXBusinessComponentRelation.h>
#import <GXObjectsModel/GXDescriptionElement.h>
#import <GXObjectsModel/GXEntityDataDescriptorProtocol.h>
#import <GXObjectsModel/GXEntityDataKeyDescriptorProtocol.h>
#import <GXObjectsModel/GXParametersDescriptorProtocol.h>
#import <GXObjectsModel/GXModelObjectProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@class GXBusinessComponentModel, GXBusinessComponentChildLevel;

@interface GXBusinessComponentLevel : GXDescriptionElement <GXModelObject,
															GXEntityDataDescriptor,
															GXEntityDataKeyDescriptor,
															GXParametersDescriptor>

@property(nonnull, nonatomic, strong, readonly) NSString *name;
@property(nonatomic, strong, readonly) NSString *levelName;
@property(nullable, nonatomic, strong, readonly) NSArray<GXBusinessComponentAttribute *> *attributes;
@property(nullable, nonatomic, strong, readonly) NSArray<GXBusinessComponentChildLevel *> *childLevels;
@property(nullable, nonatomic, strong, readonly) NSArray<GXBusinessComponentRelation *> *levelRelations;

@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, GXBusinessComponentAttribute *> *attributesByName;

@property(nullable, nonatomic, strong, readonly) GXBusinessComponentAttribute *descriptionAttribute;

@property(nullable, nonatomic, weak, readonly) GXBusinessComponentModel *businessComponent;
@property(nullable, weak, readonly) GXBusinessComponentLevel *parentLevel NS_SWIFT_NAME(parentLevel);

- (instancetype)initWithName:(NSString *)name
				   levelName:(NSString *)levelName
				 description:(nullable NSString *)desc
				  attributes:(nullable NSArray<GXBusinessComponentAttribute *> *)attributes
				 childLevels:(nullable NSArray<GXBusinessComponentChildLevel *> *)childLevels
			  levelRelations:(nullable NSArray<GXBusinessComponentRelation *> *)levelRelations
		  descAttributeIndex:(NSUInteger)descAttributeIndex NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithName:(nullable NSString *)name NS_UNAVAILABLE;
- (instancetype)initWithName:(nullable NSString *)name description:(nullable NSString *)desc NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

- (nullable NSArray<GXBusinessComponentChildLevel *> *)allChildLevels;
- (nullable NSArray<GXBusinessComponentAttribute *> *)primaryKey;
- (nullable NSArray<GXBusinessComponentRelation *> *)allChildLevelsRelations;

- (nullable GXBusinessComponentChildLevel *)childLevelWithLevelName:(NSString *)levelName;

@end

@interface GXBusinessComponentRootLevel : GXBusinessComponentLevel {
	GXBusinessComponentModel * __weak _businessComponent;
}

@end

@interface GXBusinessComponentChildLevel : GXBusinessComponentLevel {
	GXBusinessComponentLevel * __weak _parentLevel;
}

@end

NS_ASSUME_NONNULL_END
