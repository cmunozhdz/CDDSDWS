//
//  GXBusinessComponentModel.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 16/12/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;
@import GXFoundation;
#import <GXObjectsModel/GXBusinessComponentLevel.h>
#import <GXObjectsModel/GXNamedModelObjectChild.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXBusinessComponentModel : GXNamedModelObjectChild

@property(nonnull, nonatomic, strong, readonly) NSString *name;
@property(nonatomic, strong, readonly) GXBusinessComponentLevel *rootLevel;
@property(nonatomic, assign, readonly) GXConnectivitySupportType connectivitySupport;

- (instancetype)initWithName:(NSString *)name
		 connectivitySupport:(GXConnectivitySupportType)connSupport
				   rootLevel:(GXBusinessComponentRootLevel *)root
			  forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithName:(nullable NSString *)name forModelObject:(nullable id<GXModelObject>)modelObject NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

- (NSArray<__kindof GXBusinessComponentLevel *> *)allLevels;
- (nullable NSArray<GXBusinessComponentRelation *> *)allRelations;
- (nullable GXBusinessComponentLevel *)levelForLevelName:(NSString *)levelName;
- (nullable GXBusinessComponentLevel *)levelForName:(NSString *)name;

@end

NS_ASSUME_NONNULL_END
