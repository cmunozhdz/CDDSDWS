//
//  GXLayoutProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 12/01/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import Foundation;
@import GXFoundation;
#import <GXObjectsModel/GXLayoutRectangle.h>
#import <GXObjectsModel/GXThemeClass.h>
#import <GXObjectsModel/GXDynamicDataServiceProtocol.h>
#import <GXObjectsModel/GXActionDescriptorProtocol.h>
#import <GXObjectsModel/GXActionUIDescriptorProtocol.h>
#import <GXObjectsModel/GXModelObjectChild.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint_least8_t, GXLayoutType) {
	GXLayoutTypeView,
	GXLayoutTypeEdit
};

typedef NS_ENUM(uint_least8_t, GXLayoutElementType) {
	GXLayoutElementTypeTable,
	GXLayoutElementTypeRow,
	GXLayoutElementTypeCell,
	GXLayoutElementTypeTabs,
	GXLayoutElementTypeGroup,
	GXLayoutElementTypeData,
	GXLayoutElementTypeAction,
	GXLayoutElementTypeTextBlock,
	GXLayoutElementTypeImage,
	GXLayoutElementTypeContent,
    GXLayoutElementTypeGrid,
	GXLayoutElementTypeUserControl,
	GXLayoutElementTypeComponent
};

typedef NS_ENUM(uint_least8_t, GXLayoutElementContentDisplayType) {
	GXLayoutElementContentDisplayDefault,
	GXLayoutElementContentDisplayInline,
	GXLayoutElementContentDisplayTab,
	GXLayoutElementContentDisplayLink
};

typedef NS_ENUM(uint_least8_t, GXLayoutActionBarItemType) {
	GXLayoutActionBarItemTypeAction,
	GXLayoutActionBarItemTypeData,
	GXLayoutActionBarItemTypeGroup
};

/**
 * Grid row selector visiblity type
 * None:		control must not show the selector as there is not an action with a 'for each selected line' that applies to this grid
 * OnAction:	control must show the selector when an action with a 'for each selected line' over this grid is executed
 * Always:		control must show the selector if there is at least one action with a 'for each selected line' over this grid
 */
typedef NS_ENUM(uint_least8_t, GXLayoutElementGridShowSelectorType) {
	GXLayoutElementGridShowSelectorNone,
	GXLayoutElementGridShowSelectorOnAction,
	GXLayoutElementGridShowSelectorAlways
};

typedef NS_ENUM(NSInteger, GXLayoutOverflowBehavior) {
	GXLayoutOverflowBehaviorDefault,
	GXLayoutOverflowBehaviorAddScroll,
	GXLayoutOverflowBehaviorClipContent
};

@protocol GXLayoutElement <GXModelObject, NSObject>

@property(nonatomic, strong, readonly) NSString *layoutElementControlName;
@property(nonatomic, assign, readonly) GXLayoutElementType layoutElementType;
@property(nonatomic, assign, readonly) NSUInteger layoutElementId;
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementClassFullName;
@property(nonatomic, assign, readonly) BOOL layoutElementVisible;
@property(nonatomic, assign, readonly) BOOL layoutElementEnabled;
@property(nonatomic, assign, readonly) GXLayoutInvisibleMode layoutElementInvisibleMode;

@optional

- (BOOL)hasChildOfType:(GXLayoutElementType)type recursive:(BOOL)recursive;
- (nullable NSArray<id<GXLayoutElement>> *)childrenOfType:(GXLayoutElementType)type recursive:(BOOL)recursive;

@end

@protocol GXLayoutElementWithAlignment <GXLayoutElement>

@property(nonatomic, assign, readonly) GXHorizontalAlignType layoutElementHorizontalAlign;
@property(nonatomic, assign, readonly) GXVerticalAlignType layoutElementVerticalAlign;

@end

@protocol GXLayoutElementWithAutoGrow <GXLayoutElement>

@property(nonatomic, assign, readonly) BOOL layoutElementAutoGrow;

@end

@protocol GXLayoutElementWithText <NSObject>

@property(nonatomic, assign, readonly) GXLayoutControlTextFormat layoutElementTextFormat;

@end

@protocol GXLayoutElementWithExpandableBounds <NSObject>

@property(nonatomic, assign, readonly) GXLayoutExpandableBounds layoutElementExpandableBounds;
@property(nonatomic, assign, readonly) GXLayoutExpandDirection layoutElementExpandDirection; // RTL Left/Right exchange not applied
@property(nonatomic, assign, readonly) GXLayoutExpandLimit layoutElementExpandLimit;

@end

@protocol GXLayoutActionBarItem;

@protocol GXLayoutActionBar <GXModelObject, NSObject>

@property(nullable, nonatomic, strong, readonly) NSArray<id<GXLayoutActionBarItem>> *layoutActionBarItems;
@property(nonatomic, assign, readonly) BOOL layoutActionBarShowActionBar;
@property(nullable, nonatomic, strong, readonly) NSString *layoutActionBarClassFullName;
@property(nullable, nonatomic, strong, readonly) NSString *layoutActionBarControlName;
@property(nullable, nonatomic, strong, readonly) NSString *layoutActionBarControlType;

@end

@protocol GXLayoutActionBarItem <GXModelObject, GXActionBarUIDescriptor>

@property(nonatomic, strong, readonly) NSString *layoutActionBarItemControlName;
@property(nonatomic, assign, readonly) GXLayoutActionBarItemType layoutActionBarItemType;

@end

@protocol GXLayoutActionBarActionItem <GXLayoutActionBarItem, GXActionUIDescriptor>

@property(nullable, nonatomic, strong, readonly) id <GXActionDescriptor> layoutActionBarItemActionDescriptor;
@property(nonatomic, strong, readonly) NSString *layoutActionBarItemActionName;

@end

@protocol GXLayoutActionBarDataItem <GXLayoutActionBarItem, GXActionUIBaseDescriptor>

@end

@protocol GXLayoutActionBarGroupItem <GXLayoutActionBarItem, GXActionUIDescriptor>

@property(nonatomic, strong, readonly) id<GXLayoutActionBar> layoutActionBarGroup;

@end

@protocol GXLayout <GXModelObject, NSObject>

@property(nonatomic, assign, readonly) GXLayoutType layoutType;
@property(nullable, nonatomic, strong, readonly) id <GXLayoutElement> layoutRootElement;
@property(nullable, nonatomic, strong, readonly) NSString *layoutControlType;
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, id> *layoutControlCustomProperties;
@property(nullable, nonatomic, strong, readonly) id <GXLayoutActionBar> layoutActionsBar;
@property(nullable, nonatomic, strong, readonly) NSString *layoutStyleClassName;
@property(nullable, nonatomic, strong, readonly) NSArray<id<GXLayoutActionBar>> *layoutActionGroups;
@property(nullable, nonatomic, strong, readonly) NSString *layoutId;
#if TARGET_OS_WATCH
@property(nullable, nonatomic, strong, readonly) NSString *layoutPlatform;
#endif // TARGET_OS_WATCH

@end

@protocol GXLayoutElementContainer <GXLayoutElement>

- (BOOL)hasElementWithAutoGrow;

@end

@protocol GXLayoutElementCell <GXLayoutElement, GXLayoutElementWithAlignment, GXLayoutElementWithAutoGrow> // layoutElementType == GXLayoutElementTypeCell

@property(nullable, nonatomic, strong, readonly) id <GXLayoutElement> layoutElementCellElement;
@property(nullable, nonatomic, strong, readonly) GXLayoutRectangle *layoutElementCellRectangle;
@property(nonatomic, assign, readonly) ushort layoutElementCellRowSpan;

@end

@protocol GXLayoutElementRow <GXLayoutElement, GXLayoutElementWithAlignment> // layoutElementType == GXLayoutElementTypeRow

@property(nullable, nonatomic, strong, readonly) NSArray<id<GXLayoutElementCell>> *layoutElementRowCells;
@property(nonatomic, assign, readonly) GXLayoutDimension layoutElementRowHeight;

@end

@protocol GXLayoutElementTable <GXLayoutElementContainer, GXLayoutElementWithAlignment, GXLayoutElementWithAutoGrow, GXLayoutElementWithExpandableBounds> // layoutElementType == GXLayoutElementTypeTable

@property(nullable, nonatomic, strong, readonly) NSArray<id<GXLayoutElementRow>> *layoutElementTableRows;
@property(nonatomic, assign, readonly) GXLayoutDimension layoutElementTableWidth;
@property(nonatomic, assign, readonly) GXLayoutDimension layoutElementTableHeight;
@property(nonatomic, assign, readonly) CGFloat layoutElementTableFixedWidthSum;
@property(nonatomic, assign, readonly) CGFloat layoutElementTableFixedHeightSum;
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementTableBackgourndImage;
@property(nonatomic, assign, readonly) CGFloat layoutElementTableScrollFactor;
@property(nonatomic, assign, readonly) CGFloat layoutElementTableZoomFactor;
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementScrollAttachment; // Nil means attached to parent
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementTableId;
@property(nonatomic, assign, readonly) BOOL layoutElementTableEnableHeaderRowPattern;
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementTableHeaderRowApplicationBarThemeClassName;
@property(nonatomic, assign, readonly) GXLayoutOverflowBehavior layoutElementTableOverflowBehavior;

@end


@protocol GXLayoutElementTab <NSObject>

@property(nullable, nonatomic, strong, readonly) NSString *layoutElementTabControlName;
@property(nonatomic, assign, readonly) NSUInteger layoutElementTabControlId;
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementTabCaption;
@property(nonatomic, strong, readonly) id <GXLayoutElement> layoutElementTabElement;
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementTabUnselectedClassFullName;
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementTabSelectedClassFullName;
@property(nonatomic, assign, readonly) BOOL layoutElementTabVisible;
@property(nonatomic, assign, readonly) BOOL layoutElementTabEnabled;
@property(nullable, nonatomic, strong, readonly) NSString * layoutElementTabImageName;
@property(nullable, nonatomic, strong, readonly) NSString * layoutElementTabUnselectedImageName;
@property(nonatomic, assign, readonly) GXActionUIImagePosition layoutElementTabImagePosition;

@end

typedef NS_ENUM(uint_least8_t, GXLayoutElementTabsBehavior) {
	GXLayoutElementTabsBehaviorMoreButton,
	GXLayoutElementTabsBehaviorScroll
};

@protocol GXLayoutElementTabs <GXLayoutElementContainer, GXLayoutElementWithExpandableBounds> // layoutElementType == GXLayoutElementTypeTabs

@property(nonatomic, strong, readonly) NSArray<id<GXLayoutElementTab>> *layoutElementTabs;
@property(nonatomic, assign, readonly) GXLayoutElementTabsBehavior layoutElementTabsBehavior;
@property(nonatomic, assign, readonly) BOOL layoutElementTabsNavigation;
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementTabsMoreButtonSelectedImageName;
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementTabsMoreButtonUnselectedImageName;
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementTabsScrollLeftIndicatorImageName;
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementTabsScrollRightIndicatorImageName;

@end

@protocol GXLayoutElementGroup <GXLayoutElement, GXLayoutElementWithAutoGrow> // layoutElementType == GXLayoutElementTypeGroup

@property(nullable, nonatomic, strong, readonly) NSString *layoutElementGroupCaption;
@property(nonatomic, strong, readonly) id <GXLayoutElementTable> layoutElementGroupElement;

@end

@protocol GXLayoutElementGrid <GXLayoutElementContainer, GXLayoutElementWithAutoGrow, GXLayoutElementWithExpandableBounds>

@property(nonatomic, strong, readonly) id<GXLayoutElementTable> layoutElementRootElement;
@property(nonatomic, strong, readonly) NSString * layoutElementRootElementName; // Lowercase
@property(nullable, nonatomic, strong, readonly) NSString * layoutElementGridDefaultSelectedRootElementName;  // Lowercase
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementCollectionDataName;
@property(nullable, nonatomic, strong, readonly) id<GXEntityDataFieldDescriptor> layoutElementCollectionDataFieldDescriptor;
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementGridDefaultAction;
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementGridControlType;
@property(nonatomic, assign, readonly) NSInteger layoutElementGridRowsPerPage;
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementGridEmptyDataSetBackground;
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementGridEmptyDataSetBackgroundClassName;
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementGridEmptyDataSetText;
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementGridEmptyDataSetTextClassName;
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementGridDataProviderName;
@property(nonatomic, assign, readonly) GXLayoutElementGridShowSelectorType layoutElementGridShowSelector;
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementGridSelectionFlagDataName;
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementGridSelectionFlagFieldSpecifier;
@property(nonatomic, assign, readonly) GXListSelectionType layoutElementGridSelectionType;
@property(nonatomic, strong, readonly) NSDictionary<NSString *, id<GXLayoutElementTable>> *layoutElementGridElementRootElementsByLayoutName; // Keys are lowercase
@property(nullable, nonatomic, strong, readonly) id<GXCodingPropertiesObject> layoutElementGridCustomProperties;
@property(nonatomic, assign, readonly) BOOL layoutElementGridPullToRefresh;
@property(nonatomic, assign, readonly) BOOL layoutElementGridInverseLoading;
@property(nonatomic, assign, readonly) BOOL layoutElementGridEnableMultipleSelection;

/// Returns the layout for the given lowercase layout name, if nil or not found, layoutElementRootElement is returned
- (id<GXLayoutElementTable>)layoutElementRootElementWithLayoutName:(nullable NSString *)lowercaseLayoutName;

@end

@protocol GXLayoutElementData <GXLayoutElement, GXLayoutElementWithAutoGrow, GXLayoutElementWithText> // layoutElementType == GXLayoutElementTypeData

@property(nonatomic, strong, readonly) NSString *layoutElementDataName;
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementFieldSpecifier;
@property(nonatomic, strong, readonly) id<GXEntityDataFieldDescriptor> layoutElementDataFieldDescriptor;
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementDataUserControl;
@property(nonatomic, assign, readonly) GXLayoutLabelPositionType layoutElementDataLabelPosition;  // RTL Left/Right exchange not applied
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementDataLabelCaption;
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementDataControlPlaceholder;
@property(nonatomic, strong, readonly) id<GXCodingPropertiesObject> layoutElementDataCustomProperties;
@property(nonatomic, assign, readonly) BOOL layoutElementDataAutoLink;
@property(nonatomic, assign, readonly) GXLayoutElementReadonly layoutElementDataReadonly;
@property(nullable, nonatomic, strong, readonly) id<GXDynamicDataService> layoutElementDataDynamicDataService;
@property(nullable, nonatomic, strong, readonly) id<GXDynamicDataService> layoutElementDataDynamicDataServiceHideCode;
@property(nullable, nonatomic, strong, readonly) id<GXDynamicDataService> layoutElementDataDynamicDataServiceHideCodeReverse;
@property(nullable, nonatomic, strong, readonly) id<GXDynamicDataService> layoutElementDataDynamicDataServiceSuggest;
@property(nonatomic, assign, readonly) GXEnterTypeKeyType layoutElementDataEnterKeyCaption;
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementDataEnterEvent;

@end

extern NSString *const GXLayoutElementDataEnterEventPlatformDefault;
extern NSString *const GXLayoutElementDataEnterEventGoToNextField;

@protocol GXLayoutElementUserControl <GXLayoutElement>

@property(nullable, nonatomic, strong, readonly) NSString *layoutElementUserControlType;
@property(nullable, nonatomic, strong, readonly) NSArray<id<GXLayoutElementTable>> *layoutElementUserControlContainerTables;
@property(nonatomic, strong, readonly) id<GXCodingPropertiesObject> layoutElementUserControlCustomProperties;

@end

@protocol GXLayoutElementAction <GXLayoutElement, GXLayoutElementWithText> // layoutElementType == GXLayoutElementTypeAction

@property(nonatomic, strong, readonly) NSString *layoutElementActionName;
@property(nullable, nonatomic, strong, readonly) id <GXActionDescriptor> layoutElementActionDescriptor;
@property(nonatomic, assign, readonly) CGSize layoutElementActionSize;
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementActionCaption;
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementActionImageName;
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementActionDisabledImageName;
@property(nonatomic, assign, readonly) GXActionUIImagePosition layoutElementActionImagePosition;

@end

@protocol GXLayoutElementTextBlock <GXLayoutElement, GXLayoutElementWithAutoGrow, GXLayoutElementWithText> // layoutElementType == GXLayoutElementTypeTextBlock

@property(nullable, nonatomic, strong, readonly) NSString *layoutElementTextBlockCaption;

@end

@protocol GXLayoutElementImage <GXLayoutElementWithAutoGrow> // layoutElementType == GXLayoutElementTypeImage

@property(nonatomic, strong, readonly) NSString *layoutElementImageName;

@end

@protocol GXLayoutElementContent <GXLayoutElement> // layoutElementType == GXLayoutElementTypeContent

@property(nullable, nonatomic, strong, readonly) NSString *layoutElementContent;
@property(nonatomic, assign, readonly) GXLayoutElementContentDisplayType layoutElementContentDisplay;
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementContentClassFullName;
@property(nonatomic, assign, readonly) BOOL layoutElementContentShowTitle;
@property(nullable, nonatomic, strong, readonly) id <GXActionParametersDescriptor> layoutElementContentParametersDescriptor;

@end

@protocol GXLayoutElementComponentContainer <GXLayoutElementContainer, GXLayoutElementWithAutoGrow> // layoutElementType == GXLayoutElementTypeComponent

@property(nonatomic, assign, readonly) GXObjectType layoutElementComponentObjectType; // Dashboard, SdPanel or WorkWith
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementComponentObjectName;
@property(nullable, nonatomic, strong, readonly) NSString *layoutElementComponentObjectComponent;
@property(nullable, nonatomic, strong, readonly) id <GXActionParametersDescriptor> layoutElementComponentParametersDescriptor;

@end

NS_ASSUME_NONNULL_END
