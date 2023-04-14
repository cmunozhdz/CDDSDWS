//
//  GXControlWithPromptRule.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 3/13/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import GXObjectsModel;
#import <GXCoreUI/GXControl.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXControlWithPromptRule;

@protocol GXControlWithPromptRuleEventsDelegate <NSObject>

- (void)handlePromptForControl:(id <GXControlWithPromptRule>)sender;

@end

#pragma mark -

@protocol GXControlWithPromptRule <GXControl>

@property(nullable, nonatomic, strong) id <GXEntityRulePrompt> controlWithPromptRulePromptRule;
@property(nullable, nonatomic, strong, readonly) id<GXEntityDataWithOverrideValues> controlWithPromptRulePromptEntityData;

@property(nullable, nonatomic, weak) id<GXControlWithPromptRuleEventsDelegate> controlWithPromptRuleEventsDelegate;

@end

NS_ASSUME_NONNULL_END
