//
//  GXWorkWithDetail.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 10/12/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXWorkWithData.h>
#import <GXObjectsModel/GXWorkWithLayout.h>
#import <GXObjectsModel/GXWorkWithLayoutsManager.h>
#import <GXObjectsModel/GXWorkWithPanelBase.h>
#import <GXObjectsModel/GXWorkWithSections.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXWorkWithDetail : GXWorkWithPanelBase

@property(nullable, nonatomic, strong, readonly) GXWorkWithSections *sections;

@property(nullable, nonatomic, strong, readonly) NSString *bcName;

- (instancetype)initWithCaption:(nullable NSString *)caption
					 parameters:(nullable GXWorkWithParameters *)parameters
			   dataProviderName:(nullable NSString *)dataProviderName
						   data:(nullable NSArray<GXWorkWithData *> *)data
				 layoutsManager:(nullable GXWorkWithLayoutsManager *)layoutsManager
					   sections:(nullable GXWorkWithSections *)sections
						actions:(nullable GXWorkWithActions *)actions
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

- (nullable GXWorkWithData *)workWithDataForName:(NSString *)name; // lookInSections:YES
- (nullable GXWorkWithData *)workWithDataForName:(NSString *)name lookInSections:(BOOL)recursive;

@end

NS_ASSUME_NONNULL_END
