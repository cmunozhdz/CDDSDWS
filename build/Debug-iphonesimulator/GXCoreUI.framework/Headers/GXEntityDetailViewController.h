//
//  GXEntityDetailViewController.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 03/02/11.
//  Copyright 2011 Artech. All rights reserved.
//

#import <GXCoreUI/GXControlComponentProtocol.h>
#import <GXCoreUI/GXControlWithExpandableBounds.h>
#import <GXCoreUI/GXEntityDataFieldViewController.h>
#import <GXCoreUI/GXEntityModelProtocol.h>
#import <GXCoreUI/GXEntityViewController.h>
#import <GXCoreUI/UIScrollView+GXUIScrollViewBehavior.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXEntityDetailViewController : GXEntityViewController <GXEntityDataFieldEditorViewControllerDelegate,
																	GXEntityCallerDelegate,
																	GXControlDelegatesProvider,
																	GXControlWithDataEventsDelegate,
																	GXControlWithPromptRuleEventsDelegate,
																	GXControlAutoHeightDelegate,
																	GXControlWithActionBarItemsDelegate,
																	GXControlContainerWithDataProviderDelegate,
																	GXControlComponentDelegate,
																	GXControlDelegate,
																	UIScrollViewDelegate>

@property(nonatomic, strong, readonly) id <GXEntityDataDetailProvider> entityDataDetailProvider;
@property(nonatomic, strong, readonly) id <GXEntityModel> entityDetailModel;
@property(assign, readonly) GXModeType validModeFlags;
@property(nullable, nonatomic, readonly) UIView<GXUIScrollViewBehavior> *scrollView;
@property(nonatomic, strong, readonly) id <GXControlComponent> rootControl;

- (void)setupWithEntityDataDetailProvider:(id <GXEntityDataDetailProvider>)entityDataDetailProvider
						entityDetailModel:(id <GXEntityModel>)entityDetailModel;

/*
 Enables autorefresh on viewDidAppear
 
 @discussion This may be useful for root controllers that are not shown by default on application launch. In
 those cases, you may want to refresh the controller the first time it is shown, and need to call this 
 method first.
 */
- (void)enableAllowReloadProviderIfNeededOnViewDidAppear;

@end

NS_ASSUME_NONNULL_END
