//
//  GXLayoutHelper.h
//  GXFlexibleClient
//
//  Created by willy on 2/18/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import GXFoundation;
@import GXObjectsModel;
@import GXDataLayer;
#import <GXCoreUI/GXControl.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXLayoutHelper : NSObject

+ (nullable NSString *)captionFromLayoutElementData:(id <GXLayoutElementData>)layoutElementData;
+ (nullable NSString *)placeholderFromLayoutElementData:(id<GXLayoutElementData>)layoutElementData;

/**
 * Parses the control properties for an item of a grid
 * If the provider is nil (not field based provider), the index and section parameters are ignored.
 */
+ (nullable GXDynamicPropertiesCollection *)parseLayoutControlDynamicPropertiesFromEntityData:(nullable id<GXEntityData>)entityData
																					 provider:(nullable id<GXEntityDataListFieldBasedProvider>)provider
																					  atIndex:(NSUInteger)index
																					  section:(NSUInteger)section
																					 filtered:(BOOL)filtered;

+ (void)overrideEntityData:(id<GXEntityDataWithOverrideValues>)entityData dynamicPropertiesCollection:(nullable GXDynamicPropertiesCollection *)properties;

/// Update entityData with the new dynamic props if property value has changed
+ (BOOL)overrideEntityDataDynamicPropertiesIfNeeded:(id<GXEntityDataWithOverrideValues>)entityData
									 forControlName:(NSString *)lowercaseControlName
									   propertyName:(NSString *)lowercasePropName
									  propertyValue:(nullable id)propertyValue;

/// Handles pending GXDynamicPropertyOverrideUserInterfaceContext  (if found in the given uiContext) for the given property name and control name by calling overrideEntityDataDynamicPropertiesIfNeeded:forControlName:propertyName:propertyValue:
+ (void)handleDynamicPropertyOverrideUserInterfaceContextIn:(GXUserInterfaceContext *)uiContext
											forPropertyName:(NSString *)lowercasePropName
													  value:(nullable id)propValue
												controlName:(NSString *)controlName
								overridesEntityDataProvider:(id<GXEntityDataWithOverrideValues>_Nullable(NS_NOESCAPE ^)(void))overridesEntityDataProvider;

/// Calls handleDynamicPropertyOverrideUserInterfaceContextIn:forPropertyName:value:controlName:overridesEntityDataProvider: with a overridesEntityDataProvider from the given control
+ (void)handleDynamicPropertyOverrideUserInterfaceContextIn:(GXUserInterfaceContext *)uiContext
											forPropertyName:(NSString *)lowercasePropName
													  value:(nullable id)propValue
												controlName:(NSString *)controlName
													control:(id<GXControlBaseProperties>)control;

+ (BOOL)controlProperty:(NSString *)lowercasePropName valueIsEqual:(nullable id)value1 toValue:(nullable id)value2;

/// Returns [self frameForTableWithLayoutElementWidth:layoutElement.layoutElementTableWidth height:layoutElement.layoutElementTableHeight withSizeForPercentValues:size]
+ (CGRect)frameForTableWithLayoutElement:(id<GXLayoutElementTable>)layoutElement withSizeForPercentValues:(CGSize)size;

/**
 * If the table element has fixed width and height, returns the definide values
 * If it has percents, it returns the percents applyed to the given size
 * Returned origin is always Zero
 */
+ (CGRect)frameForTableWithLayoutElementWidth:(GXLayoutDimension)width height:(GXLayoutDimension)height withSizeForPercentValues:(CGSize)size;

/// Returns [self relativeContentSizeForTableWithLayoutElement:layoutElement width:layoutElement.layoutElementTableWidth height:layoutElement.layoutElementTableHeight thatFitsContentSize:size]
+ (CGSize)relativeContentSizeForTableWithLayoutElement:(id<GXLayoutElementTable>)layoutElement thatFitsContentSize:(CGSize)contentSize;

/*!
 Returns the computed relative content size for the given table layout element, width and hight dimensions and content size
 
 @param width Table layout element width
 @param height Table layout element height
 @param contentSize Available table content size to layout child controls
 @result The computed relative size to be used for laying out child controls (see [GXLayoutRectangle computedFrame:]).
 @discussion Adjusts contentSize.width with the given width, if dimension unit is Point, limit width to the dimension point value;
 if dimension unit is Percent, substracts [layoutElement layoutElementTableFixedWidthSum] to width. Same process is used for contentSize.height using given height.
 */
+ (CGSize)relativeContentSizeForTableWithLayoutElement:(id<GXLayoutElementTable>)layoutElement width:(GXLayoutDimension)width height:(GXLayoutDimension)height thatFitsContentSize:(CGSize)contentSize;

+ (nullable id <GXLayoutElementTable>)defaultSelectedRootElementForGridlayoutElement:(id <GXLayoutElementGrid>)gridLayoutElement;
+ (BOOL)gridlayoutElementHasMultipleItemLayouts:(id <GXLayoutElementGrid>)gridLayoutElement;
+ (BOOL)gridlayoutElementHasDynamicRowWidth:(id <GXLayoutElementGrid>)gridLayoutElement;
+ (BOOL)gridlayoutElementHasItemWithPercentWidth:(id <GXLayoutElementGrid>)gridLayoutElement;
+ (BOOL)gridlayoutElementHasItemWithPercentHeight:(id <GXLayoutElementGrid>)gridLayoutElement;
+ (BOOL)gridlayoutElementHasItemWithPointWidth:(id <GXLayoutElementGrid>)gridLayoutElement;
+ (BOOL)gridlayoutElementHasItemWithPointHeight:(id <GXLayoutElementGrid>)gridLayoutElement;

/**
 * Returns the first data element in the layout with the given name (case insensitive)
 *
 * @param name The name of the data element to search for
 * @param gridLayoutElement The grid layout element where the search is performed
 * @return The first data element with the given name
 */
+ (nullable id<GXLayoutElementData>)firstLayoutElementDataWithName:(NSString *)name fromLayoutElementGrid:(id<GXLayoutElementGrid>)gridLayoutElement;

/**
 * Returns true if the table layout element is empty, that is, has no children elements
 *
 * @param tableLayout The table layout element to inspect
 * @return true if the element is empty, false otherwise
 */
+ (BOOL)isLayoutElementTableEmpty:(id<GXLayoutElementTable>)tableLayout;

@end

NS_ASSUME_NONNULL_END
