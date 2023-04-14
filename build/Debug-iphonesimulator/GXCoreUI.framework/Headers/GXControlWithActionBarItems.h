//
//  GXControlWithActionBarItems.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 12/01/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

#import <GXCoreUI/GXControl.h>
#import <GXCoreUI/GXControlActionBarItem.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXControlActionBarItem;
@protocol GXControlWithActionBarItemsDelegate;

typedef NS_OPTIONS(uint_least8_t, GXControlWithActionBarItemsEnumerationOptions) {
	GXControlWithActionBarItems_None = 0,
	GXControlWithActionBarItems_ExistingOnly = 1 << 0,	// User to avoid child controls creation
	GXControlWithActionBarItems_VisibleOnly = 1 << 1,
	GXControlWithActionBarItems_CurrentComponentOnly = 1 << 2,
};

@protocol GXControlWithActionBarItems <GXControl>

@property(nullable, nonatomic, weak) id<GXControlWithActionBarItemsDelegate> controlWithActionBarItemsDelegate;

@property(nullable, nonatomic, strong, readonly) NSArray<id<GXControlActionBarItem>> *controlActionBarItems;

- (void)enumerateControlActionBarItemsWithBlock:(void (^)(id <GXControlActionBarItem> item, BOOL *stop))block options:(GXControlWithActionBarItemsEnumerationOptions)options;

@end

#pragma mark -

@protocol GXControlWithActionBarItemsDelegate <NSObject>

/// The control should call this method if it needs to refresh the actions
- (void)controlWithActionBarItemsNeedsReloadActions:(id<GXControlWithActionBarItems>)control;
/// The control should call this method if it needs to refresh the actions with explicit animated transition
- (void)controlWithActionBarItemsNeedsReloadActions:(id<GXControlWithActionBarItems>)control animated:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END
