//
//  GXControlComponentProtocol.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 27/02/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import GXDataLayer;
#import <GXCoreUI/GXControlContainer.h>
#if !TARGET_OS_WATCH
#import <GXCoreUI/GXControlWithActionBarItems.h>
#endif // !TARGET_OS_WATCH

NS_ASSUME_NONNULL_BEGIN

#if TARGET_OS_WATCH
@protocol GXControlComponent <GXControlContainerWithDataProvider, GXControlRuntimePropertiesProxy, GXObjectWithParameters>
#else
@protocol GXControlComponent <GXControlContainerWithDataProvider, GXControlRuntimePropertiesProxy, GXControlWithActionBarItems, GXObjectWithParameters>
#endif // TARGET_OS_WATCH

@property(nullable, nonatomic, weak) id<GXControlComponentDelegate> controlComponentDelegate;

@property(nonatomic, strong, readonly) id <GXEntityModel> componentEntityModel;
@property(nonatomic, strong, readonly) id <GXEntityDataDetailProvider> componentEntityDataDetailProvider;

@property(nullable, nonatomic, strong, readonly) id <GXLayout> componentCurrentLayout;

@property(nullable, nonatomic, strong, readonly) id <GXControlActionsDispatcher> componentActionsDispatcher;

- (GXClientStartExecutionState)componentClientStartExecutionState;
@property(nullable, nonatomic, strong, readonly) id <GXClientStartExecutionContext> componentClientStartExecutionContext;
- (BOOL)componentExecuteClientStartIfNeeded;

@optional

@end

#pragma mark - GXControlComponentDelegate

@protocol GXControlComponentClientStartDelegate;
@protocol GXControlComponentProviderDelegate;
@protocol GXControlComponentDynamicPropertiesDelegate;
@protocol GXControlComponentControlPropertiesDelegate;
@protocol GXControlComponentControlMethodsDelegate;

@protocol GXControlComponentDelegate <GXControlComponentClientStartDelegate, GXControlComponentProviderDelegate, GXControlComponentDynamicPropertiesDelegate, GXControlComponentControlPropertiesDelegate, GXControlComponentControlMethodsDelegate>
@end

#pragma mark - ClientStart

@protocol GXControlComponentClientStartDelegate <NSObject>

- (BOOL)controlComponentCanExecuteClientStart:(id <GXControlComponent>)control;

@end

#pragma mark - DataProvider

@protocol GXControlComponentProviderDelegate <NSObject>

- (void)controlComponentProviderDidLoad:(id <GXControlComponent>)control;
- (void)controlComponent:(id <GXControlComponent>)control providerDidFailLoadingWithError:(NSError *)error;

- (void)controlComponentProviderLoadedEntityDataUpdated:(id <GXControlComponent>)control;
- (void)controlComponentProviderLoadedEntityDataDeleted:(id <GXControlComponent>)control;

- (void)controlComponentProviderDidUnload:(id <GXControlComponent>)control;

@optional
- (void)controlComponentMutableProviderDidSave:(id <GXControlComponent>)control;
- (BOOL)controlComponent:(id <GXControlComponent>)control mutableProviderDidFailSavingWithError:(NSError *)error;
- (void)controlComponentMutableProviderDidDelete:(id <GXControlComponent>)control;
- (BOOL)controlComponent:(id <GXControlComponent>)control mutableProviderDidFailDeletingWithError:(NSError *)error;

- (BOOL)controlComponentShouldReloadProviderIfNeededOnViewDidAppear:(id <GXControlComponent>)control;

@end


#pragma mark - Dynamic Properties

@protocol GXControlComponentDynamicPropertiesDelegate <NSObject>

- (void)controlComponent:(id <GXControlComponent>)control applyNonLayoutControlDynamicProperty:(__kindof GXControlDynamicPropertyBase *)dynPropery;

@end


#pragma mark - Control Properties

@protocol GXControlComponentControlPropertiesDelegate <NSObject>

- (nullable id)controlComponent:(id <GXControlComponent>)control
	   valueForNonLayoutControl:(NSString *)controlName
					   property:(NSString *)propName
		   userInterfaceContext:(nullable GXUserInterfaceContext *)uiContext;

- (void)controlComponent:(id <GXControlComponent>)control
   applyNonLayoutControl:(NSString *)controlName
				property:(NSString *)propName
				   value:(nullable id)value
	userInterfaceContext:(nullable GXUserInterfaceContext *)uiContext
	   contextEntityData:(nullable id<GXEntityDataWithOverrideValues>)contextEntityData;

@end


#pragma mark - Control Methods

@protocol GXControlComponentControlMethodsDelegate <NSObject>

- (nullable id)controlComponent:(id <GXControlComponent>)control
		executeNonLayoutControl:(NSString *)controlName
						 method:(NSString *)methodName
					 parameters:(NSArray *)parameters
		   userInterfaceContext:(nullable GXUserInterfaceContext *)uiContext
			  contextEntityData:(nullable id<GXEntityDataWithOverrideValues>)contextEntityData;

@end

NS_ASSUME_NONNULL_END
