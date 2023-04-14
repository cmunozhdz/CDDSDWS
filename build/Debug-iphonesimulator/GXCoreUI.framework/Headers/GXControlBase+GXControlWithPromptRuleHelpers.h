//
//  GXControlBase+GXControlWithPromptRuleHelpers.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 6/8/15.
//  Copyright (c) 2015 Artech. All rights reserved.
//

#import <GXCoreUI/GXControlBase.h>
#import <GXCoreUI/GXControlWithPromptRule.h>
#import <GXCoreUI/GXControlWithDataEditable.h>

extern NSString *const GXControlBaseWithPromptRuleUserActionIdentifierPromptRule;

@interface GXControlBase (GXControlWithPromptRuleHelpers)

+ (void)onControlBaseWithPrompt:(GXControlBase<GXControlWithPromptRule> *)control ruleChanged:(id <GXEntityRulePrompt>)oldRulePrompt;
+ (void)onControlBaseWithDataWithPrompt:(GXControlBase<GXControlWithData, GXControlWithPromptRule> *)control modeChanged:(GXModeType)oldMode;
+ (void)onControlBaseWithDataEditableWithPromptReadonlyChanged:(GXControlBase<GXControlWithDataEditable, GXControlWithPromptRule> *)control;

+ (BOOL)controlBaseWithPromptCanHandlePrompt:(id <GXControlWithPromptRule>)control;
+ (BOOL)controlBaseWithPromptHandlePrompt:(id <GXControlWithPromptRule>)control withSender:(id)sender;

@end
