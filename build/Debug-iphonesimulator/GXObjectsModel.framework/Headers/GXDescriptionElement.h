//
//  GXDescriptionElement.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 10/12/10.
//  Copyright 2010 Artech. All rights reserved.
//

#import <GXObjectsModel/GXNamedElement.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXDescriptionElement : GXNamedElement <NSCoding>

@property(nullable, nonatomic, strong, readonly) NSString *desc; /// Translated if self conforms to GXModelObject
@property(nullable, nonatomic, strong, readonly) NSString *descNoTranslation;

- (instancetype)initWithName:(nullable NSString *)name
				 description:(nullable NSString *)desc NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
