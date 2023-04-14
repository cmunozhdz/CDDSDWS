//
//  GXWorkWithLayoutElementCell.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 19/04/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

#import <GXObjectsModel/GXWorkWithLayoutElement.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXWorkWithLayoutElementCell : GXWorkWithLayoutElement <GXLayoutElementCell>

@property(nullable, nonatomic, strong, readonly) GXWorkWithLayoutElement *cellElement;
@property(nullable, nonatomic, strong, readonly) GXLayoutRectangle *rectangle;
@property(assign, readonly) GXHorizontalAlignType hAlign;
@property(assign, readonly) GXVerticalAlignType vAlign;

+ (nullable instancetype)layoutElementCellWithElement:(nullable GXWorkWithLayoutElement *)cellElement
									   forModelObject:(nullable id<GXModelObject>)modelObject;

@end

NS_ASSUME_NONNULL_END
