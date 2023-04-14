//
//  GXMapView.h
//  GXCoreUI-iOS
//
//  Created by José Echagüe on 3/2/18.
//  Copyright © 2018 GeneXus. All rights reserved.
//

@import CoreLocation;
@import MapKit;

@import GXObjectsModel;

typedef NS_ENUM(uint_least8_t, GXMapType) {
    GXMapStandard,
    GXMapSatellite,
    GXMapHybrid,
};

#define MERCATOR_OFFSET 268435456.0
#define MERCATOR_RADIUS 85445659.44705395
#define MAPVIEW_MAX_ZOOM 20.0f
#define MAPVIEW_MIN_ZOOM 1.0f

NS_ASSUME_NONNULL_BEGIN

@protocol GXMapView;
@protocol GXMapViewDelegate

- (id<GXModelObject>)mapViewModelObject:(UIView<GXMapView> *)mapView;

- (void)didResizeMapView:(UIView<GXMapView> *)mapView;

@end

@protocol GXMapView

@property(nullable, nonatomic, weak) id<GXMapViewDelegate> gxMapViewDelegate;

@property(nullable, nonatomic, readonly) NSNumber *gxMinZoomLevel;
@property(nullable, nonatomic, readonly) NSNumber *gxMaxZoomLevel;

- (NSArray<id<MKAnnotation>> *)gxAnnotations;

- (NSArray<id<MKAnnotation>> *)gxSelectedAnnotations;

- (CLLocationCoordinate2D) gxRegionCenter;

- (nullable CLLocation *)gxUserLocation;

- (CLLocationDegrees)gxLongitudeDelta;
- (CLLocationDegrees)gxLatitudeDelta;

- (BOOL)gxIsScrollEnabled;

/// #deprecated: 2022-06-29: trunk; #to-remove: ??
- (void)gxAddAnnotation:(id <MKAnnotation>)annotation __deprecated_msg("Use `gxAddAnnotation:isPersistent:` instead");
- (void)gxAddAnnotation:(id <MKAnnotation>)annotation isPersistent:(BOOL)isPersistent;
/// #deprecated: 2022-06-29: trunk; #to-remove: ??
- (void)gxAddAnnotations:(NSArray<id<MKAnnotation>> *)annotations __deprecated_msg("Use `gxAddAnnotation:arePersistent:` instead");
- (void)gxAddAnnotations:(NSArray<id<MKAnnotation>> *)annotations arePersistent:(BOOL)arePersistent;

- (void)gxRemoveAnnotation:(id <MKAnnotation>)annotation;
- (void)gxRemoveAnnotations:(NSArray<id<MKAnnotation>> *)annotations;

- (void)gxShowAnnotations:(NSArray<id<MKAnnotation>> *)annotations animated:(BOOL)animated;

- (void)gxSelectAnnotation:(id <MKAnnotation>)annotation animated:(BOOL)animated;
- (void)gxSelectAnnotationAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated;

- (void)gxDeselectAnnotation:(nullable id <MKAnnotation>)annotation animated:(BOOL)animated;
- (void)gxDeselectAnnotationAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated;

- (void)gxSetShowsUserLocation:(BOOL)showLocation;

- (void)gxSetGXMapType:(GXMapType)gxMapType;

- (void)gxSetCenterCoordinate:(CLLocationCoordinate2D)newCenterCoordinate animated:(BOOL)animated;
- (void)gxSetCenterCoordinate:(CLLocationCoordinate2D)newCenterCoordinate withZoomLevel:(float)zoomLevel animated:(BOOL)animated;

- (void)gxSetZoomLevel:(float)zoomLevel animated:(BOOL)animated;
- (float)gxZoomLevel;
- (void)gxSetMinZoomLevel:(float)minZoomLevel;
- (void)gxSetMaxZoomLevel:(float)maxZoomLevel;

@property(nonatomic, readonly) CGPoint gxMapViewCenter;
- (CLLocationCoordinate2D)gxConvertPoint:(CGPoint)point toCoordinateFromView:(UIView *)mapView;

- (nullable MKAnnotationView *)gxViewForAnnotation:(id <MKAnnotation>)annotation;

- (MKMapRect)gxVisibleMapRect;
- (void)gxSetVisibleMapRect:(MKMapRect)mapRect edgePadding:(UIEdgeInsets)adjustedMapViewEdgePadding animated:(BOOL)animated;

- (void)gxClearPolylines;
- (void)gxClear;
- (void)gxClear:(BOOL)removeAll NS_SWIFT_NAME(gxClear(removeAll:));
@end

NS_ASSUME_NONNULL_END
