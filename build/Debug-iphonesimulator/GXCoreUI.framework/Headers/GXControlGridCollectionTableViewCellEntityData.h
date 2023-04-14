//
//  GXControlGridCollectionTableViewCellEntityData.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 20/6/17.
//  Copyright © 2017 GeneXus. All rights reserved.
//

#import <GXCoreUI/GXControlGridCollectionTableViewCell.h>
#import <GXCoreUI/GXControlGridItem.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GXControlGridCollectionTableViewCellEntityData <GXControlGridCollectionTableViewCell, GXControlGridItem>

- (void)initializeWithGridItemTable:(GXControlTableGridItem *)gridItemTable relativeSizeForPercentDimension:(CGSize)relativeSizeForPercentDimension;

@end

NS_ASSUME_NONNULL_END
