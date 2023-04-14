//
//  GXMultilineActionHandlerProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 19/11/15.
//  Copyright © 2015 Artech. All rights reserved.
//

#import <GXObjectsModel/GXActionHandlerProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXMultilineActionHandler <GXActionHandler>

@property(nonatomic, strong, readonly) id <GXMultilineActionDescriptor> multilineActionDescriptor;
/**
 * Continues execition of action if the given collection of id <GXEntityData> corresponding
 * to [self multilineActionDescriptor] actionMultilineIterationType in actionMultilineGridControlName
 */
- (void)continueExecutingActionWithEntities:(nullable NSArray<id <GXEntityData>> *)items;

@end

NS_ASSUME_NONNULL_END
