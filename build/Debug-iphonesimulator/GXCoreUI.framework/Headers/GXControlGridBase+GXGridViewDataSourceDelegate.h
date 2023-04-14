//
//  GXControlGridBase+GXGridViewDataSourceDelegate.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 24/11/17.
//  Copyright © 2017 GeneXus. All rights reserved.
//

#import <GXCoreUI/GXControlGridBase.h>
#import <GXCoreUI/GXControlGridItem.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXControlGridBase (GXGridViewDataSourceDelegate)

- (NSString *)cellIdentifierForEntityData:(inout id <GXEntityDataWithOverrideValues> __autoreleasing _Nullable * _Nonnull)entityData
				   atProviderIndexPathRow:(NSUInteger)pIndexPathRow
						 indexPathSection:(NSUInteger)pIndexPathSection
								 filtered:(BOOL)filtered
							   layoutName:(out NSString * __autoreleasing _Nullable * _Nullable)layoutName
			  highlightStyleModifierFlags:(out GXControlGridItemHighlightStyleModifierFlags * _Nullable)hStyleMod;

- (NSString *)cellIdentifierForEntityDataCellAtEvenIndex:(BOOL)evenCell
								 withLayoutLowercaseName:(nullable NSString *)layoutLowecaseName; // evenCellAsOddCellIfSameListItemThemeClasses:YES
- (NSString *)cellIdentifierForEntityDataCellAtEvenIndex:(BOOL)evenCell
			 evenCellAsOddCellIfSameListItemThemeClasses:(BOOL)ignoreEvenCell
								 withLayoutLowercaseName:(nullable NSString *)layoutLowecaseName;

- (GXControlGridItemHighlightStyleModifierFlags)highlightStyleModifiersForEntityDataAtIndex:(NSUInteger)index section:(NSUInteger)section filtered:(BOOL)filtered;

- (void)updateGridViewVisibleEntityDataCellsGridItemThemeClass:(UIView *)gridView; // Default implementation does nothing
- (void)updateGridViewVisibleEntityDataCellsGridItemRelativeSizeForPercentDimension:(UIView *)gridView; // Default implementation does nothing

@end

NS_ASSUME_NONNULL_END
