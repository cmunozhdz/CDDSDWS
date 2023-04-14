//
//  GXWorkWithLayout.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 11/12/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXLayoutProtocol.h>
#import <GXObjectsModel/GXWorkWithLayoutActionBar.h>
#import <GXObjectsModel/GXWorkWithLayoutElements.h>
#import <GXObjectsModel/GXModelObjectChild.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXWorkWithLayout : GXModelObjectChild <GXLayout>

@property(nullable, nonatomic, strong, readonly) GXWorkWithLayoutElement *rootElement;
@property(nullable, nonatomic, strong, readonly) GXWorkWithLayoutActionBar *actionBar;
@property(nullable, nonatomic, strong, readonly) NSArray<GXWorkWithLayoutActionBar *> *actionGroups;

- (instancetype)initWithLayoutType:(GXLayoutType)layoutType
					   rootElement:(nullable GXWorkWithLayoutElement *)rootElement
					   controlType:(nullable NSString *)controlType
		   controlCustomProperties:(nullable NSDictionary<NSString *, id> *)controlCustomProperties
						 actionBar:(nullable GXWorkWithLayoutActionBar *)actionBar
					  actionGroups:(nullable NSArray<GXWorkWithLayoutActionBar *> *)actionGroups
					styleClassName:(nullable NSString *)styleClassName
						  layoutId:(nullable NSString *)layoutId
#if TARGET_OS_WATCH
					layoutPlatform:(nullable NSString *)layoutPlatform
#endif // TARGET_OS_WATCH
					forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithModelObject:(nullable id<GXModelObject>)modelObject NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
