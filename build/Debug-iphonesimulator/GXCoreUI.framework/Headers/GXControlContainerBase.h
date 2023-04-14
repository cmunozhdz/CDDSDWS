//
//  GXControlContainerBase.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 28/07/11.
//  Copyright 2011 Artech. All rights reserved.
//

#if !TARGET_OS_WATCH
#import <GXCoreUI/GXControlAutoHeight.h>
#endif // !TARGET_OS_WATCH
#import <GXCoreUI/GXControlBase.h>
#import <GXCoreUI/GXControlContainer.h>
#if !TARGET_OS_WATCH
#import <GXCoreUI/GXControlWithExpandableBounds.h>
#endif // !TARGET_OS_WATCH

NS_ASSUME_NONNULL_BEGIN

#if !TARGET_OS_WATCH
@interface GXControlContainerBase : GXControlBase <GXControlContainer, GXControlWithActionBarItems, GXControlWithExpandableBounds>
#else
@interface GXControlContainerBase : GXControlBase <GXControlContainer>
#endif // !TARGET_OS_WATCH
{
@protected
	GXControlContainerContext *_context;
@private
    id<GXEntityDataDescriptor> _dataDescriptor;
	GXListSelectionModeType _selectionMode;
	GXBusinessComponentLevel *_businessComponentLevel;
    NSDictionary *_relationsByDataElementName;
}

#if !TARGET_OS_WATCH
- (instancetype)initWithLayoutElement:(id <GXLayoutElement>)layoutElement
					   dataDescriptor:(id<GXEntityDataDescriptor>)dataDescriptor
			   businessComponentLevel:(nullable GXBusinessComponentLevel *)businessComponentLevel
							controlId:(NSUInteger)controlId
							   gxMode:(GXModeType)modeType
						 indexerStack:(nullable NSArray<NSNumber *> *)indexer
						parentControl:(nullable id<GXControlContainer>)parentControl
							relations:(nullable NSDictionary *)relationsByDataElementName NS_DESIGNATED_INITIALIZER;
	
- (instancetype)initWithLayoutElement:(id <GXLayoutElement>)layoutElement
							controlId:(NSUInteger)controlId
							   gxMode:(GXModeType)modeType
						 indexerStack:(nullable NSArray<NSNumber *> *)indexer
						parentControl:(nullable id<GXControlContainer>)parentControl NS_UNAVAILABLE;
#else
- (instancetype)initWithInterfaceObject:(WKInterfaceObject *)interfaceObject
						  layoutElement:(id <GXLayoutElement>)layoutElement
						 dataDescriptor:(id<GXEntityDataDescriptor>)dataDescriptor
				 businessComponentLevel:(nullable GXBusinessComponentLevel *)businessComponentLevel
							  controlId:(NSUInteger)controlId
								 gxMode:(GXModeType)modeType
						   indexerStack:(nullable NSArray<NSNumber *> *)indexer
						  parentControl:(nullable id<GXControlContainer>)parentControl
							  relations:(nullable NSDictionary *)relationsByDataElementName NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithInterfaceObject:(WKInterfaceObject *)interfaceObject
						  layoutElement:(id <GXLayoutElement>)layoutElement
							  controlId:(NSUInteger)controlId
								 gxMode:(GXModeType)modeType
						   indexerStack:(nullable NSArray<NSNumber *> *)indexer
						  parentControl:(nullable id<GXControlContainer>)parentControl NS_UNAVAILABLE;
#endif // !TARGET_OS_WATCH

#pragma mark - Override points for child controls

/**
 * Returns context to be set on child controls
 * Called on setContext:
 * Default implementation returns context
 */
- (nullable GXControlContainerContext *)childrenControlsContextForContext:(nullable GXControlContainerContext *)context;

#pragma mark - GXControlAutoHeightDelegate Helper Methods

#if !TARGET_OS_WATCH
/**
 * Handles child control auto height changed
 * Called on autoHeightChangedForControl:dependency:synchronic: if is not accumulating auto height changes and on commitAccumulatedAutoHeightChangesWithFlags:
 * Default implementations calls setNeedsLayout on controls view it it is loaded
 */
- (void)handleAutoHeightChangedForChildControlWithFlagsDependency:(GXControlAutoHeightDependencyFlags)flags synchronic:(BOOL)sync;

@property(nonatomic, assign, readonly) GXControlAutoHeightDependencyFlags accumulatedAutoHeightDependencyFlags;
- (BOOL)isAccumulatingAutoHeightChanges;

- (void)beginAccumulatingAutoHeightChanges;
- (void)commitAccumulatedAutoHeightChanges;
- (void)commitAccumulatedAutoHeightChangesWithFlags:(GXControlAutoHeightDependencyFlags)accumulatedAutoHeightDependencyFlags;


@property(nonatomic, assign, readonly) GXControlAutoHeightDependencyFlags ignoredAutoHeightDependencyFlags;

- (void)addIgnoredAutoHeightChangesFlags:(GXControlAutoHeightDependencyFlags)flags;
- (void)remoteIgnoredAutoHeightChangesFlags:(GXControlAutoHeightDependencyFlags)flags;
- (void)cleanIgnoredAutoHeightChangesFlags;
#endif // !TARGET_OS_WATCH

@end

@interface GXControlContainerBase (GXControlDelegatesProvider) <GXControlDelegatesProvider>

/*!
 Invalidates child controls delegates
 
 @param options Options to invalidate
 @discussion Called from [self invalidateProviderWithOptions:options].
 Default implementation enumerates existing controls (if options != 0) and calls
 [GXControlHelpers updateControlDelegates:childControl withControlDelegatesProvider:self options:options].
 */
- (void)invalidateChildControlsProviderWithOptions:(GXControlDelegatesProviderInvalidateOptions)options;

@end

@interface GXControlContainerBase (GXControlActionsDispatcher) <GXControlActionsDispatcher>
@end

@interface GXControlContainerBase (GXControlWithEventsDelegate) <GXControlWithEventsDelegate>
@end

#pragma mark - Reuse

#if !TARGET_OS_WATCH
@interface GXControlContainerBaseReuseContext : GXControlBaseReuseContext
@end

@interface GXControlContainerBase (Reuse)

@property(nullable, nonatomic, strong, readonly) GXControlContainerBaseReuseContext *containerReuseContext;

@end
#endif // !TARGET_OS_WATCH

#pragma mark - Expandable Bounds

#if !TARGET_OS_WATCH
@interface GXControlContainerBase (GXControlWithExpandableBounds)

/// Same as [self validatedExpandableEdgeInsets:self.expandableEdgeInsets]
@property(nonatomic, assign, readonly) UIEdgeInsets validatedExpandableEdgeInsets;
/// Returns the given expandable edge insets validated against expandDirection
- (UIEdgeInsets)validatedExpandableEdgeInsets:(UIEdgeInsets)expandableEdgeInsets;

/// Same as [self expandableEdgeInsets:self.expandableEdgeInsets forChildControlsWithViewSize:viewSize contentFrame:contentFrame]
- (UIEdgeInsets)expandableEdgeInsetsForChildControlsWithViewSize:(CGSize)viewSize contentFrame:(CGRect)contentFrame;
/// Returns expandableEdgeInsets for child controls with the given view size and content frame
- (UIEdgeInsets)expandableEdgeInsets:(UIEdgeInsets)expandableEdgeInsets forChildControlsWithViewSize:(CGSize)viewSize contentFrame:(CGRect)contentFrame;
/// Returns expandableEdgeInsets for child controls with the given view size, content frame and contextOptions for additional height calculation
- (UIEdgeInsets)expandableEdgeInsetsForChildControlsWithViewSize:(CGSize)viewSize
													contentFrame:(CGRect)contentFrame
						   additionalHeightToFrameContextOptions:(nullable NSDictionary<NSString *, id> *)contextOptions;

/*!
 Called when expandableEdgeInsets changes.
 
 Default implementation calls setNeedsLayout on loadedView if self.expandableBounds != GXLayoutExpandableBoundsNone
 */
- (void)onExpandableBoundsDidChange:(UIEdgeInsets)oldEdgeInsets;

@end
#endif // !TARGET_OS_WATCH

NS_ASSUME_NONNULL_END
