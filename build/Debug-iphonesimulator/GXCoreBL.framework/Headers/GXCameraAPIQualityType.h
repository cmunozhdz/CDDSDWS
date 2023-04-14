//
//  GXCameraAPIQualityType.h
//  GXCoreBL
//
//  Created by Marcos Crispino on 6/23/20.
//  Copyright © 2020 GeneXus. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint_least8_t, GXCameraAPIQualityType) {
	GXCameraAPIQualityLow = 3,
	GXCameraAPIQualityMedium = 5,
	GXCameraAPIQualityHigh = 7,
};

GXCameraAPIQualityType GXCameraAPIQualityFromValue(id _Nullable value, GXCameraAPIQualityType defaultValue);

NS_ASSUME_NONNULL_END
