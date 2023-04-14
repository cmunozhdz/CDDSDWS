//
//  GXUserInterfaceContextHelper.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 16/11/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXUserInterfaceContext.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^GXUserInterfaceContextEnumerationBlock)(id <GXUserInterfaceContext> __nonnull, BOOL * __nonnull);

@interface GXUserInterfaceContextHelper : NSObject

/*!
 Tries to match a valid ui element from sender and adds it to the given context (or creates one if nil and needed)
 
 @param sender The object to add to the user interface context
 @param controller The controller which the sender belongs to
 @param uiContext The context to add the sender into (might be nil)
 @result The given uiContext parameter or a new instance if nil and the sender is a valid ui element, nil otherwise
 */
+ (nullable GXUserInterfaceContext *)addSender:(nullable id)sender
				   fromUserInterfaceController:(nullable GXUserInterfaceController *)controller
						toUserInterfaceContext:(nullable GXUserInterfaceContext *)uiContext;

+ (void)executeBlock:(GXUserInterfaceContextEnumerationBlock)block inContextItems:(GXUserInterfaceContext *)context;
+ (void)executeBlock:(GXUserInterfaceContextEnumerationBlock)block inContextItems:(GXUserInterfaceContext *)context filteringUsingPredicate:(nullable NSPredicate *)predicate;
+ (void)executeBlock:(GXUserInterfaceContextEnumerationBlock)block inContextItemsFilteringUsingIsValidContextPredicate:(GXUserInterfaceContext *)context;

+ (void)executeBlocks:(NSArray<GXUserInterfaceContextEnumerationBlock> *)blocks inContextItems:(GXUserInterfaceContext *)context;
+ (void)executeBlocks:(NSArray<GXUserInterfaceContextEnumerationBlock> *)blocks inContextItems:(GXUserInterfaceContext *)context filteringUsingPredicate:(nullable NSPredicate *)predicate;
+ (void)executeBlocks:(NSArray<GXUserInterfaceContextEnumerationBlock> *)blocks inContextItemsFilteringUsingIsValidContextPredicate:(GXUserInterfaceContext *)context;

+ (nullable id)findUIElementFromContext:(GXUserInterfaceContext *)context withPreferredContextPrococols:(NSArray<Protocol *> *)preferredContextProtocols;

@end

NS_ASSUME_NONNULL_END
