//
//  GXControlBase+GXThemeClassPropertiesOverrides.h
//  GXCoreUI
//
//  Created by Fabian Inthamoussu on 16/07/2019.
//  Copyright © 2019 GeneXus. All rights reserved.
//

@import GXObjectsModel;
#import <GXCoreUI/GXControlBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXControlBase (GXStyleClassPropertiesOverrides) <GXStyleClassPropertiesOverrides>

/// Returns the value previously stored with setStyleClassPropertyValueOverride:forName:
- (nullable id)styleClassPropertyValueOverrideForName:(GXStyleClassPropertyName)propertyName;
/// Stores the given value for the given property name. If propertyValue == nil, removes the override for the given property name.
- (void)setStyleClassPropertyValueOverride:(nullable id)propertyValue forName:(GXStyleClassPropertyName)propertyName;
/// Removes the override for the given property name. Same as calling [self setStyleClassPropertyValueOverride:nil forName:propertyName].
- (void)removeStyleClassPropertyValueOverrideForName:(GXStyleClassPropertyName)propertyName;

/**
 * Called on setStyleClassPropertyValueOverride:forName: if the property value changes
 * Default implementation calls [self onStyleClassChanged:self.styleClass]
 */
- (void)onStyleClassPropertyValueOverrideDidChange:(GXStyleClassPropertyName)propertyName oldValue:(nullable id)oldPropertyValue;

@end

NS_ASSUME_NONNULL_END
