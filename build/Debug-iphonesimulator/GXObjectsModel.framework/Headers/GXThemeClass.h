//
//  GXThemeClass.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 11/04/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXStyleClass.h>

@class GXTheme;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint_least16_t, GXThemeClassType) {
	GXThemeClassTypeBase = 0,
	GXThemeClassTypeAttribute = 100,
	GXThemeClassTypeAttributeTitle,
	GXThemeClassTypeAttributeSubtitle,
	GXThemeClassTypeAttributeReadOnly,
	GXThemeClassTypeList = 200,
	GXThemeClassTypeListListWorkWith,
	GXThemeClassTypeListListLevel,
	GXThemeClassTypeListItem = 300,
	GXThemeClassTypeListItemEvenItem,
	GXThemeClassTypeListItemOddItem,
	GXThemeClassTypeLabel = 400,
	GXThemeClassTypeLabelTitle,
	GXThemeClassTypeLabelSubtitle,
	GXThemeClassTypeImage = 500,
    GXThemeClassTypeButton = 600,
	GXThemeClassTypeTab = 700,
	GXThemeClassTypeTabPage = 800,
	GXThemeClassTypeTabPageSelected,
	GXThemeClassTypeTabPageUnselected,
	GXThemeClassTypeTable = 900,
	GXThemeClassTypeGroup = 1000,
    GXThemeClassTypeApplication = 1100,
	GXThemeClassTypeGroupSeparator = 1200,
	GXThemeClassTypeApplicationBars = 1300,
	GXThemeClassTypeDashboardOption = 1400,
	GXThemeClassTypeHorizontalSeparator = 1500,
	GXThemeClassTypeDashboard = 1400,
	GXThemeClassTypeAnimation = 1500,
    GXThemeClassTypeProgress = 1600,
};

@interface GXThemeClass : GXStyleClass

- (instancetype)init;

@property(assign, readonly) GXThemeClassType type;
@property(nullable, weak, readonly) GXTheme *theme;
@property(nullable, weak, readonly) GXThemeClass *parentClass;
@property(nullable, nonatomic, strong, readonly) NSDictionary<NSString *, __kindof GXThemeClass *> *themeSubClassesByName;

- (nullable __kindof GXThemeClass *)themeSubClassForName:(NSString *)name;

- (BOOL)isDefaultThemeClass;

@end

NS_ASSUME_NONNULL_END
