//
//  GXControlGeoLocationHelper+Internal.h
//  GXCoreUI-iOS
//
//  Created by José Echagüe on 3/2/18.
//  Copyright © 2018 GeneXus. All rights reserved.
//

@import MapKit;
@import GXObjectsModel;
#import <GXCoreUI/GXControlGeoLocationHelper.h>
#import <GXCoreUI/GXMapAnnotation.h>
#import <GXCoreUI/GXMapView.h>

NS_ASSUME_NONNULL_BEGIN

#define kGXRemovePinString @"GXM_RemovePin"
#define kGXCancelString @"GXM_cancel"

@interface GXControlGeoLocationHelper () {
	@protected UIView<GXMapView> * _Nullable _mapView;
	@protected GXMapAnnotation * _Nullable _annotation;
	@protected BOOL _animateDrop;
}

- (void)reloadEditorSubviews;

- (void)updateReadOnly:(BOOL)updateReadOnly
         updateEnabled:(BOOL)updateEnabled
            annotation:(nullable GXMapAnnotation *)annotation
               mapView:(nullable UIView<GXMapView> *)mapView
        annotationView:(nullable MKPinAnnotationView *)annotationView;

- (void)internalUpdateAnnotationCoordinate:(CLLocationCoordinate2D)coordinate
                             animateChange:(BOOL)animateChange
                               animateDrop:(BOOL)animateDrop
                    showAnnotationOnChange:(BOOL)showAnnotationOnChange;

- (void)handleRemoveLoadedAnnotation;

- (void)reverseGeocodeLoadedAnnotation;

+ (id<MKAnnotation>)createEmptyAnnotation; //Abstract

@end

NS_ASSUME_NONNULL_END
