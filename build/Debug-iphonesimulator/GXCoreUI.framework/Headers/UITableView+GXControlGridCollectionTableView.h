//
//  UITableView+GXControlGridCollectionTableView.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 20/6/17.
//  Copyright © 2017 GeneXus. All rights reserved.
//

#import <GXCoreUI/GXControlGridCollectionTableView.h>
#import <GXCoreUI/UITableViewCell+GXControlGridCollectionTableViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface UITableView (GXControlGridCollectionTableView) <GXControlGridCollectionTableView>

+ (UITableViewScrollPosition)scrollPosistionFromGXScrollPisition:(GXControlGridCollectionTableViewScrollPosition)scrollPosition;

@end

NS_ASSUME_NONNULL_END
