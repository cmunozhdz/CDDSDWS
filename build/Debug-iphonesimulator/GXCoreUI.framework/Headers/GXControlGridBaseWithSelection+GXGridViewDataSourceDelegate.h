//
//  GXControlGridBaseWithSelection+GXGridViewDataSourceDelegate.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 24/11/17.
//  Copyright © 2017 GeneXus. All rights reserved.
//

#import <GXCoreUI/GXControlGridBaseWithSelection.h>
#import <GXCoreUI/GXControlGridBase+GXGridViewDataSourceDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXControlGridBaseWithSelection (GXGridViewDataSourceDelegate)

- (NSString *)cellIdentifierForEntityData:(inout id <GXEntityDataWithOverrideValues> __autoreleasing _Nullable * _Nonnull)entityData
				   atProviderIndexPathRow:(NSUInteger)pIndexPathRow
						 indexPathSection:(NSUInteger)pIndexPathSection
								 filtered:(BOOL)filtered
							   layoutName:(out NSString * __autoreleasing _Nullable * _Nullable)layoutName
								 selected:(out BOOL * _Nullable)isGridItemSelected
			  highlightStyleModifierFlags:(out GXControlGridItemHighlightStyleModifierFlags * _Nullable)hStyleMod;

@end

NS_ASSUME_NONNULL_END
