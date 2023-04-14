//
//  GXControlGridCollectionTableViewCell.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 20/6/17.
//  Copyright © 2017 GeneXus. All rights reserved.
//

#import <GXCoreUI/GXControlGridItem.h>
#import <GXCoreUI/GXBackgroundViewContainerProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXControlGridCollectionTableViewCell <GXControlGridReusableItem, GXBackgroundViewContainer>

@property(nonatomic, strong, readonly) UIView *gxContentView; // add custom subviews to the cell's contentView
@property(nonatomic) BOOL gxSelected;
@property(nonatomic) BOOL gxHighlighted;

//@property(nonatomic, strong, nullable) UIView *gxBackgroundView; // from GXBackgroundViewContainer
@property(nonatomic, strong, nullable) UIView *gxSelectedBackgroundView;

- (CGSize)gxRequiredSizeGivenInsets:(GXLayoutQuadDimension)cellInsets;

@optional
@property(nonatomic, strong, readonly, nullable) NSIndexPath *gxItemIndexPath;

@end

NS_ASSUME_NONNULL_END
