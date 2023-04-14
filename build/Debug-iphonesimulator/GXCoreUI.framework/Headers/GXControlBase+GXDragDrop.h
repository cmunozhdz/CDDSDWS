//
//  GXControlBase+GXDragDrop.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 2/5/18.
//  Copyright © 2018 GeneXus. All rights reserved.
//

#import <GXCoreUI/GXControlBase.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint_least8_t, GXDragDropState) {
	GXDragDropStateNone,
	GXDragDropStateDragging,
	GXDragDropStateOver,
	GXDragDropStateAcceptDrop,
	GXDragDropStateNoAcceptDrop
};

@interface GXControlBase (GXDragDrop)

@property(nonatomic, assign, readonly) GXDragDropState dragDropState;
@property(nonatomic, assign, readonly, getter=isUnderDragOperation) BOOL underDragOperation; // Helper self.dragDropState == GXDragDropStateDragging

/// Called when dragDropState changes
- (void)onDragDropStateChanged:(GXDragDropState)oldState;

@end

NS_ASSUME_NONNULL_END
