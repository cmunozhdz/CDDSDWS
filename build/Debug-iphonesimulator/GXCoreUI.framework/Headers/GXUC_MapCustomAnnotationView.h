//
//  GXUC_MapCustomAnnotationView.h
//  GXUCMaps
//
//  Created by Marcos Crispino on 12/07/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import Foundation;
@import MapKit;
@import GXObjectsModel;
@import GXCoreBL;
#import <GXCoreUI/SDMapPinImageThemeClass.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXMapCustomAnnotationViewLoadingDelegate <NSObject>

- (void)didSet:(UIImage *)image forAnnotation:(id<MKAnnotation>)annotation;

@end

@interface GXUC_MapCustomAnnotationView : MKAnnotationView

@property(nullable, nonatomic, weak, readwrite) id<GXMapCustomAnnotationViewLoadingDelegate> loadingDelegate;

@property(nonatomic, assign, readonly) BOOL hasPlaceholderPinImage;

- (void)gxSetImageFromEntityDataFieldValue:(nullable id)entityDataFieldValue
							   modelObject:(nullable id<GXModelObject>)modelObject;

/// #deprecated: 2022-02-01: trunk; #to-remove: ??
- (void)gxSetImageFromEntityDataFieldValue:(nullable id)entityDataFieldValue __attribute__((deprecated("Use gxSetImageFromEntityDataFieldValue:modelObject: instead")));

- (void)gxSetImageFromEntityDataFieldValue:(nullable id)entityDataFieldValue
							   modelObject:(nullable id<GXModelObject>)modelObject
								styleClass:(nullable GXStyleClass *)styleClass;

/// #deprecated: 2022-02-01: trunk; #to-remove: ??
- (void)gxSetImageFromEntityDataFieldValue:(nullable id)entityDataFieldValue
								styleClass:(nullable GXStyleClass *)styleClass __attribute__((deprecated("Use gxSetImageFromEntityDataFieldValue:modelObject:styleClass: instead")));

@end

NS_ASSUME_NONNULL_END
