//
//  GXControlGeoLocation.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 09/05/11.
//  Copyright 2011 Artech. All rights reserved.
//

#import <GXCoreUI/GXControlEditableWithLabelSingleEditorViewBase.h>
#import <GXCoreUI/GXControlGeoLocationHelper.h>

@interface GXControlGeoLocation : GXControlEditableWithLabelSingleEditorViewBase <GXControlGeoLocationHelperDelegate>

+ (BOOL)shouldUseGeoLocationControlForFieldInfo:(id <GXEntityDataFieldInfo>) fieldInfo
							  layoutElementData:(id <GXLayoutElementData>)layoutElementData;

@end

#pragma mark - Reuse


@interface GXControlGeoLocationReuseContext : GXControlEditableWithLabelBaseReuseContext

@property(nonatomic, assign) BOOL restoreLayoutMapType;
@property(nonatomic, assign) BOOL restoreLayoutZoomLevel;

@end

@interface GXControlGeoLocation (Reuse)

@property(nonatomic, strong, readonly) GXControlGeoLocationReuseContext *geolocationReuseContext;

@end
