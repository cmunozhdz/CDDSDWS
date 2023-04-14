//
//  GXWorkWithLayoutElementTable.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 19/04/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

#import <GXObjectsModel/GXWorkWithLayoutElementContainer.h>
#import <GXObjectsModel/GXWorkWithLayoutElementRow.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXWorkWithLayoutElementTable : GXWorkWithLayoutElementContainer <GXLayoutElementTable>

@property(assign, readonly) GXHorizontalAlignType hAlign;
@property(assign, readonly) GXVerticalAlignType vAlign;
@property(nonatomic, readonly) BOOL autoGrow;
@property(nullable, nonatomic, strong, readonly) NSString *backgourndImageName;
@property(nonatomic, assign, readonly) CGFloat scrollFactor;
@property(nonatomic, assign, readonly) CGFloat zoomFactor;
@property(nullable, nonatomic, strong, readonly) NSString *scrollAttachment; // Nil means attached to parent
@property(nullable, nonatomic, strong, readonly) NSString *tableId;

+ (GXWorkWithLayoutElementTable *)layoutElementTableWithOneCellElement:(GXWorkWithLayoutElement *)cellElement
														 classFullName:(nullable NSString *)className
														forModelObject:(nullable id<GXModelObject, NSCoding>)modelObject;

@end

NS_ASSUME_NONNULL_END
