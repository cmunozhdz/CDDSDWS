//
//  GXResources.h
//  GXFlexibleClient
//
//  Created by Guillermo Pasquero on 11/1/11.
//  Copyright 2011 Artech. All rights reserved.
//

@import GXFoundation;
#import <GXObjectsModel/GXLanguage.h>
#import <GXObjectsModel/GXModelObjectChild.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(uint_least8_t, GXResourcesTranslationType) {
	GXResourcesTranslationNone,
	GXResourcesTranslationStatic,
	GXResourcesTranslationRuntime,
};

@class GXImage;
@class GXImagesLocalization;

@interface GXResources : GXModelObjectChild

- (instancetype)initWithLanguages:(nullable NSArray<GXLanguage *> *)languages
			   imagesLocalization:(nullable NSArray<GXImagesLocalization *> *)imagesLocalization
			  defaultLanguageName:(NSString *)defaultLanguageName
				  translationType:(GXResourcesTranslationType)translationType
				   forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;

@property(nullable, nonatomic, strong, readonly) GXLanguage *currentLanguage;
@property(nullable, nonatomic, strong, readonly) NSLocale *currentLanguageLocale;
@property(nullable, nonatomic, strong, readonly) GXImagesLocalization *currentImages;

- (void)clearCurrentLanguage;

/// #deprecated: 2022-01-31: trunk; #to-remove: ??
+ (nullable UIImage *)imageForName:(NSString *)name __attribute__((deprecated("Use instance currentImages.image(forName:) instead.")));
/// #deprecated: 2022-01-31: trunk; #to-remove: ??
+ (nullable NSURL *)urlForImageName:(NSString *)name __attribute__((deprecated("Use instance currentImages.url(forImageName:) instead.")));
/// #deprecated: 2022-01-31: trunk; #to-remove: ??
+ (nullable NSURL *)urlForImageGuid:(NSString *)guid __attribute__((deprecated("Use instance currentImages.url(forImageGuid:) instead.")));

/// #deprecated: 2022-01-31: trunk; #to-remove: ??
+ (NSString *)translationFor:(NSString *)message __attribute__((deprecated("Use translation(for:modelObject:) or instance translation(for:) instead.")));

// #deprecated: 2021-12-02: trunk; #to-remove: ??
+ (NSString *)translationWithFormat:(NSString *)format, ... NS_REQUIRES_NIL_TERMINATION  __attribute__((deprecated("Use translation(withFormat:values:) instead")));

/// #deprecated: 2022-01-31: trunk; #to-remove: ??
+ (nullable NSString *)currentLanguageName __attribute__((deprecated("Use instance currentLanguage.name instead.")));
/// #deprecated: 2022-01-31: trunk; #to-remove: ??
+ (nullable GXLanguage *)currentLanguage __attribute__((deprecated("Use instance currentLanguage instead.")));
/// #deprecated: 2022-01-31: trunk; #to-remove: ??
+ (nullable NSLocale *)currentLanguageLocale __attribute__((deprecated("Use instance currentLanguageLocale instead.")));

@end

NS_ASSUME_NONNULL_END
