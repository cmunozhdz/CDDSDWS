//
//  GXKBObjectsModel.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 10/11/15.
//  Copyright © 2015 Artech. All rights reserved.
//

@import Foundation;
@import GXFoundation;
#import <GXObjectsModel/GXBusinessComponentModel.h>
#import <GXObjectsModel/GXNamedElement.h>
#import <GXObjectsModel/GXProcedureModel.h>
#import <GXObjectsModel/GXResources.h>
#import <GXObjectsModel/GXWorkWithModel.h>

NS_ASSUME_NONNULL_BEGIN

@class GXAttributeInfo;
@class GXDashboardModel;
@class GXDomainInfo;
@class GXStructureDataTypeInfo;
@class GXStyleKBObject;
@class GXDesignSystemObject;
@class GXTheme;
@protocol GXModelObject;

@interface GXKBObjectsModel : GXModelObjectChild

- (instancetype)initWithObjectModelsById:(nullable NSDictionary <NSString *, NSDictionary<NSString *, __kindof GXNamedElement<GXModelObject> *> *> *)objectModels
							   resources:(GXResources *)resources
						  forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@property(nonatomic, strong, readonly) NSDictionary<NSString *, GXAttributeInfo *> *attributeInfoByName;
@property(nonatomic, strong, readonly) NSDictionary<NSString *, GXBusinessComponentModel *> *businessComponentsByName;
@property(nonatomic, strong, readonly) NSDictionary<NSString *, GXDashboardModel *> *dashboardsByName;
@property(nonatomic, strong, readonly) NSDictionary<NSString *, GXDesignSystemObject *> *designSystemsByName;
@property(nonatomic, strong, readonly) NSDictionary<NSString *, GXDomainInfo *> *domainInfoByName;
@property(nonatomic, strong, readonly) NSDictionary<NSString *, GXProcedureModel *> *proceduresByName;
@property(nonatomic, strong, readonly) NSDictionary<NSString *, GXStructureDataTypeInfo *> *sdtInfoByName;
@property(nonatomic, strong, readonly) NSDictionary<NSString *, GXTheme *> *themesByName;
@property(nonatomic, strong, readonly) NSDictionary<NSString *, GXWorkWithModel *> *workWithsByName;
@property(nonatomic, strong, readonly) NSDictionary<NSString *, GXWorkWithModel *> *workWithsByBusinessComponentName;

@property(nonatomic, copy, readonly) NSArray<GXStyleKBObject *> *styleKBObjects; // GXDesignSystemObject + GXTheme

@property(nonatomic, strong, readonly) GXResources *resources;

- (nullable GXNamedElement<GXModelObject> *)objectForName:(NSString *)name type:(GXObjectType)type;
- (nullable GXAttributeInfo *)attributeInfoForName:(NSString *)name;
- (nullable GXBusinessComponentModel *)businessComponentForName:(NSString *)name;
- (nullable GXDashboardModel *)dashboardForName:(NSString *)name;
- (nullable GXDesignSystemObject *)designSystemsForName:(NSString *)name;
- (nullable GXDomainInfo *)domainInfoForName:(NSString *)name;
- (nullable GXProcedureModel *)procedureForName:(NSString *)name;
- (nullable GXStructureDataTypeInfo *)sdtInfoForName:(NSString *)name;
- (nullable GXStyleKBObject *)styleKBObjectForName:(NSString *)name;
- (nullable GXTheme *)themeForName:(NSString *)name;
- (nullable GXWorkWithModel *)workWithForName:(NSString *)name;
- (nullable GXWorkWithModel *)workWithForBusinessComponent:(NSString *)entityType;

@end

@interface GXKBObjectsModel (GXModel)

/// #deprecated: 2022-01-27: trunk; #to-remove: ??
+ (nullable GXKBObjectsModel *)currentModel __attribute__((deprecated("Use GXModel appModel instead")));

@end

NS_ASSUME_NONNULL_END
