//
//  GXWorkWithLayoutElementExpandableBoundsHelper.h
//  GXObjectsModel
//
//  Created by Fabian Inthamoussu on 25/10/17.
//  Copyright © 2017 GeneXus. All rights reserved.
//

@import Foundation;
@import GXFoundation;

NS_ASSUME_NONNULL_BEGIN

@interface GXWorkWithLayoutElementExpandableBoundsHelper : NSObject <NSCoding>

@property(assign, readonly) GXLayoutExpandableBounds expandableBounds;
@property(assign, readonly) GXLayoutExpandDirection expandDirection;
@property(assign, readonly) GXLayoutExpandLimit expandLimit;

- (instancetype)initWithExpandableBounds:(GXLayoutExpandableBounds)expandableBounds
						 expandDirection:(GXLayoutExpandDirection)expandDirection
							 expandLimit:(GXLayoutExpandLimit)expandLimit NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

+ (GXLayoutExpandableBounds)expandableBounds:(nullable GXWorkWithLayoutElementExpandableBoundsHelper *)expandableBoundsHelperObject;
+ (GXLayoutExpandDirection)expandDirection:(nullable GXWorkWithLayoutElementExpandableBoundsHelper *)expandableBoundsHelperObject;
+ (GXLayoutExpandLimit)expandLimit:(nullable GXWorkWithLayoutElementExpandableBoundsHelper *)expandableBoundsHelperObject;

@end

NS_ASSUME_NONNULL_END
