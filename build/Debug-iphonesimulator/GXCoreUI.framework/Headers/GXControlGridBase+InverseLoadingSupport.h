//
//  GXControlGridBase+InverseLoadingSupport.h
//  GXCoreUI
//
//  Created by Marcos Crispino on 5/8/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

#import <GXCoreUI/GXControlGridBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXControlGridBase (InverseLoadingSupport)

- (BOOL)isInReverseOrder;

- (nullable NSIndexPath *)viewIndexPathFromProviderIndexPath:(NSIndexPath *)pIndexPath;

- (nullable NSIndexPath *)providerIndexPathFromViewIndexPath:(NSIndexPath *)vIndexPath;

- (NSUInteger)viewSectionFromProviderSection:(NSUInteger)pSection;

- (NSUInteger)providerSectionFromViewSection:(NSUInteger)vSection;

@end

NS_ASSUME_NONNULL_END
