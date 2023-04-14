//
//  GXEntityActionBarItemActionReference.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 09/11/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import GXObjectsModel;
#import <GXCoreUI/GXEntityModelProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXEntityActionBarItemReference : NSObject <GXNamedControlElement>

@property(nonatomic, strong, readonly) id<GXEntityModel> entityModel;
@property(nonatomic, strong, readonly) id<GXLayoutActionBarItem> layoutElement;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithLayoutActionBarItem:(id<GXLayoutActionBarItem>)layoutElement
								entityModel:(id<GXEntityModel>)entityModel NS_DESIGNATED_INITIALIZER;

@end

@interface GXEntityActionBarItemActionReference : GXEntityActionBarItemReference

@property(nullable, nonatomic, strong, readonly) id<GXActionDescriptor> actionDescriptor;
@property(nonatomic, strong, readonly) id<GXLayoutActionBarActionItem> layoutActionBarActionItem;

@end

@interface GXEntityActionBarItemGroupReference : GXEntityActionBarItemReference

@property(nonatomic, strong, readonly) id<GXLayoutActionBarGroupItem> layoutActionGroupActionItem;

@end

@interface GXEntityActionBarItemDataReference : GXEntityActionBarItemReference 

@end

NS_ASSUME_NONNULL_END
