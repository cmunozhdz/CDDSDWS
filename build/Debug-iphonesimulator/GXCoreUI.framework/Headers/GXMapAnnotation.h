//
//  GXMapAnnotation.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 19/07/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

@import Foundation;
@import MapKit;

@interface GXMapAnnotation : NSObject <MKAnnotation>

#pragma mark - MKAnnotation

@property (nonatomic, readwrite, assign) CLLocationCoordinate2D coordinate;

@property (nonatomic, readwrite, copy) NSString *title;
@property (nonatomic, readwrite, copy) NSString *subtitle;

@end