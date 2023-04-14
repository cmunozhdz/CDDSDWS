//
//  GXWorkWithLayoutActionBar.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 31/05/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXLayoutProtocol.h>
#import <GXObjectsModel/GXWorkWithLayoutActionBarItem.h>
#import <GXObjectsModel/GXModelObjectChild.h>

@class GXWorkWithLayoutActionBarItem;

NS_ASSUME_NONNULL_BEGIN

@interface GXWorkWithLayoutActionBar : GXModelObjectChild <GXLayoutActionBar>

- (instancetype)initWithActionBarItems:(nullable NSArray<__kindof GXWorkWithLayoutActionBarItem *> *)actionBarItems
						   controlName:(nullable NSString *)controlName
						   controlType:(nullable NSString *)controlType
				   showApplicationBars:(BOOL)showAppBars
				  applicationBarsClass:(nullable NSString *)appBarsClass
						forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
