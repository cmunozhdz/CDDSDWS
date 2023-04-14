//
//  GXMKMapView.h
//  GXCoreUI
//
//  Created by José Echagüe on 12/9/21.
//  Copyright © 2021 GeneXus. All rights reserved.
//

@import Foundation;
@import MapKit;

#import <GXCoreUI/GXMapView.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXMKMapView : MKMapView

@property(nonatomic, readwrite, strong) NSArray<id<MKOverlay>> *drawnOverlays;
@property(nonatomic, readwrite, strong) NSArray<id<MKAnnotation>> *nonPersistentAnnotations;
@property(nonatomic, readwrite, assign) float minZoomLevel;
@property(nonatomic, readwrite, assign) float maxZoomLevel;
@property(nonatomic, readwrite, weak) id<GXMapViewDelegate> gxMapViewDelegate;

@end

NS_ASSUME_NONNULL_END
