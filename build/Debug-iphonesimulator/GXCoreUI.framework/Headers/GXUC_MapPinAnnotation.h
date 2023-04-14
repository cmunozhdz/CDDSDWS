//
//  GXUC_MapPinAnnotation.h
//  GXUCMaps-iOS/
//
//  Created by José Echagüe on 2/27/18.
//  Copyright © 2018 GeneXus. All rights reserved.
//

@import UIKit;
@import GXObjectsModel;
@import MapKit;
#import <GXCoreUI/SDMapPinImageThemeClass.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXUC_MapPinAnnotation <MKAnnotation>

@property (nonatomic, readonly, strong) id <GXEntityData> entityData;
@property (nonatomic, readonly, strong) NSIndexPath *indexPath;
@property (nullable, nonatomic, readonly, strong) NSString *animationKey;
@property (nullable, nonatomic, readonly, strong) NSString *geometryLayerId;
@property (nonnull, nonatomic, readonly, strong) NSString *geometryId;

@property (nullable, nonatomic, strong) id pinImageFieldValue;
@property (nullable, nonatomic, strong) GXStyleClass *pinImageStyleClass;

@property (nonatomic, readwrite) CLLocationCoordinate2D coordinate;

- (instancetype)initWithLocation:(CLLocationCoordinate2D)location
                      entityData:(id <GXEntityData>)entityData
                       indexPath:(NSIndexPath *)indexPath
					animationKey:(nullable NSString *)animationKey
				 geometryLayerId:(nullable NSString *)geometryLayerId;

#if !TARGET_OS_WATCH
@property (nullable, nonatomic, strong, readwrite) UIViewPropertyAnimator *forwardAnimator NS_AVAILABLE_IOS(10.0);
@property (nullable, nonatomic, strong, readwrite) UIViewPropertyAnimator *backwardAnimator NS_AVAILABLE_IOS(10.0);
#endif // !TARGET_OS_WATCH

@end

NS_ASSUME_NONNULL_END

