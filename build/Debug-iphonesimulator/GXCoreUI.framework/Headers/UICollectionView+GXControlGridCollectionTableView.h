//
//  UICollectionView+GXControlGridCollectionTableView.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 20/6/17.
//  Copyright © 2017 GeneXus. All rights reserved.
//

#import <GXCoreUI/GXControlGridCollectionTableView.h>
#import <GXCoreUI/UICollectionViewCell+GXControlGridCollectionTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface UICollectionView (GXControlGridCollectionTableView) <GXControlGridCollectionTableView>

+ (UICollectionViewScrollPosition)scrollPosistionFromGXScrollPisition:(GXControlGridCollectionTableViewScrollPosition)scrollPosition;

@end

NS_ASSUME_NONNULL_END
