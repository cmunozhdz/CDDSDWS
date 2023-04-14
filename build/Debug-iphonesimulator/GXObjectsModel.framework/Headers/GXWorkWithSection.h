//
//  GXWorkWithSection.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 11/12/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXWorkWithData.h>
#import <GXObjectsModel/GXWorkWithLayout.h>
#import <GXObjectsModel/GXWorkWithPanelBase.h>
#import <GXObjectsModel/GXWorkWithParameters.h>

NS_ASSUME_NONNULL_BEGIN

@class GXWorkWithDetail;
@class GXWorkWithSections;

@interface GXWorkWithSection : GXWorkWithPanelBase

@property(nullable, nonatomic, weak, readonly) GXWorkWithDetail *workWithDetail;
@property(nullable, nonatomic, weak, readonly) GXWorkWithSections *workWithSections;

@property(nullable, nonatomic, strong, readonly) id <GXEventDescriptor> defaultEventDescriptor;

@property(nullable, nonatomic, strong, readonly) NSString *businessComponentName;
@property(nullable, nonatomic, strong, readonly) NSString *businessComponentLevel;

@property(nullable, nonatomic, strong, readonly) NSString *linkClassFullName;
@property(nullable, nonatomic, strong, readonly) NSString *selectedImageName;
@property(nullable, nonatomic, strong, readonly) NSString *unselectedImageName;

@property(nonatomic, strong, readonly) NSString *name;

- (instancetype)initWithName:(NSString *)name
					 caption:(nullable NSString *)caption
			dataProviderName:(nullable NSString *)dataProviderName
				  parameters:(nullable GXWorkWithParameters *)parameters
						data:(nullable NSArray<GXWorkWithData *> *)data
			  layoutsManager:(nullable GXWorkWithLayoutsManager *)layoutsManager
					 actions:(nullable GXWorkWithActions *)actions
		   defaultActionName:(nullable NSString *)defaultActionName
				   linkClass:(nullable NSString *)linkClass
		   selectedImageName:(nullable NSString *)selectedImageName
		 unselectedImageName:(nullable NSString *)unselectedImageName
					   rules:(nullable GXWorkWithRules *)rules NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithCaption:(nullable NSString *)caption
			   dataProviderName:(nullable NSString *)dpName
						   data:(nullable NSArray<GXWorkWithData *> *)data
					 parameters:(nullable GXWorkWithParameters *)parameters
				 layoutsManager:(nullable GXWorkWithLayoutsManager *)layoutsManager
						actions:(nullable GXWorkWithActions *)actions
						  rules:(nullable GXWorkWithRules *)rules NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

- (nullable GXWorkWithData *)workWithDataForName:(NSString *)name;

@end

NS_ASSUME_NONNULL_END
