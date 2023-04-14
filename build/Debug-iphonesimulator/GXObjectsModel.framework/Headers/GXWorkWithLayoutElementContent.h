//
//  GXWorkWithLayoutElementContent.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 19/04/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

#import <GXObjectsModel/GXWorkWithLayoutElement.h>

NS_ASSUME_NONNULL_BEGIN

@class GXWorkWithLayoutElementContentWithAutoGrow;

@interface GXWorkWithLayoutElementContent : GXWorkWithLayoutElement <GXLayoutElementContent>

+ (GXWorkWithLayoutElementContent *)defaultLinkWorkWithLayoutElementContentWithComponenet:(nullable NSString *)component
																		   forModelObject:(nullable id<GXModelObject, NSCoding>)modelObject;
+ (GXWorkWithLayoutElementContentWithAutoGrow *)defaultInlineWorkWithLayoutElementContentWithComponenet:(nullable NSString *)component
																						 forModelObject:(nullable id<GXModelObject, NSCoding>)modelObject;

@end


@interface GXWorkWithLayoutElementContentWithAutoGrow : GXWorkWithLayoutElementContent <GXLayoutElementContent, GXLayoutElementWithAutoGrow>

@property(assign, readonly) BOOL autoGrow;

@end

NS_ASSUME_NONNULL_END
