//
//  GXControlWithEvents.h
//  GXFlexibleClient
//
//  Created by willy on 5/26/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import GXObjectsModel;
#import <GXCoreUI/GXControl.h>
#if TARGET_OS_WATCH
#import <GXCoreUI/GXControlWithActionSelectors.h>
#endif // TARGET_OS_WATCH
#import <GXCoreUI/GXControlWithPromptRule.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXControlWithEvents;

@protocol GXControlWithEventsDelegate <NSObject>

- (void)handleControlEvent:(id <GXControlWithEvents>)sender userInterfaceContext:(nullable GXUserInterfaceContext *)uiContext;

@end

#if !TARGET_OS_WATCH
@protocol GXControlWithEvents <GXControl, GXControlWithPromptRule>
#else
@protocol GXControlWithEvents <GXControl, GXControlWithPromptRule, GXControlWithActionSelector>
#endif // !TARGET_OS_WATCH

@property (nullable, nonatomic, weak) id<GXControlWithEventsDelegate> controlWithEventsDelegate;
@property (nonatomic, strong, readonly) id <GXActionDescriptor> controlWithEventsActionDescriptor;

- (void)setCaption:(nullable NSString *)caption;

@end

NS_ASSUME_NONNULL_END
