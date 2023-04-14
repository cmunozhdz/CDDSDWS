//
//  GXWorkWithLayoutElementRow.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 19/04/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

#import <GXObjectsModel/GXWorkWithLayoutElementContainer.h>
#import <GXObjectsModel/GXWorkWithLayoutElementCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXWorkWithLayoutElementRow : GXWorkWithLayoutElementContainer <GXLayoutElementRow>

@property(assign, readonly) GXHorizontalAlignType hAlign;
@property(assign, readonly) GXVerticalAlignType vAlign;

+ (nullable instancetype)layoutElementRowWithOneCellElement:(nullable GXWorkWithLayoutElement *)cellElement
											 forModelObject:(nullable id<GXModelObject>)modelObject;

@end

NS_ASSUME_NONNULL_END
