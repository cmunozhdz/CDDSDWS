//
//  GXUserInterfaceContextHelper+GXControl.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 4/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

@import GXObjectsModel;
#import <GXCoreUI/GXUserInterfaceContext+GXControl.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXUserInterfaceContextHelper (GXControl)

+ (GXUserInterfaceContext *)newUserInterfaceContextForControl:(nullable id <GXControlBaseProperties>)control
												   withSender:(nullable id)sender NS_SWIFT_NAME(newUserInterfaceContext(for:withSender:));

+ (nullable id <GXControlBaseProperties>)controlBasePropertiesInContextItems:(GXUserInterfaceContext *)context;
+ (nullable id <GXControlBaseProperties>)controlBasePropertiesInContextItems:(GXUserInterfaceContext *)context filteringUsingPredicate:(nullable NSPredicate *)predicate;
+ (nullable id <GXControlBaseProperties>)controlBasePropertiesInContextItemsFilteringUsingIsValidContextPredicate:(GXUserInterfaceContext *)context;

+ (nullable id <GXControl>)controlInContextItems:(GXUserInterfaceContext *)context;
+ (nullable id <GXControl>)controlInContextItems:(GXUserInterfaceContext *)context filteringUsingPredicate:(nullable NSPredicate *)predicate;
+ (nullable id <GXControl>)controlInContextItemsFilteringUsingIsValidContextPredicate:(GXUserInterfaceContext *)context;

@end

NS_ASSUME_NONNULL_END
