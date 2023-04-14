//
//  GXWorkWithLayoutActionBarItem.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 18/01/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXLayoutProtocol.h>
#import <GXObjectsModel/GXWorkWithLayoutActionBar.h>
#import <GXObjectsModel/GXModelObjectChild.h>

@class GXWorkWithLayoutActionBar;

NS_ASSUME_NONNULL_BEGIN

@interface GXWorkWithLayoutActionBarItem : GXModelObjectChild <NSCoding, GXLayoutActionBarItem>

- (instancetype)initWithControlName:(NSString *)controlName
						   position:(id<GXActionBarUIPositionDescriptor, NSCoding>)position
					 forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithModelObject:(nullable id<GXModelObject>)modelObject NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

@interface GXWorkWithLayoutActionBarItemWithBaseUIAction : GXWorkWithLayoutActionBarItem <GXActionUIBaseDescriptor>

- (instancetype)initWithControlName:(NSString *)controlName
						   position:(id<GXActionBarUIPositionDescriptor, NSCoding>)position
					 themeClassName:(nullable NSString *)themeClassName
							visible:(BOOL)visible
							enabled:(BOOL)enabled
					 forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

@interface GXWorkWithLayoutActionBarItemWithUIAction : GXWorkWithLayoutActionBarItemWithBaseUIAction <GXActionUIDescriptor>

- (instancetype)initWithControlName:(NSString *)controlName
						   position:(id<GXActionBarUIPositionDescriptor, NSCoding>)position
							caption:(nullable NSString *)caption
						  imageName:(nullable NSString *)imageName
				  disabledImageName:(nullable NSString *)disabledImageName
					  imagePosition:(GXActionUIImagePosition)imagePosition
					 themeClassName:(nullable NSString *)themeClassName
							visible:(BOOL)visible
							enabled:(BOOL)enabled
					 forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

@interface GXWorkWithLayoutActionBarActionItem : GXWorkWithLayoutActionBarItemWithUIAction <GXLayoutActionBarActionItem>

- (instancetype)initWithEventDescriptor:(id <GXEventDescriptor>)eventDesc
							controlName:(NSString *)controlName
							   position:(id<GXActionBarUIPositionDescriptor, NSCoding>)position
								caption:(nullable NSString *)caption
							  imageName:(nullable NSString *)imageName
					  disabledImageName:(nullable NSString *)disabledImageName
						  imagePosition:(GXActionUIImagePosition)imagePosition
						 themeClassName:(nullable NSString *)themeClassName
								visible:(BOOL)visible
								enabled:(BOOL)enabled
						 forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithControlName:(NSString *)controlName
						   position:(id<GXActionBarUIPositionDescriptor, NSCoding>)position
							caption:(nullable NSString *)caption
						  imageName:(nullable NSString *)imageName
				  disabledImageName:(nullable NSString *)disabledImageName
					  imagePosition:(GXActionUIImagePosition)imagePosition
					 themeClassName:(nullable NSString *)themeClassName
							visible:(BOOL)visible
							enabled:(BOOL)enabled
					 forModelObject:(nullable id<GXModelObject>)modelObject NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

@interface GXWorkWithLayoutActionBarDataItem : GXWorkWithLayoutActionBarItemWithBaseUIAction <GXLayoutActionBarDataItem>

- (instancetype)initWithDataElement:(id <GXLayoutElementData>)dataElement
						controlName:(NSString *)controlName
						   position:(id<GXActionBarUIPositionDescriptor, NSCoding>)position
					 themeClassName:(nullable NSString *)themeClassName
							visible:(BOOL)visible
							enabled:(BOOL)enabled
					 forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithControlName:(NSString *)controlName
						   position:(id<GXActionBarUIPositionDescriptor, NSCoding>)position NS_UNAVAILABLE;
- (instancetype)initWithControlName:(NSString *)controlName
						   position:(id<GXActionBarUIPositionDescriptor, NSCoding>)position
					 themeClassName:(nullable NSString *)themeClassName
							visible:(BOOL)visible
							enabled:(BOOL)enabled
					 forModelObject:(nullable id<GXModelObject>)modelObject NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

@interface GXWorkWithLayoutActionBarGroupItem : GXWorkWithLayoutActionBarItemWithUIAction <GXLayoutActionBarGroupItem>

- (instancetype)initWithActionBarGroup:(GXWorkWithLayoutActionBar *)actionBarGroup
						   controlName:(NSString *)controlName
							  position:(id<GXActionBarUIPositionDescriptor, NSCoding>)position
							   caption:(nullable NSString *)caption
							 imageName:(nullable NSString *)imageName
					 disabledImageName:(nullable NSString *)disabledImageName
						 imagePosition:(GXActionUIImagePosition)imagePosition
						themeClassName:(nullable NSString *)themeClassName
							   visible:(BOOL)visible
							   enabled:(BOOL)enabled
						forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithControlName:(NSString *)controlName
						   position:(id<GXActionBarUIPositionDescriptor, NSCoding>)position
							caption:(nullable NSString *)caption
						  imageName:(nullable NSString *)imageName
				  disabledImageName:(nullable NSString *)disabledImageName
					  imagePosition:(GXActionUIImagePosition)imagePosition
					 themeClassName:(nullable NSString *)themeClassName
							visible:(BOOL)visible
							enabled:(BOOL)enabled
					 forModelObject:(nullable id<GXModelObject>)modelObject NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
