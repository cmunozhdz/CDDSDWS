//
//  UITableViewCell+GXHelpers.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 22/01/2019.
//  Copyright © 2019 GeneXus. All rights reserved.
//

@import UIKit;
@import GXFoundation;

NS_ASSUME_NONNULL_BEGIN

@protocol GXTableViewCellLazySubviewsOptionals <NSObject>

@optional
@property(nonatomic, readonly) BOOL gxOptionalHasImageView;
@property(nonatomic, readonly) BOOL gxOptionalHasTextLabel;
@property(nonatomic, readonly) BOOL gxOptionalHasDetailTextLabel;

@end

@interface UITableViewCell (GXHelpers) <GXTableViewCellLazySubviewsOptionals>

@property(nonatomic, readonly) GXOptionalBoolean gxHasImageView;
@property(nonatomic, readonly) GXOptionalBoolean gxHasTextLabel;
@property(nonatomic, readonly) GXOptionalBoolean gxHasDetailTextLabel;

/// Image view will be created if necessary if gxHasImageView == GXOptionalBooleanUnknown
@property(nonatomic, readonly, strong, nullable) UIImageView *gxImageViewIfLoaded;
/// Label will be created if necessary if gxHasTextLabel == GXOptionalBooleanUnknown
@property(nonatomic, readonly, strong, nullable) UILabel *gxTextLabelIfLoaded;
/// Label will be created if necessary if gxHasDetailTextLabel == GXOptionalBooleanUnknown (and the current style supports a detail label)
@property (nonatomic, readonly, strong, nullable) UILabel *gxDetailTextLabelIfLoaded;

@end

typedef struct GXTableViewCellLazySubviewsOptionalsStruct {
	unsigned hasImageView:1;
	unsigned hasTextLabel:1;
	unsigned hasDetailTextLabel:1;
} GXTableViewCellLazySubviewsOptionalsStruct;
NS_ASSUME_NONNULL_END
