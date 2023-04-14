//
//  GXControlGridBaseLoadedInfo+Subclasses.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 9/5/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

#import <GXCoreUI/GXControlGridBaseLoadedInfo.h>

NS_ASSUME_NONNULL_BEGIN

#if !TARGET_OS_WATCH
@protocol GXControlGridItemHeightLoadedInfoDelegate <NSObject>

- (void)controlGridItemHeightLoadedInfo:(GXControlGridItemHeightLoadedInfo *)itemHeights
					didChangeItemHeight:(CGFloat)oldItemHeight
					  withNewItemHeight:(CGFloat)newItemHeight
							atIndexPath:(NSIndexPath *)indexPath;

@end
#endif // !TARGET_OS_WATCH

#if !TARGET_OS_WATCH
@interface GXControlGridBaseLoadedInfo (Subclasses) <GXControlGridItemHeightLoadedInfoDelegate>
#else
@interface GXControlGridBaseLoadedInfo (Subclasses)
#endif // !TARGET_OS_WATCH

// Called on setNumberOfLoadedSectionsWithoutSupplementaryElements:
- (void)willRemoveLoadedSectionsCountInRange:(NSRange)rangeToRemove;

#if !TARGET_OS_WATCH
// Same as calculatedItemHeights & runtimeItemHeights but returns nil if not loaded yet
@property(nonatomic, strong, readonly, nullable) GXControlGridItemHeightLoadedInfo *loadedCalculatedItemHeights;
@property(nonatomic, strong, readonly, nullable) GXControlGridItemHeightLoadedInfo *loadedRuntimeItemHeights;

@property(nonatomic, assign, readonly) BOOL itemHeightsLoadedInfoDelegateRequired;
- (void)invalidateItemHeightsLoadedInfoDelegateRequired;
#endif // !TARGET_OS_WATCH

@end

NS_ASSUME_NONNULL_END
