//
//  GXUC_MapKitList_CalloutAnnotation.h
//  GXUCMaps
//
//  Created by willy on 2/3/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import MapKit;
#import <GXCoreUI/GXControlGridItem.h>

NS_ASSUME_NONNULL_BEGIN

@class GXUC_MapListCalloutAnnotationView;

@protocol GXUC_MapKitListCalloutAnnotationViewDelegate <NSObject>
@required
- (void)mapKitListCalloutAnnotationViewDidReceiveTap:(GXUC_MapListCalloutAnnotationView *)callout;
@end

#pragma mark -

@interface MKAnnotationView (GXControlGridReusableItem) <GXControlGridReusableItem>
@end

@interface GXUC_MapListCalloutAnnotationView : MKAnnotationView <GXControlGridItem, GXControlAutoHeightDelegate, GXControlTableGridItemDelegate, UIGestureRecognizerDelegate>

- (instancetype)initWithInnerTable:(nullable GXControlTableGridItem *)innerTable
						annotation:(nullable id<MKAnnotation>)annotation
				   reuseIdentifier:(nullable NSString *)reuseIdentifier;
- (instancetype)initWithInnerTable:(nullable GXControlTableGridItem *)innerTable
						annotation:(nullable id<MKAnnotation>)annotation
				   reuseIdentifier:(nullable NSString *)reuseIdentifier
   relativeSizeForPercentDimension:(CGSize)relativeSizeForPercentDimension NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithAnnotation:(nullable id <MKAnnotation>)annotation reuseIdentifier:(nullable NSString *)reuseIdentifier;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

@property(nonatomic, strong, readonly) UIView *contentView;

@end

NS_ASSUME_NONNULL_END
