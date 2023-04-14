//
//  GXEntityListFilterSearchProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 21/12/10.
//  Copyright 2010 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXEntityDataFieldDescriptorProtocol.h>
#import <GXObjectsModel/GXModelObjectProtocol.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint_least8_t, GXEntityListFilterSearchOperator) {
	GXEntityListFilterSearchOperatorContains,
	GXEntityListFilterSearchOperatorBeginsWith
};

typedef NS_ENUM(uint_least8_t, GXEntityListFilterSearchBreakByBehavior) {
	GXEntityListFilterSearchBreakByBehaviorDisabled,
	GXEntityListFilterSearchBreakByBehaviorUseOrdersBreakBy
};

@protocol GXEntityListFilterSearchField;

@protocol GXEntityListFilterSearch <NSObject, GXModelObject>

@property(nonatomic, strong, readonly) NSArray<id<GXEntityListFilterSearchField>> *entityListFilterSearchFields;
@property(nonatomic, assign, readonly) GXEntityListFilterSearchOperator entityListFilterSearchOperator;
@property(nonatomic, assign, readonly) BOOL entityListFilterSearchCaseSensitive;
@property(nullable, nonatomic, strong, readonly) NSString *entityListFilterSearchCaption;
@property(nonatomic, assign, readonly) BOOL entityListFilterSearchAllowIndividualField;
@property(nonatomic, assign, readonly) BOOL entityListFilterSearchAlwaysVisible;
@property(nonatomic, assign, readonly) GXEntityListFilterSearchBreakByBehavior entityListFilterSearchBreakByBehavior;

@end



@protocol GXEntityListFilterSearchField <GXEntityDataFieldDescriptor>

@property(nonatomic, strong, readonly) NSString *entityListFilterSearchFieldDescription;

@end

NS_ASSUME_NONNULL_END
