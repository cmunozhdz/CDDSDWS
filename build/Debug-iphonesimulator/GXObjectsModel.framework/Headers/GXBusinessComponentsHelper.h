//
//  GXBusinessComponentsHelper.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 30/09/11.
//  Copyright (c) 2011 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXBusinessComponentLevel.h>
#import <GXObjectsModel/GXKBObjectsModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXBusinessComponentsHelper : NSObject

+ (nullable GXBusinessComponentLevel *)businessComponentLevelWithName:(NSString *)levelName
										 forBusinessComponentWithName:(NSString *)bcName
															fromModel:(GXKBObjectsModel *)model;

@end

@interface GXBusinessComponentsHelper (GXDeprecated)
/// #deprecated: 2022-01-12: trunk; #to-remove: ??
+ (nullable GXBusinessComponentLevel *)businessComponentLevelRootForBusinessComponentWithName:(nullable NSString *)bcName __attribute__((deprecated("Use GXKBObjectsModel.businessComponent(forName:)?.rootLevel instead")));

/// #deprecated: 2021-12-02: trunk; #to-remove: ??
+ (nullable GXBusinessComponentModel *)businessComponentModelForBusinessComponentWithName:(nullable NSString *)bcName __attribute__((deprecated("Use GXKBObjectsModel.businessComponent(forName:) instead")));

/// #deprecated: 2021-12-02: trunk; #to-remove: ??
+ (nullable GXBusinessComponentLevel *)businessComponentLevelWithName:(nullable NSString *)levelName
										 forBusinessComponentWithName:(nullable NSString *)bcName __attribute__((deprecated("Use businessComponentLevelWithName:forBusinessComponentWithName:fromModel: instead")));
@end

NS_ASSUME_NONNULL_END
