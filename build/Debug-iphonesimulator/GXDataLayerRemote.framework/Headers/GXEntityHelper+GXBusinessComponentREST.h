//
//  GXEntityHelper+GXBusinessComponentREST.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 29/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@interface GXEntityHelper (GXBusinessComponentREST)

+ (nullable NSURL *)businessComponentURLFromLevel:(GXBusinessComponentLevel *)bcLevel
											  key:(id <GXEntityDataKey>)key;

+ (nullable NSURL *)businessComponentDefaultURLFromModel:(GXBusinessComponentModel *)bcModel;

/// #deprecated: 2022-01-26: trunk; #to-remove: ??
+ (nullable NSURL *)businessComponentDefaultURLFromName:(NSString *)bcName __attribute__((deprecated("Use businessComponentDefaultURLFromModel: instead")));

+ (nullable NSString *)fileUploadURLPathComponentForBusinessComponentLevel:(GXBusinessComponentLevel *)bcLevel;

@end

NS_ASSUME_NONNULL_END
