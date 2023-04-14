//
//  GXWorkWithLayoutElementTabs.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 19/04/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

#import <GXObjectsModel/GXWorkWithLayoutElementContainer.h>
#import <GXObjectsModel/GXWorkWithLayoutElementTab.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXWorkWithLayoutElementTabs : GXWorkWithLayoutElementContainer <GXLayoutElementTabs>

@property(nonatomic, strong, readonly) NSArray<GXWorkWithLayoutElementTab *> *tabs;

@end

NS_ASSUME_NONNULL_END
