//
//  GXEntityDetailLayout.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 13/01/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import GXObjectsModel;
@import GXDataLayer;
#import <GXCoreUI/GXControlComponentProtocol.h>
#import <GXCoreUI/GXEntityModelProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@class GXEntityDetailLayoutSection;
@class GXEntityDetailLayoutSectionInLine;
@class GXEntityDetailLayoutSectionLink;

#pragma mark -

@protocol GXEntityDetailLayoutSectionProvider <NSObject>

- (nullable GXEntityDetailLayoutSectionInLine *)detailLayoutSectionWithCode:(NSString *)caption;

- (void)presentViewControlerForComponentSectionLayout:(GXEntityDetailLayoutSection *)componentSectionLayout
						withInputParametersEntityData:(id <GXEntityData>)inputParametersEntityData;

- (nullable NSArray<__kindof GXEntityDetailLayoutSection *> *)allSections;

@end

#pragma mark -

@interface GXEntityDetailLayout : NSObject

@property(nullable, nonatomic, strong, readonly) NSArray<__kindof GXEntityDetailLayoutSection *> *sections;

- (instancetype)initWithSections:(nullable NSArray<__kindof GXEntityDetailLayoutSection *> *)sections NS_DESIGNATED_INITIALIZER;

@property(nonatomic, assign, readonly) NSUInteger numberOfSections;
- (GXEntityDetailLayoutSection *)sectionAtIndex:(NSUInteger)index;

- (nullable GXEntityDetailLayoutSectionInLine *)detailLayoutSectionWithCode:(NSString *)caption;

@end

#pragma mark -

typedef NS_ENUM(uint_least8_t, GXEntityDetailLayoutSectionType) {
	GXEntityDetailLayoutSectionTypeInLine,
	GXEntityDetailLayoutSectionTypeLink
};

#pragma mark -

@interface GXEntityDetailLayoutSection : NSObject // Abstract

@property(assign, readonly) GXEntityDetailLayoutSectionType type;
@property(nonatomic, strong, readonly) id <GXEntityComponentModel> model;
@property(nonatomic, strong, readonly) id <GXEntityDataDetailProvider> provider;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithModel:(id <GXEntityComponentModel>)model NS_DESIGNATED_INITIALIZER;

@end

#pragma mark -

@interface GXEntityDetailLayoutSectionInLine : GXEntityDetailLayoutSection

@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, GXBusinessComponentRelation *> *relationsByDataElementName;

- (instancetype)initWithModel:(id <GXEntityComponentModel>)model
   relationsByDataElementName:(nullable NSDictionary<NSString *, GXBusinessComponentRelation *> *)relationsByDataElementName  NS_DESIGNATED_INITIALIZER;

@end

#pragma mark -

@interface GXEntityDetailLayoutSectionLink : GXEntityDetailLayoutSection

@end

NS_ASSUME_NONNULL_END
