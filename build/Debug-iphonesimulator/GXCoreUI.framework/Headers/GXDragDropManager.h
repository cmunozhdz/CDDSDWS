//
//  GXDragDropManager.h
//  GXFlexibleClient
//
//  Created by willy on 3/13/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import GXObjectsModel;
#import <GXCoreUI/GXControl.h>

extern NSString *const GXControlEventNameDrag;
extern NSString *const GXControlEventNameDragOverEnter;
extern NSString *const GXControlEventNameDragOverExit;
extern NSString *const GXControlEventNameDragCanceled;
extern NSString *const GXControlEventNameDrop;
extern NSString *const GXControlEventNameDropAccepted;

typedef NS_ENUM(uint_least8_t, GXDragDropEvent) {
	GXDragDropEventStart,
	GXDragDropEventMove,
	GXDragDropEventEnd,
	GXDragDropEventCancel
};

@interface GXDragDropSignature : NSObject

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithActionParametersDescriptor:(id<GXActionParametersDescriptor>)parametersDescriptor NS_DESIGNATED_INITIALIZER;

- (BOOL)matchSignature:(GXDragDropSignature *)signature;

@end

@interface GXDragDropData : NSObject

@property(nonatomic, strong, readonly) id object;
@property(nonatomic, strong, readonly) GXDragDropSignature *signature;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithObject:(id)object signature:(GXDragDropSignature *)signature NS_DESIGNATED_INITIALIZER;

@end

@protocol GXDragableControl <GXControl>

- (void)dragableControlOnDropAccepted:(GXDragDropData *)data;
- (void)dragableControlOnDropCancelled:(GXDragDropData *)data;
- (void)setUnderDragOperation:(BOOL)underDragOperation;

@optional
- (UIView *)dragableControlView;

@end

@protocol GXDropTargetControl<GXControl>

- (BOOL)dropTargetControlOnDragDrop:(GXDragDropData *)data;
- (void)dropTargetControlOnDragOverEnter:(GXDragDropData *)data;
- (void)dropTargetControlOnDragOverExit:(GXDragDropData *)data;
- (void)dropTargetControlOnDragStart:(GXDragDropData *)data;
- (void)dropTargetControlOnDragCancelled:(GXDragDropData *)data;

@end

@interface GXDragDropManager : NSObject

+ (GXDragDropManager *)sharedManager;

- (void)dragDropEvent:(GXDragDropEvent)event gxControl:(id<GXDragableControl>)gxControl atWindowPoint:(CGPoint)windowPoint;
- (void)dragStart:(id<GXDragableControl>)gxControl atPoint:(CGPoint)windowPoint data:(GXDragDropData *)data;
- (void)addDropTargetControl:(id<GXDropTargetControl>)gxControl;
- (void)removeDropTargetControl:(id<GXDropTargetControl>)gxControl;

@end
