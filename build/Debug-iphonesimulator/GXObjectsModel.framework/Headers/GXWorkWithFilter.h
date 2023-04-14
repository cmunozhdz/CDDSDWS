//
//  GXWorkWithFilter.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 10/12/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXNamedElement.h>
#import <GXObjectsModel/GXWorkWithFilterSearch.h>
#import <GXObjectsModel/GXWorkWithFilterAdvanced.h>
#import <GXObjectsModel/GXNamedModelObjectChild.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXWorkWithFilter : GXNamedModelObjectChild

@property(nullable, nonatomic, strong, readonly) GXWorkWithFilterSearch *search;
@property(nullable, nonatomic, strong, readonly) GXWorkWithFilterAdvanced *advanced;

- (instancetype)initWithName:(nullable NSString *)name
					  search:(nullable GXWorkWithFilterSearch *)search
					advanced:(nullable GXWorkWithFilterAdvanced *)advanced
			  forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
