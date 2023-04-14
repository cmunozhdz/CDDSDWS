//
//  GXControlGridBase+GXAsyncReload.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 11/5/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

#import <GXCoreUI/GXControlGridBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXControlGridBase (GXAsyncReload)

/// Adds the given index path to be reloaded async
- (void)addIndexPathToBeReloaded:(NSIndexPath *)vIndexPath;

/// Clears all pending index paths to be reloaded async added with addIndexPathToBeReloaded:
- (void)clearPendingReloadIndexPaths;

/*!
 Reloads the given index paths
 
 @param vReloadIndexPaths The index paths of grid items to be reloaded. Note indexes must be handled as unsafe, as items may not exist anymore at these indexes.
 @discussion Default implementation calls reloadData if view is loaded.
 */
- (void)reloadPendingReloadIndexPaths:(NSArray<NSIndexPath *> *)vReloadIndexPaths;

@end

NS_ASSUME_NONNULL_END
