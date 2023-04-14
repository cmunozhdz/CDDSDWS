//
//  GXWorkWithLayoutElementGroup.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 19/04/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

#import <GXObjectsModel/GXWorkWithLayoutElement.h>
#import <GXObjectsModel/GXWorkWithLayoutElementTable.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXWorkWithLayoutElementGroup : GXWorkWithLayoutElement <GXLayoutElementGroup>

@property(nullable, nonatomic, strong, readonly) NSString *translatedCaption;
@property(nonatomic, strong, readonly) GXWorkWithLayoutElementTable *groupElement;
@property(assign, readonly) BOOL autoGrow;

@end

NS_ASSUME_NONNULL_END
