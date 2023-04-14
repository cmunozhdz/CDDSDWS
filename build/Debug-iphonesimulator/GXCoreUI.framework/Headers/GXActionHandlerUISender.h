//
//  GXActionHandlerUISender.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 3/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

@import GXObjectsModel;
@import GXCoreBL;

NS_ASSUME_NONNULL_BEGIN

@interface GXActionHandlerUISender : GXActionHandlerSender <GXActionUISender>

- (instancetype)initWithUserInterfaceContext:(nullable GXUserInterfaceContext *)uiContext NS_DESIGNATED_INITIALIZER;

@end

@interface GXActionHandlerUISenderWrapper : NSObject <GXActionUISender>

@property(nonatomic, strong, readonly) id<GXActionSender> innerActionSender;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithActionSender:(id<GXActionSender>)actionSender NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
