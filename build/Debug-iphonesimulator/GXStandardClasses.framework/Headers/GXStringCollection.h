//
//  GXStringCollection.h
//  GXStd
//
//  Created by Marcos Crispino on 30/10/12.
//  Copyright (c) 2012 Artech. All rights reserved.
//

#import <GXStandardClasses/GXObjectCollection.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXStringCollection : GXObjectCollection

/// #deprecated: 2022-02-19: trunk; #to-remove: ??
+ (GXStringCollection *)stringCollectionFromString:(nullable NSString *)list __deprecated_msg("Use `initWithArray:embeddedModelObject:` instead");

- (NSString *)stringAtIndex:(NSInteger)index;

- (NSString *)getString;

@end

NS_ASSUME_NONNULL_END
