//
//  GXThemeClassPropertiesOverridesWithDictionary.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 16/07/2019.
//  Copyright © 2019 GeneXus. All rights reserved.
//

@import GXObjectsModel;

NS_ASSUME_NONNULL_BEGIN

@interface GXStyleClassPropertiesOverridesWithDictionary : NSObject <GXStyleClassPropertiesOverrides>

- (instancetype)initWithPropertiesOverridesByName:(NSDictionary<GXStyleClassPropertyName, id> *)propertiesOverridesByName NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
