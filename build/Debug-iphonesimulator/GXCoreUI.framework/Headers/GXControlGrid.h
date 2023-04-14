//
//  GXControlGrid.h
//  GXFlexibleClient
//
//  Created by willy on 8/18/11.
//  Copyright 2011 Artech. All rights reserved.
//

#import <GXCoreUI/GXControlGridCollectionTableViewBase.h>
#import <GXCoreUI/GXControlAutoHeight.h>
#import <GXCoreUI/GXControlGridItem.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXControlGrid : GXControlGridCollectionTableViewBase <UITableViewDataSource, UITableViewDelegate, GXControlAutoHeight, GXControlGridItemDelegate>

@property(nullable, nonatomic, strong, readonly) UITableView *tableView;
@property(nonatomic, assign) BOOL autoGrow;

@end

NS_ASSUME_NONNULL_END
