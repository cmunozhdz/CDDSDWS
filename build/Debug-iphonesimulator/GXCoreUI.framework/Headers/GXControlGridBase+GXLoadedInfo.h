//
//  GXControlGridBase+GXLoadedInfo.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 10/5/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

#import <GXCoreUI/GXControlGridBase.h>
#import <GXCoreUI/GXControlGridBaseLoadedInfo.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXControlGridBase (GXLoadedInfo)

+ (nonnull Class)loadedInfoClass;

@property(nonatomic, strong, readonly) GXControlGridBaseLoadedInfo *loadedInfo; // Lazzy, created on first call
@property(nonatomic, strong, readonly) GXControlGridBaseLoadedInfo *filteredLoadedInfo; // Lazzy, created on first call

@property(nonatomic, assign, readonly, getter=isLoadedInfoLoaded) BOOL loadedInfoLoaded;
@property(nonatomic, assign, readonly, getter=isFilteredLoadedInfoLoaded) BOOL filteredLoadedInfoLoaded;
- (BOOL)isLoadedInfoLoaded:(BOOL)filtered;

- (void)updateLoadedInfoFromProvider:(BOOL)updateItemsCount;
- (void)updateLoadedInfoFromProvider:(BOOL)updateItemsCount filtered:(BOOL)filtered;
- (void)updateFilteredLoadedInfoFromProvider:(BOOL)updateItemsCount;

- (void)updateLoadedInfoNumberOfLoadedItemsInSection:(NSUInteger)sectionIndex;
- (void)updateLoadedInfoNumberOfLoadedItemsInSection:(NSUInteger)sectionIndex filtered:(BOOL)filtered;
- (void)updateFilteredLoadedInfoNumberOfLoadedItemsInSection:(NSUInteger)sectionIndex;

@end

NS_ASSUME_NONNULL_END
