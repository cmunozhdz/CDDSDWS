//
//  GXBusinessComponentRelation.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 21/01/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXNamedElement.h>

@class GXBusinessComponentModel;
@class GXBusinessComponentLevel;

NS_ASSUME_NONNULL_BEGIN

@interface GXBusinessComponentRelation : GXNamedElement

@property(nullable, nonatomic, weak, readonly) GXBusinessComponentModel *businessComponent;
@property(nullable, weak, readonly) GXBusinessComponentLevel *businessComponentLevel;

@property(nonnull, nonatomic, strong, readonly) NSString *name;
@property(nonatomic, strong, readonly) NSString *relatedBusinessComponentName;
@property(nonatomic, strong, readonly) NSString *relatedBCLevelName;
@property(nonatomic, strong, readonly) NSArray<NSString *> *foreingKeyAttributesNames;
@property(nullable, nonatomic, strong, readonly) NSArray<NSString *> *inferredAttributesNames;
@property(nullable, nonatomic, strong, readonly) NSString *inferredDescriptionAttributeName;

- (instancetype)initWithRelationName:(NSString *)name
			relatedBusinessComponent:(NSString *)relatedBCName
				  relatedBCLevelName:(NSString *)levelName
		   foreingKeyAttributesNames:(NSArray<NSString *> *)fkAttributesNames
			 inferredAttributesNames:(nullable NSArray<NSString *> *)inferredAttributesNames NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithName:(nullable NSString *)name NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

- (NSArray<NSString *> *)foreignKeyAndInferredAttributeNames;

@end

NS_ASSUME_NONNULL_END
