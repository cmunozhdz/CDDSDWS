//
//  GXOfflineHelper.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 4/5/16.
//  Copyright © 2016 GeneXus. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface GXOfflineHelper : NSObject

/// #deprecated: 2022-02-10: trunk; #to-remove: ??
+ (BOOL)isSwiftGenerator __attribute__((deprecated("Always returns true. ObjC generator is no longer available.")));

@end

NS_ASSUME_NONNULL_END
