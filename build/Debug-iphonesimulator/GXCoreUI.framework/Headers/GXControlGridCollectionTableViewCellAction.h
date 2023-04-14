//
//  GXControlGridCollectionTableViewCellAction.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 23/6/17.
//  Copyright © 2017 GeneXus. All rights reserved.
//

#import <GXCoreUI/GXControlGridCollectionTableViewCell.h>

@protocol GXActivityIndicatorView;

NS_ASSUME_NONNULL_BEGIN

@protocol GXControlGridCollectionTableViewCellAction <GXControlGridCollectionTableViewCell>

- (void)gxGridCellActionStartAnimating;
- (void)gxGridCellActionStopAnimating;

@property(nonatomic, readonly, getter=isGridCellActionAnimating) BOOL gxGridCellActionAnimating;

@property(nullable, nonatomic, copy) NSString *gxGridCellActionText;
@property(null_resettable, nonatomic,strong) UIColor *gxGridCellActionTextColor;

@property(nonatomic) BOOL gxGridCellActionAllowsSelection;

@optional
@property(nullable, nonatomic, strong) NSString *gxGridCellActionActivityIndicatorTypeIdentifier;
@property(nonatomic, strong, readonly) id<GXActivityIndicatorView> gxGridCellActionActivityIndicatorView;

@end

NS_ASSUME_NONNULL_END
