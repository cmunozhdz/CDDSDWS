//
//  GXControlMultilineSelectionGridBase.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 21/02/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

#import <GXCoreUI/GXControlGridBaseWithSelection.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXControlMultilineSelectionGridBase : GXControlGridBaseWithSelection <GXControlGridWithMultilineSelection>

- (BOOL)multilineSelectedEntitiesDataAreFiltered;

// Abstract

/*!
 Called on setMultilineSelectorsVisible:animated: if visible changed
 
 @param animated YES if the change was animated and NO if it was immediate.
 @discussion Override this method to apply user interface changes. Do not call super, as this method is abstract.
 */
- (void)onMultilineSelectorsVisibleChanged:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END
