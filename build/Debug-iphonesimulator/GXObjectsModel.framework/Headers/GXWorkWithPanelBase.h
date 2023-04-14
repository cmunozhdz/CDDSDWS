//
//  GXWorkWithPanelBase.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 30/12/11.
//  Copyright (c) 2011 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXWorkWithActions.h>
#import <GXObjectsModel/GXWorkWithData.h>
#import <GXObjectsModel/GXWorkWithLayout.h>
#import <GXObjectsModel/GXWorkWithLayoutsManager.h>
#import <GXObjectsModel/GXWorkWithParameters.h>
#import <GXObjectsModel/GXWorkWithRules.h>

NS_ASSUME_NONNULL_BEGIN

@class GXWorkWithModel;
@class GXWorkWithLevel;

@interface GXWorkWithPanelBase : NSObject <NSCoding>

@property(nullable, nonatomic, weak, readonly) GXWorkWithModel *workWithModel; // ABSTRACT
@property(nullable, nonatomic, weak, readonly) GXWorkWithLevel *workWithLevel; // ABSTRACT

@property(nullable, nonatomic, strong, readonly) NSString *caption;
@property(nullable, nonatomic, strong, readonly) NSString *dataProviderName;
@property(nonatomic, strong, readonly) NSArray<GXWorkWithData *> *data;
@property(nullable, nonatomic, strong, readonly) GXWorkWithParameters *parameters;
@property(nullable, nonatomic, strong, readonly) GXWorkWithLayoutsManager *layoutsManager;
@property(nullable, nonatomic, strong, readonly) GXWorkWithActions *actions;
@property(nullable, nonatomic, strong, readonly) GXWorkWithRules *rules;

- (instancetype)initWithCaption:(nullable NSString *)caption
			   dataProviderName:(nullable NSString *)dpName
						   data:(nullable NSArray<GXWorkWithData *> *)data
					 parameters:(nullable GXWorkWithParameters *)parameters
				 layoutsManager:(nullable GXWorkWithLayoutsManager *)layoutsManager
						actions:(nullable GXWorkWithActions *)actions
						  rules:(nullable GXWorkWithRules *)rules NS_DESIGNATED_INITIALIZER;

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

#if TARGET_OS_IOS
- (nullable GXWorkWithLayout *)layoutForOrientation:(UIInterfaceOrientation)orientation mode:(GXModeType)mode;
#else
- (nullable GXWorkWithLayout *)layoutForMode:(GXModeType)mode;
#endif // TARGET_OS_IOS

@end

NS_ASSUME_NONNULL_END
