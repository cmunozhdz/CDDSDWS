//
//  NSIndexPath+GXEntityDataListProvider.h
//  GXDataLayer
//
//  Created by Fabian Inthamoussu on 9/1/17.
//  Copyright © 2017 GeneXus. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface NSIndexPath (GXEntityDataListProvider)

+ (instancetype)indexPathForGXEntityDataIndex:(NSInteger)index inSection:(NSInteger)section;

@property(nonatomic, readonly) NSInteger gxEntityDataSection;
@property(nonatomic, readonly) NSInteger gxEntityDataIndex;

@end

NS_ASSUME_NONNULL_END
