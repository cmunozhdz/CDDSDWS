//
//  GXControlTableGridItem.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 14/08/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

#import <GXCoreUI/GXControlTable.h>
#if TARGET_OS_WATCH
#import <GXCoreUI/GXControlInterfaceObjectsProvider.h>
#else
#import <GXCoreUI/GXControlBase+GXDragDrop.h>
#endif // TARGET_OS_WATCH

NS_ASSUME_NONNULL_BEGIN

@class GXControlTableGridItem;

#if !TARGET_OS_WATCH
@protocol GXControlThemeClassDelegate <NSObject>

- (BOOL)controlThemeClass:(id <GXControl>)control
shouldApplyBackgroundColor:(UIColor * __autoreleasing _Nullable * _Nonnull)color
				   toView:(UIView * __autoreleasing _Nonnull * _Nonnull)view
				  oldView:(UIView * __autoreleasing _Nonnull * _Nonnull)oldView;
@end

@protocol GXControlTableGridItemDelegate <GXControlThemeClassDelegate>

@optional
- (void)controlTableGridItem:(GXControlTableGridItem *)control didChangeDragDropState:(GXDragDropState)oldState;
- (nullable UIView *)controlTableGridItemDragableControlView:(GXControlTableGridItem *)control;

@end
#endif // !TARGET_OS_WATCH

@interface GXControlTableGridItem : GXControlTable

#if !TARGET_OS_WATCH
@property(nonatomic, assign) BOOL handleGridItemHighlightOnTouch;
@property(nonatomic, assign) BOOL tableLayoutElementTablePercentDimensionAs100; // if YES, tableLayoutElementTableWidth/Height returns GXLayoutDimension100Percent if unit is percent
@property(nullable, nonatomic, weak) id<GXControlTableGridItemDelegate> tableGridItemDelegate;
#endif // !TARGET_OS_WATCH
@property(nullable, nonatomic, strong, readonly) NSString *layoutGridItemName;
@property(nonatomic, assign, readonly) BOOL shouldApplyNonLayoutControlDynamicProperties;


#if !TARGET_OS_WATCH
- (instancetype)initWithLayoutElement:(id <GXLayoutElement>)layoutElement
				   layoutGridItemName:(nullable NSString *)layoutGridItemName
					   dataDescriptor:(id<GXEntityDataDescriptor>)dataDescriptor
			   businessComponentLevel:(nullable GXBusinessComponentLevel *)businessComponentLevel
							controlId:(NSUInteger)controlId
							   gxMode:(GXModeType)modeType
						 indexerStack:(nullable NSArray<NSNumber *> *)indexer
						parentControl:(id<GXControlContainer>)parentControl
							relations:(nullable NSDictionary *)relationsByDataElementName NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithLayoutElement:(id <GXLayoutElement>)layoutElement
					   dataDescriptor:(id<GXEntityDataDescriptor>)dataDescriptor
			   businessComponentLevel:(nullable GXBusinessComponentLevel *)businessComponentLevel
							controlId:(NSUInteger)controlId
							   gxMode:(GXModeType)modeType
						 indexerStack:(nullable NSArray<NSNumber *> *)indexer
						parentControl:(nullable id<GXControlContainer>)parentControl
							relations:(nullable NSDictionary *)relationsByDataElementName NS_UNAVAILABLE;
#else
- (instancetype)initWithInterfaceObjectsProvider:(id<GXControlInterfaceObjectsProvider>)interfaceObjectsProvider
								   layoutElement:(id <GXLayoutElement>)layoutElement
							  layoutGridItemName:(nullable NSString *)layoutGridItemName
								  dataDescriptor:(id<GXEntityDataDescriptor>)dataDescriptor
						  businessComponentLevel:(nullable GXBusinessComponentLevel *)businessComponentLevel
									   controlId:(NSUInteger)controlId
										  gxMode:(GXModeType)modeType
									indexerStack:(nullable NSArray<NSNumber *> *)indexer
								   parentControl:(id<GXControlContainer>)parentControl
									   relations:(nullable NSDictionary *)relationsByDataElementName NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithInterfaceObject:(WKInterfaceObject *)interfaceObject
						  layoutElement:(id <GXLayoutElement>)layoutElement
						 dataDescriptor:(id<GXEntityDataDescriptor>)dataDescriptor
				 businessComponentLevel:(nullable GXBusinessComponentLevel *)businessComponentLevel
							  controlId:(NSUInteger)controlId
								 gxMode:(GXModeType)modeType
						   indexerStack:(nullable NSArray<NSNumber *> *)indexer
						  parentControl:(nullable id<GXControlContainer>)parentControl
							  relations:(nullable NSDictionary *)relationsByDataElementName NS_UNAVAILABLE;
#endif // !TARGET_OS_WATCH

@end

NS_ASSUME_NONNULL_END
