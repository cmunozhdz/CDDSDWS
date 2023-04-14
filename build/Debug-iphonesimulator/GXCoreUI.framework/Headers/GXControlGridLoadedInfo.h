//
//  GXControlGridLoadedInfo.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 12/5/15.
//  Copyright (c) 2015 Artech. All rights reserved.
//

#import <GXCoreUI/GXControlGridBaseLoadedInfo.h>

@interface GXControlGridLoadedInfo : GXControlGridBaseLoadedInfo

@property(nonatomic, assign) BOOL showLoadingItemInLastSection;

@end


@interface GXControlGridLoadedInfo (ItemHeight)

@property(nonatomic, assign) BOOL keepAllItemsHeightSum;
@property(nonatomic, assign, readonly) CGFloat allItemsHeightSum;

@end
