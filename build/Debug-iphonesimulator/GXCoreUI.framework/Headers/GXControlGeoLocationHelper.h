//
//  GXControlGeoLocationHelper.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 23/12/14.
//  Copyright (c) 2014 Artech. All rights reserved.
//

@import MapKit;
@import GXObjectsModel;
#import <GXCoreUI/GXMapView.h>

NS_ASSUME_NONNULL_BEGIN

@class GXControlGeoLocationHelper;

@protocol GXControlGeoLocationHelperDelegate <NSObject>

- (id<GXModelObject>)geolocationHelperModelObject:(GXControlGeoLocationHelper *)helper;
- (GXViewVisibleStateType)geolocationHelperMapViewVisibleState:(GXControlGeoLocationHelper *)helper;
- (void)geolocationHelper:(GXControlGeoLocationHelper *)helper showError:(NSError *)error;
- (void)geolocationHelper:(GXControlGeoLocationHelper *)helper presentAlertController:(UIAlertController *)controller fromSender:(id)sender animated:(BOOL)animated;

@optional
- (nullable NSString *)geolocationHelperTitleForAnnotation:(GXControlGeoLocationHelper *)helper;
- (void)geolocationHelper:(GXControlGeoLocationHelper *)helper didUpdateAnnotationCoordinate:(CLLocationCoordinate2D)coordinate;
- (void)geolocationHelper:(GXControlGeoLocationHelper *)helper trackingLocationBarButtonItem:(UIBarButtonItem *)barButtonItem visibleChanged:(BOOL)visible;

@end

@interface GXControlGeoLocationHelper : NSObject <CLLocationManagerDelegate>

@property(nonatomic, assign) BOOL enabled;
@property(nonatomic, assign) BOOL readOnly;
@property(nonatomic, assign) GXMapType mapType;
@property(nonatomic, assign) NSInteger zoomLevel;
@property(nonatomic, assign) NSInteger minZoomLevel;
@property(nonatomic, assign) NSInteger maxZoomLevel;
@property(nullable, nonatomic, weak) id<GXControlGeoLocationHelperDelegate> delegate;

@property(nullable, nonatomic, strong, readonly) UIView<GXMapView> *loadedMapView;
@property(nullable, nonatomic, strong, readonly) id<MKAnnotation> loadedAnnotation;
#if TARGET_OS_IOS
@property(readonly, getter=isTrackingLocation) BOOL trackingLocation;
#endif // TARGET_OS_IOS
@property(readonly, getter=hasPendingAnimateDrop) BOOL pendingAnimateDrop;

- (void)loadMapViewWithFrame:(CGRect)frame;
- (UIView<GXMapView> *)newMapViewWithFrame:(CGRect)frame; //Abstract
- (void)unloadMapView;

- (void)mapViewVisibleStateDidChange:(BOOL)animated;
- (void)mapViewTitleForAnnotationDidChange;
- (void)prepareForReuse;

- (void)loadAnnotationWithCoordinate:(CLLocationCoordinate2D)coordinate
					   animateChange:(BOOL)animateChange
						 animateDrop:(BOOL)animateDrop
			  showAnnotationOnChange:(BOOL)showAnnotationOnChange;

- (void)showAnnotation:(BOOL)animated;

#if TARGET_OS_IOS
- (void)startUpdatingLocation;
- (void)stopUpdatingLocation;
#endif // TARGET_OS_IOS

@end

NS_ASSUME_NONNULL_END
