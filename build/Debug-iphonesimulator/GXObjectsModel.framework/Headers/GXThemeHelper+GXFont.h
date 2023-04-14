//
//  GXThemeHelper+GXFont.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 12/2/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import UIKit;
#import <GXObjectsModel/GXThemeHelper.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXStyleHelper (GXFont)

+ (nullable NSDictionary<NSAttributedStringKey, id> *)textAttributesForFont:(nullable UIFont *)font textColor:(nullable UIColor *)color;

@end

NS_ASSUME_NONNULL_END
