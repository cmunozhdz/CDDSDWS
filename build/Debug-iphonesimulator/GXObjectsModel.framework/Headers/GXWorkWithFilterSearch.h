//
//  GXWorkWithFilterSearch.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 10/12/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXWorkWithFilterSearchField.h>
#import <GXObjectsModel/GXEntityListFilterSearchProtocol.h>
#import <GXObjectsModel/GXModelObjectChild.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXWorkWithFilterSearch : GXModelObjectChild <NSCoding, GXEntityListFilterSearch>

@property(nullable, nonatomic, strong, readonly) NSString *caption;
@property(assign, readonly) BOOL allowIndividualFilter;
@property(nonatomic, strong, readonly) NSArray<__kindof GXWorkWithFilterSearchField *> *fields;
@property(assign, readonly) GXEntityListFilterSearchOperator filterOperator;
@property(assign, readonly) BOOL caseSensitive;
@property(assign, readonly) BOOL alwaysVisible;

- (instancetype)initWithCaption:(nullable NSString *)caption
		  allowIndividualFilter:(BOOL)allowIndividualFilter
						 fields:(NSArray<__kindof GXWorkWithFilterSearchField *> *)fields
				 filterOperator:(GXEntityListFilterSearchOperator)filterOperator
				  caseSensitive:(BOOL)caseSensitive
				  alwaysVisible:(BOOL)alwaysVisible
				breakByBehavior:(GXEntityListFilterSearchBreakByBehavior)breakByBehavior
				 forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithModelObject:(nullable id<GXModelObject>)modelObject NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
