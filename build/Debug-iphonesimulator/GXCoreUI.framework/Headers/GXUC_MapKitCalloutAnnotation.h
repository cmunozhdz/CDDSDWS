//
//  GXUC_MapKitCalloutAnnotation.h
//  GXUCMaps
//
//  Created by willy on 2/3/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import Foundation;
@import MapKit;

NS_ASSUME_NONNULL_BEGIN

@interface GXUC_MapKitCalloutAnnotation : NSObject <MKAnnotation>

@property(nullable, nonatomic, weak) id<MKAnnotation> parentAnnotation;

- (instancetype)initWithParentAnnotation:(id<MKAnnotation>)parentAnnotation NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
