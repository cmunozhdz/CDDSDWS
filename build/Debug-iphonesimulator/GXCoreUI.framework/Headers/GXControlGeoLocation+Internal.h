//
//  GXControlGeoLocation+Internal.h
//  GXCoreUI
//
//  Created by José Echagüe on 3/8/18.
//  Copyright © 2018 GeneXus. All rights reserved.
//

#import <GXCoreUI/GXControlGeoLocationHelper.h>
#import <GXCoreUI/GXMapView.h>

@interface GXControlGeoLocation () {
    @protected GXControlGeoLocationHelper *_geoLocationHelper;
}

- (GXMapType)layoutElementMapType;
- (NSInteger)layoutElementZoomLevel;
- (NSInteger)layoutElementMinZoomLevel;
- (NSInteger)layoutElementMaxZoomLevel;

@end
