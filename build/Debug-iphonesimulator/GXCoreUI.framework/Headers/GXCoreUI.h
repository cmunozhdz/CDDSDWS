//
//  GXCoreUI.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 10/2/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
//! Project version number for GXCoreUI.
FOUNDATION_EXPORT double GXCoreUIVersionNumber;

//! Project version string for GXCoreUI.
FOUNDATION_EXPORT const unsigned char GXCoreUIVersionString[];

#import <GXCoreUI/GXActionControllerDelegateProtocol.h>
#import <GXCoreUI/GXActionExObjEventsHelper+GXControl.h>
#import <GXCoreUI/GXActionHandler+GXControlRuntimePropertiesProxy.h>
#import <GXCoreUI/GXActionHandler+GXMenuActionHandlerProtocol.h>
#import <GXCoreUI/GXActionHandlerUIContext.h>
#import <GXCoreUI/GXActionHandlerUISender.h>
#import <GXCoreUI/GXActionsManager+GXActionHandlerUIDelegate.h>
#import <GXCoreUI/GXApplicationBarsAppearance.h>
#import <GXCoreUI/GXApplicationLaunchingViewController.h>
#import <GXCoreUI/GXBackgroundViewContainerProtocol.h>
#import <GXCoreUI/GXBarButtonItemWithBlock.h>
#import <GXCoreUI/GXButtonWithExtendedHitArea.h>
#import <GXCoreUI/GXCallerDelegate.h>
#import <GXCoreUI/GXCallOptions+GXRuntime.h>
#import <GXCoreUI/GXControl.h>
#import <GXCoreUI/GXControlActionBarButtonItem.h>
#import <GXCoreUI/GXControlActionBarItem.h>
#import <GXCoreUI/GXControlActionBarItemAlertActionView.h>
#import <GXCoreUI/GXControlActionBarItemHelper.h>
#import <GXCoreUI/GXEditorLabelWithPlaceholderAndInputViewBase.h>
#import <GXCoreUI/GXControlAutoHeight.h>
#import <GXCoreUI/GXControlBase.h>
#import <GXCoreUI/GXControlBase+GXControlWithPromptRuleHelpers.h>
#import <GXCoreUI/GXControlBase+GXDragDrop.h>
#import <GXCoreUI/GXControlBase+GXThemeClassPropertiesOverrides.h>
#import <GXCoreUI/GXControlBase+GXThemeClassWithScrollHelpers.h>
#import <GXCoreUI/GXControlBaseReuseContext.h>
#import <GXCoreUI/GXControlBaseWithLayout.h>
#import <GXCoreUI/GXControlComponentContainerProtocol.h>
#import <GXCoreUI/GXControlComponentProtocol.h>
#import <GXCoreUI/GXControlContainer.h>
#import <GXCoreUI/GXControlContainerBase.h>
#import <GXCoreUI/GXControlContainerContext.h>
#import <GXCoreUI/GXControlContainerLoadOptions.h>
#import <GXCoreUI/GXControlDynamic.h>
#import <GXCoreUI/GXControlEditableWithLabelAndInputViewBase.h>
#import <GXCoreUI/GXControlEditableWithLabelAndPickerBase.h>
#import <GXCoreUI/GXControlEditableWithLabelBase.h>
#import <GXCoreUI/GXControlEditableWithLabelSingleEditorViewBase.h>
#import <GXCoreUI/GXControlFactory.h>
#if TARGET_OS_IOS || TARGET_OS_TV
#import <GXCoreUI/GXControlGeoLocationHelper.h>
#import <GXCoreUI/GXControlGeoLocationHelper+Internal.h>
#endif // TARGET_OS_IOS || TARGET_OS_TV
#import <GXCoreUI/GXControlGrid.h>
#import <GXCoreUI/GXControlGridBase.h>
#import <GXCoreUI/GXControlGridBase+GXAsyncReload.h>
#import <GXCoreUI/GXControlGridBase+GXControlGridItem.h>
#import <GXCoreUI/GXControlGridBase+GXExpandableBounds.h>
#import <GXCoreUI/GXControlGridBase+GXGridViewDataSourceDelegate.h>
#import <GXCoreUI/GXControlGridBase+GXHeightCalculationHelper.h>
#import <GXCoreUI/GXControlGridBase+GXLoadedInfo.h>
#import <GXCoreUI/GXControlGridBase+InverseLoadingSupport.h>
#import <GXCoreUI/GXControlGridBaseLoadedInfo.h>
#import <GXCoreUI/GXControlGridBaseLoadedInfo+Subclasses.h>
#import <GXCoreUI/GXControlGridBaseWithSelection.h>
#import <GXCoreUI/GXControlGridBaseWithSelection+GXGridViewDataSourceDelegate.h>
#import <GXCoreUI/GXControlGridCollectionTableView.h>
#import <GXCoreUI/GXControlGridCollectionTableViewBase.h>
#import <GXCoreUI/GXControlGridCollectionTableViewBase+GXGridViewDataSourceDelegate.h>
#import <GXCoreUI/GXControlGridCollectionTableViewBase+GXGridViewDelegate.h>
#import <GXCoreUI/GXControlGridCollectionTableViewBase+GXLoadingItem.h>
#if TARGET_OS_IOS
#import <GXCoreUI/GXControlGridCollectionTableViewBase+GXPullToRefresh.h>
#endif // TARGET_OS_IOS
#import <GXCoreUI/GXControlGridCollectionTableViewBase+GXSearch.h>
#import <GXCoreUI/GXControlGridCollectionTableViewCell.h>
#import <GXCoreUI/GXControlGridCollectionTableViewCellAction.h>
#import <GXCoreUI/GXControlGridCollectionTableViewCellEntityData.h>
#if TARGET_OS_IOS || TARGET_OS_TV
#import <GXCoreUI/GXControlGridCollectionViewBase.h>
#endif // TARGET_OS_IOS || TARGET_OS_TV
#import <GXCoreUI/GXControlGridHeightCalculationHelper.h>
#import <GXCoreUI/GXControlGridItem.h>
#import <GXCoreUI/GXControlGridItemHeightCalculationHelper.h>
#import <GXCoreUI/GXControlGridLoadedInfo.h>
#import <GXCoreUI/GXControlHelpers.h>
#import <GXCoreUI/GXControlImage.h>
#import <GXCoreUI/GXControlMultilineSelectionGridBase.h>
#import <GXCoreUI/GXControlScrollIntoViewTypes.h>
#import <GXCoreUI/GXControlSectionProtocol.h>
#import <GXCoreUI/GXControlSingleContainerBase.h>
#import <GXCoreUI/GXControlTable.h>
#import <GXCoreUI/GXControlTableForHeightCalculation.h>
#import <GXCoreUI/GXControlTableGridItem.h>
#import <GXCoreUI/GXControlTextViewProtocol.h>
#import <GXCoreUI/GXControlWithActionBarItems.h>
#import <GXCoreUI/GXControlWithData.h>
#import <GXCoreUI/GXControlWithDataEditable.h>
#import <GXCoreUI/GXControlWithEvents.h>
#import <GXCoreUI/GXControlWithExpandableBounds.h>
#import <GXCoreUI/GXControlWithLabelAutoWidth.h>
#import <GXCoreUI/GXControlWithLabelBase.h>
#import <GXCoreUI/GXControlWithLabelSingleEditorViewBase.h>
#import <GXCoreUI/GXControlWithLabelSingleEditorViewHelper.h>
#import <GXCoreUI/GXControlWithLabelSingleEditorViewProtocol.h>
#import <GXCoreUI/GXControlWithPromptRule.h>
#import <GXCoreUI/GXControlWithUserInterfaceController.h>
#import <GXCoreUI/GXDragDropManager.h>
#import <GXCoreUI/GXEditorLabelWithPlaceholderAndInputViewBase.h>
#import <GXCoreUI/GXEntityActionBarItemReference.h>
#import <GXCoreUI/GXEntityActionHandler.h>
#import <GXCoreUI/GXEntityActionHandlerProtocol.h>
#import <GXCoreUI/GXEntityDataFieldBarCodeScannerProtocol.h>
#import <GXCoreUI/GXEntityDataFieldViewController.h>
#import <GXCoreUI/GXEntityDataFieldViewControllerHelper.h>
#import <GXCoreUI/GXEntityDataFieldViewControllerProtocol.h>
#import <GXCoreUI/GXEntityDetailLayout.h>
#import <GXCoreUI/GXEntityDetailViewController.h>
#import <GXCoreUI/GXEntityDetailViewController+GXActionBar.h>
#import <GXCoreUI/GXEntityHelper+GXCoreUI_BusinessComponentRelation.h>
#import <GXCoreUI/GXEntityListFilterAdvancedViewController.h>
#import <GXCoreUI/GXEntityModelHelper+GXCoreUI.h>
#import <GXCoreUI/GXEntityModelProtocol.h>
#import <GXCoreUI/GXEntityViewController.h>
#import <GXCoreUI/GXEOProgressIndicator.h>
#import <GXCoreUI/GXFlexboxLayoutDelegate.h>
#if TARGET_OS_IOS
#import <GXCoreUI/GXKeyboardStateListener.h>
#endif // TARGET_OS_IOS
#import <GXCoreUI/GXLayoutControlUserInterfaceContextProtocol.h>
#import <GXCoreUI/GXLayoutHelper.h>
#if TARGET_OS_IOS
#import <GXCoreUI/GXImagePickerControllerHelper.h>
#endif // TARGET_OS_IOS
#import <GXCoreUI/GXImageViewActivityIndicator.h>
#import <GXCoreUI/GXImageViewController.h>
#import <GXCoreUI/GXInlinePickerView.h>
#import <GXCoreUI/GXMenuActionHandlerProtocol.h>
#import <GXCoreUI/GXMenuControllerProtocol.h>
#import <GXCoreUI/GXMessageView.h>
#import <GXCoreUI/GXMessageViewController.h>
#if TARGET_OS_IOS || TARGET_OS_TV
#import <GXCoreUI/GXMKMapView.h>
#endif // TARGET_OS_IOS || TARGET_OS_TV
#if TARGET_OS_IOS
#import <GXCoreUI/GXMultiColumnWheelHelper.h>
#endif // TARGET_OS_IOS
#import <GXCoreUI/GXNavigationBar.h>
#import <GXCoreUI/GXNavigationController.h>
#import <GXCoreUI/GXPreferencesViewController.h>
#import <GXCoreUI/GXRootControllerHelper.h>
#import <GXCoreUI/GXRootControllerProtocol.h>
#import <GXCoreUI/GXScrollableControlProtocol.h>
#import <GXCoreUI/GXScrollManager.h>
#import <GXCoreUI/GXScrollView.h>
#import <GXCoreUI/GXSegmentedControlItem.h>
#import <GXCoreUI/GXSegmentedControlActionBarItemView.h>
#import <GXCoreUI/GXSegmentedControlItem+WebCache.h>
#import <GXCoreUI/GXSharing.h>
#import <GXCoreUI/GXSharingServices.h>
#import <GXCoreUI/GXStyleClassWithFontHelper+GXControlTextView.h>
#import <GXCoreUI/GXTextInputHelper.h>
#import <GXCoreUI/GXThemeClassPropertiesOverridesWithDictionary.h>
#import <GXCoreUI/GXThemeHelper+GXApplicationBar.h>
#import <GXCoreUI/GXThemeHelper+GXUI.h>
#import <GXCoreUI/GXTintColorLabel.h>
#import <GXCoreUI/GXUserInterfaceContext+GXControl.h>
#import <GXCoreUI/GXUserInterfaceContextHelper+GXControl.h>
#import <GXCoreUI/GXUserInterfaceContextFactory+GXControl.h>
#import <GXCoreUI/GXViewController.h>
#import <GXCoreUI/GXViewController+GXSecurityService.h>
#import <GXCoreUI/GXViewControllerHelper.h>
#if TARGET_OS_IOS
#import <GXCoreUI/GXViewControllerHelper+GXInterfaceOriantation.h>
#endif // TARGET_OS_IOS
#import <GXCoreUI/GXViewControllerHelper+GXReturnTo.h>
#import <GXCoreUI/GXViewControllerHelper+GXViewControllerAdaptativePresentation.h>
#import <GXCoreUI/GXViewControllerHelper+GXViewControllerFactory.h>
#import <GXCoreUI/GXViewLayoutDelegationProtocol.h>
#import <GXCoreUI/GXViewWithLayoutDelegation.h>
#if TARGET_OS_IOS
#import <GXCoreUI/GXWebViewController.h>
#endif // TARGET_OS_IOS
#import <GXCoreUI/GXWindow.h>

#import <GXCoreUI/CALayer+GXAnimationProxy.h>

#import <GXCoreUI/MKAnnotationView+WebCache.h>

#if TARGET_OS_IOS
#import <GXCoreUI/GXPHPickerResultHelper.h>
#endif // TARGET_OS_IOS

#import <GXCoreUI/UIBarButtonItem+Helpers.h>
#import <GXCoreUI/UIBarButtonItem+WebCache.h>
#import <GXCoreUI/UIButton+WebCache.h>
#import <GXCoreUI/UICollectionView+GXControlGridCollectionTableView.h>
#import <GXCoreUI/UICollectionViewCell+GXControlGridCollectionTableViewCell.h>
#import <GXCoreUI/UIImageView+Alignment.h>
#import <GXCoreUI/UIImageView+GXImageWebCache.h>
#import <GXCoreUI/UIImageView+HighlightedWebCache.h>
#import <GXCoreUI/UIImageView+WebCache.h>
#import <GXCoreUI/UINavigationBar+Helpers.h>
#import <GXCoreUI/UINavigationBar+WebCache.h>
#import <GXCoreUI/UINavigationController+Helpers.h>
#import <GXCoreUI/UIResponder+Helpers.h>
#import <GXCoreUI/UIScrollView+GXHelpers.h>
#import <GXCoreUI/UIScrollView+GXUIScrollViewBehavior.h>
#import <GXCoreUI/UITabBar+WebCache.h>
#import <GXCoreUI/UITableView+GXControlGridCollectionTableView.h>
#import <GXCoreUI/UITableViewCell+GXControlGridCollectionTableViewCell.h>
#import <GXCoreUI/UITableViewCell+GXHelpers.h>
#if TARGET_OS_IOS
#import <GXCoreUI/UIToolbar+WebCache.h>
#endif // TARGET_OS_IOS
#import <GXCoreUI/UIView+GestureRecognizers.h>
#import <GXCoreUI/UIView+GXSnapshotting.h>
#import <GXCoreUI/UIView+GXTheme.h>
#if TARGET_OS_IOS
#import <GXCoreUI/UIView+GXWebView.h>
#endif // TARGET_OS_IOS
#import <GXCoreUI/UIView+UserInterfaceLayoutDirection.h>
#import <GXCoreUI/UIView+ViewHierarchy.h>
#import <GXCoreUI/UIView+WebCacheOperation.h>
#import <GXCoreUI/UIViewController+GXCallOptions.h>
#import <GXCoreUI/UIViewController+GXPropertiesObject.h>
#import <GXCoreUI/UIViewController+GXControllerPresentationHandlerProtocol.h>
#import <GXCoreUI/UIViewController+Helpers.h>

#import <GXCoreUI/SDPageControllerThemeClass.h>

#if TARGET_OS_IOS
#import <GXCoreUI/GXMapAnnotation.h>
#import <GXCoreUI/GXUC_MapKitPinAnnotation.h>
#import <GXCoreUI/GXUC_MapKitCalloutAnnotation.h>
#import <GXCoreUI/GXUC_MapListCalloutAnnotationView.h>
#endif // TARGET_OS_IOS

#if TARGET_OS_IOS || TARGET_OS_TV
#import <GXCoreUI/GXControlTableBase+ChildControls.h>
#endif // TARGET_OS_IOS || TARGET_OS_TV

#if TARGET_OS_IOS || TARGET_OS_TV
#import <GXCoreUI/GXControlGeoLocation.h>
#import <GXCoreUI/GXControlGeoLocation+Internal.h>
#import <GXCoreUI/GXControlGeoLocationHelper.h>
#import <GXCoreUI/GXMapView.h>
#import <GXCoreUI/GXUC_MapCustomAnnotationView.h>
#import <GXCoreUI/GXUC_MapPinAnnotation.h>
#import <GXCoreUI/SDMapPinImageThemeClass.h>
#endif // TARGET_OS_IOS || TARGET_OS_TV
