//
//  GXModel+GXUserData.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 14/12/15.
//  Copyright © 2015 GeneXus. All rights reserved.
//

#import <GXObjectsModel/GXModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXModel (GXUserData)

- (void)removeUserDataForKey:(NSString *)key;
- (void)setUserData:(id)userData forKey:(NSString *)key; // Plist valid value
- (nullable id)getUserDataForKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
