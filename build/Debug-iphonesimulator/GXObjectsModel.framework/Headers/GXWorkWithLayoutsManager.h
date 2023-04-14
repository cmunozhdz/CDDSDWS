//
//  GXWorkWithLayoutsManager.h
//  GXFlexibleClient
//
//  Created by Marcos Crispino on 22/11/11.
//  Copyright (c) 2011 Artech. All rights reserved.
//

@import Foundation;
#import <GXObjectsModel/GXWorkWithLayout.h>
#import <GXObjectsModel/GXModelObjectChild.h>

NS_ASSUME_NONNULL_BEGIN

@interface GXWorkWithLayoutsManager : GXModelObjectChild

#if TARGET_OS_IOS
- (instancetype)initWithViewPortraitLayout:(nullable GXWorkWithLayout *)viewPortraitLayout
					   viewLandscapeLayout:(nullable GXWorkWithLayout *)viewLadscapeLayout
						editPortraitLayout:(nullable GXWorkWithLayout *)editPortraitLayout
					   editLandscapeLayout:(nullable GXWorkWithLayout *)editLadscapeLayout
							forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;
#else
- (instancetype)initWithViewLayout:(nullable GXWorkWithLayout *)viewLayout
						editLayout:(nullable GXWorkWithLayout *)editLayout
					forModelObject:(nullable id<GXModelObject>)modelObject NS_DESIGNATED_INITIALIZER;
#endif // TARGET_OS_IOS

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

#if TARGET_OS_IOS
- (nullable GXWorkWithLayout *)layoutForMode:(GXModeType)mode orientation:(GXInterfaceOrientation)orientation;
#else
- (nullable GXWorkWithLayout *)layoutForMode:(GXModeType)mode;
#endif


@end

NS_ASSUME_NONNULL_END
