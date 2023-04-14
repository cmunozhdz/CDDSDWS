//
//  GXWorkWithLayoutElementAlignmentHelper.h
//  GXFlexibleClient
//
//  Created by Fabian Inthamoussu on 23/04/13.
//  Copyright (c) 2013 Artech. All rights reserved.
//

@import Foundation;
@import GXFoundation;

NS_ASSUME_NONNULL_BEGIN

@interface GXWorkWithLayoutElementAlignmentHelper : NSObject <NSCoding>

@property(assign, readonly) GXHorizontalAlignType hAlign;
@property(assign, readonly) GXVerticalAlignType vAlign;

- (instancetype)initWithHorizontalAlign:(GXHorizontalAlignType)horizontalAlign
						  verticalAlign:(GXVerticalAlignType)verticalAlign NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

+ (GXHorizontalAlignType)hAlign:(nullable GXWorkWithLayoutElementAlignmentHelper *)alignHelperObject;
+ (GXVerticalAlignType)vAlign:(nullable GXWorkWithLayoutElementAlignmentHelper *)alignHelperObject;

@end

NS_ASSUME_NONNULL_END
