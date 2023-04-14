//
//  GXUC_MapKitPinAnnotation.h
//  GXUCMaps
//
//  Created by willy on 2/3/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import MapKit;
#import <GXCoreUI/GXUC_MapPinAnnotation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXUC_MapKitPinAnnotation : NSObject <GXUC_MapPinAnnotation>

@property (nullable, nonatomic, weak) id<MKAnnotation> callout;

- (instancetype)initWithLocation:(CLLocationCoordinate2D)location
                      entityData:(id <GXEntityData>)entityData
                       indexPath:(NSIndexPath *)indexPath
					animationKey:(nullable NSString *)animationKey
				 geometryLayerId:(nullable NSString *)geometryLayerId NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
