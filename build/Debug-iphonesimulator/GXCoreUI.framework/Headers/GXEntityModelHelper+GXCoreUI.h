//
//  GXEntityModelHelper+GXCoreUI.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 23/12/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import GXObjectsModel;
@import GXCoreBL;
#import <GXCoreUI/GXEntityModelProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXEntityModelHelper (GXCoreUI)

+ (BOOL)isAppEntryPoint:(GXApplicationModel *)appModel sdObjectLocator:(id<GXSDObjectLocator>)sdObjectLocator;

+ (nullable id <GXEntityModel>)entityModelForWorkWithComponent:(GXWorkWithDetail *)wwComponent
									conectivitySupportResolver:(nullable id <GXInheritedConnectivitySupportResolver>)connSupportResolver;

+ (nullable GXWorkWithModel *)workWithModelFromPromptRule:(id <GXEntityRulePrompt>)promptRule;
	
+ (nullable id <GXParametersDescriptor>)promptParametersFromPromptRule:(id <GXEntityRulePrompt>)promptRule;

+ (NSDictionary<GXActionHandlerUserInfoKey,id> *)newActionHandlerUserInfoForEntityModel:(id<GXEntityModel>)entityModel;

@end

NS_ASSUME_NONNULL_END
