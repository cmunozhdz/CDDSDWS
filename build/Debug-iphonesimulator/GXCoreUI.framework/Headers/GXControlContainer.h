//
//  GXControlContainer.h
//  GXFlexibleClient
//
//  Created by willy on 6/29/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import GXObjectsModel;
#import <GXCoreUI/GXActionControllerDelegateProtocol.h>
#import <GXCoreUI/GXControl.h>
#if !TARGET_OS_WATCH
#import <GXCoreUI/GXControlAutoHeight.h>
#import <GXCoreUI/GXControlScrollIntoViewTypes.h>
#endif // !TARGET_OS_WATCH
#import <GXCoreUI/GXControlContainerContext.h>
#import <GXCoreUI/GXControlContainerLoadOptions.h>
#import <GXCoreUI/GXControlWithData.h>
#import <GXCoreUI/GXControlWithEvents.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXEntityDetailLayoutSectionProvider;
@protocol GXControlComponentDelegate;
@protocol GXControlContainerWithDataProviderDelegate;
@protocol GXControlDelegatesProvider;
@protocol GXControlGrid;
@protocol GXControlSection;
#if !TARGET_OS_WATCH
@protocol GXControlWithActionBarItemsDelegate;
#endif // !TARGET_OS_WATCH
@class GXControlContainerContext;

typedef NS_OPTIONS(uint_least8_t, GXControlContainerChildControlsEnumerationOptions) {
	GXControlContainerChildControlsEnumeration_None = 0,
	GXControlContainerChildControlsEnumeration_ExistingControlsOnly = 1 << 0,	// User to avoid child controls creation
	GXControlContainerChildControlsEnumeration_VisibleControlsOnly = 1 << 1,
};

typedef NS_OPTIONS(NSUInteger, GXControlDelegatesProviderInvalidateOptions) {
	GXControlDelegatesProviderInvalidateOption_ActionControllerDelegate = 1 << 0,
	GXControlDelegatesProviderInvalidateOption_ControlWithDataEventsDelegate = 1 << 1,
	GXControlDelegatesProviderInvalidateOption_ControlWithPromptRuleEventsDelegate = 1 << 2,
	GXControlDelegatesProviderInvalidateOption_EntityDetailLayoutSectionProvider = 1 << 3,
	GXControlDelegatesProviderInvalidateOption_ControlContainerWithDataProvider = 1 << 4,
	GXControlDelegatesProviderInvalidateOption_ControlComponentDelegate = 1 << 5,
	GXControlDelegatesProviderInvalidateOption_ControlWithEventsDelegate = 1 << 6,
	GXControlDelegatesProviderInvalidateOption_ControlWithActionBarItems = 1 << 7,
	GXControlDelegatesProviderInvalidateOption_All = GXControlDelegatesProviderInvalidateOption_ActionControllerDelegate |
													GXControlDelegatesProviderInvalidateOption_ControlWithDataEventsDelegate |
													GXControlDelegatesProviderInvalidateOption_ControlWithPromptRuleEventsDelegate |
													GXControlDelegatesProviderInvalidateOption_EntityDetailLayoutSectionProvider |
													GXControlDelegatesProviderInvalidateOption_ControlContainerWithDataProvider |
													GXControlDelegatesProviderInvalidateOption_ControlComponentDelegate |
													GXControlDelegatesProviderInvalidateOption_ControlWithEventsDelegate |
													GXControlDelegatesProviderInvalidateOption_ControlWithActionBarItems
};

#if TARGET_OS_WATCH
@protocol GXControlContainer <GXControl, GXControlDelegate>
#else
@protocol GXControlContainer <GXControl, GXControlDelegate, GXControlAutoHeightDelegate, GXControlWithActionBarItemsDelegate>
#endif // TARGET_OS_WATCH

@property (nonatomic, strong, readonly) id<GXEntityDataDescriptor> dataDescriptor;
@property (nullable, nonatomic, strong, readonly) GXBusinessComponentLevel *businessComponentLevel;
@property (nonatomic, strong, readonly) NSDictionary *relationsByDataElementName;

@property (nullable, nonatomic, weak) id <GXControlDelegatesProvider> controlDelegatesProvider;
- (void)invalidateProviderWithOptions:(GXControlDelegatesProviderInvalidateOptions)options;

/**
 * Called when delegate's dealloc
 */
- (void)cleanDelegates;

@property (nonatomic, strong) GXControlContainerContext *context;

@property (nonatomic, assign) GXListSelectionModeType selectionMode;

#if TARGET_OS_IOS
@property (nonatomic, readonly) UIInterfaceOrientation interfaceOrientation;
#endif // TARGET_OS_IOS

@property (nullable, nonatomic, readonly) id<GXEntityDataWithOverrideValues> containerLoadedEntityData;

- (void)loadEntityData:(nullable id <GXEntityDataWithOverrideValues>)entityData withOptions:(GXControlContainerLoadOptions *)options;

#if !TARGET_OS_WATCH
- (nullable NSArray<id<GXControlSection>> *)visibleSectionControls;
- (nullable NSArray<id<GXControlGrid>> *)visibleGridControls;
#endif // !TARGET_OS_WATCH

#if TARGET_OS_WATCH
- (id)initWithInterfaceObject:(WKInterfaceObject *)interfaceObject
				layoutElement:(id <GXLayoutElement>)layoutElement
			   dataDescriptor:(id<GXEntityDataDescriptor>)dataDescriptor
	   businessComponentLevel:(nullable GXBusinessComponentLevel *)businessComponentLevel
					controlId:(NSUInteger)controlId
					   gxMode:(GXModeType)modeType
				 indexerStack:(nullable NSArray<NSNumber *> *)indexer
				parentControl:(nullable id<GXControlContainer>)parentControl
					relations:(nullable NSDictionary *)relationsByDataElementName;
#else
- (id)initWithLayoutElement:(id <GXLayoutElement>)layoutElement
             dataDescriptor:(id<GXEntityDataDescriptor>)dataDescriptor
     businessComponentLevel:(nullable GXBusinessComponentLevel *)businessComponentLevel
                  controlId:(NSUInteger)controlId
                     gxMode:(GXModeType)modeType
               indexerStack:(nullable NSArray<NSNumber *> *)indexer
			  parentControl:(nullable id<GXControlContainer>)parentControl
				  relations:(nullable NSDictionary *)relationsByDataElementName;
#endif // TARGET_OS_WATCH

/*
 * Tells the provider to refresh data
 */
- (void)refresh:(BOOL)keep;

- (void)enumerateChildControlsWithBlock:(void (^)(id <GXControl> control, BOOL *stop))block options:(GXControlContainerChildControlsEnumerationOptions)options;
// Convenience methods that should call enumerateChildControlsWithBlock:options: with the corresponding options
- (void)enumerateChildControlsWithBlock:(void (^)(id <GXControl> control, BOOL *stop))block; // Enumerates with GXControlContainerChildControlsEnumeration_None options
- (void)enumerateVisibleChildControlsWithBlock:(void (^)(id <GXControl> control, BOOL *stop))block; // Enumerates with GXControlContainerChildControlsEnumeration_VisibleControlsOnly options

@required

// From UIViewController | WKInterfaceController
#if TARGET_OS_IOS
- (void)willRotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration;
- (void)willAnimateRotationToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation duration:(NSTimeInterval)duration;
- (void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation;
#endif // TARGET_OS_IOS
- (void)viewWillAppear:(BOOL)animated;    // Called when the view is about to made visible. Default does nothing
- (void)viewDidAppear:(BOOL)animated;     // Called when the view has been fully transitioned onto the screen. Default does nothing
- (void)viewWillDisappear:(BOOL)animated; // Called when the view is dismissed, covered or otherwise hidden. Default does nothing
- (void)viewDidDisappear:(BOOL)animated;  // Called after the view was dismissed, covered or otherwise hidden. Default does nothing

@end

@protocol GXControlDelegatesProvider <NSObject>

@property(nullable, nonatomic, weak, readonly) id<GXActionControllerDelegate> controlDelegateActionControllerDelegate;
@property(nullable, nonatomic, weak, readonly) id<GXControlWithDataEventsDelegate> controlDelegateControlWithDataEventsDelegate;
@property(nullable, nonatomic, weak, readonly) id<GXControlWithPromptRuleEventsDelegate> controlDelegateControlWithPromptRuleEventsDelegate;
#if !TARGET_OS_WATCH
@property(nullable, nonatomic, weak, readonly) id<GXEntityDetailLayoutSectionProvider> controlDelegateSectionsProviderDelegate;
#endif // !TARGET_OS_WATCH
@property(nullable, nonatomic, weak, readonly) id<GXControlContainerWithDataProviderDelegate> controlDelegateControlContainerWithDataProviderDelegate;
@property(nullable, nonatomic, weak, readonly) id<GXControlComponentDelegate> controlDelegateControlComponentDelegate;
@property(nullable, nonatomic, weak, readonly) id<GXControlWithEventsDelegate> controlDelegateControlWithEventsDelegate;
#if !TARGET_OS_WATCH
@property(nullable, nonatomic, weak, readonly) id<GXControlWithActionBarItemsDelegate> controlDelegateControlWithActionBarItemsDelegate;
#endif // !TARGET_OS_WATCH

@end

@protocol GXControlContainerWithDataProvider <GXControlContainer>

@property(nullable, nonatomic, weak) id<GXControlContainerWithDataProviderDelegate> containerEntityDataProviderDelegate;

@property(nonatomic, strong, readonly) id <GXEntityDataProvider> containerEntityDataProvider;

@end

@protocol GXControlContainerWithDataProviderDelegate <NSObject>

- (GXEntityDataProviderWaitingForDelegateState)controlContainerWithDataProvider:(id <GXControlContainerWithDataProvider>)control
													  canLoadWaitingWithOptions:(GXEntityDataProviderWaitingOptions)options;

- (BOOL)allowReloadContainerWithDataProviderIfNeededOnDidAppear:(id <GXControlContainerWithDataProvider>)control;

@end

extern NSString *const GXControlGridEventNamePageChanged;
extern NSString *const GXControlGridEventNameSelectionChanged;

NS_SWIFT_NAME(GXControlGridProtocol)
@protocol GXControlGrid <GXControlContainerWithDataProvider>

@property(nonatomic, strong, readonly) id <GXEntityDataListProvider> entityDataListProvider;

// Helper properties to access entityDataListProvider's data source properties
@property(nullable, nonatomic, strong, readonly) id <GXEntityListFilterSearch> filterSearch;
@property(nullable, nonatomic, strong, readonly) id <GXEntityListFilterAdvanced> filterAdvanced;
@property(nullable, nonatomic, strong, readonly) NSArray<id<GXEntityListOrder>> *orders;
@property(assign, readonly) BOOL allowsMultilineSelection; // if YES, the must conform to GXControlGridWithMultilineSelection protocol

@optional

#if !TARGET_OS_WATCH
/**
 * Notification sent to the Grid control before the containing entity view controller presents the filtes panel for that grid
 */
- (void)entityViewControllerWillPresentFiltersAdvancedViewController;

/**
 * Notification sent to the Grid control when the filters panel is being dismissed
 */
- (void)entityViewControllerDidFinishPresentingFiltersAdvancedViewController;
#endif // !TARGET_OS_WATCH

@end

@protocol GXControlGridWithMultilineSelection <GXControlGrid>

@property(nonatomic, assign) BOOL multilineSelectorsVisible; // Setter calls [self setMultilineSelectorsVisible:visible animated:NO]
- (void)setMultilineSelectorsVisible:(BOOL)visible animated:(BOOL)animated;

- (nullable NSArray<id<GXEntityData>> *)multilineSelectedEntitiesData;
- (void)clearMultilineSelection;

@end

NS_ASSUME_NONNULL_END
